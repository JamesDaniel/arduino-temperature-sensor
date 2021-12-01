#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);

  dht.begin();
}

void loop()
{
  delay(5000);
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println("0.00");
//    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("%  Temperature: "));
  Serial.print(t);
}