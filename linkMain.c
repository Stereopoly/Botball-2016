#include <kipr/botball.h>
#include "drive.h"

void hopPipes() {
  linkSquareUp(700, 1500);
  hop();
  //linkSquareUp(900, 1500);
  //linkSquareUp(500, -1500);

  linkSquareUp(1900, 1500);
  hop();
  set_servo_position(0, 490);
  msleep(200);
}

void flipBin() {
  mav(0, 1300);   // speeds needed to drive straight
  mav(1, 1500);   // speeds needed to drive straight
  msleep(4000);
  mav(0, 1400);  //drive a bit tilted to not hit the pipe
  mav(1, 1500);
  /*mav(0, 1000);
  mav(1, 0);
  msleep(200);
  mav(0, 1450);
  mav(1, 1500);
  msleep(2700);
  mav(0, -1450);
  msleep(450);
  mav(0, 1450);*/
  set_servo_position(0,940);
  msleep(1500);
  set_servo_position(0,490);
  msleep(1600);
}

int main() {
  startUp();
  set_servo_position(0,490);
  msleep(300);
  hopPipes();
  flipBin();

  //linkSquareUp(900, 1500);
  //linkSquareUp(500, -1500);

  
  linkDriveBack(12, 1500);
  linkDriveToOpponentBase();
  ao();
  return 0;
}
