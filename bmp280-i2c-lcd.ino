#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <LiquidCrystal_I2C.h>

#define BMP280_ADDRESS 0x76
#define STANDARD_PRESSURE 1021
Adafruit_BMP280 bmp;
LiquidCrystal_I2C lcd(0x27, 16, 2);

volatile float temperature = -1000;
volatile float pressure = -1000;

void setup() {
  Serial.begin(9600);
  while ( !Serial ) delay(100);   // wait for native usb
  // initialize display
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.println(F("BMP280 test"));
  unsigned status;
  status = bmp.begin(BMP280_ADDRESS);
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }

  /* Default settings from the datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
  readSensor();
  writeLcd();

  delay(2000);
}

void readSensor() {
  temperature = bmp.readTemperature();
  pressure = bmp.readPressure() / 100.0;
}

void writeLcd() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Temp: "));
  lcd.print(temperature);
  lcd.print(F(" "));
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print(F("Pre: "));
  lcd.print(pressure, 2);
  lcd.print(" hPa");
}
