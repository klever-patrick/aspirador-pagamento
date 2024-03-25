void buzzer1()
{
    tone(BUZZER_PIN, 1500);
    delay(500);
    noTone(BUZZER_PIN);
    delay(500);
}
void buzzer2()
{
    tone(BUZZER_PIN, 1500);
    delay(250);
    noTone(BUZZER_PIN);
    delay(250);
    tone(BUZZER_PIN, 1500);
    delay(250);
    noTone(BUZZER_PIN);
    delay(250);
}
void buzzer3()
{
    tone(BUZZER_PIN, 1500);
    delay(500);
    noTone(BUZZER_PIN);
    delay(500);
}
