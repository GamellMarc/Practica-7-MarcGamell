# Pràctica 7 - Processadors Digitals: Busos de Comunicació III (I2S)

Aquest repositori conté el codi font i la memòria corresponents a la **Pràctica 7** de l'assignatura de Processadors Digitals. L'objectiu d'aquest projecte és l'estudi, configuració i ús del protocol de comunicació digital **I2S (*Inter-IC Sound*)** per al processament i reproducció d'àudio en temps real mitjançant un microcontrolador ESP32-S3.

## 📂 Estructura del Repositori

El repositori s'organitza en les següents carpetes i fitxers:

* **`Practica7Ex1/`** (Reproducció des de memòria interna): 
  * Codi on s'implementa la lectura i descodificació matemàtica d'un arxiu d'àudio AAC. L'arxiu s'ha convertit prèviament a un array hexadecimal i s'ha emmagatzemat directament a la memòria flaix del microcontrolador utilitzant la directiva `PROGMEM`.

* **`Practica7Ex2/`** (Reproducció d'arxiu WAVE des de SD): 
  * Sistema integrat d'alta velocitat que fa conviure dos busos de maquinari en paral·lel. L'ESP32 llegeix un arxiu `.wav` des d'una targeta micro SD externa (mitjançant el bus **SPI**) i el transfereix contínuament al descodificador/amplificador d'àudio (mitjançant el bus **I2S**). També fa ús de *callbacks* asíncrons per processar metadades.

* **`InformePràctica7PD.pdf`**: 
  * Memòria descriptiva i completa de la pràctica. Inclou l'explicació tècnica del codi, l'anàlisi de l'estrès de la CPU (avaluant l'impacte computacional de descodificar àudio en temps real vs moure dades d'entrada/sortida), diagrames de flux, diagrames temporals del funcionament dels busos i resultats de depuració.

## 🛠️ Tecnologies i Maquinari Utilitzat

* **Microcontrolador:** Placa de desenvolupament ESP32-S3 (Mestre)
* **Dispositius de maquinari:** * Descodificador DAC i Amplificador classe D I2S (Mòdul MAX98357A)
  * Altaveu estàndard
  * Mòdul adaptador per a targetes micro SD (Esclau SPI)
* **Entorn de desenvolupament:** Visual Studio Code amb l'extensió PlatformIO.
* **Llenguatge:** C++ (Framework d'Arduino)
* **Llibreries principals:** `ESP8266Audio` (Earle F. Philhower), `ESP32-audioI2S` (ESPHome), `SPI.h`, `SD.h`, `FS.h`.

## 👤 Autor
**Marc Gamell**
