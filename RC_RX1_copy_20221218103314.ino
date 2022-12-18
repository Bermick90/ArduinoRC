#define RCPin 2
#define RCPin2 7
#define RCPin3 8
#define RCPin4 4
#define LEDPin1 6
#define LEDPin2 5

#include <Servo.h>
double RCValue;
double RCValuePin2;
double RCValuePin3;
double RCValuePin4;
double LEDPin2Value;
Servo myservo;
double val;

void setup() {
  Serial.begin(9600);
  pinMode(RCPin,INPUT);
  pinMode(RCPin2,INPUT);
  pinMode(RCPin3,INPUT);
  pinMode(RCPin4,INPUT);
  pinMode(LEDPin1,OUTPUT);
  pinMode(LEDPin2,OUTPUT);
  myservo.attach(10);
}

void loop() {
  RCValue=pulseIn(RCPin,HIGH);
  RCValuePin2=pulseIn(RCPin2,HIGH);
  RCValuePin3=pulseIn(RCPin3,HIGH);
  RCValuePin4=pulseIn(RCPin4,HIGH);
  val = map(RCValue, 1010, 2000, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  LEDPin2Value=map(RCValuePin3, 900, 2000, 0, 255);
  Serial.println(RCValuePin4);
  analogWrite(LEDPin2,val);//LEDPin2Value
  myservo.write(val);                  // sets the servo position according to the scaled value

  if(RCValuePin2 < 1300){
    digitalWrite(LEDPin1,LOW);
  }
  if(RCValuePin2 > 1700){
    digitalWrite(LEDPin1,HIGH);
  }

  delay(5);
}
