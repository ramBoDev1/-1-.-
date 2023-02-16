#define dir1 3  //x
#define pul1 2
#define dir2 5  //y
#define pul2 4
#define dir3 7  //z
#define pul3 6

#define seli 11


#define proximity1 8
#define proximity2 9
#define proximity3 10


int i;
int j;
long k;


int checkX = 1;
int checkY = 1;
int checkZ = 1;



  int n2 = 1;
  int n1 = 7;////////
  long stepsX = 2000;//////////7142
  long stepsY = 2000;//////////37500
  long stepsZ = 2000;//////////44000

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
  for(int l=1;l<=22;l++)
  {
    
    if(l>=2)
    {
      y();
      water();
    }else
    {
    water();
    }
    if(l%2==1)
    {
      for(int j=1;j<=3;j++)
      {
        m(1,1,10000);
        water();
      }
    }else{
      for(int j=1;j<=3;j++)
      {
        m(1,0,10000);
        water();
      }
    } 
  }
    
    
    
} 
void y()
{
  for(int yy=1;yy<=5;yy++)
  {
    m(2,0,8200);
  }
      
}
void m(int motor,int dir, long pul)
{
  if(motor==1)
  {
    digitalWrite(dir1,dir);
    for(k=0;k<=pul;k++)
    {
      digitalWrite(pul1,HIGH);
      delayMicroseconds(200);
      digitalWrite(pul1,LOW);
      delayMicroseconds(200);
    }
  }
  else if(motor==2)
  {
    digitalWrite(dir2,dir);
    for(k=0;k<=pul;k++)
    {
      digitalWrite(pul2,HIGH);
      delayMicroseconds(100);
      digitalWrite(pul2,LOW);
      delayMicroseconds(100);
    }
  }
  else
  {
    digitalWrite(dir3,dir);
    for(k=0;k<=pul;k++)
    {
      digitalWrite(pul3,HIGH);
      delayMicroseconds(100);
      digitalWrite(pul3,LOW);
      delayMicroseconds(100);
    }
  }
}
void z()
{
  for(int zz=1;zz<=3;zz++)
  {
    m(3,1,11000);
  }
}
void z1()
{
  for(int zz=1;zz<=3;zz++)
  {
    m(3,0,11000);
  }
}
void water()
{
  z();
  delay(1500);
  float humi_G=analogRead(A0);
  humi_G=humi_G*100/1023;
  if(humi_G<90)
  {
    z1();
    digitalWrite(seli,HIGH);
  delay(10000);
    digitalWrite(seli,LOW);
    delay(500);
  }else{
    z1();
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
  
}
