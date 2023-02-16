#define dir1 2  //x
#define pul1 3
#define dir2 4  //y
#define pul2 5
#define dir3 6  //z
#define pul3 7

#define seli 8
#define Flowsensor 10


int i;
int j;
long k;
int motorSpeed = 100;////////////หน่วงแบบไมโครวินาที

int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
  int n2 = 1;
  int n1 = 16;////////
  long stepsX = 17000;//////////1700
  long stepsY = 1600*5;//////////1600
  long stepsZ = 80000;//////////8000

void setup() 
{
  pinMode(dir1,OUTPUT);
  pinMode(pul1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pul2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(pul3,OUTPUT);
  pinMode(seli,OUTPUT); 

  pinMode(Flowsensor,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
    m(3,1,stepsZ);
    delay(1000);
    m(3,0,stepsZ);
    delay(1000);
}
void m(int motor,int dir,long pul)
{
  if(motor==1)
  {
    digitalWrite(dir1,dir);
    for(k=0;k<=pul;k++)
    {
      digitalWrite(pul1,HIGH);
      delayMicroseconds(motorSpeed);
      digitalWrite(pul1,LOW);
      delayMicroseconds(motorSpeed);
    }
  }
  else if(motor==2)
  {
    digitalWrite(dir2,dir);
    for(k=0;k<=pul;k++)
    {
      digitalWrite(pul2,HIGH);
      delayMicroseconds(motorSpeed);
      digitalWrite(pul2,LOW);
      delayMicroseconds(motorSpeed);
    }
  }
  else
  {
    digitalWrite(dir3,dir);
    for(k=0;k<=pul;k++)
    {
      digitalWrite(pul3,HIGH);
      delayMicroseconds(motorSpeed);
      digitalWrite(pul3,LOW);
      delayMicroseconds(motorSpeed);
    }
  }
}
void water()
{
  delay(1500);
  float humi_G=analogRead(A0);
  humi_G=humi_G*100/1023;
  if(humi_G<50)
  {
    m(3,1,stepsZ);
    digitalWrite(seli,HIGH);
    flow();
    digitalWrite(seli,LOW);
    delay(500);
  }else{
    m(3,1,stepsZ);
  }
  
}
void flow()
{
  while(1)
  {
    X = pulseIn(Flowsensor, HIGH);
    Y = pulseIn(Flowsensor, LOW);
    TIME = X + Y;//อันนี้คือได้ค่า 1 คาบเวลา
    FREQUENCY = 1000000/TIME;//หาความถี่ตามสูตร 1/T 1ก็คือ1วินาที หรือ1,000,000ไมโครวินาที
    WATER = FREQUENCY/7.5; //ปริมาณน้ำ 1 นาที
    LS = WATER/60; //ทำเป็นวินาทีจากนาที
    if(FREQUENCY >= 0)
    {
      if(isinf(FREQUENCY))
      {
        Serial.println(TOTAL);
        Serial.println("Not Flowing!");
      }
      else
      {
        Serial.println("Flowing!");
        TOTAL = TOTAL + LS;
        Serial.println(WATER);
        Serial.println(TOTAL);
      }
    }
    if(TOTAL==0.3)
    {
      TOTAL=0;
      break;
    }
  }
}
