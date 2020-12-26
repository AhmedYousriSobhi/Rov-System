#define m1_d  2  //1.1     3.1
#define m1_a  3  //1.1     3.1
         
#define m2_d  4  //1.2     3.2  
#define m2_a  5  //1.2     3.2

#define m3_d  8  //1.3     3.3
#define m3_a  9  //1.3     3.3
     
#define m4_d  10  //1.4    3.4
#define m4_a  11  //1.4    3.4

String    key_speed1 ="0";
String    key_speed2 = "0" ;
String    key_speed3 = "0";
String    key_speed4 ="0";
byte bytes[8];
void  dir_secnod_4_bits (void);
void  dir_first_4_bits (void);
void slave_one_init(void);
void moter_pin_initialize(void);
void process(void);
void special_process_s3_5(void);
void stopall(void);
void test(void);
void slave_one_init(){
    
  moter_pin_initialize();
  }

void moter_pin_initialize()
{
      pinMode(m2_d,OUTPUT);
      pinMode(m2_a,OUTPUT);
      pinMode(m4_a,OUTPUT);
      pinMode(m4_d,OUTPUT);
      pinMode(m3_d,OUTPUT);
      pinMode(m3_a,OUTPUT);
      pinMode(m1_a,OUTPUT);
      pinMode(m1_d,OUTPUT);
}

 void process()
 {
  
     String   key_dir = value.substring(1,4); 
     for(int i=7; i>=0; i--){
       bytes[i] = bitRead(key_dir.toInt(),i);
    }
    if (value.substring(4,5)=="*"){
      }
    else {
     key_speed1 = value.substring(4,7); 
     key_speed2 = value.substring(7,10); 
     key_speed3 = value.substring(10,13); 
     key_speed4 = value.substring(13,16); 
    }
  digitalWrite(m1_d,bytes[0]);
  digitalWrite(m2_d,bytes[1]);
  digitalWrite(m3_d,bytes[2]);
  digitalWrite(m4_d,bytes[3]);
  analogWrite(m1_a,key_speed1.toInt());
  analogWrite(m2_a,key_speed2.toInt());
  analogWrite(m3_a,key_speed3.toInt());
 analogWrite(m4_a,key_speed4.toInt());
    
     

 }
 void special_process_s3_5(){
   
String   key_dir = value.substring(1,4); 
     for(int i=7; i>=0; i--){
       bytes[i] = bitRead(key_dir.toInt(),i);
    }
    if (value.substring(4,5)== "*"){}
    else {
     key_speed1 = value.substring(4,7); 
     key_speed2 = value.substring(7,10); 
     key_speed3 = value.substring(10,13); 
     key_speed4 = value.substring(13,16); 
    }
  digitalWrite(m1_d,bytes[4]);
  digitalWrite(m2_d,bytes[5]);
  digitalWrite(m3_d,bytes[6]);
  digitalWrite(m4_d,bytes[7]);
  analogWrite(m1_a,key_speed1.toInt());
  analogWrite(m2_a,key_speed2.toInt());
  analogWrite(m3_a,key_speed3.toInt());
  analogWrite(m4_a,key_speed4.toInt());
    
 }
void stopall(void){
          digitalWrite(m1_d,0);
          digitalWrite(m2_d,0);
          digitalWrite(m3_d,0);
          digitalWrite(m4_d,0);
          analogWrite(m1_a,0);
          analogWrite(m2_a,0);
          analogWrite(m3_a,0);
          analogWrite(m4_a,0); 
        }
void test(void){
         digitalWrite(m1_d,1);
         digitalWrite(m2_d,0);
         digitalWrite(m3_d,0);
         digitalWrite(m4_d,0);
         analogWrite(m1_a,250);
         analogWrite(m2_a,0);
         analogWrite(m3_a,0);
         analogWrite(m4_a,0);
         delay(1000);
         digitalWrite(m1_d,0);
         digitalWrite(m2_d,0);
         digitalWrite(m3_d,0);
         digitalWrite(m4_d,0);
         analogWrite(m1_a,250);
         analogWrite(m2_a,0);
         analogWrite(m3_a,0);
         analogWrite(m4_a,0);
         delay(1000);
          digitalWrite(m1_d,0);
         digitalWrite(m2_d,1);
         digitalWrite(m3_d,0);
         digitalWrite(m4_d,0);
         analogWrite(m1_a,0);
         analogWrite(m2_a,250);
         analogWrite(m3_a,0);
         analogWrite(m4_a,0);
         delay(1000);
          digitalWrite(m1_d,0);
         digitalWrite(m2_d,0);
         digitalWrite(m3_d,0);
         digitalWrite(m4_d,0);
         analogWrite(m1_a,0);
         analogWrite(m2_a,250);
         analogWrite(m3_a,0);
         analogWrite(m4_a,0);
         delay(1000);
         digitalWrite(m1_d,0);
         digitalWrite(m2_d,0);
         digitalWrite(m3_d,1);
         digitalWrite(m4_d,0);
         analogWrite(m1_a,0);
         analogWrite(m2_a,0);
         analogWrite(m3_a,250);
         analogWrite(m4_a,0);
         delay(1000);
         digitalWrite(m1_d,0);
         digitalWrite(m2_d,0);
         digitalWrite(m3_d,0);
         digitalWrite(m4_d,0);
         analogWrite(m1_a,0);
         analogWrite(m2_a,0);
         analogWrite(m3_a,250);
         analogWrite(m4_a,0);
         delay(1000);
          digitalWrite(m1_d,0);
         digitalWrite(m2_d,0);
         digitalWrite(m3_d,0);
         digitalWrite(m4_d,1);
         analogWrite(m1_a,0);
         analogWrite(m2_a,0);
         analogWrite(m3_a,0);
         analogWrite(m4_a,250);
         delay(1000);
         digitalWrite(m1_d,0);
         digitalWrite(m2_d,0);
         digitalWrite(m3_d,0);
         digitalWrite(m4_d,0);
         analogWrite(m1_a,0);
         analogWrite(m2_a,0);
         analogWrite(m3_a,0);
         analogWrite(m4_a,250);
         delay(1000);   
  
         }
void  dir_first_4_bits (void){
        digitalWrite(m1_d,bytes[0]);
        digitalWrite(m2_d,bytes[1]);
        digitalWrite(m3_d,bytes[2]);
        digitalWrite(m4_d,bytes[3]);
        }
void  dir_secnod_4_bits (void){
        digitalWrite(m1_d,bytes[4]);
        digitalWrite(m2_d,bytes[5]);
        digitalWrite(m3_d,bytes[6]);
        digitalWrite(m4_d,bytes[7]);  
        }
float sensor (char Data_Return )
{
  float monitoring=0;
  float Celcius=0;
  if (Data_Return == 't' || Data_Return == 'T')
  {
    OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
  
   sensors.requestTemperatures(); 
   Celcius=sensors.getTempCByIndex(0);
   
    return Celcius;   
  } 
  else if (Data_Return == 'm' || Data_Return == 'M')
  {
    monitoring = analogRead(metalDetection);    
    return monitoring;
  } 
  else {return 0.0;}
}

double avergearray(int* arr, int number){
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(number<=0){
   
    return 0;
  }
  if(number<5){   //less than 5, calculated directly statistics
    for(i=0;i<number;i++){
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<number;i++){
      if(arr[i]<min){
        amount+=min;        //arr<min
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max;    //arr>max
          max=arr[i];
        }else{
          amount+=arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}

