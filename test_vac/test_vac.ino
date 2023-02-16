#define dir 2
#define pul 3
#define en1 6
#define en2 5
#define en3 4
#define red 7
#define orange 8
#define green 9
#define seli 10
#define proximityx 11
#define proximityy 12
#define proximityz 13

int checkX = 1;
int checkY = 1;
int checkZ = 1;

int motorSpeed = 100;

int x= 2;
int y= 5;

void setup() {
  pinMode(dir,OUTPUT);
  pinMode(pul,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(en3,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(orange,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(seli,OUTPUT);
  pinMode(proximityx,INPUT);
  pinMode(proximityy,INPUT);
  pinMode(proximityz,INPUT);
  

}

void loop() {
    start();
    setp();  
    for(int i=1;i<=15;i++)
    {
      if(i==0)
      {
        
      }else{
        motorSpeed=400;
        digitalWrite(en2,LOW);
        motor(0,1360);
        digitalWrite(en2,HIGH);
        motorSpeed=400;
      }
      for(int j=1;j<=10;j++)
      {
        mz_take();
        for(int l=1;l<=j;l++)
        {
          digitalWrite(en1,LOW);
          motor(0,2081);
          digitalWrite(en1,HIGH);
        }
        mz_out();
        for(int k=1;k<=j;k++)
        {
          digitalWrite(en1,LOW);
          motor(1,2081);
          digitalWrite(en1,HIGH);
        }
      }
    }
    digitalWrite(en3,LOW);
    motor(0,2000);
    digitalWrite(en3,HIGH);    
}
void start()
{
 digitalWrite(en1,HIGH);
 digitalWrite(en2,HIGH);
 digitalWrite(en3,HIGH);
 digitalWrite(green,HIGH);
 digitalWrite(orange,HIGH);
 digitalWrite(red,HIGH);
 digitalWrite(seli,HIGH);
}
void setp()
{
  digitalWrite(green,LOW);
  digitalWrite(en3,LOW);
  motorSpeed=40;
  while(1){
    checkZ = digitalRead(proximityz);
    if(checkZ==1)
   {
    
    break;
   }else{
     motor(1,1);
   }
  }
  delay(1000);
  for(int z1=1;z1<=12;z1++)
  {
    motor(1,1000);
  }
    motorSpeed=200;
  digitalWrite(en3,HIGH);
  ////////////////////////////////
  digitalWrite(en1,LOW);
  
   while(1){
    checkX = digitalRead(proximityx);
    if(checkX==0)
   {
    
    break;
   }else{
     motor(1,1);
   }
   
  }
  digitalWrite(en1,HIGH);
  ////////////////////////////////
  digitalWrite(en2,LOW);
   while(1){
    checkY = digitalRead(proximityy);
    if(checkY==0)
   {
    break;
   }else{
     motor(1,1);
   }
  }
  digitalWrite(en2,HIGH);
  ////////////////////////////////
  digitalWrite(green,HIGH);
}
void motor(int dir_m,long pul_m)
{
  digitalWrite(dir,dir_m);
  for(int k=1;k<=pul_m;k++)
    {
      digitalWrite(pul,HIGH);
      delayMicroseconds(motorSpeed);
      digitalWrite(pul,LOW);
      delayMicroseconds(motorSpeed);
    }
}
void motorZ(int dir_m,long pul_m)
{
  digitalWrite(en3,LOW);
  digitalWrite(dir,dir_m);
  for(int k=1;k<=pul_m;k++)
    {
      digitalWrite(pul,HIGH);
      delayMicroseconds(30);
      digitalWrite(pul,LOW);
      delayMicroseconds(30);
    }
    digitalWrite(en3,HIGH);
}
void mz_take(){
  digitalWrite(orange,HIGH);
  digitalWrite(red,LOW);
  for(int zz=1;zz<=6;zz++)
        {
          for(int z2=1;z2<=10;z2++)
          {
            motorZ(0,1000);
          }
          
        }
        digitalWrite(seli,LOW);
        delay(1000);
        for(int zz=1;zz<=6;zz++)
        {
         for(int z2=1;z2<=10;z2++)
          {
            motorZ(1,1000);
          }
        }
        digitalWrite(red,HIGH);
        digitalWrite(orange,LOW);
}
void mz_out(){
  digitalWrite(orange,HIGH);
  digitalWrite(red,LOW);
  for(int zz=1;zz<=6;zz++)
        {
          for(int z2=1;z2<=10;z2++)
          {
            motorZ(0,1400);
          }
        }
        digitalWrite(seli,HIGH);
        delay(1000);
        for(int zz=1;zz<=6;zz++)
        {
          for(int z2=1;z2<=10;z2++)
          {
            motorZ(1,1400);
          }
        }
        digitalWrite(red,HIGH);
        digitalWrite(orange,LOW);
}
void set_x()
{
  digitalWrite(green,LOW);
  digitalWrite(en1,LOW);
  while(1){
    checkX = digitalRead(proximityx);
    if(checkX==0)
   {
    break;
   }else{
     motor(1,1);
   }
  }
  digitalWrite(en1,HIGH);
  digitalWrite(green,HIGH);
}
