/* The project is designed to measure and 
  optimize the performance of a solar collector
  by humidity and temperature sensors.
  Note: There is also a fan for different air velocities .
  required pieces : 1- Ardiuino Mega2560 2- Dc Fan(12v)
  3- DHT 22 ( best Humidity and temperature )
  4- Motor shield L298P 5- Wires and Power supply 
  Note: 1. There are 9 DHT-22 sensors in the collector to measure Humidity and Temperature in 
  Different points of collector
  2. With a servo motor we are able to adapt the collector's angle to place it in the optimum position
  to absorb maximum energy from the Sun */

int speed = (100); // Control Fan speed by change speed value to circulate Hot weather in the collector

int value;
// Example testing sketch for various DHT humidity/temperature sensors

#include "DHT.h"
#include "Adafruit_Sensor.h"

#define DHTPIN1 22 
#define DHTPIN2 24
#define DHTPIN3 26
#define DHTPIN4 28
#define DHTPIN5 30
#define DHTPIN6 32
#define DHTPIN7 34
#define DHTPIN8 36
#define DHTPIN9 38
// what digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);
DHT dht5(DHTPIN5, DHTTYPE);
DHT dht6(DHTPIN6, DHTTYPE);
DHT dht7(DHTPIN7, DHTTYPE);
DHT dht8(DHTPIN8, DHTTYPE);
DHT dht9(DHTPIN9, DHTTYPE);


void setup() {
  digitalWrite(12,OUTPUT);
  Serial.begin(9600);
  

  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
  dht5.begin();
  dht6.begin();
  dht7.begin();
  dht8.begin();
  dht9.begin();

}

void loop() {
  // Wait a few seconds between measurements.

  value=(speed*(2.55));
  digitalWrite(12,HIGH);
  analogWrite(10,value);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h1 = dht1.readHumidity();
  // Read temperature as Celsius (the default)
  float t1 = dht1.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f1 = dht1.readTemperature(true);

  float h2 = dht2.readHumidity();
  // Read temperature as Celsius (the default)
  float t2 = dht2.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f2 = dht2.readTemperature(true);

  float h3 = dht3.readHumidity();
  // Read temperature as Celsius (the default)
  float t3 = dht3.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f3 = dht3.readTemperature(true);

  float h4 = dht4.readHumidity();
  // Read temperature as Celsius (the default)
  float t4 = dht4.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f4 = dht4.readTemperature(true);

  float h5 = dht5.readHumidity();
  // Read temperature as Celsius (the default)
  float t5 = dht5.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f5 = dht5.readTemperature(true);

  float h6 = dht6.readHumidity();
  // Read temperature as Celsius (the default)
  float t6 = dht6.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f6 = dht6.readTemperature(true);

  float h7 = dht7.readHumidity();
  // Read temperature as Celsius (the default)
  float t7 = dht7.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f7 = dht7.readTemperature(true);

  float h8 = dht8.readHumidity();
  // Read temperature as Celsius (the default)
  float t8 = dht8.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f8 = dht8.readTemperature(true);

  float h9 = dht9.readHumidity();
  // Read temperature as Celsius (the default)
  float t9 = dht9.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f9 = dht9.readTemperature(true);

  Serial.print("Humidity1: ");
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Temperature1: ");
  Serial.print(t1);
  Serial.print(" *C ");
  Serial.print(f1);
  Serial.print("  ");

  Serial.print("Humidity2: ");
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperature2: ");
  Serial.print(t2);
  Serial.print(" *C ");
  Serial.print(f2);
  Serial.print("  ");

  Serial.print("Humidity3: ");
  Serial.print(h3);
  Serial.print(" %\t");
  Serial.print("Temperature3: ");
  Serial.print(t3);
  Serial.print(" *C ");
  Serial.print(f3);
  Serial.print("  ");

  Serial.print("Humidity4: ");
  Serial.print(h4);
  Serial.print(" %\t");
  Serial.print("Temperature4: ");
  Serial.print(t4);
  Serial.print(" *C ");
  Serial.print(f4);
  Serial.print("  ");

  Serial.print("Humidity5: ");
  Serial.print(h5);
  Serial.print(" %\t");
  Serial.print("Temperature5: ");
  Serial.print(t5);
  Serial.print(" *C ");
  Serial.print(f5);
  Serial.print("  ");
  
  Serial.print("Humidity6: ");
  Serial.print(h6);
  Serial.print(" %\t");
  Serial.print("Temperature6: ");
  Serial.print(t6);
  Serial.print(" *C ");
  Serial.print(f6);
  Serial.print("  ");

  
  Serial.print("Humidity7: ");
  Serial.print(h7);
  Serial.print(" %\t");
  Serial.print("Temperature7: ");
  Serial.print(t7);
  Serial.print(" *C ");
  Serial.print(f7);
  Serial.print("  ");

  Serial.print("Humidity8: ");
  Serial.print(h8);
  Serial.print(" %\t");
  Serial.print("Temperature8: ");
  Serial.print(t8);
  Serial.print(" *C ");
  Serial.print(f8);
  Serial.print("  ");

  Serial.print("Humidity9: ");
  Serial.print(h9);
  Serial.print(" %\t");
  Serial.print("Temperature9: ");
  Serial.print(t9);
  Serial.print(" *C ");
  Serial.print(f9);
  Serial.print("  ");
  Serial.println("  ");
  
  delay(30000); //Control the speed of data measuremeny
}
