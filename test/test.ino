#define dir1 2  //x
#define pul1 3
#define dir2 4  //y
#define pul2 5
#define dir3 6  //z
#define pul3 7

#define seli 8
#define Flowsensor 10

#define proximity1 10
#define proximity2 11
#define proximity3 12


int i;
int j;
long k;
int motorSpeed = 400;////////////หน่วงแบบไมโครวินาที

int checkX = 1;
int checkY = 1;
int checkZ = 1;


int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
  int n2 = 2;
  int n1 = 20;////////
  long stepsX = 4600;//////////1700 1ขวากล่อง
  long stepsY = 9800;//////////1600 1ตรง
  long stepsZ = 18400;//////////8000 1ลง

void setup() 
{
  pinMode(dir1,OUTPUT);
  pinMode(pul1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pul2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(pul3,OUTPUT);
  pinMode(seli,OUTPUT); 
  pinMode(proximity1,INPUT);
  pinMode(proximity2,INPUT);
  pinMode(proximity3,INPUT);
  pinMode(Flowsensor,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
    set_p();
    m(3,1,stepsZ);
    water();
    
    while(1)
    {
     for(i=0;i<=n1;i++)
    { 
      if(i!=0)
      {
        m(2,1,stepsY);
        m(3,1,stepsZ);
        water();
         
      }
      if(i%2==0)
       {
       for(j=0;j<=n2;j++)
       {
          m(1,0,stepsX);
          m(3,1,stepsZ);
          water();
           
        }
      }
      else
      {
        for(j=0;j<=n2;j++)
        {
          m(1,1,stepsX);
          m(3,1,stepsZ);
          water();
          
        }
      }
      
    }
    if(i==20){
        break; 
      }  
  } 
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
      delayMicroseconds(200);
      digitalWrite(pul3,LOW);
      delayMicroseconds(200);
    }
  }
}
void water()
{
  delay(1500);
  float humi_G=analogRead(A0);
  humi_G=humi_G*100/1023;
  if(humi_G<90)
  {
    m(3,0,stepsZ);
    digitalWrite(seli,HIGH);
    delay(5000);
    digitalWrite(seli,LOW);
    delay(500);
  }else{
    m(3,0,stepsZ);
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
void set_p()
{
  while(1)
  {
    
    checkZ = digitalRead(proximity3);
    if(checkZ == 1)
    {
      break;
    }else{
      m(3,0,1);
    }    
  }
  while(1)
  {
    checkX = digitalRead(proximity1);
    if(checkX == 0)
    {
      break;
    }else{
      m(1,1,1);
    }   
  }
  while(1)
  {
    checkY = digitalRead(proximity2);
    if(checkY == 0)
    {
      break;
    }else{
      m(2,0,1);
    }   
  }  
}
