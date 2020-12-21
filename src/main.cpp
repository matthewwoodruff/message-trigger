#include <Arduino.h>

int MINUTES_BETWEEN_MESSAGES = 10;

int MESSAGE_1 = 3;
int MESSAGE_2 = 5;
int MESSAGE_3 = 7;
int MESSAGE_4 = 9;

#define NUMBER_OF_MESSAGES 4

int messages[NUMBER_OF_MESSAGES] = {MESSAGE_1, MESSAGE_2, MESSAGE_3, MESSAGE_4};

void setup() {
  for (int i = 0; i < NUMBER_OF_MESSAGES; i++) {
    pinMode(messages[i], OUTPUT);
  } 
  pinMode(LED_BUILTIN, OUTPUT);
}

void flash() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
}

void trigger(int message, int flashes) {
  for (int i = 0; i < flashes; i++) {
    flash();
  }
  digitalWrite(message, HIGH);   
  delay(500);                      
  digitalWrite(message, LOW);   
}

void wait(int minutes) {
  delay(MINUTES_BETWEEN_MESSAGES * 60000);
}

void loop() {
  for (int i = 0; i < NUMBER_OF_MESSAGES; i++) {
    trigger(messages[i], i + 1);   
    wait(MINUTES_BETWEEN_MESSAGES);
  }                    
}