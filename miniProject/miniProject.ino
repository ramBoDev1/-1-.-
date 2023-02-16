#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  

char auth[] = "NcXgWcEc6PvaTmfbQ95HL-xZOp_gBH-A";
char ssid[] = "Jureerat_2.4GHz";
char pass[] = "043112233";

int val=0;
int humid=0;
//Relay
int IN1=16; 
//water flow
int wfPin = 14;
volatile float pulse = 0;
float volume=0;

void setup() {
  pinMode(wfPin,INPUT_PULLUP);
  //external interrupt (ขาที่ต้องการอินเทอรัพ,ฟังชันก์ที่ต้องการให้ทำงานเมื่อเกิดการอิเทอรัพ,เงื่อนไขการเข้าไปทำงานในฟังชันก์)
  attachInterrupt(digitalPinToInterrupt(wfPin), checkWater, RISING);
  
  pinMode(IN1,OUTPUT);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  Blynk.begin(auth, ssid, pass);
}
//***********************************LOOP****************************************
void loop(){
  Blynk.run();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Liter=");
  lcd.setCursor(7,0);
  volume=pulse/425;
  lcd.print(volume);
  lcd.print("L");
  Blynk.virtualWrite(V3,volume);
  humid=analogRead(A0);
  lcd.setCursor(0,1);
  lcd.print("humid=");
  lcd.setCursor(7,1);
  int humid1=map(humid,0,1024,0,100);
  Blynk.virtualWrite(V1,humid1);
  lcd.print(humid1);
  lcd.print("%");
  if(humid1<65)
  {
    while(1)
    {
      digitalWrite(IN1,HIGH);
      Blynk.virtualWrite(V2,"Water the plans");
      if(humid1>80){
        break;
      }
    }  
  }else
    {
      digitalWrite(IN1,LOW);
      Blynk.virtualWrite(V2," - "); //state
    }  
  delay(200);
}//end loop

//*****************************************interrupt funtion**************************************
ICACHE_RAM_ATTR void checkWater()
{
  pulse++;
}
