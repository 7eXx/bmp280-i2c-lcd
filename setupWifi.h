#ifndef SETUP_WIFI_H
#define SETUP_WIFI_H

#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <secrets.h>
#include <lcdManager.h>

void setupWifi();
void showWifiConnected();
void showWifiNotConnected();

#endif
