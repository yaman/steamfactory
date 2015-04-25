#include <dht.h>

dht DHT;

#define DHT11_PIN 6
int ledPin = 2;

void setup()
{
  Serial.begin(9600); 
  
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  delay(2000);
  int chk = DHT.read11(DHT11_PIN);

  switch (chk)
  {
    case DHTLIB_OK:
      Serial.println("-----------------------------------------");
      Serial.print("Humidity : %");
      Serial.println(DHT.humidity);
      Serial.print("Temp : ");
      Serial.print(DHT.temperature);
      Serial.println("C");
      arrangeHumidity();
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    default:
      Serial.println("Unknown error");
      break;
  }
}

void arrangeHumidity() {
  if (DHT.humidity < 56) {
    Serial.println("Humidity is below %56");
    digitalWrite(ledPin, LOW);
  } else if (DHT.humidity > 56) {
    Serial.println("Humidity is above %56");
    digitalWrite(ledPin, HIGH);
  }
}
