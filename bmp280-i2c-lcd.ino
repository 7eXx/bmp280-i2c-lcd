#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <sensorManager.h>
#include <lcdManager.h>
#include <setupWifi.h>
#include <mqttManager.h>

#define SDA_PIN 8
#define SCL_PIN 9

void setup() {
  Serial.begin(115200);
  while ( !Serial ) delay(100);   // wait for native usb
  // initialize i2c;
  Wire.begin(SDA_PIN, SCL_PIN);
  
  setupSensor();
  setupLcd();

  setupWifi();
  setupMqttClient();
}

void loop() {
  tryReconnect();
  loopMqttClient();

  updateReadValues();
  writeLcd();

  tryPublishUpdates();

  delay(2000);
}
