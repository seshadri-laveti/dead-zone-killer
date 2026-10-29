/*
  ZONEZAP / DZK-1 - Relay node reference
  Requires: Arduino LoRa library by Sandeep Mistry.
  Pins and frequency are examples only. Verify hardware before use.
*/
#include <SPI.h>
#include <LoRa.h>

static const long LORA_FREQUENCY_HZ = 433E6; // Confirm local legality and module band.
static const int LORA_SS = 5;       // TEMPLATE ONLY
static const int LORA_RST = 14;     // TEMPLATE ONLY
static const int LORA_DIO0 = 26;    // TEMPLATE ONLY
uint32_t rxCount = 0;
String lastForwarded = "";

void setup() {
  Serial.begin(115200);
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(LORA_FREQUENCY_HZ)) {
    Serial.println("{\"type\":\"status\",\"status\":\"LORA_INIT_FAILED\"}");
    while (true) delay(1000);
  }
  Serial.println("{\"type\":\"status\",\"status\":\"RELAY_READY\"}");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (!packetSize) return;

  String packet;
  while (LoRa.available()) packet += (char)LoRa.read();
  ++rxCount;

  // Minimal duplicate suppression. Replace with a bounded sequence-ID cache for production.
  if (packet == lastForwarded) {
    Serial.println("{\"type\":\"relay\",\"status\":\"DUPLICATE_IGNORED\"}");
    return;
  }
  lastForwarded = packet;

  int rssi = LoRa.packetRssi();
  float snr = LoRa.packetSnr();

  // Forward packet to another node if the physical architecture supports a second radio hop.
  // This single-radio reference logs it to serial; it does not magically create a second hop.
  Serial.print("{\"type\":\"telemetry\",\"node\":\"relay-01\",\"seq\":");
  Serial.print(rxCount);
  Serial.print(",\"rssi\":");
  Serial.print(rssi);
  Serial.print(",\"snr\":");
  Serial.print(snr, 1);
  Serial.print(",\"battery\":null,\"temperature\":null,\"alert\":\"NORMAL\",\"payload\":\"");
  for (size_t i=0; i<packet.length(); i++) {
    char c = packet[i];
    if (c == '"' || c == '\\') Serial.write('\\');
    if (c >= 32 && c <= 126) Serial.write(c);
  }
  Serial.println("\"}");
}
