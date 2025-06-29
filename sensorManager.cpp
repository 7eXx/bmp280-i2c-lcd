#include "sensorManager.h"

#define SDA_PIN 8
#define SCL_PIN 9

#define BMP280_ADDRESS 0x76
#define STANDARD_PRESSURE 1021
Adafruit_BMP280 bmp;

volatile float temperature = -1000, pressure = -1000;

unsigned long prevReadMillis = 0;
const unsigned long readDelayMs = 2000;

void setupSensor() {
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

void updateReadValues() {
  unsigned long currentMillis = millis();
  if (currentMillis - prevReadMillis >= readDelayMs) {
    prevReadMillis = currentMillis;
    temperature = bmp.readTemperature();
    pressure = bmp.readPressure() / 100;
  }
}

float getTemperature() { return temperature; }
float getPressure() { return pressure; }
