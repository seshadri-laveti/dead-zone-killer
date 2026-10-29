/*
  Optional serial bridge template.
  Use when the ground station has a compatible USB-connected microcontroller.
  The dashboard expects one JSON object per line at 115200 baud.
*/
void setup() {
  Serial.begin(115200);
  Serial.println("{\"type\":\"status\",\"status\":\"GROUND_STATION_SERIAL_READY\"}");
}
void loop() {
  // Connect your selected receiver/radio library and emit validated JSON-lines
  // telemetry here. This sketch intentionally does not claim to receive LoRa
  // without a fitted radio module and verified wiring.
  delay(1000);
}
