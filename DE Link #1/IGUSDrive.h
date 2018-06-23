#define RIGHT_PORT 0
#define LEFT_PORT 1
#define ARM_PORT 0
#define CARDBOARD_PORT 1

#define ARM_DOWN 292
#define ARM_OUT 1900
#define CARDBOARD_LOW 470
#define CARDBOARD_MID 250
#define CARDBOARD_HI 160
#define CARDBOARD_START 1850

#define LINK_LEFT_OFFSET 1
#define LINK_RIGHT_OFFSET 0.84
#define LINK_DRIVE_OFFSET 1

#define PI 3.14159265

#define WHEEL_DIAMETER 2.2
#define TICKS_PER_ROTATION 1100.0
#define CM_TO_TICKS TICKS_PER_ROTATION / (PI*WHEEL_DIAMETER)

void StartUp();
void LinkThrowArm();
void LinkDrive(float distance, float speed);
void LinkDriveBack(float distance, float speed);
void LinkSquareUp(int time, float speed);
void LinkDriveSlanted(float rightSpeed, float IGUSTime, float time);
void LinkDriveSlantedNoThrow(float rightSpeed, float time);
void LinkTurnRightTime(float speen, float time);
void LinkTurnLeftTime(float speen, float time);
void CardboardLow();
void CardboardMid();
void CardboardHi();
