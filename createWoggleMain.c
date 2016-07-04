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

  /*printf("please calibrate blue using the left color sensor\n");
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

  cont = 1;*/

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
  set_servo_position(clawPort, 650);
  msleep(200);
  CreateDrive(createDriveSpeed, 35);
  set_servo_position(clawPort, clawClosePos+110);
  msleep(200);
  clawCarry();
  msleep(200);
}

void PickUpFirstPile(int blackValue, int whiteValue) {
  lineFollowDistance(blackValue, whiteValue, 300, 42);
  clawOpen();
  msleep(200);
  clawDownSlow(clawDownPos);
  //lineFollow(blackValue, whiteValue, 1.4, 300);
  lineFollowDistance(blackValue, whiteValue, 300, 38);
  clawCloseSlow(clawClosePos);
  clawOpenSlow(1300);
  //clawCloseSlow(clawClosePos);
  //clawOpen();
  lineFollowDistance(blackValue, whiteValue, 100, 3);
  clawCloseSlow(clawClosePos);
  clawUp();
  lineFollowDistance(blackValue, whiteValue, 300, 37);
  CreateTurnRight(250, 89);
  CreateSquareUp(createDriveSpeed, 700);
}

void GrabBin(int blackValue, int whiteValue) {
  /*CreateTurnRightConst(40, 80);
  CreateDrive(150, 10);
  LowerBin();
  CreateDriveBack(150, 8);
  CreateWobbleBackTill (100, 150);
  msleep(200);*/
  //CreateDrive(100,6);
  CreateDrive(100, 4);
  //CreateTurnRightConst(40, 88);
  CreateTurnRightConst(40, 91);
  //CreateDrive(createDriveSpeed, 10);
  LowerBin();
  CreateDriveBackET(60);
  Wibble (60, 150, 2);

  //CreateDrive(createDriveSpeed, 10);
  //CreateDriveBack(createDriveSpeed, 12);
  //CreateDriveBack(createDriveSpeed, 14);
  //CreateTurnLeftConst(40, 5);
  //CreateWobbleBackTill (80, 150, 5);
  msleep(200);

  //CreateDrive(100, 3);
  msleep(200);
  RaiseBin();
  msleep(200);
  CreateDrive(createDriveSpeed, 15);
  CreateTurnRight(200, 17);
}

void DumpPile() {
  //clawCarry();
  clawUp();
  msleep(1500);
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
  CreateTurnLeft(100, 91);
  //  CreateDriveBack(100, 2);
  set_servo_position(clawPort, clawOpenPos+100);
  msleep(200);
  clawDownSlow(clawDownPos);
  //CreateTurnRight(100, 5);

  CreateDrive(createDriveSpeed, 15);
  clawCloseSlow(clawClosePos);
  CreateDrive(createDriveSpeed, 10);
  clawOpen();
  if (FindColor() == 1) {
    LineTribbles();
    greenSeen = 1;
  }
  else {
    clawCloseSlow(clawClosePos);
  }
  //CreateDriveBack(100, 10);
  clawSquareUp();
  //CreateLineSquareUp(200, blueValue, whiteValue, 500, 1.5);
  CreateDriveBack(createDriveSpeed, 15);
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
  CreateSquareUp(150, 1800);
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
    clawCarry();
    CreateDrive(100, 3);
    CreateTurnRight(200, 98);
    CreateDrive(createDriveSpeed, 5);
  }
  else {
    //clawCloseSlow(clawClosePos);.
    //clawOpen();
    clawCloseSlow(clawClosePos);
    //CreateTurnLeft(100, 2);
  }
  return greenSeen;
}

void PickUpFourthPile(int greenSeen) {
  CreateDrive(createDriveSpeed, 20.5);
  clawOpen();
  msleep(200);
  //CreateTurnRight(100, 2);
  clawDownSlow(clawDownPos);
  CreateDrive(createDriveSpeed, 13);
  CreateTurnLeft(100, 2);
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
  set_servo_position(clawMoverPort, clawSquareUpPos+150);
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
  CreateTurnLeft(100, 90);
  CreateSquareUp(100, 4000);
  CreateDrive(100, 5);
  CreateTurnLeft(100, 90);
  CreateDriveBack(400, 130);
  Wibble(100, 100, 5);
  msleep(300);
  LowerBinSlow();
}

int main() {
  int greenSeen = 0;

  printf("starting up\n");
  StartUp();
  printf("%d\n", get_create_battery_charge());
  //create_full();
  printf("started up\n");
  //clawClose();
  //clawCarry();
  //CreateDrive(300, 80);

  //CreateDrive(300, 60);

  int blackValue = 3000;
  int whiteValue = 300;
  int blueValue;
  clawOpen();

  //CreateDrive(createDriveSpeed, 150);

  // LineTribbles();

  //Calibrate(&blackValue, &whiteValue, &blueValue);

  //CreateLineSquareUp(100, blackValue, whiteValue);

  //wait_for_light(0);

  printf("starting\n");
  shut_down_in(119);
  msleep(5000);
  //lineFollowBackET(blackValue, whiteValue, 60);
  //clawCarry();
  set_servo_position(clawPort, 1650);
  msleep(300);
  //clawUp();
  //clawClose();
  PickUpStartTribble();

  PickUpFirstPile(blackValue, whiteValue);

  GrabBin(blackValue, whiteValue);

  DumpPile();

  clawDownSlow(clawCarryPos);

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
