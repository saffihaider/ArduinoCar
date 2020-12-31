#include <AFMotor.h>
#include <Servo.h>
Servo servo;

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

const int buzzer = A0; //Define buzzer pin, initialize variables
int horn;
char state;

void setup() {
  Serial.begin(9600);
  Serial.println("Beginnning setup");
  servo.attach (10);        // Define the servo signal pins
  motor1.setSpeed(255);     // Set motors to max speed
  motor2.setSpeed(255);     

  pinMode(buzzer, OUTPUT); //Attach piezo buzzer
  tone(buzzer, 1000); //Startup sound
  delay(500);
  noTone(buzzer);
  
}

void loop() {
    if(Serial.available() > 0){ // Checks whether data is coming from the serial port
      state = Serial.read(); // Reads the data from the serial port
      Serial.println(state);
    }
       
#include <AFMotor.h>
#include <Servo.h>
Servo servo;

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

const int buzzer = A0; //Define buzzer pin, initialize variables
int horn;
char state;

void setup() {
  Serial.begin(9600);
  Serial.println("Beginnning setup");
  servo.attach (10);        // Define the servo signal pins
  motor1.setSpeed(255);     // Set motors to max speed
  motor2.setSpeed(255);
}

void loop() {
  if (Serial.available() > 0) { // Checks whether data is coming from the serial port
    state = Serial.read(); // Reads the data from the serial port
    Serial.println(state);
  }

  switch (state)
  {
    case 'F': //Drive forward
      drive();
      servo.write(90);
      break;

    case 'B': //Reverse
      reverse();
      servo.write(90);
      break;

    case 'L': //Turn left
      cruise();
      servo.write(60);
      break;

    case 'R': //Turn right
      cruise();
      servo.write(120);
      break;

    case 'G': //Drive left
      drive();
      servo.write(60);
      break;

    case 'I': //Drive right
      drive();
      servo.write(115);
      break;

    case 'H': //Reverse left
      reverse();
      servo.write(60);
      break;

    case 'J': //Reverse right
      reverse();
      servo.write(115);
      break;
    case 'V': //Enable horn
      horn = 1;
      break;

    case 'v': //Disable horn
      horn = 0;
      break;

    default: //Cruise car
      cruise();
      servo.write(90);
      if (horn) { //Logic to handle horn
        tone(buzzer, 1000);
      }
      else {
        noTone(buzzer);
      }
  }

}

void drive() { //Drive car
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void reverse() { //Reverse car
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void cruise() { //Cruise car
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
