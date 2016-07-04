#include "drive.h"
#include <kipr/botball.h>
void hop_pipes(){
  	linkDrive(2, 1600);
    hop();
  	msleep(1250);
  	linkDrive(7.5, 1600);
  	hop();
}
void flip_bins(){
    int i = 0;
    set_servo_position(ARM_PORT, 800);
 	mav(RIGHT_PORT, 1500);
    mav(LEFT_PORT, 1500);
    msleep(6500);
    while (i < 5){
      mav(RIGHT_PORT, 1500);
      mav(LEFT_PORT, -1500);
      msleep(500);
      mav(LEFT_PORT, 1500);
      mav(RIGHT_PORT, -1500);
      msleep(500);
      i++;
    }
  	set_servo_position(ARM_PORT, 200);
	msleep(250);
  	linkSquareUp(2500, 1500);
}
//Direction should be -1 or 1.
void spin(short direction, float rotations){
  	 int cw = 0;
  	 while (cw < rotations){
     	mav(0, direction*1500);
       	msleep(5000);
        cw++;
     }
}
int main(){
	startUp();
	hop_pipes();
  	flip_bins();
  	linkDriveBack(17.5, 1500);
  	SpinReady();
  	set_servo_position(ARM_PORT, 800);
 	while (1 == 1){
	  	spin(1, 1.15);
     	spin(-1, 1);
    }
 	return 0;
}
