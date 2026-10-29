# Packet Format (Reference)

A compact JSON-lines format is used by the dashboard bridge in this repository. For the radio payload itself, prefer a bounded binary or compact text format to reduce airtime; keep the mapping documented.

## Dashboard telemetry JSON
```json
{
  "type": "telemetry",
  "version": 1,
  "node": "relay-01",
  "seq": 42,
  "rssi": -68,
  "battery": 94,
  "temperature": 28.4,
  "lat": 17.7,
  "lon": 83.2,
  "alert": "NORMAL"
}
```

Fields are illustrative. `lat`, `lon`, and sensor fields may be omitted when unavailable. The values are not measured project results.

## Validation requirements
- Reject malformed JSON and unknown packet versions.
- Bound message length and avoid forwarding arbitrary untrusted input.
- Use sequence numbers and a short duplicate cache.
- Add a checksum or CRC at the radio frame layer.
- Consider authentication and encryption before carrying sensitive messages.
