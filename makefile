all: blink0.bin

GCCARMBIN=/data/embedded-bins/gcc-arm-none-eabi-4_7-2013q2/bin
CC=$(GCCARMBIN)/arm-none-eabi-gcc
CFLAGS=-Os -mthumb -mcpu=cortex-m0plus
LDFLAGS=-nostdlib -T ./blink0.ld

blink0.axf: blink0.o blink0.ld makefile
	$(CC) $(CFLAGS) $(LDFLAGS) blink0.o -o blink0.axf

blink0.bin: blink0.axf
	$(GCCARMBIN)/arm-none-eabi-objcopy blink0.axf -O binary blink0.bin
