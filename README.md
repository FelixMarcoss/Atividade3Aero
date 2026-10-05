# Comunicação LoRa ponto a ponto com ESP32

Experimento de comunicação sem fio feito para a atividade 3 do trainee Aero. Dois ESP32 com módulos LoRa Ra-02 (SX1278) desempenham papéis separados: um transmite pacotes numerados e o outro mostra os pacotes recebidos no monitor serial.

**Equipe:** Marcos Ferreira e Samuel Froes.

## Funcionamento

1. O transmissor inicia o rádio em **915 MHz**.
2. A cada **5 segundos**, envia uma mensagem de texto `#1`, `#2`, `#3` e assim por diante.
3. O receptor escuta a mesma frequência e imprime o conteúdo de cada pacote recebido.
4. Ambos usam comunicação serial a **115200 baud** para diagnóstico.

O código está dividido entre [`codTransmissao/codTransmissao.ino`](codTransmissao/codTransmissao.ino) e [`codRecebimento/codRecebimmento.ino`](codRecebimento/codRecebimmento.ino).

## Ligações do módulo Ra-02

| Ra-02 | ESP32 | Função |
| --- | --- | --- |
| VCC | 3,3 V | Alimentação |
| GND | GND | Referência |
| NSS/CS | GPIO 5 | Seleção SPI |
| RST | GPIO 14 | Reset |
| DIO0 | GPIO 2 | Interrupção |
| SCK | GPIO 18 | Clock SPI |
| MISO | GPIO 19 | Dados do módulo para o ESP32 |
| MOSI | GPIO 23 | Dados do ESP32 para o módulo |

**Atenção:** o Ra-02 deve ser alimentado com 3,3 V. Confirme a capacidade de alimentação da placa e as conexões antes de energizar o circuito.

## Reproduzir o experimento

1. Prepare duas placas ESP32 e dois módulos Ra-02 com as ligações acima.
2. Instale o suporte para ESP32 e uma biblioteca que forneça `LoRa.h` no Arduino IDE.
3. Grave o sketch de transmissão em uma placa e o de recepção na outra.
4. Abra o monitor serial de cada placa em `115200 baud` e acompanhe os números enviados e recebidos.

## Escopo

O projeto demonstra transmissão **unidirecional** de texto. Não implementa confirmação de entrega, retransmissão, criptografia ou medição de alcance. A recepção depende de frequência e pinagem compatíveis nos dois dispositivos.
