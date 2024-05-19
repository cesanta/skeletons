# Environment setup: https://mongoose.ws/documentation/tutorials/tools/

CFLAGS  = -W -Wall -Wextra -Wundef -Wshadow -Wdouble-promotion
CFLAGS += -Wformat-truncation -fno-common -Wconversion -Wno-sign-conversion
CFLAGS += -g3 -Os -ffunction-sections -fdata-sections
CFLAGS += -I. -Icmsis_core/CMSIS/Core/Include -Icmsis_f7/Include
CFLAGS += -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 $(CFLAGS_EXTRA)
LDFLAGS ?= -Tlink.ld -nostdlib -nostartfiles --specs nosys.specs -lc -lgcc -Wl,--gc-sections -Wl,-Map=$@.map

SOURCES = main.c hal.c
SOURCES += cmsis_f7/Source/Templates/gcc/startup_stm32f746xx.s

all build: firmware.bin

firmware.bin: firmware.elf
	arm-none-eabi-objcopy -O binary $< $@
	arm-none-eabi-size --format=berkeley $<

firmware.elf: cmsis_core cmsis_f7 $(SOURCES) $(wildcard *.h) link.ld Makefile
	arm-none-eabi-gcc $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $@

cmsis_core:
	git clone -q -c advice.detachedHead=false --depth 1 -b 5.9.0 https://github.com/ARM-software/CMSIS_5 $@
cmsis_f7:
	git clone -q -c advice.detachedHead=false --depth 1 -b v1.2.8 https://github.com/STMicroelectronics/cmsis_device_f7 $@

flash: firmware.bin
	st-flash --reset write $< 0x8000000

PORT ?= /dev/cu.usb*
monitor:
	cu -l $(PORT) -s 115200

clean:
	rm -rf firmware.* cmsis_*
