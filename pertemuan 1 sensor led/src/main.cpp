#include <Arduino.h>

int LED1 = D0;
int LED2 = D2;
int LED3 = D3;
int LED4 = D4;
int LED5 = D6;
int LED6 = D7;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(50);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(30);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(10);
  digitalWrite(LED3, LOW);
  
  digitalWrite(LED4, HIGH);
  delay(50);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
  delay(30);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, HIGH);
  delay(10);
  digitalWrite(LED6, LOW);
}