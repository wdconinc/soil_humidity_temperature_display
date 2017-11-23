/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// Include the library code:
#include <LiquidCrystal.h>

// Include the SHT library:
#include <SHT1x.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Specify data and clock connections and instantiate SHT1x object
#define dataPin  12
#define clockPin 13

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  Serial.begin(9600);
  Serial.println("Starting up");
}

void loop() {
  // Read values from the sensor
  SHT1x sht1x(dataPin, clockPin);
  float temp_c = sht1x.readTemperatureC();
  float temp_f = sht1x.readTemperatureF();
  float humidity = sht1x.readHumidity();

  // Print the values to the serial port
  Serial.print("Temperature: ");
  Serial.print(temp_c, 2);
  Serial.print("C / ");
  Serial.print(temp_f, 2);
  Serial.print("F. Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  // set the cursor to column 0, line 1
  lcd.setCursor(0, 0);
  lcd.print("temp = "); lcd.print(temp_f,2); lcd.print(" F");

  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print("hum = "); lcd.print(humidity,2); lcd.print(" %");

  delay(500);
}

