/*
   Based on the following examples:
   WiFi > WiFiMulti: https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/WiFiMulti/WiFiMulti.ino
   WiFi > WiFiScan: https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/WiFiScan/WiFiScan.ino
   Complete project details at our blog: https://RandomNerdTutorials.com/
  
 */

#include <WiFi.h>
#include <WiFiMulti.h>   //  Biblioteca Inserida
WiFiMulti wifiMulti;    //Declarando um recurso para ser utilizado

#include <Adafruit_SSD1306.h>//inclusão da biblioteca do display oled
#define OLED_LARGURA 128 // Número de Pixels do display OLED (Largura)
#define OLED_ALTURA 64   // Número de Pixels do display OLED (Altura)
#define OLED_RESET   4 // Reset pin # (or -1 if sharing Arduino reset pin) 


Adafruit_SSD1306 display(OLED_LARGURA, OLED_ALTURA, &Wire, OLED_RESET);//inicialização do display SSD1306

// WiFi connect timeout per AP. Increase when connecting takes longer.
const uint32_t connectTimeoutMs = 10000;

const char* rede1 = "moto g9 play";
const char* rede2 = "Tavin Net";

void setup(){
  Serial.begin(115200);
  pinMode(2, OUTPUT)
  delay(10);
  WiFi.mode(WIFI_STA);
  
  // Add list of wifi networks
 
  wifiMulti.addAP(rede1, "tbsnzv09826"); // Aqui estamos registrando uma nova rede, com ssid e senha
  wifiMulti.addAP(rede2, "eotatasnekrl"); // Aqui estamos registrando uma nova rede, com ssid e senha
  
  // Conectando no wifi com a maior potência  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();     // Limpa p display
  display.setTextSize(1);     // Tamanho da fonte
  display.setTextColor(WHITE);// Cor da fonte
  display.setCursor(0,0);     //coordenada coluna=0 e linha=0
  
  display.println("Buscando conexão...");

  if (wifiMulti.run(connectTimeoutMs) == WL_CONNECTED) { 
   display.clearDisplay();     // Limpa p display
   display.setCursor(0,8);
   display.println("Wifi conectado!");

   display.setCursor(0,30);
   display.print(WiFi.SSID());
   display.print(" "); 

   display.setCursor(0,40);
   display.println("IP ");
  }
  else 
  {
    display.clearDisplay();     // Limpa p display
    display.setCursor(0,0);
    display.println("Buscando conexão...");
    
  }
  
  display.display();
}



void loop(){
  display.clearDisplay();     // Limpa p display
  display.setTextSize(1);     // Tamanho da fonte
  display.setTextColor(WHITE);// Cor da fonte
  display.setCursor(0,0);     //coordenada coluna=0 e linha=0

  display.setCursor(0,0);
  display.println("Buscando conexão");
  
  // Piscar o led de forma rápida
  
  if (wifiMulti.run(connectTimeoutMs) == WL_CONNECTED) { 
   display.clearDisplay();     // Limpa p display
   display.setCursor(0,8);
   display.println("Wifi conectado!");

   display.setCursor(0,30);
   display.print(WiFi.SSID());
   display.print(" "); 

   display.setCursor(0,40);
   display.println("IP ");
   display.print(WiFi.localIP());
      
  } 
  else 
  {
    display.clearDisplay();     // Limpa p display
    display.setCursor(0,0);
    display.println("Buscando conexão...");
    
  }
  display.display();
  delay(500);
}
