# Bmp 280 sensor with LCD
This is a simple example of how to use the Bmp 280 sensor with an LCD display using the Arduino platform.  
The code reads the temperature and pressure from the Bmp 280 sensor and displays it on the LCD.

## Required Libraries
- `Adafruit_BMP280.h`: Library for the Bmp 280 sensor.
- `Wire.h`: Library for I2C communication.
- `LiquidCrystal_I2C.h`: Library for the LCD display.

## Connections
- Bmp 280 sensor:
    - VCC to 3.3V or 5V
    - GND to GND
    - SDA to PIN 8 (ESP32-S3)
    - SCL to PIN 9 (ESP32-S3)
- LCD display:
    - VCC to 5V
    - GND to GND
    - SDA to PIN 8 (ESP32-S3)
    - SCL to PIN 9 (ESP32-S3)

## Addresses
- Bmp 280 sensor: `0x76` or `0x77` (depending on the sensor model)
- LCD display: `0x27` (common address for I2C LCDs)
