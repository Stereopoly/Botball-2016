#include "createDrive.h"
#include <kipr/botball.h>

void createConnectAll () {
  	create_connect();
  	enable_servos();
  	clear_motor_position_counter(armMotorF);
  	clear_motor_position_counter(armMotorB);
}

void createDrive (float speed, float distance) {
set_create_distance(0);
create_drive_direct(speed*createRightOffset, speed*createLeftOffset);
while (get_create_distance() <= distance*10*createDriveOffset) {
    }
create_stop();
}

void createDriveBack (float speed, float distance) {
set_create_distance(distance*createDriveOffset);
create_drive_direct(-speed*createRightOffset, -speed*createLeftOffset);
while (get_create_distance() >= 0) {
    }
create_stop();
}

void createDriveUntilTouch (float speed) {
create_drive_direct(speed*createRightOffset, speed*createLeftOffset);
  	while (!get_create_rbump() && !get_create_lbump()) {
    }
  	create_stop();
}

void createSquareUp(float speed, float time) {
  	create_drive_direct(-speed*createRightOffset, -speed*createLeftOffset);
  	msleep(time);
  	create_stop();
}

void driveUntil (float speed, float time) {
create_drive_direct(speed*createRightOffset, speed*createLeftOffset);
  	msleep(time);
  	create_stop();
}


void createTurnLeft(float speed, int degrees) {
set_create_normalized_angle(0); //Reset the angle
create_spin_CCW(speed); //Spin at half power
while(get_create_normalized_angle() < (degrees - 20)*createTurnOffset) {} //go most of the distance
create_spin_CCW(speed/5); //slow down as to not overshoot
while(get_create_normalized_angle() < degrees) {} //and finish the turn
create_stop();
}

void createTurnRight(float speed, int degrees) {
set_create_normalized_angle(degrees*createTurnOffset); //Reset the angle
create_spin_CW(speed); //Spin at half power
while(get_create_normalized_angle() > 20) {} //go most of the distance
create_spin_CW(speed/5); //slow down as to not overshoot
while(get_create_normalized_angle() > 0) {} //and finish the turn
create_stop();
}
/*
void createMoveArm (float speed, int position) {
int arm_pos_calc = -(down_pos_counter/start_pos)*position + down_pos_counter;
    if (get_motor_position_counter(armMotorF) > arm_pos_calc*armCalcOffset) {
//too high
//go down
motor(armMotorF, speed);
motor(armMotorB, -speed);
    }
  	else if (get_motor_position_counter(armMotorF) < arm_pos_calc*armCalcOffset) {
//too low
//go up
motor(armMotorB, speed);
motor(armMotorF, -speed);
    }
while (!(arm_pos_calc*armCalcOffset-10 < -get_motor_position_counter(armMotorF) &&
-get_motor_position_counter(armMotorF) < arm_pos_calc*armCalcOffset+10)) {
}
  	ao();
}

void createResetArm(float speed) {
  	motor(armMotorB, speed);
motor(armMotorF, -speed);
  	while (!digital(touchPort)) {
    }
  	ao();
}
*/

void createArmStay() {
motor(armMotorB, 1);
motor(armMotorF, -1);
}

void createArmUp(float speed) {
  	motor(armMotorB, -speed);
motor(armMotorF, speed);
  	while (!digital(touchPortB)) {
    }
  	ao();
}

void createArmDown(float speed) {
  	motor(armMotorB, speed);
motor(armMotorF, -speed);
  	while (!digital(touchPortF)) {
    }
  	ao();
}

void createFClawClose () { //BotGuy Claw Close
set_servo_position(FClawServo, FClawClose);
}

void createFClawOpen () { //BotGuy Claw Opens
set_servo_position(FClawServo, FClawOpen);
}

void createBClawOpen () { //BotGuy Claw Opens
set_servo_position(BClawServo, BClawOpen);
}

void createBClawClose () { //BotGuy Claw Opens
set_servo_position(BClawServo, BClawClose);
}
