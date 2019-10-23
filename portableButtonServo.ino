#include <Servo.h>
//Johnny Krosby, Lucy Gray
//Portable Button Servo
//description

Servo myServo;

int noMove = 0;
int clockwise = 0;
int counter = 0;
int delayVar = 0;
int servoPin = 8;
int buttonPin1 = 4;
int buttonPin2 = 5;
int val1 = 0;
int val2 = 0;
int servoAngle = 0;

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

  if (val1 == HIGH && val2 == LOW) {
    //Button 1 on
    servoAngle = clockwise;
    myServo.writeMicroseconds(clockwise);
    delay(delayVar);
  }
  else if (val1 == LOW && val2 == LOW) {
    servoAngle = noMove;
    myServo.writeMicroseconds(noMove);
    delay(delayVar);
  }
  else if (val1 == HIGH && val2 == HIGH) {
    servoAngle = noMove;
    myServo.writeMicroseconds(noMove);
    delay(delayVar);
  }

  if (val1 == LOW && val2 == HIGH) {
    //Button 2 on
    servoAngle = counter;
    myServo.writeMicroseconds(counter);
    delay(delayVar);
  }
  else if (val1 == LOW && val2 == LOW) {
    servoAngle = noMove;
    myServo.writeMicroseconds(noMove);
    delay(delayVar);
  }
  else if (val1 == HIGH && val2 == HIGH) {
    servoAngle = noMove;
    myServo.writeMicroseconds(noMove);
    delay(delayVar);
  }

}
//https://www.arduino.cc/en/tutorial/pushbutton
//https://create.arduino.cc/projecthub/SBR/working-with-two-leds-and-two-push-buttons-1d4182       wiring
//https://create.arduino.cc/projecthub/glowascii/button-arduino-basics-5ecffc       more wiring
