#define dir1 3  //x
#define pul1 2
#define dir2 5  //y
#define pul2 4
#define dir3 7  //z
#define pul3 6

#define seli 8


#define proximity1 10
#define proximity2 11
#define proximity3 12


int i;
int j;
long k;
int motorSpeed = 500;////////////หน่วงแบบไมโครวินาที

int checkX = 1;
int checkY = 1;
int checkZ = 1;



  int n2 = 1;
  int n1 = 7;////////
  long stepsX = 2000;//////////1700
  long stepsY = 2000;//////////1600
  long stepsZ = 2000;//////////8000

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

  Serial.begin(9600);
}

void loop() 
{
  set_p();
    m(3,1,stepsZ);
    m(3,0,stepsZ);
    while(1)
    {
     for(i=0;i<=n1;i++)
    { 
      if(i!=0)
      {
        m(2,0,stepsY);
        m(3,1,stepsZ);
         m(3,0,stepsZ);
      }
      if(i%2==0)
       {
       for(j=0;j<=n2;j++)
       {
          m(1,1,stepsX);
          m(3,1,stepsZ);
           m(3,0,stepsZ);
        }
      }
      else
      {
        for(j=0;j<=n2;j++)
        {
          m(1,0,stepsX);
          m(3,1,stepsZ);
          m(3,0,stepsZ);
        }
      } 
    }
    for(i=0;i<=n1;i++)
    {
      if(i!=0)
      {
        m(2,1,stepsY); 
        m(3,1,stepsZ);
         m(3,0,stepsZ);
      }   
      if(i%2==0)
      {
        for(j=0;j<=n2;j++)
        {
          m(1,1,stepsX);
          m(3,1,stepsZ);
           m(3,0,stepsZ);
        }
      }
      else
      {
        for(j=0;j<=n2;j++)
        {
          m(1,0,stepsX);
          m(3,1,stepsZ);
           m(3,0,stepsZ);  
        }
      } 
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

    digitalWrite(seli,LOW);
    delay(500);
  }else{
    m(3,1,stepsZ);
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
      m(3,1,1);
    }    
  }
  while(1)
  {
    checkX = digitalRead(proximity1);
    if(checkX == 0)
    {
      break;
    }else{
      m(1,0,1);
    }   
  }
  while(1)
  {
    checkY = digitalRead(proximity2);
    if(checkY == 0)
    {
      break;
    }else{
      m(2,1,1);
    }   
  }
  m(1,1,1700*7);
  m(2,0,1600*10);
  
}
