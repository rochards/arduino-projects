// Caso esteja utilizando a IDE do Arduino, essas bibliotecas são importadas automaticamente
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5 // pino 13 no Arduino Uno 
#define BUTTON_PIN PB2 // pino 10 no Arduino Uno

#define SET_ONE_ON_BIT(register, bit) (register |= 1 << bit)
#define SET_ZERO_ON_BIT(register, bit) (register &= ~(1 << bit))

void mySetup() {
    
  SET_ONE_ON_BIT(DDRB, LED_PIN); // configura o pino como saída
    
  SET_ZERO_ON_BIT(DDRB, BUTTON_PIN); // configura o pino como entrada
  SET_ONE_ON_BIT(PORTB, BUTTON_PIN); // habilita o resistor de pull-up interno
}

uint8_t isButtonPressed() {
  return !(PINB & (1 << BUTTON_PIN));
}

int main(void) {
    
  mySetup();

  while (1) {
    if (isButtonPressed()) {
      SET_ONE_ON_BIT(PORTB, LED_PIN); // -> PORTB |= 1 << LED_PIN;
    } else {
      SET_ZERO_ON_BIT(PORTB, LED_PIN); // -> PORTB &= ~(1 << LED_PIN);
    }
    _delay_ms(100);
  }

  return 0;
}
