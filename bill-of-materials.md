# Bill of Materials (BOM) — Verify Against Your Actual Build

| Block | Example item | Notes |
|---|---|---|
| Controller | ESP32 development board | Confirm board revision and available UART/SPI pins |
| Radio | LoRa SX127x module or the actual fitted module | Match frequency band and antenna impedance |
| Antenna | Frequency-matched antenna | Never transmit without an appropriate antenna/load |
| Position | GPS module, if fitted | Validate cold-start and antenna placement |
| Power | Protected battery pack and regulator | Verify current draw, runtime, charging, and temperature |
| Alert | Buzzer / status LEDs, if fitted | Use transistor driver when current exceeds GPIO limits |
| Ground station | USB-capable ESP32 or USB-UART bridge | Confirm serial framing and voltage levels |
| Payload enclosure | Lightweight enclosure | Assess thermal, vibration, moisture, and secure tethering |

This is a planning list, not a confirmed inventory. Replace examples with exact part numbers and actual connections before assembly.
