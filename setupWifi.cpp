#include "setupWifi.h"

void setupWifi() {
  lcd.clear();
  delay(10);
  lcd.setCursor(0,0);
  lcd.print(F("Connecting WiFi:"));
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  lcd.setCursor(0,1);
  unsigned short retry = 0;
  while (WiFi.status() != WL_CONNECTED && retry < 15) {
    delay(500);
    lcd.print(".");
    retry++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    showWifiConnected();
  } else {
    showWifiNotConnected();
  }

  delay(5000);
}

void showWifiConnected() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Connected WiFi. IP:"));
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());
  
  Serial.print("WiFi Connected! IP: ");
  Serial.println(WiFi.localIP());
}

void showWifiNotConnected() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WiFi not connected.");
  Serial.println("WiFi not connected");
}