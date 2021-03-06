#include "createDrive.h"
#include <kipr/botball.h>

void Calibrate(int* blackValue, int* whiteValue, int *blueValue) {
  int cont = 1;

  printf("please calibrate black using the left color sensor\n");
  //while (cont == 1) {
    while (a_button() != 1) {
      printf("current black value seen is %d\n", analog(leftSensorPort));
    }
    /*if(analog(leftSensorPort) > 2500) {
      cont = 0;
    }
    else {
      printf("please recalibrate black\n");
    }*/
  //}
  *blackValue = analog(leftSensorPort);

  cont = 1;

  msleep(1000);

  printf("please calibrate white using the left color sensor\n");
  //while (cont == 1) {
    while (a_button() != 1) {
      printf("current white value seen is %d\n", analog(leftSensorPort));
    }
    
  *whiteValue = analog(leftSensorPort);
}

void PickUpStartTribble() {
  set_servo_position(clawMoverPort, clawDownPos);
  msleep(200);
  set_servo_position(clawPort, 600);
  msleep(200);
  CreateDrive(createDriveSpeed, 40);
  set_servo_position(clawPort, clawClosePos+110);
  msleep(200);
  clawCarry();
  msleep(200);
}

void PickUpFirstPile(int blackValue, int whiteValue) {
  lineFollowDistance(blackValue, whiteValue, 300, 42);
  clawDownSlow(clawDownPos);
  clawOpenSlow(clawOpenPos-25);
  //lineFollow(blackValue, whiteValue, 1.4, 300);
  lineFollowDistance(blackValue, whiteValue, 300, 38);
  clawCloseSlow(clawClosePos);
  clawOpenSlow(clawOpenPos+50);
  //clawCloseSlow(clawClosePos);
  //clawOpen();
  lineFollowDistance(blackValue, whiteValue, 100, 18);
  clawCloseSlow(clawClosePos+100);
  clawUp();
  lineFollowDistance(blackValue, whiteValue, 300, 22);
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
  TurnRightBlackWhite(40, blackValue, whiteValue);
  CreateTurnLeftConst(30, 1);
  //CreateTurnRightConst(40, 92);
  CreateDrive(createDriveSpeed, 4);
  LowerBin();
  if(CreateDriveBackET(60, 6.5) == 1) {
    CreateDrive(100, 2);
  }
  //CreateDrive(60, 2);
  Wibble (80, 150, 4);
  Wibble (80, 100, 3);

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
  CreateTurnRight(200, 18);
}

void DumpPile() {
  //clawCarry();
  clawUp();
  msleep(700);
  set_servo_position(clawPort, clawClosePos-550);
  //clawOpen();
  //clawClose();
  //clawOpen();
  //clawClose();
  //clawSquareUp();
  msleep(800);
}

int PickUpSecondPile(int blackValue, int whiteValue, int blueValue) {
  //clawDown();
  //CreateWobbleBack (100, 100, 4);
  //clawSquareUp();
  int greenSeen = 0;
  // Robot sitting squared up after picking up bin now

  // Pickup 2nd pile of poms
  CreateDrive(createDriveSpeed, 9);
  CreateTurnLeft(100, 105);
  //CreateTurnLeft(100, 91);
  //  CreateDriveBack(100, 2);
  set_servo_position(clawPort, clawOpenPos);
  msleep(200);
  clawDownSlow(clawDownPos);
  //CreateTurnRight(100, 5);

  CreateDrive(createDriveSpeed, 20);
  clawCloseSlow(clawClosePos);
  clawOpenSlow(clawOpenPos+150);
  CreateDrive(createDriveSpeed, 5);
  if (FindColor() == 1) {
    clawCloseSlow(clawClosePos);
    LineTribbles();
    greenSeen = 1;
    CreateDriveBack(createDriveSpeed, 12);
  }
  else {
    clawCloseSlow(clawClosePos);
    CreateDriveBack(createDriveSpeed, 15);
  }
  //CreateDriveBack(100, 10);
  clawSquareUp();
  //CreateLineSquareUp(200, blueValue, whiteValue, 500, 1.5);
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
  CreateTurnLeft(150, 98);
  CreateSquareUp(100, 1200);
  CreateDrive(100, 9);
  CreateTurnRight(100, 103);
  CreateDriveBack(createDriveSpeed, 34);
  CreateTurnLeft(95, 5);
  CreateSquareUp(150, 1500);
}

int PickUpThirdPile(int greenSeen) {
  clawOpen();
  msleep(600);
  clawDownSlow(clawDownPos);
  printf("might work\n");
  CreateDrive(createDriveSpeed, 25);
  clawCloseSlow(clawClosePos);
  clawOpen();
  if(greenSeen != 1 && FindColor() == 1) {
    greenSeen = 1;
    clawCloseSlow(clawClosePos);
    printf("done closing claw\n");
    CreateDriveBack(createDriveSpeed, 10);
    CreateTurnLeft(200, 100);
    LineTribbles();
    clawCarry();
    CreateDrive(100, 3);
    CreateTurnRight(200, 91);
    CreateDrive(createDriveSpeed, 5);
  }
  else {
    //clawCloseSlow(clawClosePos);.
    //clawOpen();
    clawCloseSlow(clawClosePos);
    //CreateTurnLeft(100, 2);
  }
  printf("we out\n");
  CreateTurnLeft(100, 1);
  printf("we out as well\n");
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
    CreateDrive(100, 3);
    clawCloseSlow(clawClosePos+100);
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

void BackToBase(float init_time) {
  clawUp();
  CreateTurnLeft(200, 89);
  CreateDriveBack(300, 15);
  CreateSquareUp(150, 1500);
  CreateDrive(100, 10);
  CreateTurnLeft(200, 96);
  CreateDriveBack(400, 12);
  set_servo_position(clawPort, get_servo_position(clawPort) + 150);
  CreateDriveBack(400, 10);
  set_servo_position(clawPort, get_servo_position(clawPort) - 150);
  CreateDriveBack(400, 10);
  set_servo_position(clawPort, get_servo_position(clawPort) + 150);
  CreateDriveBack(400, 10);
  set_servo_position(clawPort, get_servo_position(clawPort) - 150);
  CreateDriveBack(400, 50);
  if(seconds() - init_time <= 118) {
    Wibble(50, 140, 5);
    msleep(300);
  }
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

  //CreateDrive(createDriveSpeed, 150);

  // LineTribbles();

  //Calibrate(&blackValue, &whiteValue, &blueValue);

  //CreateLineSquareUp(100, blackValue, whiteValue);

  wait_for_light(0);

  printf("starting\n");
  shut_down_in(119);
  int init_time = seconds();
  set_servo_position(binPort, releaseBinPos);
  msleep(1000);
  set_servo_position(binPort, grabBinPos);
  msleep(1000);
  create_drive_direct(0, -100);
  msleep(150);
  CreateSquareUp(createDriveSpeed, 700);
  msleep(1200);
  //lineFollowBackET(blackValue, whiteValue, 60);
  //clawCarry();
  set_servo_position(clawPort, 650);
  msleep(300);
  //clawUp();
  //CreateDriveBackET(80, 5.5);
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

  BackToBase(init_time);

  msleep(1000);

  //CreateLineSquareUp(100, blackValue, whiteValue, 1000, 1.5); for black

  ao();
  camera_close();

  return 0;
}
