# Experimental Protocol and Data Logging

## Objective
Measure whether the prototype can transfer emergency-style messages over a LoRa link under repeatable bench and outdoor ground-level conditions.

## Test sequence
1. **Bench link:** place nodes 1–3 m apart; send at least 100 numbered packets.
2. **Distance test:** increase distance in documented increments while keeping antenna height and orientation consistent.
3. **Obstruction test:** repeat with specified obstacles; record environment and antenna positions.
4. **Relay test:** compare direct link against relay-enabled path using the same packet schedule.
5. **Stress test:** introduce controlled packet bursts and node restarts; verify duplicate suppression and recovery.
6. **Power test:** log battery voltage/current over time using suitable measurement equipment.

## Per-packet fields
`timestamp_utc,node_id,seq,mode,tx_status,rx_status,rssi_dbm,snr_db,lat,lon,battery_v,battery_pct,temperature_c,hop_count,alert,notes`

## Metrics
- Packet delivery ratio = unique valid packets received / packets transmitted × 100%.
- Median and 95th percentile message latency.
- RSSI/SNR distribution.
- Recovery time after power or link interruption.
- Battery runtime under a documented workload.

## Reporting
Report number of trials, sample size, device firmware version, antenna details, radio settings, environmental conditions, failures, and uncertainty. Never replace missing measurements with simulated dashboard values.
