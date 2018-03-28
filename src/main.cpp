#include <Arduino.h>
#include "HCSR04.h"

#define LEFT_MOTOR 10
#define RIGHT_MOTOR 9
#define BUTTON 13

// function prototypes
void moveForward();
void stop();
void turnLeft();
void turnRight();


float distance = 1;
int leftMotorPWM = 180;
int rightMotorPWM = 180;
float minDistance = .4;


HCSR04 distanceSensor(5,4);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Hello World!");
    pinMode(LEFT_MOTOR, OUTPUT);
    pinMode(RIGHT_MOTOR, OUTPUT);
    pinMode(BUTTON,INPUT);
    while(!digitalRead(BUTTON));
    while(digitalRead(BUTTON));
    delay(200);
}


void loop() {
    // put your main code here, to run repeatedly:
    if(digitalRead(BUTTON)){
      Serial.println("Button detected, stopping!");
      stop();
      while(true);
    }
    distance = distanceSensor.getDistance();
    Serial.println("Dist: " + String(distance));
    if(distance < minDistance && distance != -1){
      stop();
      turnLeft();
      delay(300);
      moveForward();
    }
    moveForward();
}

void moveForward(){
  analogWrite(LEFT_MOTOR, leftMotorPWM);
  analogWrite(RIGHT_MOTOR, rightMotorPWM);
}

void stop(){
  digitalWrite(LEFT_MOTOR, LOW);
  digitalWrite(RIGHT_MOTOR, LOW);
}

void turnLeft(){
  analogWrite(RIGHT_MOTOR, rightMotorPWM);
  digitalWrite(LEFT_MOTOR, LOW);
}

void turnRight(){
  analogWrite(LEFT_MOTOR, leftMotorPWM);
  digitalWrite(RIGHT_MOTOR, LOW);
}
