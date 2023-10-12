
void calculaDHT() {
  
  delay(2000);
  
  umidadeDHT = dht.readHumidity();
  temperaturaDHT = dht.readTemperature();

  if (isnan(umidadeDHT) || isnan(temperaturaDHT)) {
    Serial.println(("Falha na leitura do sensor"));
    return;
  }
}
