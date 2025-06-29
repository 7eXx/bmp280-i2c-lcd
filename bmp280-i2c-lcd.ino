#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <sensorManager.h>

#define SDA_PIN 8
#define SCL_PIN 9

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  while ( !Serial ) delay(100);   // wait for native usb
  // initialize i2c;
  Wire.begin(SDA_PIN, SCL_PIN);
  
  // initialize display
  lcd.init();
  lcd.backlight();
  lcd.clear();

  setupSensor();
}

void loop() {
  updateReadValues();
  writeLcd();

  delay(2000);
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
