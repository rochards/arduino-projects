/*
  Placa utilizada: Arduino Nano 33 IoT
  Objetivo do programa: Controlar o ângulo de um servo motor utilizando um potenciômetro
*/

#include <Servo.h>

#define SERVO_PIN 2 // D2
#define SERVO_MAX_ANGLE 180

#define POTENTIOMETER_PIN A0
#define ANALOG_MAX_VALUE 1023

Servo servo;
int potentiometerValue = 0;
int servoAngle = 0;

void setup() {
  servo.attach(SERVO_PIN);
}

void loop() {
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  servoAngle = map(potentiometerValue, 0, ANALOG_MAX_VALUE, 0, SERVO_MAX_ANGLE);

  servo.write(servoAngle);

  delay(5);
}
