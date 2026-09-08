## Why

当前最小工程尚未实现三路充电电流检测与对应双色 LED 状态控制，需要利用已有 ADC、GPIO 和延时驱动完成板载充满/充电状态指示。

## What Changes

- 将 P03、P04、P05 配置为三路 ADC 输入，并按顺序对应 P00、P01、P02 LED 控制输出。
- 每路 ADC 连续采样 10 次，剔除 2 个最高值和 2 个最低值后，对剩余 6 个样本求平均并换算电流。
- 每 300 ms 完成一次三路滤波采样和 LED 状态刷新。
- 滤波电流大于 100 mA 时输出高电平（红灯、充电），否则输出低电平（绿灯、充满或空载）。
- 所有应用逻辑仅在现有 `main.c` 中实现，不新增源码模块。

## Capabilities

### New Capabilities

- `adc-current-led-control`: 规定三路 ADC 电流采样、10 点截尾平均滤波、300 ms 刷新周期及对应 LED 电平控制行为。

### Modified Capabilities

无。

## Impact

- 受影响源码：`../Source_Code/main.c`。
- 使用现有 `adc.c`、`gpio.c`、`delay.c` 驱动和 WY8S8002XX 寄存器定义，不改变其公共接口。
- 占用 ADC_AIN6/P03、ADC_AIN5/P04、ADC_AIN4/P05，以及 GPIO P00、P01、P02 和 Timer0 阻塞延时。
- 需要通过 Keil C51 编译，并在实板上校验 100 mA 阈值与 300 ms 周期。
