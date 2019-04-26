#include <Arduino.h>
#include <Servo.h>

Servo thrustServo;
Servo pitchServo;

int dcSpeed = 3;
int dcDir = 6;

int posThrust = 0;
int posPitch = 0;

void setup() {
   pinMode(dcSpeed,OUTPUT);
   pinMode(dcDir,OUTPUT);
}

void loop() {
   digitalWrite(dcDir,HIGH);
   for(size_t i = 60; i < 255; i++)
   {
      analogWrite(dcSpeed,i);
      delay(50);
   }   
   analogWrite(dcSpeed,255);   
   delay(5000);
   for(size_t i = 255; i > 60; i--)
   {
      analogWrite(dcSpeed,i);
      delay(50);   
   }
   delay(5000);
}