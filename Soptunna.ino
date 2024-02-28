/*
File: 
 */

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int trigPin = 9, echoPin = 10; //Attaches trig to pin 9 and echo to pin 10
float duration, distance; //Variables to store duration and distance

void setup() {
  myservo.attach(11);  // attaches the servo on pin 11 to the servo object
  pinMode(trigPin, OUTPUT); //sets pin 9 as outout pin
  pinMode(echoPin, INPUT); // sets pin 10 as input pin
}

void loop() {
  //Triggering the ultasonic sensor to initiate distance measurement
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time taken for the ultrasonic pulse to return
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration*.0343)/2;  //calculate distance based on speed of sound
  delay(10); 

  //Opens the lid if you are 19 cm away drom the distance sensor
  if (distance < 19) {
    myservo.write(90);  // tell servo to go to position 90 degrees
    delay(5000); 
    //waits 5 seconds for servo to get in this position
  } else {
    myservo.write(0);              // set myservo to position 0 degrees
    delay(100);    
  }// waits 100ms for the servo to reach the position
}
  
