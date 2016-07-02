#include "drive.h"
#include <kipr/botball.h>

void startUp () {
	enable_servos();
  	set_servo_position(ARM_PORT, ARM_UP);
  	msleep(300);
}

void linkDrive (float distance, float speed) {
 	 clear_motor_position_counter(LEFT_PORT);
 	 clear_motor_position_counter(RIGHT_PORT);
  	mav(LEFT_PORT, speed*LINK_LEFT_OFFSET);
  	mav(RIGHT_PORT, speed*LINK_RIGHT_OFFSET);
  	while(get_motor_position_counter(LEFT_PORT)< distance*LINK_DRIVE_OFFSET*CM_TO_TICKS  && 
    	    get_motor_position_counter(RIGHT_PORT) < distance*LINK_DRIVE_OFFSET*CM_TO_TICKS) {
  	}
  	//printf("%d\n", get_motor_position_counter(LEFT_PORT));
  	ao();
}

void linkDriveBack (float distance, float speed) {
	clear_motor_position_counter(LEFT_PORT);
	clear_motor_position_counter(RIGHT_PORT);
	mav(LEFT_PORT,-speed*LINK_LEFT_OFFSET);
	mav(RIGHT_PORT,-speed*LINK_RIGHT_OFFSET);
	while(get_motor_position_counter(LEFT_PORT)>-distance*LINK_DRIVE_OFFSET*CM_TO_TICKS && 
          get_motor_position_counter(RIGHT_PORT)>-distance*LINK_DRIVE_OFFSET*CM_TO_TICKS) {
	}
	ao();
}

void linkSquareUp (int time, float speed) {
  	mav(LEFT_PORT,speed*LINK_LEFT_OFFSET);
  	mav(RIGHT_PORT,speed*LINK_RIGHT_OFFSET);
  	msleep(time);
  	ao();
}

void hop() {
  	mav(LEFT_PORT,1500*LINK_LEFT_OFFSET);
  	mav(RIGHT_PORT,1500*LINK_RIGHT_OFFSET);
 	set_servo_position(ARM_PORT,ARM_DOWN);
  	msleep(800);
  	set_servo_position(ARM_PORT,ARM_UP);
  	msleep(500);
}

void linkDriveToOpponentBase(){
  	mav(RIGHT_PORT, 1500*LINK_RIGHT_OFFSET);
  	msleep(1250);
  	ao();
}
