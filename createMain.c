#include "createDrive.h"
#include <kipr/botball.h>

void Calibrate(int* blackValue, int* whiteValue, int *blueValue) {
  int cont = 1;

  printf("please calibrate black using the left color sensor\n");
  while (cont == 1) {
    while (a_button() != 1) {
      printf("current black value seen is %d\n", analog(leftSensorPort));
    }
    if(analog(leftSensorPort) > 2500) {
      cont = 0;
    }
    else {
      printf("please recalibrate black\n");
    }
  }
  *blackValue = analog(leftSensorPort);

  cont = 1;

  msleep(1000);
  
  printf("please calibrate blue using the left color sensor\n");
  while (cont == 1) {
    while (a_button() != 1) {
      printf("current blue value seen is %d\n", analog(leftSensorPort));
    }
    if(analog(leftSensorPort) > 900 && analog(leftSensorPort) < 1200) {
      cont = 0;
    }
    else {
      printf("please recalibrate blue\n");
    }
  }
  *blueValue = analog(leftSensorPort);
  
  msleep(1000);
  
  cont = 1;
  
  printf("please calibrate white using the left color sensor\n");
  while (cont == 1) {
    while (a_button() != 1) {
      printf("current white value seen is %d\n", analog(leftSensorPort));
    }
    if(analog(leftSensorPort) < 525) {
      cont = 0;
    }
    else {
      printf("please recalibrate white\n");
    }
  }
  *whiteValue = analog(leftSensorPort);
}

void PickUpStartTribble() {
  set_servo_position(clawMoverPort, clawDownPos);
  msleep(200);
  set_servo_position(clawPort, 1300);
  msleep(200);
  CreateDrive(createDriveSpeed, 28);
  set_servo_position(clawPort, clawClosePos-110);
  msleep(200);
  clawCarry();
  msleep(200);
}

void PickUpFirstPile(int blackValue, int whiteValue) {
  lineFollowDistance(blackValue, whiteValue, 300, 42);
  clawOpen();
  msleep(200);
  clawDown();
  //lineFollow(blackValue, whiteValue, 1.4, 300);
  lineFollowDistance(blackValue, whiteValue, 300, 38);
  clawCloseSlow(clawClosePos);
  clawOpen();
  //clawCloseSlow(clawClosePos);
  //clawOpen();

  clawCloseSlow(clawClosePos);
  clawUp();
  lineFollowDistance(blackValue, whiteValue, 300, 40);
  CreateTurnRight(250, 89);
  CreateSquareUp(createDriveSpeed, 700);
}

void GrabBin(int blackValue, int whiteValue) {
  CreateDrive(createDriveSpeed,8);
  CreateTurnRight(75, 82);
  //CreateDrive(150, 10);
  LowerBin();
  //CreateDriveBack(createDriveSpeed, 14);
  CreateWobbleBackTill (100, 150);
  msleep(200);
  CreateDrive(100, 3);
  msleep(200);
  RaiseBin();
  msleep(200);
  CreateDrive(createDriveSpeed, 12);
  CreateTurnRight(200, 29);
}

void DumpPile() {
  //clawCarry();
  clawUp();
  msleep(800);
  clawOpen();
  msleep(500);
  clawClose();
  //clawOpen();
  //clawClose();
  //clawOpen();
  //clawClose();
  //clawSquareUp();
  msleep(300);
}

int PickUpSecondPile(int blackValue, int whiteValue, int blueValue) {
  //clawDown();
  //CreateWobbleBack (100, 100, 4);
  //clawSquareUp();
  int greenSeen = 0;
  // Robot sitting squared up after picking up bin now

  // Pickup 2nd pile of poms
  CreateDrive(createDriveSpeed, 9);
  CreateTurnLeft(100, 99);
  //  CreateDriveBack(100, 2);
  set_servo_position(clawPort, clawOpenPos-100);
  msleep(200);
  clawDown();
  CreateTurnRight(100, 3);

  CreateDrive(createDriveSpeed, 15);
  clawCloseSlow(clawClosePos);
  CreateDrive(createDriveSpeed, 10);
  clawOpen();
  if (FindColor() == 1) {
    LineTribbles();
    greenSeen = 1;
  }
  else {
    clawClose();
  }
  //CreateDriveBack(100, 10);
  clawSquareUp();
  //CreateLineSquareUp(200, blueValue, whiteValue, 500, 1.5);
  CreateDriveBack(createDriveSpeed, 16);
  CreateTurnRight(200, 94);
  CreateSquareUp(200, 800);
  CreateDrive(createDriveSpeed, 20);
  DumpPile();
  clawDownSlow(clawSquareUpPos);
  CreateDriveBack(200,  17);
  CreateSquareUp(100, 1500);
  return greenSeen;
}

void PrepareToPickUpSecondPile() {
  CreateDriveBack(createDriveSpeed, 25);
  CreateTurnLeft(100, 5);
  CreateSquareUp(150, 1600);
}

int PickUpThirdPile(int greenSeen) {
  clawOpen();
  msleep(600);
  clawDownSlow(clawDownPos);
  CreateDrive(createDriveSpeed, 25);
  clawCloseSlow(clawClosePos);
  clawOpen();
  if(greenSeen != 1 && FindColor() == 1) {
    greenSeen = 1;
    clawCloseSlow(clawClosePos);
    CreateDriveBack(createDriveSpeed, 10);
    CreateTurnLeft(200, 100);
    LineTribbles();
    CreateDrive(100, 3);
    CreateTurnRight(200, 93);
    CreateDrive(createDriveSpeed, 5);
  }
  else {
    clawCloseSlow(clawClosePos);
    clawOpen();
    clawCloseSlow(clawClosePos);
  }
  return greenSeen;
}

void PickUpFourthPile(int greenSeen) {
  CreateDrive(createDriveSpeed, 20.5);
  clawOpen();
  msleep(200);
  clawDownSlow(clawDownPos);
  CreateDrive(createDriveSpeed, 13);

  if(greenSeen != 1) {
    clawCloseSlow(clawClosePos);
    CreateDriveBack(createDriveSpeed, 10);
    LineTribbles();
    CreateTurnLeft(100, 4);
    CreateDrive(createDriveSpeed, 10);
  }
  else {
    clawCloseSlow(clawClosePos);
    clawOpen();
    clawCloseSlow(clawClosePos);
  }
}

void GrabComposter(int blackValue, int whiteValue, int blueValue) {
  set_servo_position(clawMoverPort, clawSquareUpPos-150);
  msleep(200);
  CreateDrive(createDriveSpeed, 31);
  CreateTurnLeft(100, 27);
  CreateDrive(createDriveSpeed, 35);
  clawOpen();
  CreateDrive(createDriveSpeed, 25);
  CreateTurnRight(100, 17.5);
  CreateDrive(createDriveSpeed, 14);
  //CreateLineSquareUp(50, blackValue, whiteValue);
  //msleep(2000);
  //CreateDrive(100, 5);
  clawCloseSlow(clawClosePos+100);
  msleep(200);
  clawUp();
  msleep(200);
  clawOpen();
  msleep(300);
  CreateDrive(createDriveSpeed, 25);
  CreateTurnLeft(100, 90);
  CreateSquareUp(100, 2000);
  LowerBinSlow();
}

void BackToBase() {
	clawUp();
  	CreateTurnRight(100, 8);
    CreateDrive(400, 55);
    CreateTurnRight(200, 195);
    CreateDriveBack(400, 20);
    LowerBinSlow();
}

int main() {
  int greenSeen = 0;

  printf("starting up\n");
  StartUp();
  printf("started up\n");
  //clawClose();
  //clawCarry();
  //CreateDrive(300, 80);
  
  //CreateDrive(300, 60);
  
  int blackValue;
  int whiteValue;
  int blueValue;
  clawCarry();
  
  //CreateDrive(createDriveSpeed, 150);
  
 // LineTribbles();
  
  Calibrate(&blackValue, &whiteValue, &blueValue);
  
  //CreateLineSquareUp(100, blackValue, whiteValue);

  msleep(3000);
  printf("starting\n");
  shut_down_in(119);

  PickUpStartTribble();

  PickUpFirstPile(blackValue, whiteValue);

  GrabBin(blackValue, whiteValue);

  DumpPile();
  clawSquareUp();
  
  PrepareToPickUpSecondPile();

  greenSeen = PickUpSecondPile(blackValue, whiteValue, blueValue);

  greenSeen = PickUpThirdPile(greenSeen);

  DumpPile();

  PickUpFourthPile(greenSeen);

  DumpPile();

  //GrabComposter(blackValue, whiteValue, blueValue);
  
  BackToBase();

  msleep(1000);
  
  //CreateLineSquareUp(100, blackValue, whiteValue, 1000, 1.5); for black

  ao();
  camera_close();
  return 0;
}
