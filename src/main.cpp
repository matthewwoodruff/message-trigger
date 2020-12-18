#include <Arduino.h>

int MINUTES_BETWEEN_MESSAGES = 10;

int MESSAGE_1 = 2;
int MESSAGE_2 = 3;
int MESSAGE_3 = 4;
int MESSAGE_4 = 5;

void setup() {
  pinMode(MESSAGE_1, OUTPUT);
  pinMode(MESSAGE_2, OUTPUT);
  pinMode(MESSAGE_3, OUTPUT);
  pinMode(MESSAGE_4, OUTPUT);
}

void trigger(int message) {
  digitalWrite(message, HIGH);   
  delay(200);                      
  digitalWrite(message, LOW);    
}

void wait(int minutes) {
  delay(10000);
}

void loop() {
  trigger(MESSAGE_1);   
  wait(MINUTES_BETWEEN_MESSAGES);

  trigger(MESSAGE_2);   
  wait(MINUTES_BETWEEN_MESSAGES); 

  trigger(MESSAGE_3);   
  wait(MINUTES_BETWEEN_MESSAGES); 

  trigger(MESSAGE_4);   
  wait(MINUTES_BETWEEN_MESSAGES);                       
}