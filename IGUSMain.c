#include "drive.h"
#include <kipr/botball.h>
        
int main () {
  	StartUp();
  
  //	blockFarEntrance(); 6/6
  
  	blockMiddle();
  
  	ao();
    return 0;
}

void blockFarEntrance() {
  
  	CardboardLow();
   	mav(LEFT_PORT, 1000*LINK_RIGHT_OFFSET);
	msleep(100);
  	LinkDrive(29, 1600);
    CardboardMid();
  	mav(RIGHT_PORT, 1000*LINK_RIGHT_OFFSET);
  	msleep(25);
    LinkDrive(4,1600);
    mav(RIGHT_PORT, 1000*LINK_RIGHT_OFFSET);
  	msleep(5);
  	LinkThrowIgus();
  	msleep(1750);
    CardboardHi();
  //  mav(RIGHT_PORT, 1600*LINK_RIGHT_OFFSET);
  //	msleep(70);
  	LinkDrive(2, 1600);
}

void blockMiddle() {
    CardboardMid();
  	LinkDrive(30, 1600);
  	/*
    LinkDriveSlanted(870, 1200, 3500);
    LinkSquareUp(1500, 2500);
  	LinkDriveSlanted(870, 2000, 3500);
    LinkSquareUp(1500, 2500);
    */

  	mav(LEFT_PORT, 1000*LINK_RIGHT_OFFSET);
  	msleep(10);
  
    LinkThrowIgus();
  	
  	msleep(2000); //Waits for one second
    /*
  	LinkSquareUp(1500, 1000);
  	LinkThrowArm();
  	LinkSquareUp(1500, 1500);
  	*/
  
  	/*
    LinkDrive(20, 1500);
  	LinkTurnRightTime(1500, 500);
  	LinkSquareUp(3000, 1500);
 	LinkThrowArm();	
    */
}
