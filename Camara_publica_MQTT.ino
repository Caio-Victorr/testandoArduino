/*
 * Ambiente reservado para a realização da publicação 
 * dos valores captados pelo sensor ultrassonico e calculados 
 * em "Caixa_valores" no broker MQTT selecionado em "Caixa_dagua_codigo".
 */

void publicarDados() {

  //Publicação no broker MQTT
  client.publish(topicoTemperatura1, String(temperatura1).c_str(), true);
  client.publish(topicoTemperatura2, String(temperatura2).c_str(), true);
  client.publish(topicoTemperaturaDHT, String(temperaturaDHT).c_str(), true);
  client.publish(topicoUmidadeDHT, String(umidadeDHT).c_str(), true);
  
  //Confirmação de envio no monitor Serial
  Serial.println("\nDados publicados no broker com sucesso!!");
  
  //Rascunho no monitor serial
  Serial.println("Temperatura 1: " +(String)temperatura1 + " ºC");
  Serial.println("Temperatura 2: " +(String)temperatura2 + " ºC");
  Serial.println("Temperatura DHT: " +(String)temperaturaDHT + " %");
  Serial.println("Umidade DHT: " +(String)umidadeDHT + " %");
}
