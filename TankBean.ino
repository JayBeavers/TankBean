#include "./ZumoMotors.h"

/*
 * This example uses the ZumoMotors library to drive each motor on the Zumo
 * forward, then backward. The yellow user LED is on when a motor should be
 * running forward and off when a motor should be running backward. If a
 * motor on your Zumo has been flipped, you can correct its direction by
 * uncommenting the call to flipLeftMotor() or flipRightMotor() in the setup()
 * function.
 */

//#define LED_PIN 13

#define LEFT_FULL_SPEED 400
#define RIGHT_FULL_SPEED 330

ZumoMotors motors;

void setup()
{
  //pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);
}

void loop()
{
  // run left motor forward
  
  if (Serial.available() > 0) {
    
    int inByte = Serial.read();
    Serial.print(inByte);
    
    if (inByte == 'a') {
      motors.setLeftSpeed(0);
      motors.setRightSpeed(RIGHT_FULL_SPEED / 2);
    } else if (inByte == 's') {
      motors.setLeftSpeed(LEFT_FULL_SPEED);
      motors.setRightSpeed(RIGHT_FULL_SPEED);
    } else if (inByte == 'd') {
      motors.setLeftSpeed(LEFT_FULL_SPEED / 2);
      motors.setRightSpeed(0);
    } else if (inByte == 'z') {
      motors.setLeftSpeed(-LEFT_FULL_SPEED / 2);
      motors.setRightSpeed(0);
    } else if (inByte == 'x') {
      motors.setLeftSpeed(-LEFT_FULL_SPEED / 4);
      motors.setRightSpeed(-RIGHT_FULL_SPEED / 4);
    } else if (inByte == 'c') {
      motors.setLeftSpeed(0);
      motors.setRightSpeed(-RIGHT_FULL_SPEED / 2);
    } else if (inByte == ' ') {
      motors.setLeftSpeed(0);
      motors.setRightSpeed(0);
    } else {
      Serial.print('Dood, not supported!');
    }

  }
}
