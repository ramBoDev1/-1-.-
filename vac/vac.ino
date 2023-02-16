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
int j;

int motorSpeed = 200;
int x = 4;
int y = 4;
int x_pul=1000;
int y_pul=2000;

void setup() {
  Serial.begin(9600);
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
    start1();
    setp();
    for(int i=1;i<=y;i++)
    {
      digitalWrite(orange,LOW);
      if(i==1)
      {
        mz_t();
      }else{
        
        digitalWrite(en2,LOW);
        motor(0,y_pul);
        digitalWrite(en2,HIGH);
        mz_t();
      }
      feed(); 
    }   
}
void feed()/////////////////////////////////////////////////////////////////////
{
  for(int j=1;j<=x;j++)
        {
          for(int kk=1;kk<=j;kk++){
            digitalWrite(en1,LOW);
            motor(0,x_pul);
            digitalWrite(en1,HIGH);
          }
          mz();
          for(int jj=1;jj<=j;jj++)
          {
            digitalWrite(en1,LOW);
            motor(1,x_pul);
            digitalWrite(en1,HIGH);
          }
          if(j==x){
            
          }else{
            mz_t();
          }  
        } 
}
void start1()
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
  Serial.println("setHome Start");
  digitalWrite(green,LOW);
  //////////////////////////////////////
  digitalWrite(en3,LOW);
  Serial.println("z");
   while(1){
    checkZ = digitalRead(proximityz);
    if(checkZ==1)
   {
    break;
   }else{
     motor(0,1);
   }
   
  }
  digitalWrite(en3,HIGH);
  ////////////////////////////////
  digitalWrite(en1,LOW);
  Serial.println("x");
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
  Serial.println("y");
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
  Serial.println("setHome End");
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
      delayMicroseconds(200);
      digitalWrite(pul,LOW);
      delayMicroseconds(200);
    }
    digitalWrite(en3,HIGH);
}
void mz(){
  digitalWrite(orange,HIGH);
  digitalWrite(red,LOW);
  for(int zz=1;zz<=6;zz++)
        {
          motorZ(1,1200);///////////////
        }
        digitalWrite(seli,HIGH);
        delay(500);
        for(int zz=1;zz<=6;zz++)
        {
          motorZ(0,1200);//////////////////
        }
        digitalWrite(red,HIGH);
        digitalWrite(orange,LOW);
}
void mz_t(){
  digitalWrite(orange,HIGH);
  digitalWrite(red,LOW);
  for(int zz=1;zz<=6;zz++)
        {
          motorZ(1,1200);///////////////
        }
        digitalWrite(seli,LOW);
        delay(500);
        for(int zz=1;zz<=6;zz++)
        {
          motorZ(0,1200);//////////////////
        }
        digitalWrite(red,HIGH);
        digitalWrite(orange,LOW);
}
