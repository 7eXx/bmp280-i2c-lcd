#include "lcdManager.h"

#define LCD_ADDRESS 0x27

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setupLcd() {
  // initialize display
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void writeLcd() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Temp: "));
  lcd.print(getTemperature());
  lcd.print(F(" "));
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print(F("Pre: "));
  lcd.print(getPressure(), 2);
  lcd.print(" hPa");
}