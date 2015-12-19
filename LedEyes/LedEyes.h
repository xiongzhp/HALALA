
// General
const int NumDevices  = 2;
const int LeftEyePos = 0;
const int RightEyePos = 1;
const int LedCols = 8;
const int NumEyesShown = 15;
const int ShowEyeDurationRandomiser = 75;

// Ultrasonic Sensor
const int TrigPin = 3;
const int EchoPin = 4;

// Photocell
const int PhotocellPin = A0; // the cell is connected to a0
const int SleepThreshold = 60; // Go to sleep if the light is lower than 100

// Cross-eyed 
const int CrossEyedDistance = 10;
const int MidCrossEyedDistance = 15;
const int SemiCrossEyedDistance = 25;

// Sleep / Wake up
const int WakeLedIntensity = 8; // 1-16?
const int SleepLedIntensity = 1; // 1-16?

// Not Used
const int MaxTransitions = 3;

typedef struct
{
  int EyeData[LedCols];
} EyeDataType;

typedef struct
{
  EyeDataType LeftEye;
  EyeDataType RightEye;
} TwoEyeDataType;


// Not Used
typedef struct
{
  TwoEyeDataType TwoEyeData1;
  int Delay1;
  TwoEyeDataType TwoEyeData2;
  int Delay2;
  TwoEyeDataType TwoEyeData3;
  int Delay3;
} TwoEyeTransistionType;

// Not Used
typedef struct
{
  EyeDataType eyeTransition1;
  EyeDataType eyeTransition2;
  EyeDataType eyeTransition3;
} EyeTransistionType;

// Not Used
typedef struct
{
  EyeTransistionType leftEyeTransition;
  EyeTransistionType rightEyeTransition;
  int Delays[MaxTransitions];
} TwoEyeTransistionTypeOld;


/******************************
 * Eye Data                   *
 * Note: each binary number   *
 *       represents a column  *
 *       in the LED matrix    *
 ******************************/

// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
EyeDataType shiftyPupilEye1 =
{
    B00111100
  , B01000010
  , B01001010
  , B01000010
  , B01000010
  , B01000010
  , B01000010
  , B00111100
};

EyeDataType shiftyPupilEye2 =
{
    B00111100
  , B01000010
  , B01000010
  , B01001010
  , B01000010
  , B01000010
  , B01000010
  , B00111100
};

EyeDataType shiftyPupilEye3 =
{
    B00111100
  , B01000010
  , B01000010
  , B01000010
  , B01001010
  , B01000010
  , B01000010
  , B00111100
};

EyeDataType shiftyPupilEye4 =
{
    B00111100
  , B01000010
  , B01000010
  , B01000010
  , B01000010
  , B01001010
  , B01000010
  , B00111100
};

EyeDataType shiftyPupilEye5 =
{
    B00111100
  , B01000010
  , B01000010
  , B01000010
  , B01000010
  , B01010010
  , B01000010
  , B00111100
};

EyeDataType shiftyPupilEye6 =
{
    B00111100
  , B01000010
  , B01000010
  , B01000010
  , B01010010
  , B01000010
  , B01000010
  , B00111100
};

EyeDataType shiftyPupilEye7 =
{
    B00111100
  , B01000010
  , B01000010
  , B01010010
  , B01000010
  , B01000010
  , B01000010
  , B00111100
};

EyeDataType shiftyPupilEye8 =
{
    B00111100
  , B01000010
  , B01010010
  , B01000010
  , B01000010
  , B01000010
  , B01000010
  , B00111100
};

EyeDataType calmLeftEye =
{
    B00011000
  , B00011000
  , B00011000
  , B00011000
  , B00011000
  , B00011000
  , B00011000
  , B00011000
};

EyeDataType calmRightEye =
{
    B00011000
  , B00011000
  , B00011000
  , B00011000
  , B00011000
  , B00011000
  , B00011000
  , B00011000
};

EyeDataType sadLeftEye =
{
    B00000000
  , B00000010
  , B00000110
  , B00001100
  , B00011000
  , B00110000
  , B01100000
  , B01000000 
};

EyeDataType sadRightEye =
{
    B01000000
  , B01100000
  , B00110000
  , B00011000
  , B00001100
  , B00000110
  , B00000010
  , B00000000 
};

EyeDataType shiftyToSad =
{
    B00111100
  , B00111110
  , B00100110
  , B00100110
  , B00100110
  , B00100110
  , B00111110
  , B00111100  
};


EyeDataType happyEye =
{
    B00010000
  , B00011000
  , B00001100
  , B00000110
  , B00000110
  , B00001100
  , B00011000
  , B00010000
};

EyeDataType surprisedEye =
{
    B00000000 
  , B00000000
  , B00011000
  , B00111100
  , B00111100
  , B00011000
  , B00000000
  , B00000000
  
};


// Eye Designed by Gia Rebello
EyeDataType madEyeLeft =
{
    B01111000 
  , B01101100
  , B01000110
  , B01000011
  , B01110110
  , B01111100
  , B01111000
  , B01110000
  
};

EyeDataType madEyeRight =
{
    B01110000
  , B01111000
  , B01111100
  , B01110110
  , B01000011
  , B01000110
  , B01101100
  , B01111000  
};

EyeDataType madLeftToShifty =
{
    B00111100  
  , B01111110
  , B01100110
  , B01100110
  , B01100110
  , B01111110
  , B01111100
  , B00111000
  
};

EyeDataType madRightToShifty =
{
    B00111000
  , B01111100
  , B01111110
  , B01100110
  , B01100110
  , B01100110
  , B01111110
  , B00111100  
};

