#include "createDrive.h"
#include <kipr/botball.h>

void Calibrate(int* blackValue, int* whiteValue) {
  int cont = 1;
  clawClose();
  set_servo_position(clawMoverPort, clawCarryPos+200);
  msleep(300);

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
  clawOpen();
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
}

void GrabBin(int blackValue, int whiteValue) {
  clawUp();
  lineFollowDistance(blackValue, whiteValue, 300, 30);
  CreateTurnRight(250, 89);
  CreateSquareUp(createDriveSpeed, 700);
  CreateDrive(createDriveSpeed,5);
  CreateTurnRight(150, 90);
  //CreateDrive(150, 10);
  LowerBin();
  CreateDriveBack(createDriveSpeed, 14);
  CreateWobbleBackTill (100, 100);
  msleep(200);
  RaiseBin();
  msleep(200);
  CreateDrive(createDriveSpeed, 15);
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
  clawSquareUp();
  msleep(300);
}

int PickUpSecondPile() {
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
  CreateDriveBack(createDriveSpeed, 12);
  CreateTurnRight(200, 94);
  CreateSquareUp(200, 800);
  CreateDrive(createDriveSpeed, 18);
  DumpPile();
  CreateSquareUp(100, 3000);
  return greenSeen;
}

void PrepareToPickUpSecondPile() {
  CreateDriveBack(createDriveSpeed, 15);
  CreateSquareUp(150, 3000);
}

int PickUpThirdPile(int greenSeen) {
  clawOpen();
  msleep(200);
  clawDown();
  CreateDrive(createDriveSpeed, 25);
  clawCloseSlow(clawClosePos);
  clawOpen();
  if(greenSeen != 1 && FindColor() == 1) {
    greenSeen = 1;
    clawCloseSlow(clawClosePos);
    CreateDriveBack(createDriveSpeed, 10);
    CreateTurnLeft(200, 100);
    LineTribbles();
    CreateTurnRight(200, 92);
    CreateDrive(createDriveSpeed, 5);
  }
  else {
    clawCloseSlow(clawClosePos);
    clawOpen();
    clawCloseSlow(clawClosePos);
  }
  //CreateDrive(100, 22);
  return greenSeen;
}

void PickUpFourthPile(int greenSeen) {
  CreateDrive(createDriveSpeed, 24);
  clawOpen();
  msleep(200);
  clawDown();
  CreateDrive(createDriveSpeed, 13);

  if(greenSeen != 1) {
    clawClose();
    CreateDriveBack(createDriveSpeed, 10);
    LineTribbles();
    CreateTurnRight(100, 4);
    CreateDrive(createDriveSpeed, 10);
  }
  else {
    clawCloseSlow(clawClosePos);
    clawOpen();
    clawCloseSlow(clawClosePos);
  }
}

void GrabComposter(int blackValue, int whiteValue) {
  CreateDrive(createDriveSpeed, 29);
  CreateTurnLeft(100, 27);
  CreateDrive(createDriveSpeed, 37);
  clawOpen();
  CreateDrive(createDriveSpeed, 29);
  CreateTurnRight(100, 14);
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
  LowerBin();
}

int main() {
  int greenSeen = 0;

  printf("starting up\n");
  StartUp();
  printf("started up\n");
  //clawClose();
  //clawCarry();
  //CreateDrive(300, 80);
  
  clawClose();
  clawUp();
  //CreateDrive(300, 60);
  
  int blackValue;
  int whiteValue;
  
  //CreateDrive(createDriveSpeed, 150);
  
 // LineTribbles();
  
  Calibrate(&blackValue, &whiteValue);

  msleep(3000);
  printf("starting\n");
  shut_down_in(119);

  PickUpStartTribble();

  PickUpFirstPile(blackValue, whiteValue);

  GrabBin(blackValue, whiteValue);

  DumpPile();
  
  PrepareToPickUpSecondPile();

  greenSeen = PickUpSecondPile(greenSeen);

  greenSeen = PickUpThirdPile(greenSeen);

  DumpPile();

  PickUpFourthPile(greenSeen);

  DumpPile();

  GrabComposter(blackValue, whiteValue);

  msleep(1000);

  ao();
  camera_close();
  return 0;
}
