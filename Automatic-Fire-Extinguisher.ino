#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;
int flame = HIGH;
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

#define Sensor A1
#define Blue 1
#define Red 2

void setup()
{ 

  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);

  lcd.println("Project By!");
  delay(500);
  lcd.clear();
  delay(100);
  lcd.println("Arushi Ghosal");
  delay(1500);
  lcd.clear();
  delay(100);
  lcd.println("Subham Roy");
  delay(1500);
  lcd.clear();
  delay(100);
  lcd.println("Subhojit Das");
  delay(1500);
  lcd.clear();
  delay(100);
  lcd.println("Suchitra Maji");
  delay(1500);
  lcd.clear();
  delay(100);
  lcd.println("Susovan Das");
  delay(1500);
  lcd.clear();
  delay(100); 
  lcd.println("Set-up Run.");
  
  delay(1000);

  lcd.clear();
  
  lcd.setCursor(0,1);
  for(int i=20;i!=0;i--)
  {
    lcd.print("Wait ");
    lcd.print(i);
    lcd.println(" Seconds");
    delay(1000);
    lcd.clear();
  }
  lcd.clear();
}
void loop()
{
  float SensorValue = analogRead(Sensor);
  int flame = digitalRead(8);
  if(SensorValue > 700)
  {
    digitalWrite(Blue,LOW);
    delay(50);
    digitalWrite(Red, HIGH);
    lcd.clear();
    digitalWrite(13,HIGH);
    lcd.println("GAS LEAK!!");
    delay(1500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(Red,LOW);
    delay(50);
  }
  if(flame == LOW)
  {
    digitalWrite(Blue,LOW);
    delay(50);
    digitalWrite(Red, HIGH);
    lcd.clear();
    digitalWrite(13,HIGH);
    lcd.println("FLAMES DETECTED");
    delay(1500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(Blue,LOW);
    delay(50);
  }
  lcd.print("Gas: ");
  lcd.println(SensorValue);
  delay(1500);
  lcd.clear();
  delay(50);
  digitalWrite(Blue,HIGH);
  delay(50);
}
