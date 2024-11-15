#include "HX711.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
// Define the HX711 load cell pins
#define DOUT  2
#define CLK   3

HX711 scale;

void setup() {
  lcd.init();
  scale.begin(DOUT, CLK);
}

void loop() {
  if (scale.is_ready()) {
    // Read the weight value
    float kilograms;
    float weight = scale.get_units();
    weight*=2.381;
    kilograms=weight/1000;
    // Print the weight on the serial monitor
    lcd.backlight();
    lcd.setCursor(0,0);
  lcd.print(kilograms);
  lcd.print(" kg");
    lcd.setCursor(0,1);
  lcd.print(weight);
  lcd.print(" grams");

    delay(1000); // Wait for a second before taking another reading
  } else {
    lcd.setCursor(0,0);
    lcd.print("Error: Unable to detect HX711.");
    lcd.setCursor(0,1);
    lcd.print("Please check your connections.");
    delay(1000);
  }
}
