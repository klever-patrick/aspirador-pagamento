void destravar()
{
  digitalWrite(RELE_PIN, HIGH);
  delay(5000);
  digitalWrite(RELE_PIN, LOW);
  globalEventoAPI = NADA;
 
}
