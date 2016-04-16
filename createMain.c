#include "createDrive.h"
#include <kipr/botball.h>

void sweep() {
	createFClawOpen();
  	createFClawClose();
  	createFClawOpen();
  	createFClawClose();
  	createTurnLeft(200, 10);
  	createTurnRight(200, 10);
  	createTurnLeft(200, 10);
  	createTurnRight(200, 10);
  	createTurnLeft(200, 10);
  	createTurnRight(200, 10);
  	createFClawOpen();
  	createFClawClose();
}
  
void start() {
  	createConnectAll();
  	createArmStay(3);
    wait_for_light(5);
    msleep(5);
    shut_down_in(119);
}

void grabBotGuy() {
  	createDrive(300, 66);      // increased here to decrease chance of missing botguy
  	createTurnRight(200, 90);
  	createSquareUp(200, 1000);
  	createDriveUntilTouch(250);
  	createDriveBack(200, 5);
  	createTurnLeft(200, 30);
  	createDrive(300, 0.5);
  	createFClawOpen();
  	msleep(1000);
  	createArmDownOffset(75, 0.9, 1);
  	createArmStay(3);
  	createFClawClose();
  	msleep(1000);
  	createArmUpOffset(75, 0.8, 1);
 	createArmStay(16);
}

void grabCube() {
  	createDriveBack(300, 9);
  	createTurnRight(200, 145);
  	createDrive(200, 34);      // increased here to adjust for botguy
  	createTurnRight(200, 82);
  	createSquareUp(200, 1500);
  	grabPipe();
  	createBClawOpen();
  	msleep(700);
    createArmUpOffset(75, 0.8, 1);
  	createArmStay(70);
  	//msleep(700);
  	createBClawClose();
  	msleep(1500);
  	createArmDownOffsetTime(75, 630, 0.8, 1);
  	createArmStay(16);
}

void setCubeDown() {
  	createDrive(200, 10);
  	createTurnRight(200, 90);
  	createDriveBack(80, 8);
  	releasePipe();
  	createDrive(200, 20);
  	createTurnRight(200, 105);
  	createDriveBack(200, 25);
  	//createSquareUp(100, 2222);
  	//createDrive(200, 8);
  	//createTurnLeft(200, 90);
  	//createDrive(200, 38);
  	//createTurnRight(200, 90);
  	createArmUpOffsetTime(75, 500, 0.9, 1);
  	createBClawOpen();
 	msleep(700);
  	createArmUpOffset(75, 0.9, 1); //dropped off
  	createArmStay(16);
  	pipeUp();
}

void setBotGuyDown() {
  	createTurnLeft(200, 145);
  	createDrive(200, 45);
  	createTurnRight(200, 82);
  	createDrive(200, 46);
  	releasePipe();
  	/*createTurnRight(200, 90);
  	createDrive(200, 80);
  	createFClawOpen();
  	createTurnLeft(200, 150);
  	createDrive(200, 20);
  	createTurnRight(200, 270);
  	createDrive(200, 230);*/

  	createArmUpOffset(75, 0.9, 1);
  	createArmStay(16);
    createDrive(200, 22);
    createTurnLeft(200, 5);
    //createTurnLeft(150, 25);
 	//createDrive(200, 8);
  	//createTurnRight(60, 5);
  	createFClawOpen();
 	msleep(500);
    createDrive(400, 5);
    createDriveBack(400, 5);
  	createDriveBack(200, 62);
 //	createTurnLeft(200, 3);
}

void knockOffPINGPONGBALLS(){
  	createTurnLeft(200, 25);
    createDrive(200, 6);
  
  	createFClawOpen();
    createTurnRight(400, 2);
    createFClawClose();
    createTurnLeft(400, 2);
    createFClawOpen();
    createTurnRight(400, 2);
    createFClawClose();
    createTurnLeft(400, 2);
    createFClawOpen();
    createTurnRight(400, 2);
    createFClawClose();
    createTurnLeft(400, 2);
    createFClawOpen();
    createTurnRight(400, 2);
    createFClawClose();
    createTurnLeft(400, 2);
    createFClawClose();
    createTurnRight(400, 2);
  
    createDriveBack(200, 15);
    createTurnRight(200, 40);
    createDriveBack(200, 35);
    createTurnLeft(200, 75);
    createDrive(200, 8);  
    
    createArmUpOffsetTime(75, 0.1, 0.9, 1);
    
    createFClawOpen();
    createTurnRight(400, 2);
    createFClawClose();
    createTurnLeft(400, 2);
    createFClawOpen();
    createTurnRight(400, 2);
    createFClawClose();
    createTurnLeft(400, 2);
    createFClawOpen();
    createTurnRight(400, 2);
    createFClawClose();
    createTurnLeft(400, 2);
    createFClawOpen();
    createTurnRight(400, 2);
    createFClawClose();
    createTurnLeft(400, 2);
    createFClawClose();
    createTurnRight(400, 2);
  
  	createFClawClose();    
}

int main() {
    start();
  	grabBotGuy();
  	grabCube();
    setCubeDown();
  	setBotGuyDown();
  	knockOffPINGPONGBALLS();
    ao();
  	return 0;
}
