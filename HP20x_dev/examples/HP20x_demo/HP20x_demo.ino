/*
 * Demo name   : HP20x_dev demo 
 * Usage       : I2C PRECISION BAROMETER AND ALTIMETER [HP206C hopeRF] 
 * Author      : Oliver Wang from Seeed Studio
 * Version     : V0.1
*/

#include <HP20x_dev.h>
#include "Arduino.h"
#include "Wire.h" 

unsigned char ret = 0;

void setup()
{  
  Serial.begin(9600);        // start serial for output
  
  Serial.println("****HP20x_dev demo by seeed studio****\n");
  
  /* Power up,delay 150ms,until voltage is stable */
  delay(150);
  /* Reset HP20x_dev */
  HP20x.begin();
  delay(100);
  
  /* Determine HP20x_dev is available or not */
  ret = HP20x.isAvailable();
  if(OK_HP20X_DEV == ret)
  {
    Serial.println("HP20x_dev is available.\n");    
  }
  else
  {
    Serial.println("HP20x_dev isn't available.\n");
  }
  
}
 

void loop()
{
    char display[40];
    if(OK_HP20X_DEV == ret)
    {
      long Temper = HP20x.ReadTemperature();
	  Serial.println("Temper:");
	  float t = Temper/100.0;
	  Serial.print(t);
	  Serial.println("\n");
 
      long Pressure = HP20x.ReadPressure();
	  Serial.println("Pressure:");
	  t = Pressure/100.0;
	  Serial.print(t);
	  Serial.println("\n");
	  
	  long Altitude = HP20x.ReadAltitude();
	  Serial.println("Altitude:");
	  t = Altitude/100.0;
	  Serial.print(t);
	  Serial.println("\n");
	  
      delay(1000);
    }
}
 