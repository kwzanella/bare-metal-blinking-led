#include <util/delay.h>

#define DDRB  *((volatile char*) 0x24) // ATmega328P -- 13.4.3 (DDRB – The Port B Data Direction Register)
#define PORTB *((volatile char*) 0x25) // ATmega328P -- 13.4.2 (PORTB – The Port B Data Register)

#define BIT_SET(x, n)   x | (1 << n)
#define BIT_UNSET(x, n) x & ~(1 << n)

int main() {
    DDRB = BIT_SET(DDRB, 2);  // set DDRB2

    while(1) {
        PORTB = BIT_SET(PORTB, 2);  // set PORTB2
        _delay_ms(1000);

        PORTB = BIT_UNSET(PORTB, 2); // unset PORTB2
        _delay_ms(1000);
    }
    return 0;
}
