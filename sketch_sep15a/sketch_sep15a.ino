#include<CapacitiveSensor.h>

CapacitiveSensor cs_2_4 = CapacitiveSensor(2,4);
CapacitiveSensor cs_2_5 = CapacitiveSensor(2,5);

int in  = 2;
int out  =4;
int out2 =5;
int state=HIGH;

int r;
int r2;
int p=LOW;
int p2=LOW;
long time =0;
long time2 = 0;
long debounce = 400;

void setup(){
  Serial.begin(9600);

  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop(){
  
  state=LOW;

  r =digitalRead(4);
  if(r==HIGH && p ==LOW &&millis() - time > debounce){
    state = HIGH;
    time=millis();
    Serial.println("Sensor Check1 : 1");
  }
  
  r2=digitalRead(5);
  if(r2==HIGH && p2 ==LOW &&millis() - time2 > debounce){
    state = HIGH;
    time2=millis();
    Serial.println("Sensor Check2 : 2");
  
}

digitalWrite(13,state);
p=r;
p2=r2;
}
