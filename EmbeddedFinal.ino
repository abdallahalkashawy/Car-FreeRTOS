#define IR_SENSOR_RIGHT 11
#define IR_SENSOR_LEFT 12
#define MOTOR_SPEED 180
#include <TM1637Display.h>
#include <Arduino_FreeRTOS.h>


int CLK =48 ;
int DIO =46;,
int pinX = 0;
int LDR = 40;
int pinSW = 50;
int LED1=38;
TM1637Display display = TM1637Display(CLK, DIO);
//Right motor
int enableRightMotor=6;
int rightMotorPin1=7;
int rightMotorPin2=8;

//Left motor
int enableLeftMotor=5;
int leftMotorPin1=22;
int leftMotorPin2=23;

void setup()
{

  TCCR0B = TCCR0B & B11111000 | B00000010 ;
  display.setBrightness(0x0f); // set brightness to maximum

  pinMode(pinSW,INPUT);
  Serial.begin(9600);
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(LDR,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  rotateMotor(0,0);   

  xTaskCreate(Task1,"Task1",1024,NULL,1,NULL);
  xTaskCreate(Task2,"Task2",1024,NULL,1,NULL);
  vTaskStartScheduler(); 

  vTaskStartScheduler();

}


void Task1(void *pvParameters)
{
  while(1)
  {
       // Motor
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  //If none of the sensors detects black line, then go straight
  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW)
  {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  //If right sensor detects black line, then turn right
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW )
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  }
  //If left sensor detects black line, then turn left  
  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH )
  {
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED); 
  } 
  //If both the sensors detect black line, then stop 
  else 
  {
    rotateMotor(0, 0);
  }

  }
}



void Task2(void *pvParameters)
{
  while(1)
  {

    int x = analogRead(pinX);
    
    if(x<600 && x>450 )
  {
  byte letterP[4] = {0b0000000,0x67 , 0b00000000, 0b0000000};
      display.setSegments(letterP);
  }

   if(x<20)
   {
     byte letterD[4] = {0x7E, 0b0000000, 0b00000000, 0b0000000};
      display.setSegments(letterD);
  }

   if(x>1000)
   {
     byte letterC[4] = {0b0000000, 0b0000000, 0x77, 0b0000000};
      display.setSegments(letterC);
  }

  if (digitalRead(LDR) == 1) {
      digitalWrite(LED1, 1);
    }
    else {
      digitalWrite(LED1, 0);
    }
  }
}






void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}



void loop()
{
  

//   int analogValue = analogRead(LDR);

//   Serial.print("Analog reading = ");
//   Serial.print(analogValue);   // the raw analog reading
//  We'll have a few threshholds, qualitatively determined
//   if (analogValue < 100)tytty {
//     Serial.println(" - Very bright");
//   } else if (analogValue < 200) {
//     Serial.println(" - Bright");
//   } else if (analogValue < 500) {
//     Serial.println(" - Light");
//   } else if (analogValue < 800) {
//     Serial.println(" - Dim");
//   } else {
//     Serial.println(" - Dark");
//   }

//      Serial.print(analogRead(pinX));
//      Serial.print("\n");
//   delay(500);

}