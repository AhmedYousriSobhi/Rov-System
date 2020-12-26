#include<SoftwareSerial.h>
SoftwareSerial master (2,4);  //RX , TX
#define enable 3
String value = "0" ;
String key_slave = "0";

void setup() 
{
  pinMode(enable,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(enable,HIGH);
  master.begin(9600);
 Serial.begin(9600);  
}

void loop() 
{
  digitalWrite(enable,HIGH);
 if ( key_slave.toInt() != 4)
 {  
 if(Serial.available())
  {
  value = Serial.readStringUntil(':');
  master.print(value);
  master.print(':');
  key_slave=value.substring(0,1);
  }
 }
  if ( key_slave.toInt() == 4){
    digitalWrite(10,1);
    digitalWrite(enable,LOW);
    master.listen();
 //if (master.isListening()) {
     if(master.available())
    {
      master.setTimeout(10);
      Serial.println(master.readStringUntil(':'));
      key_slave = "0" ;
    }
  } 
}
