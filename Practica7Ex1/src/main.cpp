#include <Arduino.h>
#include "AudioGeneratorAAC.h"
#include "AudioOutputI2S.h"
#include "AudioFileSourcePROGMEM.h"
#include "sampleaac.h" // Recorda que has de tenir aquest fitxer amb l'array d'àudio!

AudioFileSourcePROGMEM *in;
AudioGeneratorAAC *aac;
AudioOutputI2S *out;

void setup() {
  Serial.begin(115200);
  
  // Inicialitzem la font d'àudio des de la memòria del programa (PROGMEM)
  in = new AudioFileSourcePROGMEM (sampleaac, sizeof(sampleaac));
  aac = new AudioGeneratorAAC();
  out = new AudioOutputI2S();
  
  // Establim el volum
  out -> SetGain (0.125);
  
  // NOU MAPA DE PINS PER A ESP32-S3 (BCLK, LRC, DIN)
  out -> SetPinout (4, 5, 6); 
  
  // Iniciem la reproducció
  aac->begin(in, out);
}

void loop(){
  if (aac->isRunning()) {
    aac->loop();
  } else {
    aac -> stop();
    Serial.printf("Sound Generator\n");
    delay(1000);
  }
}