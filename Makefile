default:
		avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o build/blinking_led.o blinking_led.c
		avr-gcc -o build/blinking_led.bin build/blinking_led.o
		avr-objcopy -O ihex -R .eeprom build/blinking_led.bin build/blinking_led.hex
		sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:build/blinking_led.hex