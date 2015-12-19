
 
#include "LedControlMS.h" // https://github.com/shaai/Arduino_LED_matrix_sketch
#include "LedEyes.h" 
#include <stdlib.h>
#include "Streaming.h" // http://arduiniana.org/libraries/streaming/

/*
 * LED Matrix:
 * Use pins 12, 11 and 10 on the Arduino for the SPI interface
 * Pin 12 is connected to the DATA IN-pin of the first MAX7221
 * Pin 11 is connected to the CLK-pin of the first MAX7221
 * Pin 10 is connected to the LOAD(/CS)-pin of the first MAX7221
 */

  

LedControl lc = LedControl(12, 11, 10, NumDevices ); // Note this will set lc1.getDeviceCount() = 2

void setup()
{
  // initialize serial communication:
  // Used for output only
  Serial.begin (38400);


  // Init the LED Matrix
  for (int i = 0; i < NumDevices ; i++)
  {
    lc.shutdown(i, false);
    /* and clear the display */
    lc.clearDisplay(i);
  }

}


void loop()
{
  Serial << "Start of loop" << endl;
    
      int emotionCode = Serial.parseInt();
      Serial << "Choose eye based on the emotion code: " << emotionCode << endl << endl;

      if (emotionCode ==168)
      {
        Serial << "Sad Eyed" << endl;
        DisplaySadEyes();
      }
      else if (emotionCode == 188)
      {
        Serial << "Happy Eyed" << endl;
        DisplayHappyEyes();
      }
      else if (emotionCode == 158 )
      {
        Serial << "Surprised Eyed" << endl;
        DisplaySurprisedEyes();
      }
      else
      {
        Serial << "Sad Eyed" << endl;
        DisplayShiftyEyesLookingInACircle();
      }
      Serial.print(emotionCode);
  Serial << endl << endl;
}

void DisplayShiftyEyesLookingInACircle()
{
  DisplayEyes( shiftyPupilEye1, shiftyPupilEye1, 100);
  DisplayEyes( shiftyPupilEye2, shiftyPupilEye2, 100);
  DisplayEyes( shiftyPupilEye3, shiftyPupilEye3, 100);
  DisplayEyes( shiftyPupilEye4, shiftyPupilEye4, 100);
  DisplayEyes( shiftyPupilEye5, shiftyPupilEye5, 100);
  DisplayEyes( shiftyPupilEye6, shiftyPupilEye6, 100);
  DisplayEyes( shiftyPupilEye7, shiftyPupilEye7, 100);
  DisplayEyes( shiftyPupilEye8, shiftyPupilEye8, 100);
  DisplayEyes( shiftyPupilEye7, shiftyPupilEye7, 100);
  DisplayEyes( shiftyPupilEye6, shiftyPupilEye6, 100);
  DisplayEyes( shiftyPupilEye5, shiftyPupilEye5, 100);
  DisplayEyes( shiftyPupilEye4, shiftyPupilEye4, 100);
  DisplayEyes( shiftyPupilEye3, shiftyPupilEye3, 100);
  DisplayEyes( shiftyPupilEye2, shiftyPupilEye2, 100);
  DisplayEyes( shiftyPupilEye1, shiftyPupilEye1, 100);
}

void DisplayCalmEyes()
{
  DisplayEyes(calmLeftEye, calmRightEye, 100);
}


void DisplaySurprisedEyes()
{
  DisplayEyes( surprisedEye, surprisedEye, 100);
}


void DisplayHappyEyes()
{
  DisplayEyes( happyEye, happyEye, 100);
}


void DisplaySadEyes()
{
  DisplayEyes( sadLeftEye, sadRightEye, 100);
}



/*********************
 * Common            *
 *********************/
void DisplayEyes( EyeDataType leftEyeData, EyeDataType rightEyeData, int delayMs )
{
  {
    DisplayEye(LeftEyePos, leftEyeData);
    DisplayEye(RightEyePos, rightEyeData);

    delay(delayMs);
  }
}

void DisplayEye( int eyePos, EyeDataType eyeArrary )
{
  for (int j = 0; j < LedCols; j++)
  {
    // Note: setRow(addr,row,value)
    lc.setRow(eyePos, j, eyeArrary.EyeData[j]);
  }
}



