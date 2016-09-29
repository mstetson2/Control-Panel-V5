#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); //Addr: 0x3F, 20 chars & 4 lines

void setup()
{
lcd.init();
lcd.backlight();
lcd.setCursor(0, 0);
}
void loop()
{
  lcd.print("Hello ");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("World");
  delay(1000);
  lcd.clear();
}
