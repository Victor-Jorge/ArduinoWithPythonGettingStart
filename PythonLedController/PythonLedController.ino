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

