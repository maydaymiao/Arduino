#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

// DHT 11 sensor
#define DHTPIN 2
#define DHTTYPE DHT11 

// Update these with values suitable for your network.

const char* ssid = "your ssid";
const char* password = "your wifi password";
const char* mqtt_server = "192.168.2.103";
char* topic = "dht11";
String clientName = "Arduino-esp"; 

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

// DHT sensor
DHT dht(DHTPIN, DHTTYPE, 15);

void setup() {
  // Init sensor
  dht.begin();

  Serial.begin(115200);
  
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
// handle message arrived
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      }
      else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {

  client.loop();
    
    // Grab the current state of the sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();


  static int counter = 0;
  String payload = 
  "{"
  "\"temperature\": \"" + String(t) + "\","
  "\"humidity\": \"" + String(h) + "\""
  "}";

  

  // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else if(!client.connected()){
      reconnect();    
    }
  else{
  Serial.print("Sending payload: ");
  Serial.println(payload);

  if (client.publish(topic, (char*) payload.c_str()))
  {
     Serial.println("Publish ok");
  }
  else {
         Serial.println("Publish failed");
    }
  }
 
++counter;
delay(5000);
}
