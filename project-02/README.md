# Piscando um Led com os registradores do ATmega328p :bulb:

Aqui utilizaremos um Arduino Uno Rev.3.

Primeiro, listando as documentações aqui utilizadas:
1. Arduino Uno Rev. 3: :link: https://docs.arduino.cc/hardware/uno-rev3;
1. Biblioteca `avr/io.h`: :link: https://github.com/avrdudes/avr-libc/blob/main/include/avr/io.h;
1. Biblioteca `avr/portpins.h`: :link: https://github.com/avrdudes/avr-libc/blob/main/include/avr/portpins.h;
1. Biblioteca `util/delay.h`: :link: https://github.com/avrdudes/avr-libc/blob/main/include/util/delay.h.in
1. Datasheet ATmega328p: :link: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf.

 
O pino que vamos utilizar é o D13, pois já possui conexão a um LED na própria placa do Arduino. A referência para os registradores está na imagem a seguir:

![arduino pinout](https://docs.arduino.cc/static/2b141eb1cfe6f465a949c203e4af1b5f/A000066-pinout.png)

perceba que o D13 está associado ao registrador PB5/PORTB5.  
**OBS.:** PB5 e PORTB5 se referem ao mesmo registrador no *datasheet* do ATmega328p.

Na página 72 do *datasheet* do ATmega328p vemos no detalhe os registradores em que estamos interessados:
![registradores do portB](registradores.png)
- PORTB: é o registrador onde controlaremos o sinal ON/OFF do pino do LED. No caso utilizaremos o bit PORTB5/PB5;
- DDRB: é o registrador que determina se determinado pino é de leitura ou escrita. Precisamos configurar o bit DDRB5/PB5.

Então vamos ao código :man_technologist::

```c++
/* Caso esteja utilizando a IDE do Arduino, essas bibliotecas são importadas automaticamente
#include <avr/io.h>
#include <util/delay.h> 
*/

#define LED_PIN PB5

#define SET_PIN_AS_OUTPUT(register, bit) (register |= 1 << bit)
#define SET_PIN_ON(register, bit) (register |= 1 << bit)
#define SET_PIN_OFF(register, bit) (register &= ~(1 << bit))

int main(void) {
  
    SET_PIN_AS_OUTPUT(DDRB, LED_PIN); // -> DDRB |= 1 << LED_PIN;

    while (1) {
        SET_PIN_ON(PORTB, LED_PIN); // -> PORTB |= 1 << LED_PIN;
        _delay_ms(500);
        SET_PIN_OFF(PORTB, LED_PIN); // -> PORTB &= ~(1 << LED_PIN);
        _delay_ms(500);
    }

    return 0;
}

```
Nesse código utilizamos muitas operações chamadas de *bitwise*, como `|`, `<<`, `&` e `~`. Caso não tenha familiaridade com essas operações da linguagem C, visite a página [Bitwise Operators in C/C++](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/).

Explicando as partes mais importantes do código:
- `#define LED_PIN PB5` -> definindo uma macro para o PB5 para melhorar a legibilidade do código. Dá para trocar PB5 só por 5, pois no final a gente só quer a posição do bit. Na verdade PB5 já está definido como 5 na biblioteca `avr/portpins.h`, que é internamente incluída pela `avr/io.h`;
- `SET_PIN_AS_OUTPUT(DDRB, LED_PIN); // -> DDRB |= 1 << LED_PIN;` -> ou `DDRB = DDRB | 1 << LED_PIN` define o bit 5 como saída. No final essa operação nos dá em binário o valor `00100000` para o DDRB, isso está definindo o bit 5 do PORTB como saída;
- `SET_PIN_ON(PORTB, LED_PIN); // -> PORTB |= 1 << LED_PIN;` -> escreve nível lógico alto no bit 5 do PORTB, ou seja, liga o LED;
- `_delay_ms(500);` -> para a execução por 500 milissegundos. Essa função está definida na biblioteca `util/delay.h`;
- `SET_PIN_OFF(PORTB, LED_PIN); // -> PORTB &= ~(1 << LED_PIN);` -> escreve nível lógico baixo no bit 5 do PORTB, ou seja, desliga o LED.

# Contribuindo
Encontrou algum erro ou possui alguma sugestão? Abra uma *issue* com as suas considerações.