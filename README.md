# Test Checklist

## Dashboard
- [ ] Open `dashboard/index.html`; confirm demo telemetry changes.
- [ ] Pause/resume demo.
- [ ] Paste valid JSON telemetry into the ingest box.
- [ ] Paste malformed JSON and confirm parse error.
- [ ] Check responsive layout on phone and desktop.
- [ ] Confirm that the UI labels all generated values as demo/simulated.

## Firmware bench test
- [ ] Confirm actual pin map and radio frequency.
- [ ] Compile each sketch with the selected board package and libraries.
- [ ] Verify two nodes receive a short packet at 1–3 m.
- [ ] Send at least 100 numbered packets and calculate delivery ratio.
- [ ] Test malformed and duplicate packets.
- [ ] Test reset and power interruption.
- [ ] Save raw logs with firmware revision and test conditions.

These are planned checks; they are not claims that the checks have passed.
