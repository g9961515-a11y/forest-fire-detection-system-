#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Details
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Pin Configuration
#define FLAME_PIN D5
#define BUZZER_PIN D7

// Most flame modules output LOW when flame is detected
#define FLAME_ACTIVE_LOW true

// KiwisIoT Object
KiwisIoT kiwisiot(ssid, password, topic);

unsigned long previousMillis = 0;
const unsigned long interval = 2000;

void setup() {

  Serial.begin(115200);

  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Forest Fire Detection System");

  // Start KiwisIoT
  kiwisiot.begin();

  Serial.println("System Started Successfully");
}

void loop() {

  // Maintain KiwisIoT connection
  kiwisiot.run();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    // Read Flame Sensor
    int flameValue = digi
