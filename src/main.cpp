#include <Arduino.h>
#include <Servo.h>

Servo thrustServo;
Servo pitchServo;

int dcSpeed = 3;
int dcDir = 6;
int speedPotPin = 14;

int turnSpeed = 0;
int posThrust = 0;
int posPitch = 0;

void setup() {
   pinMode(dcSpeed,OUTPUT);
   pinMode(dcDir,OUTPUT);
   pinMode(speedPotPin,INPUT);
   Serial.begin(9600);
}

void loop() {
   turnSpeed = analogRead(speedPotPin);
   turnSpeed = map(turnSpeed, 0, 1023, 0, 255);
   digitalWrite(dcDir,HIGH);
   analogWrite(dcSpeed,turnSpeed);
}