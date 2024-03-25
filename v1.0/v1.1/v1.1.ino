///////////////////////////////////////
//  aspirador pagamneto              //    
//  27/02/2024 - Felipe Nogueira     //
//  Modificado e editado             //
//  Open Source - hardware/Software  //
///////////////////////////////////////

#include <Arduino.h>
#include <TM1637Display.h>

/* defines */

//#define USE_SERIAL Serial
#define CLK 2
#define DIO 3
#define RELE_PIN 5
#define BUTTON 6

/* constantes */
const int ButtonContadorNumero = 10;

//WiFiMulti WiFiMulti;

TM1637Display display(CLK, DIO);


/* VARIAVEIS GLOBAIS */
int globalTempo = 100;

unsigned long globalPreviousMillis = 0;
const long globalInterval = 1000;
int globalButtonState = 0;
int globalButtonContador = 0;
int globalButtonContadorNumero = 10;


void setup() {
  pinMode(RELE_PIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  atualizarTempo();
  atualizarButton();
  atualizarRele();

  
  //delay(5000);
}

void atualizarTempo()
{
  unsigned long currentMillis = millis();

  if (currentMillis - globalPreviousMillis >= globalInterval) {
    
    globalPreviousMillis = currentMillis;
   
    if (globalTempo > 0) {
      globalTempo--;

    }
    atualizarDisplay();
  }

}

void atualizarDisplay()
{
  display.setBrightness(0x0f);
  display.showNumberDec(globalTempo, false);
}

void atualizarButton()
{
  globalButtonState = digitalRead(BUTTON);

  if (globalButtonState == LOW) {
    if (globalButtonContador > ButtonContadorNumero) {
      globalTempo = 100;
      globalButtonContador = 0;
    } else {
      globalButtonContador ++;
    }
  }else {
    if(globalButtonContador > 0){
      globalButtonContador --;
    }
  }
  //Serial.println(globalButtonContador);
  //delay(100);
}

void atualizarRele()
{
  if (globalTempo > 0) {
    digitalWrite(RELE_PIN, HIGH);
  } else {
    digitalWrite(RELE_PIN, LOW);
  }
}