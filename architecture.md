# System Architecture

## Functional blocks
1. **User node:** collects a short emergency message from a local interface and packages it into a radio packet.
2. **Relay node:** receives a packet, validates it, records sequence metadata, and forwards it once according to duplicate-suppression rules.
3. **Ground station:** receives packets from a serial-connected radio bridge or a direct serial telemetry source.
4. **Dashboard:** presents link status, last packet time, RSSI, battery, temperature, GPS position (when available), and alerts.

## Data flow
`message -> packet framing -> radio transmit -> receive/validate -> relay -> ground station -> dashboard`

## Design principles
- Offline-first local operation.
- Explicit packet version and sequence number.
- Timeouts and duplicate suppression.
- Clear separation between demo telemetry and hardware telemetry.
- Bench tests before any elevated or outdoor test.

## Unresolved implementation decisions
Confirm whether the final relay is one-hop or two-hop, the exact LoRa module and board variants, GPS integration, USB serial bridge design, and the required local UI before calling this architecture final.
