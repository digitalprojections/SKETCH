#include "thermistor.h"
#include "HardwareSerial.h"


// Analog pin used to read the NTC
#define NTC_PIN               A0
#define NTC_PIN2               A1

int LED_G = 8;
int LED_R = 9;

// Thermistor objects
THERMISTOR thermistor(NTC_PIN,        // Analog pin
                      10000,          // Nominal resistance at 25 ºC
                      3950,           // thermistor's beta coefficient
                      10000);         // Value of the series resistor
THERMISTOR thermistor2(NTC_PIN2,        // Analog pin
                      10000,          // Nominal resistance at 25 ºC
                      3950,           // thermistor's beta coefficient
                      10000);         // Value of the series resistor
// Global temperature reading
uint16_t temp;
uint16_t temp2;
/**
 * setup
 *
 * Arduino setup function
 */
void setup()
{
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  digitalWrite (LED_G, HIGH);
  digitalWrite (LED_R, LOW);
  Serial.begin(9600);
}

/**
 * loop
 *
 * Arduino main loop
 */
void loop()
{
  temp = thermistor.read();   // Read temperature
  temp2 = thermistor2.read();   // Read temperature
  Serial.print("Temp in 1/10 ºC : ");
  Serial.println(temp);
  Serial.println(temp2);

  if(temp<320){
    digitalWrite (LED_G, HIGH);
    digitalWrite (LED_R, LOW);
  }else {
    digitalWrite (LED_G, LOW);
    digitalWrite (LED_R, HIGH);
  }

  delay(5000);
}
