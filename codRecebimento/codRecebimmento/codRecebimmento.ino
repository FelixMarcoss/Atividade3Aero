#include <SPI.h>
#include <LoRa.h>

const int csPin = 5;
const int resetPin = 14;
const int irqPin = 2;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(915E6)) {
    Serial.println("Erro ao iniciar LoRa RX!");
    while (1);
  }
  Serial.println("Receptor aguardando mensagens...");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Recebido: ");
    
    // Lê o conteúdo da mensagem
    while (LoRa.available()) {
      String data = LoRa.readString();
      Serial.println(data);
    }

    
  }
}