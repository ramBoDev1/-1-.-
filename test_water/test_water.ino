//ส่งค่า lite กับ pos
#define en1 25
#define en2 26
#define en3 17
#define dir 16
#define pul 27
#define poxy1 18
#define poxy2 13
#define poxy3 5
#define re1 23
#define humi 2
int pos =1;
int checkx = 0;
int checky = 0;
int checkz = 0;
int x=3;
int l;
int j;
int z;
void setup() {
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(en3,OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(pul,OUTPUT);
  pinMode(poxy1,INPUT);
  pinMode(poxy2,INPUT);
  pinMode(poxy3,INPUT);
  pinMode(re1,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  start();
  set_p();
  digitalWrite(re1,LOW);
  for(l=1;l<=22;l++)//y
  {
    water();
    pos++;
    if(l%2==1)
    {
      for(j=1;j<=2;j++)//x+z
      {
        m(2000,0,1);
        pos++;
        water();
      }
    }
    else
    {
      for(j=1;j<=x;j++)//x+z
      {
        m(2000,1,1);
        pos++;
        water();
      }
    }
  }

}

void m(long pul1,int dir1,int en)
{
  if(en==1)
  {
    digitalWrite(en1,LOW);
  }
  else if(en==2)
  {
    digitalWrite(en2,LOW);
  }
  else if(en==3)
  {
    digitalWrite(en3,LOW);
  }

  
  digitalWrite(dir,dir1);
  for(int i=1;i<=pul1;i++)
  {
    digitalWrite(pul,HIGH);
    delayMicroseconds(500);
    digitalWrite(pul,LOW);
    delayMicroseconds(500);
  }
  if(en==1)
  {
    digitalWrite(en1,HIGH);
  }
  else if(en==2)
  {
    digitalWrite(en2,HIGH);
  }
  else if(en==3)
  {
    digitalWrite(en3,HIGH);
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
     m(1,1,3);
   }
   
  }
  while(1){
    checkx = digitalRead(poxy1);
    if(checkx==0)
   {
    break;
   }else{
     m(1,1,1);
   }
  }
   while(1){
    checky = digitalRead(poxy2);
    if(checky==0)
   {
    break;
   }else{
     m(1,0,2);
   }
  }
  pos=1;
}
void start()
{
  digitalWrite(re1,LOW);
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en3,HIGH);

}
void water()
{
  m(3000,0,3);
  z=1;
  delay(2000);
  int humid=analogRead(2);/////////////////ความชื้น
  Serial.println(humid);
  if(humid<700)
  {
    m(3000,1,3);
    z=0;
    digitalWrite(re1,HIGH);
    delay(4000);
    digitalWrite(re1,LOW);
  }   
  else
  { 
    m(3000,1,3);
    z=0;
   digitalWrite(re1,LOW); 
  } 
}
