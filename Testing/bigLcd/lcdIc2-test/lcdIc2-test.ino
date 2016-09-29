#include <Wire.h>
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 // Define I2C Address where the SainSmart LCD is
#define BACKLIGHT_PIN 3

//LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

void setup()
{
lcd.begin (20, 4);

// Switch on the backlight
lcd.setBacklightPin(3,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home();
}

void loop() {
lcd.setCursor ( 0, 0 );
lcd.print("It's Working! ");
lcd.setCursor ( 0, 1 );
lcd.print("HELLO WORLD ! ");
lcd.setCursor ( 0, 2 );
lcd.print("GREAT SCOTT ! ");
lcd.setCursor ( 0, 3 );
lcd.print("IT IS WORKING ! ");
delay(3000);
lcd.setCursor ( 0, 3 );
lcd.print("It's Working! ");
lcd.setCursor ( 0, 2 );
lcd.print("HELLO WORLD ! ");
lcd.setCursor ( 0, 1 );
lcd.print("GREAT SCOTT ! ");
lcd.setCursor ( 0, 0 );
lcd.print("IT IS WORKING ! ");
delay(3000);
}

