.PHONY : all
all : main.elf main.bin main.hex

main.hex : main.elf
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-objcopy -O ihex main.elf main.hex

main.bin : main.elf
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-objcopy -O binary main.elf main.bin

main.elf : main.o startup.o main.ld
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-ld -T main.ld -Map main.map --cref main.o startup.o -o main.elf

main.o : main.c
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -g main.c -o main.o

startup.o : startup.c
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -g startup.c -o startup.o




main-rel.elf : main-rel.o startup-rel.o main.ld
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-ld -T main.ld  -Map main.map --cref main-rel.o startup-rel.o -o main-rel.elf

main-rel.o : main.c
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb main.c -o main-rel.o

startup-rel.o : startup.c
	/opt/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb startup.c -o startup-rel.o



.PHONY : clean
clean:
	rm -f *.o *.elf *.bin *.hex *.map
