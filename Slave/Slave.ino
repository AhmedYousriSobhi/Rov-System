#include <stdio.h>
#include<SoftwareSerial.h>
SoftwareSerial S1_M (18,17);
SoftwareSerial S13_32_23 (14,15);
SoftwareSerial S3_1 (16,17);

#define enable A2
char slave_loop = 0 ;
#define CHECK0 A6
#define CHECK1 A7
String value = "0";
String key_slave = "0";
void slave_one_init(void);
void process(void);
void special_process_s3_5(void);
void stopall(void);
void test(void);
#include <OneWire.h>
#include <DallasTemperature.h>
#define metalDetection A5
#define ONE_WIRE_BUS A3
#define SensorPin A4           //pH meter Analog output to Arduino Analog Input 0
#define Offset 0.00            //deviation compensate
#define samplingInterval 20
#define ArrayLenth  40     //times of c
char DataReturn = '0';
float data;
float dataArray[3];

int pHArray[ArrayLenth];   
int pHArrayIndex=0;
static float pHValue,voltage;  
static unsigned long samplingTime = millis();
int index =0;
void setup() 
{
   pinMode(CHECK0,INPUT);
   pinMode(CHECK1,INPUT);
   int CHECK0_VALUE = analogRead(A6);
   int CHECK1_VALUE = analogRead(A7);
  
     if ( (CHECK1_VALUE<=200) && (CHECK0_VALUE<=200)){
    // GO TO SLAVE 1 CODE 
    pinMode(enable,OUTPUT);
    S1_M.begin(9600);
    S13_32_23.begin(9600);
    S13_32_23.setTimeout(10);
    S1_M.setTimeout(10);
    slave_one_init();
    slave_loop = 1 ;
   }
  else if ( (CHECK1_VALUE<=200) && (CHECK0_VALUE>=1000)){
    // GO TO SLAVE 2 CODE 
  
    SoftwareSerial micro (12,16);
    OneWire oneWire(ONE_WIRE_BUS);
    DallasTemperature sensors(&oneWire);
    Serial.begin(9600);
    slave_one_init();
    S13_32_23.begin(9600);
    micro.begin(9600);
    
    slave_loop = 2 ;
    sensors.begin(); 
    S13_32_23.setTimeout(10);
    
   }
   else if ((CHECK1_VALUE>=1000) && (CHECK0_VALUE<=200)){
    // GO TO SLAVE 3 CODE
      pinMode(A5,OUTPUT);
    pinMode(A4,OUTPUT);
    slave_one_init();
    S3_1 .begin(9600);
    S13_32_23.begin(9600);
    S3_1 .setTimeout(10);
    S13_32_23.setTimeout(10);
    slave_loop = 3 ;
   }

}

void loop() 
{ if ( slave_loop == 1 )
{
  digitalWrite(enable,LOW);
  if (key_slave.toInt() != 4){
  S1_M.listen();
  if(S1_M.available())
  {
   value = S1_M.readStringUntil(':');
    S13_32_23.print(value);
    S13_32_23.print(':');
    key_slave = value.substring(0,1);
    switch (key_slave.toInt()){
         case 1 : process();break;
         case 5 : process();break;
         case 6 : stopall();break;
         case 7 : test();break; 
  }
   }
   
  }

  if (key_slave.toInt() == 4){
   digitalWrite(enable,HIGH);
   S13_32_23.listen();
   
 if( S13_32_23.available())
  {
   S1_M.print(  S13_32_23.readStringUntil(':'));
   key_slave = "0" ;
  }
 
  }
}
if ( slave_loop == 2) {
 
   if(millis()-samplingTime > samplingInterval)
  {
      pHArray[pHArrayIndex++]=analogRead(SensorPin);
      if(pHArrayIndex==ArrayLenth)pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
      //pHValue = 3.5*voltage+Offset;
      samplingTime=millis();
  } 
  float x = sensor ('t');
  float m = sensor ('m');
  if (key_slave.toInt() != 4)
  {
      S13_32_23.listen();
      if( S13_32_23.available())
      {
       value = S13_32_23.readStringUntil(':');
       key_slave = value.substring(0,1);
       switch (key_slave.toInt())
         {
           case 2 : 
           if ( value.substring(1,2)=="*")
           {
             SoftwareSerial micro (12,16);
             micro.begin(9600);    
            micro.print(value.substring(2,3));
           //digitalWrite(10,1);
            }
           else {
            process();
           }
           break;
           case 6 : stopall();break;
           case 8 : test();break; 
         }
      }  
  }
  if (key_slave.toInt() == 4){
  float f = 55.55 ;
  S13_32_23.print(String(x,3));
  S13_32_23.print(',');
    
  S13_32_23.print(String(voltage,3));
  S13_32_23.print(',');

  S13_32_23.print(String(m,3));
  S13_32_23.print(':');
  key_slave = "0" ;
  }
}
if ( slave_loop == 3 )
{
   if (key_slave.toInt() != 4){
  S3_1 .listen();
  if(S3_1 .available())
  {
    value=S3_1 .readStringUntil(':');
    S13_32_23.print(value);
    S13_32_23.print(':');
    key_slave = value.substring(0,1);
     switch (key_slave.toInt()){
     case 3 : 
     if ( value.substring(1,2)=="*")
           {
             
           switch( value.substring(2,3).toInt()){
            case 1 : digitalWrite(A5,1); break;
            case 2 : digitalWrite(A5,0); break;
            case 3 : digitalWrite(A4,1); break;
            case 4 : digitalWrite(A4,0); break;
            
           }
           
            }
           else {
            process();
           }
           break;
     case 5 : special_process_s3_5();break;
     case 6 : stopall();break; 
     case 9 : test();break;
  }
  }
   }

  if (key_slave.toInt()  == 4){
  S13_32_23.listen();
   
 if(S13_32_23.available())
  {
    S3_1 .print( S13_32_23.readStringUntil(':'));
   
   key_slave = "0" ;
  }
 
  }
}
}


