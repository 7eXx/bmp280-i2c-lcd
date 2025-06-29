#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <LiquidCrystal_I2C.h>
#include "sensorManager.h"

extern LiquidCrystal_I2C lcd;

void setupLcd();
void writeLcd();

#endif
