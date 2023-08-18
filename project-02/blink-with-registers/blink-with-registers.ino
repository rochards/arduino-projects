/* Caso esteja utilizando a IDE do Arduino, essas bibliotecas são importadas automaticamente
#include <avr/io.h>
#include <util/delay.h> 
*/

#define LED_PIN PB5

#define SET_PIN_AS_OUTPUT(register, pin) (register |= (1 << pin))
#define SET_PIN_ON(register, pin) (register |= (1 << pin))
#define SET_PIN_OFF(register, pin) (register &= ~(1 << pin))

int main(void) {
  
    SET_PIN_AS_OUTPUT(DDRB, LED_PIN);

    while (1) {
        SET_PIN_ON(PORTB, LED_PIN);
        _delay_ms(500);
        SET_PIN_OFF(PORTB, LED_PIN);
        _delay_ms(500);
    }

    return 0;
}
