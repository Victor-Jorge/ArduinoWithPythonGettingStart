# Python with arduino Serial comunication

Projeto simples para demonstrar a comunicação entre Python e Arduino Uno através da porta serial USB. Nesse exemplo pra representar o output foi usado uma fita de led rgb endereçavél, mas você pode trocar por um led


### Hardware
* Arduino Uno
* Cabo USB
* Computador com Python instalado

### Software
* Python 3.x
* Arduino IDE
* Biblioteca PySerial

## Instalação

Instale a dependência necessária:

```bash
pip install pyserial
```

## Código python
```bash
import serial
import time

# Altere 'COM4' para a porta correta do seu Arduino
arduino = serial.Serial('COM4', 9600)

# Aguarda a inicialização da conexão serial
time.sleep(2)

# Liga o LED
arduino.write(b'1')  

# Para desligar o LED, use:
# arduino.write(b'0')

arduino.close()
```

## Código arduino
```bash
#include <Adafruit_NeoPixel.h>

// Variaveis do botao
#define botao 2
bool botaoant = false;
bool botaoatu = false;

#define LED_COUNT 14  // quantidade de leds
#define LED_PIN 7     // Pino de dados 

#define AMARELO strip.Color(255,100,0)   // codigo RGB pro led ficar amarelo
#define BRANCO strip.Color(255,255,255)  // codigo RGB pro led ficar branco

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int estado = 0;


void ligarLedsAmarelo(){
  for( int i =0; i < LED_COUNT; i++){
    strip.setPixelColor(i , AMARELO);
  }
  strip.show();
}

void desligarLeds(){
  strip.clear();
  strip.show();
}

void setup() {
  pinMode(botao,INPUT);

  Serial.begin(9600);
  Serial.println("Iniciando...");

  strip.begin();
  strip.setBrightness(50);

}

void loop() {
  if(Serial.available()){
    char comando = Serial.read();
    Serial.println(comando);
    if (comando == '1'){
      ligarLedsAmarelo();
    }
    else{
      desligarLeds();
    }
  }
        
}
```
