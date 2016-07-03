#include "drive.h"
#include <kipr/botball.h>
        
int main () {
    printf("a button will run block mid\nb button will block the far entrance\n");
    while(a_button() == 0 && b_button() == 0) {
    }
    if(a_button() == 1) {
      printf("a button pressed, wallaby will run block mid\n");
      StartUp();
      blockMiddle();
    }
    else {
      printf("b button pressed, wallaby will run block the far entrance\n");
      StartUp();
      blockFarEntrance();
    }
  
  //	blockFarEntrance(); 6/6
  
  	
  
  	ao();
    return 0;
}

void blockFarEntrance() {
  
  	CardboardMid();
    set_servo_position(2, 800);
    msleep(200);
  	LinkDrive(2, 1600);
    set_servo_position(2, 1500);
    msleep(100);
    mav(LEFT_PORT, 1600*LINK_LEFT_OFFSET);
  	msleep(200);
    set_servo_position(2, 800);
    LinkDrive(3, 1600);
    set_servo_position(2, 1500);
    msleep(100);
    set_servo_position(2, 800);
    LinkDrive(3, 1600);
    set_servo_position(2, 1500);
    LinkDrive(18, 1600);
    CardboardMid();
    mav(RIGHT_PORT, 1600*LINK_RIGHT_OFFSET);
    mav(LEFT_PORT, -1600*LINK_LEFT_OFFSET);
  	msleep(200);
  
    LinkDrive(8,1600);
    
  	LinkThrowIgus();
  	msleep(1750);
    CardboardHi();
  //  mav(RIGHT_PORT, 1600*LINK_RIGHT_OFFSET);
 // 	msleep(70);
  
}

void blockMiddle() {
    CardboardMid();
    set_servo_position(2, 800);
    msleep(200);
  	LinkDrive(3, 1600);
    set_servo_position(2, 1500);
    msleep(100);
    set_servo_position(2, 800);
    LinkDrive(3, 1600);
    set_servo_position(2, 1500);
    msleep(100);
    set_servo_position(2, 800);
    LinkDrive(3, 1600);
    set_servo_position(2, 1500);
    LinkDrive(10, 1600);
    CardboardLow();
  //  LinkDrive(9, 1600);
  	/*
    LinkDriveSlanted(870, 1200, 3500);
    LinkSquareUp(1500, 2500);
  	LinkDriveSlanted(870, 2000, 3500);
    LinkSquareUp(1500, 2500);
    */

  	mav(LEFT_PORT, 1000*LINK_LEFT_OFFSET);
    mav(RIGHT_PORT, -1000*LINK_LEFT_OFFSET);
  	msleep(250);
  
    LinkDrive(17, 1600);
  
  //  mav(LEFT_PORT, 1000*LINK_LEFT_OFFSET);
  //  msleep(30);
  
 // 	mav(RIGHT_PORT, 0);
 //   mav(LEFT_PORT, 0);
 //   msleep(150);
    
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
