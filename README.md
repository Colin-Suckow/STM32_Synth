# STM32 Polyphonic Synthesizer

A basic toy synth with 16 polyphonic voices and a simple ADSR envelope. Built using an STM32F302 nucleo board. Done as a project to become more familiar with both sound synthesis and stm32 development. Might do a full write up later on my website. Currently only plays the wii shop song and other songs of similar complexity, anything more complicated starts to get a little muddy due to the lack of different instruments.

### TODO
- [ ] Record demo
- [ ] Make sound more like a real piano
- [ ] Multiple instruments
- [ ] FM synthesis

### Build
Standard stm32cube project. Doesn't use any crazy hardware features so it should build for most boards. Requires TIM2 for sound generation and USART1 for serial communication.

