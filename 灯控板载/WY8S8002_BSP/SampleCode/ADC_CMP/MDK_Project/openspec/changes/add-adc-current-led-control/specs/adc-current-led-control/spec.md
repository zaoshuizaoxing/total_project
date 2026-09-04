## ADDED Requirements

### Requirement: ADC 与 LED 通道映射
系统 SHALL 将 P03/ADC_AIN6、P04/ADC_AIN5、P05/ADC_AIN4 作为三路电流采样输入，并依次将 P00、P01、P02 作为各路对应的 LED 状态输出。

#### Scenario: 三路对应关系
- **WHEN** 系统处理 P03、P04 或 P05 的滤波结果
- **THEN** 系统分别只更新 P00、P01 或 P02 对应输出

### Requirement: 十点平均滤波与电流换算
系统 SHALL 对每个 ADC 输入连续采集 10 个有效的 12 位样本，并使用 10 个样本的算术平均效果和 200 mΩ 采样电阻换算滤波电流，换算单位为 mA。

#### Scenario: 完成一路滤波
- **WHEN** 某一路已取得 10 个有效 ADC 样本
- **THEN** 系统使用全部 10 个样本计算该路滤波电流，且不使用其他通道的样本

### Requirement: LED 充电状态控制
系统 SHALL 在滤波电流大于 100 mA 时将对应 LED 控制管脚置高，在滤波电流小于或等于 100 mA 时将对应管脚置低。

#### Scenario: 充电电流大于阈值
- **WHEN** 某一路滤波电流大于 100 mA
- **THEN** 对应 LED 控制管脚输出高电平并显示红灯

#### Scenario: 充满、阈值点或空载
- **WHEN** 某一路滤波电流小于或等于 100 mA，包括空载状态
- **THEN** 对应 LED 控制管脚输出低电平并显示绿灯

### Requirement: 状态刷新周期
系统 SHALL 在每轮完成三路滤波采样和 LED 更新后等待 300 ms，再开始下一轮采样。

#### Scenario: 连续运行
- **WHEN** 一轮三路 LED 状态均已更新
- **THEN** 系统延时 300 ms 后开始下一轮三路采样

### Requirement: 上电默认状态
系统 SHALL 在 ADC 首轮滤波结果产生前将 P00、P01、P02 配置为低电平推挽输出。

#### Scenario: 初始化完成但尚未采样
- **WHEN** GPIO 初始化完成且首轮 ADC 滤波尚未完成
- **THEN** 三路 LED 控制管脚均保持低电平并显示绿灯
