# Controlando um ângulo de um servo motor com arduino

Lista de materiais utilizadas:
- Placa utilizada: Arduino Nano 33 IoT;
- Referência para a pinagem do arduino: página 10 do [datasheet](https://docs.arduino.cc/static/e4c0995f6804e9803ce25b51fca86afb/ABX00027-datasheet.pdf);
- Servo motor utilizado: MG 90 S;
- Referência para a pinagem do servo motor: página 2 do [datasheet](https://www.makerhero.com/img/files/download/Servo-mg90s-Datasheet.pdf);
- Potenciômetro 10 kΩ;
- Protoboard;
- Fonte 5 V;


**OBS.:** o Arduino Nano fornece no máximo uma tensão de saída de 3,3 V, enquanto o pino de sinal PWM do servo trabalha na faixa compreendida em 4,8 V - 6 V, então utilizar o pino do Arduino pode trazer efeitos colaterais, como queima da placa, ou simplesmente não funcionar.

Esquema de ligação:
- 5 V da fonte -> pino `Vin` Arduino;
- 3,3 V da fonte -> alimentação do potenciômetro;
- 5 V da fonte -> `Vcc` servo motor
- pino central do potenciômetro -> pino `A0` Arduino;
- GND/negativo da fonte -> `GND` Arduino;
- GND/negativo da fonte -> GND potenciômetro;
- GND/negativo da fonte -> `Ground` servo motor;
- pino `D2` Arduino -> `PWM` servo motor. **Leia a observação acima**;