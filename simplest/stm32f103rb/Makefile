all : main.elf main.bin

main.bin : main.elf
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-objcopy -O binary main.elf main.bin

main.elf : main.o startup.o main.ld
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-ld -T main.ld -Map main.map --cref main.o startup.o -o main.elf

main.o : main.c
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -g main.c -o main.o

startup.o : startup.s
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-as -mcpu=cortex-m3 -mthumb startup.s -o startup.o

.PHONY : clean
clean:
	rm -f *.o *.elf *.bin *.map
