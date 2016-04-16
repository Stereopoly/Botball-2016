//#define createRightOffset 1 //when lower, create goes left
//#define createLeftOffset 0.725 //when lower, create goes right
#define createLeftOffset 1 //when lower, create goes left
#define createRightOffset 0.98669 //when lower, create goes right   0.9867 - old
#define createDriveOffset 1
#define armMotorF 0
#define armMotorB 1
#define FArmOffset 1
#define BArmOffset 0.88
#define createTurnOffset 0.987
//#define createTurnOffset 1
#define FClawServo 1
#define FClawClose 0
#define FClawOpen 1331
#define BClawServo 0
#define BClawClose 1952
#define BClawOpen 59
#define clawPickUp 86
#define touchPortF 0
#define touchPortB 1
#define grabPort 2
#define up_pos 100
#define release_pos 274
#define grab_pos 1025

void createConnectAll();
void createDrive(float speed, float distance);
void createDriveBack(float speed, float distance);
void createDriveUntilTouch(float speed);
void driveUntil(float speed, float time);
void createSquareUp(float speed, float time);
void createTurnRight(float speed, int degrees);
void createTurnLeft(float speed, int degrees);
void createArmUp(float speed);
void createArmDown(float speed);
void createArmUpOffset(float speed, float FOffset, float BOffset);
void createArmDownOffset(float speed, float FOffset, float BOffset);
void createArmUpOffsetTime(float speed, float time, float FOffset, float BOffset);
void createArmDownOffsetTime(float speed, float time, float FOffset, float BOffset);
void createArmStay(float speed);
void createFClawOpen();
void createFClawClose();
void createBClawOpen();
void createBClawClose();
void pipeUp();
void grabPipe();
void releasePipe();
