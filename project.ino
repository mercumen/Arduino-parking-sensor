#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define trig 2
#define echo 3
#define buzzer 6
#define yesil 7
#define sari 8
#define kirmizi 5
int sure , mesafe;
void setup()
{
 
pinMode(yesil,OUTPUT);
pinMode(sari,OUTPUT);
pinMode(kirmizi,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);


  

}

void loop() {
digitalWrite(trig,LOW);
delayMicroseconds(5);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
sure = pulseIn(echo, HIGH);
mesafe=(sure/2)/29;
if (mesafe>3 && mesafe<=10)
{
  digitalWrite(kirmizi,HIGH);
  tone(buzzer,1000);
  

}
else 
{
  digitalWrite(kirmizi,LOW);
  noTone(buzzer);
}
if (mesafe>10 && mesafe<=30)
{
  digitalWrite(sari,HIGH);
  tone(buzzer,1000);
  delay(1000);
  noTone(buzzer);
  delay(50);

}
else 
{
  digitalWrite(sari,LOW);
  noTone(buzzer);
  
}if (mesafe>30 && mesafe<60)
{
  digitalWrite(yesil,HIGH);
  tone(buzzer,1000);
  delay(1000);
  noTone(buzzer);
  delay(1000);
}
else 
{
  digitalWrite(yesil,LOW);
  noTone(buzzer);
}
 lcd.begin();
lcd.clear();
lcd.home();
lcd.print(mesafe);

}
