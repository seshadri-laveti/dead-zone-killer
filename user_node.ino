/*
  ZONEZAP / DZK-1 - User Node reference
  Requires: Arduino LoRa library by Sandeep Mistry.
  IMPORTANT: Replace pin definitions with your verified board wiring.
*/
#include <SPI.h>
#include <LoRa.h>

static const long LORA_FREQUENCY_HZ = 433E6; // Confirm local legality and module band.
static const int LORA_SS = 5;      // TEMPLATE ONLY
static const int LORA_RST = 14;    // TEMPLATE ONLY
static const int LORA_DIO0 = 26;   // TEMPLATE ONLY
uint32_t seqNo = 0;

void setup() {
  Serial.begin(115200);
  delay(300);
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(LORA_FREQUENCY_HZ)) {
    Serial.println("{\"type\":\"status\",\"status\":\"LORA_INIT_FAILED\"}");
    while (true) delay(1000);
  }
  Serial.println("{\"type\":\"status\",\"status\":\"USER_NODE_READY\"}");
  Serial.println("Type a short message and press Enter.");
}

void loop() {
  if (!Serial.available()) return;
  String msg = Serial.readStringUntil('\n');
  msg.trim();
  if (msg.isEmpty()) return;
  if (msg.length() > 180) msg = msg.substring(0, 180);

  String packet = "DZK1|" + String(++seqNo) + "|" + msg;
  LoRa.beginPacket();
  LoRa.print(packet);
  int result = LoRa.endPacket();
  Serial.print("{\"type\":\"tx\",\"seq\":");
  Serial.print(seqNo);
  Serial.print(",\"ok\":");
  Serial.print(result == 1 ? "true" : "false");
  Serial.println("}");
}
