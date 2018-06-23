#define ARM_PORT 0
#define ARM_UP 490
#define ARM_DOWN 2020
#define LEFT_PORT 1
#define RIGHT_PORT 0
#define PI 3.14159265
#define WHEEL_DIAMETER 2.2
#define TICKS_PER_ROTATION 1100.0
#define CM_TO_TICKS TICKS_PER_ROTATION / (PI*WHEEL_DIAMETER)
#define LINK_LEFT_OFFSET 0.90
#define LINK_RIGHT_OFFSET 0.91
#define LINK_DRIVE_OFFSET 1

void startUp ();
void linkDrive (float distance, float speed);
void linkDriveBack (float distance, float speed);
void linkSquareUp (int time, float speed);
void linkSquareUpBack(int time, float speed);
void hop();
void SpinReady();
void spin(short direction, float rotations);
