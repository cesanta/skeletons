# Microcontroller template projects

This is a collection of minimal template project for various microcontrollers,
tailored for make+GCC build tool chain.

Projects that use ARM microcontrollers, use vendor's CMSIS and implement
a tiny HAL (Hardware Abstraciton Layer) that initialises:
- CPU clock
- GPIO (for LED blinking)
- UART (for debug output)
- Ethernet/WiFi/Cellular (if a respective microcontroller provides that)

The rest of the firmware functionality is left to the user.
