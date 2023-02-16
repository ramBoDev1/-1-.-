//ส่งค่า lite กับ pos
#define p1 2
#define d1 3
#define p2 4
#define d2 5
#define p3 6
#define d3 7
#define poxy1 8
#define poxy2 9
#define poxy3 10
#define re1 11
#define humi A0

int checkx = 0;
int checky = 0;
int checkz = 0;

void setup() {
  pinMode(p1,OUTPUT);
  pinMode(d1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(d3,OUTPUT);
  pinMode(poxy1,INPUT);
  pinMode(poxy2,INPUT);
  pinMode(poxy3,INPUT);
  pinMode(re1,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  m3(500,1);
  m3(500,0);
}
void m1(long pul,int dir)
{ 
  digitalWrite(d1,dir);
  for(int i=1;i<=pul;i++)
  {
    digitalWrite(p1,HIGH);
    delayMicroseconds(500);
    digitalWrite(p1,LOW);
    delayMicroseconds(500);
  }
}
void m2(long pul,int dir)
{ 
  digitalWrite(d2,dir);
  for(int i=1;i<=pul;i++)
  {
    digitalWrite(p2,HIGH);
    delayMicroseconds(500);
    digitalWrite(p2,LOW);
    delayMicroseconds(500);
  }
}
void m3(long pul,int dir)
{ 
  digitalWrite(d3,dir);
  for(int i=1;i<=pul;i++)
  {
    digitalWrite(p3,HIGH);
    delayMicroseconds(500);
    digitalWrite(p3,LOW);
    delayMicroseconds(500);
  }
}
void set_p()////////////////////////////////////////////////////////////////////////////////////////////////////
{
  while(1){
    checkz = digitalRead(poxy3);
    if(checkz==1)
   {
    break;
   }else{
     m3(1,1);
   }
   
  }
  while(1){
    checkx = digitalRead(poxy1);
    if(checkx==0)
   {
    break;
   }else{
     m1(1,1);
   }
  }
   while(1){
    checky = digitalRead(poxy2);
    if(checky==0)
   {
    break;
   }else{
     m2(1,0);
   }
  }
}

void water()
{
  m3(3000,0);
  delay(2000);
  int humid=analogRead(2);/////////////////ความชื้น
  Serial.println(humid);
  if(humid<700)
  {
    m3(3000,1);
    digitalWrite(re1,HIGH);
    delay(4000);
    digitalWrite(re1,LOW);
  }   
  else
  { 
    m3(3000,1);
   digitalWrite(re1,LOW); 
  } 
}
