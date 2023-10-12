/*
   Ambiente reservado para a realização das conexões
   dos dispositivos necessarios para a comunicação da placa,
   como os utilizados em "Caixa_dagua_codigo" e "Caixa_publica_MQTT".
*/

void conectarWifi() {
  int tryCount = 0;
  Serial.print("\nConectando a ");
  Serial.println((String)ssid);
  Serial.println();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    //lcd.setCursor(14, 3);
    //lcd.print("      ");
    //delay(150);
    //displayLoading();//Caixa_display
    tryCount ++;
    if (tryCount == 20) {
      //displayErroWiFi();
      tryCount = 0;
      digitalWrite(pinoBuzzer, HIGH);
      //break;
    }
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConectado!!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    digitalWrite(pinoBuzzer, LOW);
  }
}

void reconectarWifi() {
  int tryCount = 0;
  Serial.print("\nConectando a ");
  Serial.println((String)ssid);
  Serial.println();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    //lcd.setCursor(14, 3);
    //lcd.print("      ");
    delay(150);
    //displayLoading();//Caixa_display
    tryCount ++;
    if (tryCount == 20) {
      //displayErroWiFi();
      digitalWrite(pinoBuzzer, HIGH);
    }
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConectado!!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    digitalWrite(pinoBuzzer, LOW);
  }
}

void reconectarMQTT() {
  while (!client.connected()) {
    client.connect(mqtt_ClientID);
    Serial.println("Reconectando...");
  }
  if (client.connected()) {
    Serial.println("Reconcetado com sucesso!!");
  }
}

void conectarMQTT() {

  int tryCount = 0;
  while (!client.connected()) {
    client.connect(mqtt_ClientID);
    Serial.println("Conectando...");
    //delay(500);
    //lcd.setCursor(14, 3);
    //lcd.print("      ");
    //delay(150);
    //displayLoading();//Caixa_display
    tryCount ++;
    if (tryCount == 20) {
      //displayErroMQTT();
      digitalWrite(pinoBuzzer, HIGH);
    }
  }
  if (client.connected()) {
    Serial.println("Conectado com sucesso!!");
    digitalWrite(pinoBuzzer, LOW);
  }
}
