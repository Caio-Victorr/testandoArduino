/*
   Ambiente principal do algoritmo reservado para a
   execução basica das atividade do modulo, realizando
   o controle das conexões, medições, calculos e publicações
   encontrados nas demais partes do algoritmo.
*/
/*
  // --- LCD ---
  #include <Wire.h>
  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 20, 4);
  #define dispAlterBotao 19
  int displayPosition = 1;
  int paramDelay = 5000;
*/
// --- WIFI ---


// --- MQTT ---
#include <PubSubClient.h>



PubSubClient client(nodemcuClient);



// ---SENSORES DS18B20---
#define pinoSensor1 27
#define pinoSensor2 26
float temperatura1;
float temperatura2;

// ---SENSOR DHT22---
#include <DHT.h>
#define pinoDHT 14
#define DHTTYPE DHT22
DHT dht(pinoDHT, DHTTYPE);
float temperaturaDHT;
float umidadeDHT;

// ---PINO BUZZER---
#define pinoBuzzer 23

// ---NTP---
#include <NTPClient.h>
#include <WiFiUdp.h>
WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

void setup() {
  //lcd.init();
  //lcd.backlight();
  //displaySetup();//Caixa_display
  pinMode(pinoSensor1, INPUT);
  pinMode(pinoSensor2, INPUT);
  pinMode(pinoDHT, INPUT);
  pinMode(pinoBuzzer, OUTPUT);

  Serial.begin(115200);
  conectarWifi();
  client.setServer(mqtt_Broker, 1883);

  ntp.begin();
  ntp.setTimeOffset(-10800);

  dht.begin();
}

void loop() {
  ntp.update();
  if (WiFi.status() != WL_CONNECTED) {
    reconectarWifi();
  }
  if (!client.connected()) {
    conectarMQTT();
  }
  publicarDados();
}
