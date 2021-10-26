#include<LiquidCrystal.h>
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  lcd.clear();
  delay(100);
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  unsigned int a = pulseIn(10, HIGH);
  unsigned int d = (a * 0.034) / 2;
  Serial.println(d);
  delay(100);
  lcd.setCursor(0, 0);
    lcd.print("waterlvl=-");
    lcd.setCursor(14, 0);
    lcd.print("cm");
    lcd.setCursor(11, 0);
    lcd.print(d);

  if (d <= 30)
  {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(1, LOW);
    lcd.setCursor(0,2);
    lcd.print("Water Status=DANGER");
    delay(1000);
  }
  if (d <= 55 && d > 30)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(1, LOW);
    
    lcd.setCursor(0,2);
    lcd.print("Water Status=safe");
    delay(1000);
  }
  if (d <= 80 && d > 55)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(1, LOW);
    
    lcd.setCursor(0,2);
    lcd.print("Water Status=safe");
    delay(1000);
  }
  else
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(1, HIGH);
    
    lcd.setCursor(0,2);
    lcd.print("Water Status=low");
    delay(1000);
  }
}

