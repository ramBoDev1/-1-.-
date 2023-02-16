#define dir1 2  //x
#define pul1 3
#define dir2 4  //y
#define pul2 5
#define dir3 6  //z
#define pul3 7
#define dir4 8  //kepper
#define pul4 9
#define dir5 10  //FORWARD/BACKWEAD
#define pul5 11



#define proximity 12

int motorSpeed = 700;////////////หน่วงแบบไมโครวินาที

  int check =1;
  int k;
  long stepsX = 4600;//////////1700 1ขวากล่อง
  long stepsY = 9800;//////////1600 1ตรง
  long stepsZ = 18400;//////////8000 1ลง
  long stepsK = 4600;//////////1700 1ขวากล่อง
  long stepsD = 9800;//////////1600 1ตรง

void setup() 
{
  pinMode(dir1,OUTPUT);
  pinMode(pul1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pul2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(pul3,OUTPUT);
  pinMode(dir4,OUTPUT);
  pinMode(pul4,OUTPUT);
  pinMode(dir5,OUTPUT);
  pinMode(pul5,OUTPUT);
 
  pinMode(proximity,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  check=digitalRead(proximity);
    if(check== 0) //เจอวัตถุ
    {
      //m( , , );
    }else // ไม่เจอ
    {
      //m( , , );
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
  else if(motor == 3)
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
  else if(motor == 4)
  {
    digitalWrite(dir4,dir);
    for(k=0;k<=pul;k++)
    {
      digitalWrite(pul4,HIGH);
      delayMicroseconds(motorSpeed);
      digitalWrite(pul4,LOW);
      delayMicroseconds(motorSpeed);
    }
  }
  else 
  {
    digitalWrite(dir5,dir);
    for(k=0;k<=pul;k++)
    {
      digitalWrite(pul5,HIGH);
      delayMicroseconds(motorSpeed);
      digitalWrite(pul5,LOW);
      delayMicroseconds(motorSpeed);
    }
  }
}
