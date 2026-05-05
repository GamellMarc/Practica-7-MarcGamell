#include <Arduino.h>
#include "Audio.h"
#include "SPI.h"
#include "SD.h"
#include "FS.h"

// --- Pins del Lector SD (SPI) per ESP32-S3 ---
#define SD_CS      10
#define SPI_MOSI   11
#define SPI_SCK    12
#define SPI_MISO   13

// --- Pins de l'Amplificador MAX98357A (I2S) ---
#define I2S_BCLK   4
#define I2S_LRC    5
#define I2S_DOUT   6

Audio audio;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  pinMode(SD_CS, OUTPUT);
  digitalWrite(SD_CS, HIGH);
  
  // Iniciem bus SPI
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
  
  // Iniciem targeta SD
  if(!SD.begin(SD_CS, SPI, 4000000)){
    Serial.println("Error muntant la targeta SD");
    return;
  }
  Serial.println("Targeta SD muntada correctament.");

  // Configurem sortida d'àudio
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(10); // Volum de 0 a 21
  
  // Obrim l'arxiu de la pràctica
  audio.connecttoFS(SD, "/Ensoniq-ZR-76-01-Dope-77.wav");
}

void loop() {
  audio.loop(); // Manté la reproducció activa
}

// --- Funcions de Callback (Informació pel Port Sèrie) ---

void audio_info(const char *info) {
  Serial.print("info        "); Serial.println(info);
}
void audio_id3data(const char *info) {
  Serial.print("id3data     "); Serial.println(info);
}
void audio_eof_mp3(const char *info) {
  Serial.print("eof_mp3     "); Serial.println(info);
}
void audio_showstation(const char *info) {
  Serial.print("station     "); Serial.println(info);
}
void audio_showstreaminfo(const char *info) {
  Serial.print("streaminfo  "); Serial.println(info);
}
void audio_showstreamtitle(const char *info) {
  Serial.print("streamtitle "); Serial.println(info);
}
void audio_bitrate(const char *info) {
  Serial.print("bitrate     "); Serial.println(info);
}
void audio_commercial(const char *info) {
  Serial.print("commercial  "); Serial.println(info);
}
void audio_icyurl(const char *info) {
  Serial.print("icyurl      "); Serial.println(info);
}
void audio_lasthost(const char *info) {
  Serial.print("lasthost    "); Serial.println(info);
}
void audio_eof_speech(const char *info) {
  Serial.print("eof_speech  "); Serial.println(info);
}