---
name: add-watchdog-protection
overview: 在 Board_Init() 中配置并启用 WDT 看门狗（~8秒超时），在主循环中定期喂狗，提供系统死机自动复位保护。
todos:
  - id: verify-wdt-in-project
    content: 确认 wdt.c 已加入 Keil 工程编译列表，若不存则添加
    status: completed
  - id: add-wdt-init
    content: 在 board_config.c 的 Board_Init() 末尾添加 WDT 配置和启动代码
    status: completed
    dependencies:
      - verify-wdt-in-project
  - id: add-wdt-feed
    content: 在 main.c 主循环 while(1) 末尾添加 WDT_ClearWDT() 喂狗
    status: completed
    dependencies:
      - verify-wdt-in-project
  - id: build-verify
    content: 编译工程，确认无错误，验证 WDT 相关符号正确链接
    status: completed
    dependencies:
      - add-wdt-init
      - add-wdt-feed
---

## 需求概述
为当前 WY8S8002 ADC_CMP 工程添加看门狗（WDT）保护，使系统在因干扰或逻辑异常导致主循环卡死时能自动复位恢复。

## 核心功能
- 在系统初始化（Board_Init）末尾配置并启用 WDT，超时约 8.192 秒
- 在主循环每轮迭代末尾执行喂狗（清除 WDT 计数器）
- 溢出时自动复位 MCU（不产生中断，直接硬件复位）
- Idle/Sleep 低功耗模式下 WDT 仍保持运行

## 技术栈
- MCU：WY8S8002（8051 内核）
- WDT 驱动：复用 BSP 已有 `Library/inc/wdt.h` + `Library/src/wdt.c`
- 编译工具链：Keil C51

## 实现方案

### 方案概述
利用 BSP 库已提供的 WDT 驱动 API，在两个位置插入极少量代码：
1. **board_config.c 的 Board_Init() 末尾**：配置 WDT 时钟分频、溢出复位、运行模式，然后启动 WDT
2. **main.c 主循环末尾**：每轮迭代调用 `WDT_ClearWDT()` 喂狗

### 关键设计决策

**超时时间选择：WDT_DIV_1024（~8.192s）**
- LRC = 32kHz，8-bit 计数器，超时 = 256 × (1024 / 32000) ≈ 8.192s
- 主循环无阻塞操作，单轮迭代远小于 1s，8s 余量充足
- 避免因偶发中断风暴（Timer3 1ms 中断等）导致的误复位
- 若选用较小分频（如 DIV_512），超时仅 ~4s，在极端情况下存在误触发风险

**运行模式选择：WDT_IDLE_SLEEP_MODE**
- 确保 MCU 进入 Idle/Sleep 低功耗状态时 WDT 仍工作
- 该工程当前未使用 Sleep 模式，但预留扩展性

**溢出复位：ENABLE_OVER_RST**
- 溢出时直接硬件复位，不依赖中断响应（中断系统可能已卡死）
- 确保看门狗在中断关闭或嵌套死锁场景下仍能恢复系统

### 改动范围
仅涉及 2 个源文件，各添加 1 行 `#include` 和 1~3 行函数调用：
- `board_config.c`：引用 `wdt.h`，在 `Board_Init()` 末尾添加配置+启动
- `main.c`：引用 `wdt.h`，在 `while(1)` 循环末尾添加喂狗

### 影响分析
- **中断时序**：WDT 是独立硬件（LRCCLK 驱动），不占用 Timer0~Timer3，不影响现有中断优先级
- **功耗**：LRC 振荡器本身已在运行，WDT 计数器模块功耗极低
- **启动时序**：WDT 在 `Board_Init()` 末尾启动（在所有外设初始化之后），避免初始化阶段误复位
- **编译链接**：`wdt.c` 已在 BSP 库中，需确认 Keil 工程已将其加入编译列表
