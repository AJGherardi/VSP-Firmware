#include <Arduino.h>
#include <Servo.h>

Servo thrustServo;
Servo pitchServo;

int pitchServoPin = 4;

int dcSpeed = 3;
int dcDir = 6;
int speedPotPin = 14;
int pitchPotPin = 15;

int turnSpeed = 0;
int posThrust = 0;
int posPitch = 0;

void setup() {
   pinMode(pitchPotPin,OUTPUT);
   pinMode(dcSpeed,OUTPUT);
   pinMode(dcDir,OUTPUT);
   pinMode(speedPotPin,INPUT);
   pinMode(pitchPotPin,INPUT);
   pitchServo.attach(pitchServoPin);
}

void loop() {
   posPitch = analogRead(pitchPotPin);
   posPitch = map(posPitch,0,1023,60,160);
   turnSpeed = analogRead(speedPotPin);
   turnSpeed = map(turnSpeed, 0, 1023, 0, 255);
   pitchServo.write(posPitch);
   digitalWrite(dcDir,HIGH);
   analogWrite(dcSpeed,turnSpeed);
}