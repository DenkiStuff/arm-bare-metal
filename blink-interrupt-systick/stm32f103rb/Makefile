.PHONY : all
all : main.elf main.bin main.hex

main.hex : main.elf
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-objcopy -O ihex main.elf main.hex

main.bin : main.elf
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-objcopy -O binary main.elf main.bin

main.elf : main.o startup.o
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-ld -T main.ld main.o startup.o -o main.elf

main.o : main.c
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -g main.c -o main.o

startup.o : startup.c
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -g startup.c -o startup.o

.PHONY : clean
clean:
	rm -f *.o *.elf *.bin *.hex
