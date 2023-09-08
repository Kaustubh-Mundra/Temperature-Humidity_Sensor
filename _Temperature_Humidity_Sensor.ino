#define BLYNK_TEMPLATE_ID "TMPL39oLAkpcp"
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor"
#define BLYNK_AUTH_TOKEN "1FWbVUjYIvTvFSaoiQiKJUKY5cENsGfm"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 // data pin is connected to D2 on  ESP
#define DHTTYPE DHT11 // Name the sensor as an object 

char auth[] = "1FWbVUjYIvTvFSaoiQiKJUKY5cENsGfm";
char ssid[] = "Kaustubh";
char pass[] = "Kaustubh";
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.println("DHT Test Successful!");
 Blynk.begin(auth,ssid,pass);
 Serial.println("Blynk Connected Successfully");
 dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
 float h = dht.readHumidity(); 
 // camelcase - start with lowercase and then nxt mains start with uppercase
 float t = dht.readTemperature();
 float f = dht.readTemperature(true);
 if (isnan(h) || isnan(t) || isnan(f)){
  Serial.println("Something is not working as intended");
  return;
 }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("degrees celcius.");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(1000);

}
