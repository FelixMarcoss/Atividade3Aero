

# Atividade 3: Comunicação LoRa Unidirecional (Ponto a Ponto)

Este projeto demonstra a implementação de um sistema de comunicação sem fio utilizando dois microcontroladores ESP32 e dois módulos LoRa Ra-02 (baseados no chip SX1278 da Semtech). O sistema é composto por um nó transmissor dedicado e um nó receptor dedicado.

## 🚀 Membros da Dupla
* **Marcos Félix Ferreira** 
* **Samuel Froes** 

---

## 🛠️ Detalhes da Montagem
A comunicação entre o ESP32 e o módulo LoRa Ra-02 é feita via interface **SPI**. Devido à sensibilidade do módulo Ra-02 em relação à alimentação, foi utilizada a linha de 3.3V do ESP32, garantindo que o módulo instável operasse apenas como receptor para evitar quedas de tensão excessivas.

### Esquema de Conexão (Pinout)
| Componente LoRa | Pino ESP32 | Função SPI |
| :--- | :--- | :--- |
| **VCC** | 3.3V | Alimentação |
| **GND** | GND | Terra |
| **NSS (CS)** | GPIO 5 | Seleção do Escravo |
| **RST** | GPIO 14 | Reset do Hardware |
| **DIO0** | GPIO 2 | Interrupção de Dados |
| **SCK** | GPIO 18 | Clock |
| **MISO** | GPIO 19 | Master In Slave Out |
| **MOSI** | GPIO 23 | Master Out Slave In |

---

## ⚙️ Configuração do Sistema
Para o cumprimento dos requisitos da atividade, os módulos foram configurados com os seguintes parâmetros:

* **Frequência:** 915.0 MHz (Banda ISM permitida no Brasil).
* **Taxa de Transmissão:** O transmissor envia uma mensagem a cada 5 segundos.
* **Formato da Mensagem:** String de texto simples contendo um índice incremental (Ex: `#1`, `#2`, `#3`...).
* **Depuração:** O status de cada pacote enviado e recebido é exibido via Serial Monitor (Baud rate: 115200).

---

## 📂 Organização do Repositório
* `/codTransmissao`: Código fonte para o ESP32 que realiza o envio dos dados.
* `/codRecebimento`: Código fonte para o ESP32 que realiza a leitura e exibição dos dados.
* `README.md`: Documentação técnica do projeto.

---
