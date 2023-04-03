#include <util/delay.h>

#define DDRB  *((volatile char*) 0x24)  // ATmega328P -- 13.4.3 (DDRB – The Port B Data Direction Register)
#define PORTB *((volatile char*) 0x25)  // ATmega328P -- 13.4.2 (PORTB – The Port B Data Register)

#define BIT_SET(x, n)   x | (1 << n)   // set n-th bit in x
#define BIT_UNSET(x, n) x & ~(1 << n)  // unset bit n-th bit in x

#define DELAY 1000

int main() {
    DDRB = BIT_SET(DDRB, 2);

    while(1) {
        PORTB = BIT_SET(PORTB, 2);
        _delay_ms(DELAY);

        PORTB = BIT_UNSET(PORTB, 2);
        _delay_ms(DELAY);
    }
    return 0;
}
