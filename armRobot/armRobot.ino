#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define dirx 2
#define pulx 3
#define diry 4
#define puly 5
#define dirz 6
#define pulz 7
#define dira 8
#define pula 9
#define px 10
#define py 11
#define pz 12
#define relay 13

long loop1=0;
void setup()
{
  pinMode(dirx,OUTPUT);
  pinMode(pulx,OUTPUT);
  pinMode(diry,OUTPUT);
  pinMode(puly,OUTPUT);
  pinMode(dirz,OUTPUT);
  pinMode(pulz,OUTPUT);
  pinMode(dira,OUTPUT);
  pinMode(pula,OUTPUT);
  
  pinMode(px,INPUT);
  pinMode(py,INPUT);
  pinMode(pz,INPUT);

  pinMode(relay,OUTPUT);
//////////////////////////////////////////////////////////////////////
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0); 
  lcd.print("PULSE = "); 
  Serial.begin(9600);
}
void loop() {
 m(2,0,10000);
 m(1,1,10000);
 m(2,0,5000);
 m(1,1,1500);
 m(3,1,9000);
 delay(1000);
 m(1,0,11000);

  m(4,1,10000);
  m(4,1,10000);
  m(4,1,10000);
  m(4,1,10000);
  m(4,1,10000);
  m(4,1,10000);
  m(1,1,11000);
 delay(2000);
  m(3,0,9000);
  delay(2000);
  m(1,0,11500);
  m(2,1,10000);
  m(2,1,5000);
  m(4,0,10000);
  m(4,0,10000);
  m(4,0,10000);
  m(4,0,10000);
  m(4,0,10000);
  m(4,0,10000);
 
 while(1)
 {
  
 }
}
void m(int motor,int dir,long pul)
{
  if(motor==1)
  {
    digitalWrite(dirx,dir);
    for(int i=1;i<=pul;i++)
    {
      digitalWrite(pulx,HIGH);
      delayMicroseconds(500);
      digitalWrite(pulx,LOW);
      delayMicroseconds(500);
    }
  }else if(motor==2)
  {
    digitalWrite(diry,dir);
    for(int i=1;i<=pul;i++)
    {
      digitalWrite(puly,HIGH);
      delayMicroseconds(500);
      digitalWrite(puly,LOW);
      delayMicroseconds(500);
    }
    
  }else if(motor==3)
  {
    digitalWrite(dirz,dir);
    for(int i=1;i<=pul;i++)
    {
      digitalWrite(pulz,HIGH);
      delayMicroseconds(500);
      digitalWrite(pulz,LOW);
      delayMicroseconds(500);
    }
  }else{
    digitalWrite(dira,dir);
    for(int i=1;i<=pul;i++)
    {
      digitalWrite(pula,HIGH);
      delayMicroseconds(150);
      digitalWrite(pula,LOW);
      delayMicroseconds(150);
    }
  }
}
void set_home()
{
  while(1)
  {
    int zz=digitalRead(pz);
    if(zz==1)
    {
      break;
      
    }else
    {
      m(3,0,1);
    } 
  }
  while(1)
  {
    int xx=digitalRead(px);
    if(xx==0)
    {
      m(1,1,1);
    }else
    {
      break;
    } 
  }
  while(1)
  {
    int yy=digitalRead(py);
    if(yy==1)
    {
      m(2,0,1);
    }else
    {
      break;
    } 
  }
  
}
void water()
{
  digitalWrite(relay,HIGH);
  delay(2000);
  digitalWrite(relay,LOW);
  delay(1000);
}
void take()
{
  m(1,1,2);
  delay(300);
  m(1,1,1);
  delay(300);
  m(1,1,3);
  delay(300);
  m(1,1,1);//////////home x
  delay(300);
  m(1,1,4);////////180 ตามเข็ม
  delay(300);
  m(1,1,1);
  delay(300);
  m(1,1,3);
  delay(300);
  set_home();
  m(1,1,5);
}
