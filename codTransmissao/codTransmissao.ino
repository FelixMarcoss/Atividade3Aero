#include <SPI.h>
#include <LoRa.h>

int counter = 1;

void setup() {
  Serial.begin(115200);
  LoRa.setPins(5, 14, 2); // CS, RST, DIO0
  
  if (!LoRa.begin(915E6)) { // Frequência 915MHz
    Serial.println("Erro ao iniciar LoRa!");
    while (1);
  }
}

void loop() {
  Serial.print("Enviando pacote: ");
  Serial.println(counter);  

  LoRa.beginPacket();
  LoRa.print("#");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
  delay(5000); 
}