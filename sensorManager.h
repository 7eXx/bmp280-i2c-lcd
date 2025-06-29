#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Adafruit_BMP280.h>

void setupSensor();
void updateReadValues();
float getTemperature();
float getPressure(); 

#endif