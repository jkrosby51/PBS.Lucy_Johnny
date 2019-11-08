#include <Servo.h>
//Portable Button Servo
//Johnny Krosby, Lucy Gray
//Continuous servo controlled by buttons

Servo myServo;

int noMove = 0; //variable for when the servo is not moving
int clockwise = 0; //variable for when the servo is moving clockwise
int counter = 0; //variable for when the servo is moving counter clockwise
int delayVar = 0; //how long each delay lasts
int servoPin = 8;
int buttonPin1 = 4;
int buttonPin2 = 5;
int val1 = 0; //whether or not button1 is on
int val2 = 0; //whether or not button2 is on
int servoAngle = 0; //variable used for servo speed

void setup() {
  noMove = 1500;
  clockwise = 1700;
  counter = 1300;
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  myServo.attach(servoPin);
  myServo.writeMicroseconds(noMove);
  delayVar = 0;
}

void loop() {

  val1 = digitalRead(buttonPin1);
  Serial.print(val1);
  Serial.println(" = val1");
  val2 = digitalRead(buttonPin2);
  Serial.print("             ");
  Serial.print(val2);
  Serial.print(" = val2");
  Serial.print("         ");
  Serial.print(servoAngle);
  Serial.println(" = servoAngle");
//if only button 1 is on the servo will turn clockwise and show in Serial Monitor
  if (val1 == HIGH && val2 == LOW) {
    //Button 1 on
    servoAngle = clockwise;
    myServo.writeMicroseconds(clockwise);
    delay(delayVar);
  }
  //if neither buttons pressed do nothing
  else if (val1 == LOW && val2 == LOW) {
    servoAngle = noMove;
    myServo.writeMicroseconds(noMove);
    delay(delayVar);
  }
  //if both buttons pressed do nothing
  else if (val1 == HIGH && val2 == HIGH) {
    servoAngle = noMove;
    myServo.writeMicroseconds(noMove);
    delay(delayVar);
  }
//if only button 2 is on the servo will turn counter clockwise and show in Serial Monitor
  if (val1 == LOW && val2 == HIGH) {
    //Button 2 on
    servoAngle = counter;
    myServo.writeMicroseconds(counter);
    delay(delayVar);
  }
  //if neither buttons pressed do nothing
  else if (val1 == LOW && val2 == LOW) {
    servoAngle = noMove;
    myServo.writeMicroseconds(noMove);
    delay(delayVar);
  }
  //if both buttons pressed do nothing
  else if (val1 == HIGH && val2 == HIGH) {
    servoAngle = noMove;
    myServo.writeMicroseconds(noMove);
    delay(delayVar);
  }

}
//References

//https://www.arduino.cc/en/tutorial/pushbutton
//https://create.arduino.cc/projecthub/SBR/working-with-two-leds-and-two-push-buttons-1d4182       wiring
//https://create.arduino.cc/projecthub/glowascii/button-arduino-basics-5ecffc       more wiring
