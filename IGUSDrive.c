#include "drive.h"
#include <kipr/botball.h>

void StartUp() {
  enable_servos();
  set_servo_position(ARM_PORT, ARM_DOWN);
  set_servo_position(CARDBOARD_PORT, CARDBOARD_START);
  msleep(300);
}
void LinkThrowIgus() {
  set_servo_position(ARM_PORT, ARM_OUT);
  msleep(300);
}
void LinkDrive(float distance, float speed) {
  mav(RIGHT_PORT, speed*LINK_RIGHT_OFFSET);
  mav(LEFT_PORT, speed*LINK_LEFT_OFFSET);
  clear_motor_position_counter(RIGHT_PORT);

  while(get_motor_position_counter(RIGHT_PORT) < distance*CM_TO_TICKS) {
  }

  ao();
}
void LinkDriveBack(float distance, float speed) {
  
}

void LinkSquareUp(int time, float speed) {
  mav(RIGHT_PORT, speed*LINK_RIGHT_OFFSET);
  mav(LEFT_PORT, speed*LINK_LEFT_OFFSET);
  mav(3, 400); //Metal blocker lowered
  msleep(time);
  ao();
}
void LinkDriveSlanted(float rightSpeed, float IGUSTime, float time) {
  mav(RIGHT_PORT,rightSpeed*LINK_RIGHT_OFFSET);
  mav(LEFT_PORT, 1500*LINK_LEFT_OFFSET);
  msleep(IGUSTime);
  set_servo_position(ARM_PORT, ARM_OUT);
  msleep(time - IGUSTime);
}

void LinkDriveSlantedNoThrow(float rightSpeed, float time) {
  mav(RIGHT_PORT,rightSpeed*LINK_RIGHT_OFFSET);
  mav(LEFT_PORT, 1500*LINK_LEFT_OFFSET);
  msleep(time);
}

void CardboardLow() {
  set_servo_position(CARDBOARD_PORT, CARDBOARD_LOW);
  msleep(100);
}

void CardboardMid() {
  set_servo_position(CARDBOARD_PORT, CARDBOARD_MID);
  msleep(100);
}

void CardboardHi() {
  set_servo_position(CARDBOARD_PORT, CARDBOARD_HI);
  msleep(100);
}
