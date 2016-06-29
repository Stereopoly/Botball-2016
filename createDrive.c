#include "createDrive.h"
#include <kipr/botball.h>

void StartUp() {
  create_connect();
  set_servo_position(clawMoverPort, clawDownPos);
  set_servo_position(clawPort, 1650);
  enable_servos();
  set_servo_position(clawMoverPort, clawDownPos);
  set_servo_position(clawPort, 1650);
  set_servo_position(binPort, grabBinPos);
  printf("opening camera\n");
  camera_open();
}

void CreateDrive (float speed, float distance) {
  set_create_distance(0);
  int distanceDriven = distance*10*createDriveOffset;
  int distToAlternate = 0;
  int leftSpeedAdjust = 1;
  int prevDist = 0;
  create_drive_direct(speed*createLeftOffset, speed*createRightOffset);
  while (get_create_distance() <= distanceDriven) {
    distToAlternate = get_create_distance() - prevDist;
    if (distToAlternate >= 10) {
      // Alternative speed
      leftSpeedAdjust ^= 1;
      distToAlternate = 0;
      prevDist = get_create_distance();
      create_drive_direct(speed*createLeftOffset + leftSpeedAdjust, speed*createRightOffset);
    }
  }
  create_stop();
}

void CreateDriveStraighter (float speed, float distance) {
  set_create_distance(0);
  create_drive_direct(speed*0.95, speed*1);
  while (get_create_distance() <= distance*10*createDriveOffset) {
  }
  create_stop();
}

void CreateDriveSlowDown (float startSpeed, float distance) { 
  distance *= 10;
  float prev_distance = distance;
  float remainingDistance = distance;
  float curr_speed = startSpeed;

  set_create_distance(0);
  create_drive_direct(startSpeed*createLeftOffset, startSpeed*createRightOffset);

  while (remainingDistance > 0) {
    remainingDistance = distance - get_create_distance();
    if (remainingDistance <= prev_distance/4) {
      prev_distance = remainingDistance;
      if (curr_speed >= 30) {
        if (curr_speed <= 70) {
          create_drive_direct(60*createLeftOffset, 60*createRightOffset);
        }
        else {
          printf("changing speed from %f to %f, remaining distance is now %f\n", curr_speed, curr_speed/2, remainingDistance);
          curr_speed = curr_speed/2;
          create_drive_direct(curr_speed*createLeftOffset, curr_speed*createRightOffset);
        }
      }
    }
  }

  create_stop();
}

void CreateDriveBack (float speed, float distance) {
  int distanceDriven = distance*10*createDriveOffset;
  int distToAlternate = 0;
  int leftSpeedAdjust = 1;
  int prevDist = distanceDriven;
  set_create_distance(distanceDriven);
  create_drive_direct(-speed*createLeftOffset, -speed*createRightOffset);
  while (get_create_distance() > 0) {
    distToAlternate = prevDist - get_create_distance();
    if (distToAlternate >= 10) {
      // Alternative speed
      leftSpeedAdjust ^= 1;
      distToAlternate = 0;
      prevDist = get_create_distance();
      create_drive_direct(-(speed*createLeftOffset + leftSpeedAdjust), -speed*createRightOffset);
    }
  }
  create_stop();
}

void CreateWobble (int wobbleSpeed, float wobbleTime, int wobbles) {
  int counter = 0;
  while (counter < wobbles) {
    create_drive_direct(0, wobbleSpeed);
    msleep(wobbleTime);
    create_drive_direct(wobbleSpeed, 0);
    msleep(wobbleTime);
    ++counter;
  }
  create_stop();
}

void CreateWobbleBack (int wobbleSpeed, float wobbleTime, int wobbles) {
  int counter = 0;
  while (counter < wobbles) {
    create_drive_direct(0, -wobbleSpeed);
    msleep(wobbleTime);
    create_drive_direct(-wobbleSpeed, 0);
    msleep(wobbleTime);
    ++counter;
  }
  create_stop();
}

void CreateWobbleBackTill (int wobbleSpeed, float wobbleTime) {
  while (!digital(touchPort)) {
    create_drive_direct(0, -wobbleSpeed);
    msleep(wobbleTime);
    create_drive_direct(-wobbleSpeed, 0);
    msleep(wobbleTime);
  }
  create_stop();
}

void CreateDriveUntilTouch (float speed) {
  create_drive_direct(speed*createLeftOffset, speed*createRightOffset);
  while (!get_create_rbump() && !get_create_lbump()) {
  }
  create_stop();
}

void CreateSquareUp(float speed, float time) {
  create_drive_direct(-speed*createLeftOffset, -speed*createRightOffset);
  msleep(time);
  create_stop();
}

void CreateDriveUntil (float speed, float time) {
  create_drive_direct(speed*createLeftOffset, speed*createRightOffset);
  msleep(time);
  create_stop();
}

/*int createDriveUntilColor(float speed) {
  create_drive_direct(speed*createLeftOffset, speed*createRightOffset);
  camera_update();
  int cont = 1;
  int i = 0;
  while(cont == 1) {
    camera_update();
    if((get_object_count(red_channel) > 0 && get_object_center_y(red_channel, 0) < 110 && get_object_center_y(red_channel, 0) > 25) || 
       (get_object_count(green_channel) > 0 && get_object_center_y(green_channel, 0) < 110 && get_object_center_y(green_channel, 0) > 25)) {
     	while(i < 7) {
        camera_update();
        if(!(get_object_count(red_channel) > 0 || get_object_center_y(red_channel, 0) < 110 || get_object_center_y(red_channel, 0) > 25 || 
             get_object_count(green_channel) > 0 || get_object_center_y(green_channel, 0) < 110 || get_object_center_y(green_channel, 0) > 25)) {
          break;
        }
        if(i == 6) {
          cont = 0;
          break;
        }
        msleep(100);
        ++i;
      }
    }
  }
  if(get_object_count(red_channel) > 0 && get_object_center_y(red_channel, 0) < 110 && get_object_center_y(red_channel, 0) > 25) {
    return 0;
  }
  else {
    return 1;
  }
  ao();
}*/

void CreateTurnLeft(float speed, int degrees) {
  set_create_normalized_angle(0); //Reset the angle
  create_spin_CCW(speed); //Spin at half power
  while(get_create_normalized_angle() < (degrees - 20)*createTurnOffset) {} //go most of the distance
  create_spin_CCW(speed/5); //slow down as to not overshoot
  while(get_create_normalized_angle() < degrees) {} //and finish the turn
  create_stop();
}

void CreateTurnRight(float speed, int degrees) {
  set_create_normalized_angle(degrees*createTurnOffset); //Reset the angle
  create_spin_CW(speed); //Spin at half power
  while(get_create_normalized_angle() > 20) {} //go most of the distance
  create_spin_CW(speed/5); //slow down as to not overshoot
  while(get_create_normalized_angle() > 0) {} //and finish the turn
  create_stop();
}

void miniGrabberDown() {
  set_servo_position(miniMoverPort, miniDownPos);
  msleep(300);
}

void miniGrabberUp() {
  set_servo_position(miniMoverPort, miniUpPos);
  msleep(300);
}

void miniGrabberMid() {
  set_servo_position(miniMoverPort, miniMidPos);
  msleep(300);
}

void RaiseBin() {
  int curr_pos = releaseBinPos;
  while(curr_pos > grabBinPos) {
    if(curr_pos - 80 < grabBinPos) {
      curr_pos = grabBinPos;
    }
    else {
      curr_pos -= 80;
    }
    set_servo_position(binPort, curr_pos);
    printf("setting bin pos to %d\n", curr_pos);
    msleep(100);
  }
  msleep(300);
  printf("done raising\n");
}

void LowerBinSlow() {
  int curr_pos = grabBinPos;
  while(curr_pos < releaseBinPos) {
    if(curr_pos + 80 > releaseBinPos) {
      curr_pos = releaseBinPos;
    }
    else {
      curr_pos += 80;
    }
    set_servo_position(binPort, curr_pos);
    printf("setting bin pos to %d\n", curr_pos);
    msleep(100);
  }
  msleep(300);
  printf("done raising\n");
}

void clawUpSlow() {
  int curr_pos = get_servo_position(clawMoverPort);
  while(curr_pos < clawUpPos) {
    if(curr_pos + 80 > clawUpPos) {
      curr_pos = clawUpPos;
    }
    else {
      curr_pos += 80;
    }
    set_servo_position(clawMoverPort, curr_pos);
    printf("setting bin pos to %d\n", curr_pos);
    msleep(100);
  }
  msleep(300);
  printf("done raising\n");
}

void clawDownSlow(int clawPos) {
  int curr_pos = get_servo_position(clawMoverPort);
  while(curr_pos > clawPos) {
    if(curr_pos - 80 < clawPos) {
      curr_pos = clawPos;
    }
    else {
      curr_pos -= 80;
    }
    set_servo_position(clawMoverPort, curr_pos);
    printf("setting bin pos to %d\n", curr_pos);
    msleep(100);
  }
  msleep(300);
  printf("done raising\n");
}

void LowerBin() {
  set_servo_position(binPort, releaseBinPos);
  msleep(300);
}

void clawDown() {
  set_servo_position(clawMoverPort, clawDownPos);
  msleep(300);
}

void clawUp() {
  set_servo_position(clawMoverPort, clawUpPos);
  msleep(300);
}

void clawCarry() {
  set_servo_position(clawMoverPort, clawCarryPos);
  msleep(300);
}

void clawSquareUp() {
  set_servo_position(clawMoverPort, clawSquareUpPos);
  msleep(300);
}

void clawOpen() {
  set_servo_position(clawPort, clawOpenPos);
  msleep(300);
}

void clawClose() {
  set_servo_position(clawPort, clawClosePos);
  msleep(300);
}

void clawCloseSlow(int closePos) {
  int curr_pos = clawOpenPos;
  while(curr_pos > closePos-100) {
    if(curr_pos - 110 < closePos-100) {
      curr_pos = closePos-100;
    }
    else {
      curr_pos -= 110;
    }
    set_servo_position(clawPort, curr_pos);
    printf("setting claw pos to %d\n", curr_pos);
    msleep(100);
  }
  msleep(300);
  printf("done closing\n");
}

void clawOpenSlow(int OpenPos) {
  int curr_pos = clawClosePos;
  while(curr_pos < OpenPos+100) {
    if(curr_pos + 110 > OpenPos+100) {
      curr_pos = OpenPos+100;
    }
    else {
      curr_pos += 110;
    }
    set_servo_position(clawPort, curr_pos);
    printf("setting claw pos to %d\n", curr_pos);
    msleep(100);
  }
  msleep(300);
  printf("done closing\n");
}

void lineFollow(int blackValue, int whiteValue, float time, float speed) {
  int initial_seconds = seconds();
  float right_value;
  float left_value;
  float right_speed;
  float left_speed;
  float right_ratio;
  float left_ratio;
  float multiplier = 0.5;
  float diff;

  diff = blackValue - whiteValue;
  while(seconds() - initial_seconds < time) {
    right_value = analog(rightSensorPort);
    left_value = analog(leftSensorPort);

    right_ratio = ((right_value - whiteValue) / diff);
    if(right_ratio > 1) {
      right_ratio = 1;
    }
    right_speed = speed * (1 - right_ratio * multiplier);

    left_ratio = ((left_value-whiteValue)/diff);
    if(left_ratio > 1) {
      left_ratio = 1;
    }
    left_speed = speed*(1-left_ratio * multiplier);
    //printf("right ratio = %f, left ratio = %f", right_ratio, left_ratio);
    create_drive_direct(left_speed, right_speed);
    msleep(5);
  }

  create_stop();
}

void lineFollowDistance(int blackValue, int whiteValue, float speed, float distance) {
  float right_value;
  float left_value;
  float right_speed;
  float left_speed;
  float right_ratio;
  float left_ratio;
  float multiplier = 0.5;
  float diff;

  diff = blackValue - whiteValue;
  set_create_distance(0);
  while(get_create_distance() < distance*10*createDriveOffset) {
    right_value = analog(rightSensorPort);
    left_value = analog(leftSensorPort);

    right_ratio = ((right_value - whiteValue) / diff);
    if(right_ratio > 1) {
      right_ratio = 1;
    }
    right_speed = speed * (1 - right_ratio * multiplier);

    left_ratio = ((left_value-whiteValue)/diff);
    if(left_ratio > 1) {
      left_ratio = 1;
    }
    left_speed = speed*(1-left_ratio * multiplier);
    //printf("right ratio = %f, left ratio = %f", right_ratio, left_ratio);
    create_drive_direct(left_speed, right_speed);
    msleep(5);
  }

  create_stop();
}

int checkTribbles () {
  camera_update();
  if (get_object_count(greenChannel) > 0) {
    printf("green object seen \n");
    return 1;
  }
  else if (get_object_count(redChannel) > 0) {
    printf("red object seen \n");
    return 0;
  }
  return 2;
}

int FindColor() {
  int failed = 0;
  int counter = 0;
  while(1==1) {
    if(counter == 9) {
      if(failed <= 6) {
        printf("sees green\n");
        return 1;
      }
      else {
        printf("sees red\n");
        return 0;
      }
    }
    if (checkTribbles() != 1) {
      ++failed;
    }
    ++counter;
    msleep(50);
  }
}

void SetTribbles(ClawSpeed speed) {
  if (speed == SLOW) {
    clawCloseSlow(clawClosePos);
    clawOpen();
    clawCloseSlow(clawClosePos);
    clawOpen();
  }
  else if (speed == FAST) {
    clawClose();
    clawOpen();
    clawClose();
    clawOpen();
  }
  else if (speed == OPENSLOW) {
    clawCloseSlow(clawClosePos);
    clawOpenSlow(clawOpenPos);
    clawCloseSlow(clawClosePos);
    clawOpenSlow(clawOpenPos);
  }
}

void LineTribbles() {
  SetTribbles(FAST);
  CreateDriveBack(100, 3);
  CreateTurnRight(200, 6);
  SetTribbles(SLOW);
  CreateTurnLeft(200, 12);
  SetTribbles(SLOW);
  CreateTurnRight(200, 6);
  clawCloseSlow(clawClosePos+300);
  CreateDrive(100, 11);
  SetTribbles(OPENSLOW);
  CreateDriveBack(100, 11);
  clawCloseSlow(clawClosePos+50);
  //CreateDrive(100, 9);
}

void CreateLineSquareUp(int speed, int blackValue, int whiteValue, float strictness, float mult) {
  float rightSpeed;
  float leftSpeed;
  float rightRatio;
  float leftRatio;
  float rightVal = analog(rightSensorPort);
  float leftVal = analog(leftSensorPort);
  while (leftVal < blackValue - 300 || rightVal < blackValue - 300) {
    rightRatio = (rightVal-whiteValue+strictness)/(blackValue-whiteValue);
    leftRatio = (leftVal-whiteValue+strictness)/(blackValue-whiteValue);
    rightSpeed = speed*(1-rightRatio)*mult;
    leftSpeed = speed*(1-leftRatio)*mult;
    create_drive_direct(leftSpeed, rightSpeed);
    msleep(5);

    rightVal = analog(rightSensorPort);
    leftVal = analog(leftSensorPort);
  }
}
