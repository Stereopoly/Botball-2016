/**************************************
			Port Definitons
**************************************/

#define clawMoverPort 0
#define clawPort 1
#define miniMoverPort 2
#define binPort 3
#define touchPort 0

/**************************************
			Claw Definitons
**************************************/            
              
#define clawOpenPos 1600
#define clawClosePos 900
#define clawDownPos 400
#define clawCarryPos 775
#define clawUpPos 2030
#define clawSquareUpPos 1100

/**************************************
		  Mini Claw Definitons
**************************************/              
              
#define miniDownPos 2000
#define miniUpPos 0
#define miniMidPos 1700
              
/**************************************
		   	Bin Definitons
**************************************/              

#define grabBinPos 0
#define releaseBinPos 2020
              
/**************************************
			Camera Definitons
**************************************/              

#define redChannel 0
#define greenChannel 1

/**************************************
	    Create Drive Definitons
/**************************************/
              
#define createRightOffset 1
//#define createLeftOffset 0.955
#define createLeftOffset 0.952
//#define createLeftOffset 0.99
#define createDriveOffset 1
#define createTurnOffset 0.92
#define createDriveSpeed 250

/**************************************
    	Line Following Definitons
**************************************/

#define leftSensorPort 4
#define rightSensorPort 5

typedef enum {
	SLOW,
  	FAST,
    OPENSLOW
} ClawSpeed;

void StartUp();
void CreateDrive (float speed, float distance);
void CreateDriveStraighter (float speed, float distance);
void CreateDriveSlowDown (float startSpeed, float distance);
void CreateDriveBack (float speed, float distance);
void CreateWobble (int wobbleSpeed, float wobbleTime, int wobbles);
void CreateWobbleBack (int wobbleSpeed, float wobbleTime, int wobbles);
void CreateWobbleBackTill (int wobbleSpeed, float wobbleTime);
void CreateDriveUntilTouch (float speed);
void CreateSquareUp(float speed, float time);
void CreateDriveUntil (float speed, float time);
void CreateTurnLeft(float speed, int degrees);
void CreateTurnRight(float speed, int degrees);
//int createDriveUntilColor(float speed);
void miniGrabberDown();
void miniGrabberUp();
void miniGrabberMid();
void RaiseBin();
void LowerBin();
void clawDown();
void clawDownSlow(int clawPos);
void clawUp();
void clawCarry();
void clawMid();
void clawSquareUp();
void clawOpen();
void clawClose();
void clawCloseSlow();
void lineFollow(int blackValue, int whiteValue, float time, float speed);
void lineFollowDistance(int blackValue, int whiteValue, float speed, float distance);
int checkTribbles ();
int FindColor();
void SetTribbles(ClawSpeed speed);
void LineTribbles();
void CreateLineSquareUp(int speed, int blackValue, int whiteValue, float strictness, float mult);
void LowerBinSlow();
