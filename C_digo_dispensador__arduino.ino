#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define trig 8
#define echo 6
int tiempo;
int dis; 
int personas=0;


void setup() {
  pinMode(8,OUTPUT); //TRIG
  pinMode(4,OUTPUT); //BOMBA 1
  pinMode(3,OUTPUT); //BOMBA 2  
  pinMode(2,OUTPUT); //LED
  
  pinMode(6,INPUT); //ECHO
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {

  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  tiempo=pulseIn(echo,HIGH);
  dis=tiempo/58.2; // a centimetros

  if(dis<10) //Cambiar dis
  {
    personas=personas+1;
    delay(200);

    lcd.setCursor(0,0);
    lcd.print("Desinfectados: ");
    lcd.setCursor(6,1);
    lcd.print("Personas");
    lcd.setCursor(3,1);
    lcd.print(personas);
    lcd.clear();
    lcd.print("Desinfectando");
     digitalWrite(4,HIGH);
     digitalWrite(3,HIGH);
     digitalWrite(2,HIGH);
     delay(300);
      
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,LOW);
     delay(300);
    }
  else{
   
     lcd.setCursor(0,0);
    lcd.print("Desinfectados: ");
    lcd.setCursor(6,1);
    lcd.print("Personas");
    lcd.setCursor(3,1);
    lcd.print(personas);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,LOW);
    }
}
