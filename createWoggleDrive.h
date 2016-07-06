/**************************************
			Port Definitons
**************************************/

#define clawMoverPort 0
#define clawPort 1
#define miniMoverPort 2
#define binPort 3
#define touchPort 0
#define ETPort 1
#define leftSensorPort 4
#define rightSensorPort 5

/**************************************
			Claw Definitons
**************************************/            
              
#define clawOpenPos 250
#define clawClosePos 1000
#define clawDownPos 250
#define clawCarryPos 580
#define clawUpPos 2030
#define clawSquareUpPos 700

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
#define startBinPos 760
              
/**************************************
			Camera Definitons
**************************************/              

#define redChannel 0
#define greenChannel 1

/**************************************
	    Create Drive Definitons
/**************************************/
              
/*#define createRightOffset 1
//#define createLeftOffset 0.955
#define createLeftOffset 0.952
//#define createLeftOffset 0.99*/
#define createRightOffset 1
#define createLeftOffset 1
#define createDriveOffset 1
#define createLeftSlowOffset 0.838
#define createRightSlowOffset 1
//#define createTurnOffset 0.92
#define createTurnOffset 1.1
#define createDriveSpeed 250

/**************************************
    	Line Following Definitons
**************************************/

#define ETUpper 3000
#define ETLower 2700

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
void CreateWobbleBackTill (int wobbleSpeed, float wobbleTime, float timer);
void CreateDriveUntilTouch (float speed);
void CreateSquareUp(float speed, float time);
void CreateDriveUntil (float speed, float time);
void CreateTurnLeft(float speed, int degrees);
void CreateTurnRight(float speed, int degrees);
//int createDriveUntilColor(float speed);
void CreateTurnRightConst(float speed, int degrees);
void CreateTurnLeftConst(float speed, int degrees);
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
int CreateDriveBackET(float speed, float time);
int checkTribbles ();
int FindColor();
void SetTribbles(ClawSpeed speed);
void LineTribbles();
void CreateLineSquareUp(int speed, int blackValue, int whiteValue, float strictness, float mult);
void LowerBinSlow();
void Wibble(int speed, int time, int times);
void TurnRightBlackWhite(int speed, int blackVal, int whiteVal);
