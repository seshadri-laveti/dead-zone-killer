# 🚀 ZONEZAP — DEAD ZONE KILLER (DZK-1)
### Balloon-Based Emergency Communication and Disaster Management System Using LoRa Technology

<p align="center">
  <img src="media/images/zonezap_logo.png" alt="ZONEZAP Logo" width="300">
</p>

<p align="center">
  <b>Restoring Emergency Communication When Conventional Networks Fail</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Project-ZONEZAP-0066FF?style=for-the-badge" alt="Project">
  <img src="https://img.shields.io/badge/Technology-ESP32%20%7C%20LoRa-00BCD4?style=for-the-badge" alt="Technology">
  <img src="https://img.shields.io/badge/Application-Disaster%20Management-FF5722?style=for-the-badge" alt="Application">
  <img src="https://img.shields.io/badge/Status-Prototype-orange?style=for-the-badge" alt="Status">
</p>

---

## 📌 Table of Contents

1. [Project Overview](#-project-overview)
2. [Problem Statement](#-problem-statement)
3. [Proposed Solution](#-proposed-solution)
4. [Project Objectives](#-project-objectives)
5. [Key Features](#-key-features)
6. [System Architecture](#-system-architecture)
7. [System Components](#-system-components)
8. [Working Principle](#-working-principle)
9. [Communication Technology](#-communication-technology)
10. [Ground Station Dashboard](#-ground-station-dashboard)
11. [Repository Structure](#-repository-structure)
12. [Hardware Requirements](#-hardware-requirements)
13. [Software Requirements](#-software-requirements)
14. [Installation and Setup](#-installation-and-setup)
15. [Firmware Configuration](#-firmware-configuration)
16. [Telemetry Data Format](#-telemetry-data-format)
17. [Testing and Validation](#-testing-and-validation)
18. [Applications](#-applications)
19. [Advantages](#-advantages)
20. [Limitations](#-limitations)
21. [Future Scope](#-future-scope)
22. [Safety and Regulatory Considerations](#-safety-and-regulatory-considerations)
23. [Project Demonstration](#-project-demonstration)
24. [Research and Development](#-research-and-development)
25. [Contributing](#-contributing)
26. [License](#-license)
27. [Acknowledgements](#-acknowledgements)

---

## 🌍 Project Overview

**ZONEZAP — DEAD ZONE KILLER (DZK-1)** is a prototype emergency communication and disaster management system designed to explore how communication can be supported in areas where conventional mobile networks or internet connectivity are unavailable or disrupted.

The project combines **ESP32-based embedded systems, LoRa wireless communication, a balloon-based relay concept, telemetry monitoring, and a ground-station dashboard**.

In disaster-affected areas, conventional communication infrastructure may become unavailable because of damaged cellular towers, power outages, damaged cables, geographical barriers, or network congestion. These conditions can make it difficult for affected people and response teams to exchange information.

ZONEZAP investigates an alternative communication architecture in which compact wireless nodes transmit short messages over a LoRa radio link. An elevated relay concept may improve line-of-sight communication, while a ground station provides a visual interface for monitoring received telemetry and system status.

The project also includes a web-based dashboard concept for presenting communication status, received signal strength, battery information, temperature, location data when available, and system alerts.

> **Project status:** Prototype and research platform. The supplied dashboard supports simulated telemetry, and the included firmware is reference code that must be configured and tested against the actual hardware before use.

## 🚨 Problem Statement

During natural disasters and other emergencies, reliable communication is essential for coordinating rescue operations and sharing information.

However, several conditions can limit conventional communication:

- Cellular towers may be damaged or lose power.
- Internet connectivity may be unavailable.
- Remote locations may have poor network coverage.
- Hills, buildings, and other obstacles may block radio paths.
- Emergency responders may need to exchange information across disconnected locations.
- Communication infrastructure may take time to restore after a disaster.

These challenges motivate the development of a portable, low-power communication prototype that can operate without relying on an internet connection for its local radio link.

ZONEZAP explores the use of LoRa communication and an elevated relay architecture as one possible approach.

## 💡 Proposed Solution

ZONEZAP proposes a multi-node wireless communication architecture built around ESP32 controllers and LoRa radio modules.

The system is organized into three primary functional blocks:

1. **User Node:** Accepts a short message and transmits it through a LoRa radio link.
2. **Balloon Relay Node:** Receives radio packets and can be developed to forward them between communication nodes.
3. **Ground Station:** Receives telemetry and displays system information through a dashboard.

The balloon is intended to elevate the relay radio to improve line-of-sight conditions. Actual coverage depends on antenna characteristics, terrain, radio settings, interference, elevation, and local regulatory limits.

The architecture is designed to be modular so that each block can be tested independently before integration.

## 🎯 Project Objectives

- Develop a prototype for emergency message transmission using LoRa.
- Explore communication without requiring internet access on the local radio link.
- Investigate an elevated relay concept for improving line-of-sight coverage.
- Build an ESP32-based embedded communication platform.
- Display telemetry and communication status through a ground-station dashboard.
- Support the monitoring of signal strength, battery information, and temperature when the relevant sensors are available.
- Provide a documented testing procedure for evaluating packet delivery, latency, and reliability.
- Establish a foundation for future disaster-management communication research.

## ✨ Key Features

| Feature | Description |
|---|---|
| LoRa wireless link | Supports long-range, low-data-rate communication when configured and validated correctly |
| ESP32 controller | Provides embedded processing and interfaces with radio and sensor modules |
| Balloon relay concept | Explores elevated radio placement to improve line of sight |
| Ground-station dashboard | Displays telemetry and mission status |
| Signal monitoring | Displays received signal strength when supplied by the receiver |
| Battery monitoring | Displays battery percentage when valid battery telemetry is available |
| Temperature monitoring | Displays temperature when a suitable sensor is installed |
| GPS integration concept | Supports latitude and longitude display when GPS data is available |
| Alert panel | Presents warnings and critical events received by the dashboard |
| Offline-first architecture | Local radio communication does not inherently require cellular internet |
| Modular development | Allows nodes, firmware, and dashboard features to be tested separately |

**Important:** A feature shown in the dashboard is not proof that the corresponding sensor or hardware function has been implemented. Verify each feature against the actual circuit and firmware.

## 🏗️ System Architecture

```text
                  ZONEZAP — DZK-1
                         |
             +-----------+-----------+
             |                       |
        USER NODE               GROUND STATION
             |                       ^
       ESP32 Controller              |
             |                       |
        LoRa Module                  |
             |                       |
             v                       |
       Wireless Link                 |
             |                       |
             v                       |
       BALLOON RELAY NODE             |
       +------------------+           |
       | ESP32 Controller |           |
       | LoRa Radio       |           |
       | GPS (optional)   |           |
       | Battery System   |           |
       +------------------+           |
             |                       |
             +---- Telemetry --------+
                                     |
                                     v
                           Web Dashboard
                                     |
                         +-----------+-----------+
                         |           |           |
                      Link RSSI   Telemetry    Alerts
                         |           |           |
                         +-----------+-----------+
```

This is a **functional architecture**, not a verified wiring diagram. The exact radio-hop arrangement depends on the hardware installed in the relay and ground station.

A single LoRa radio cannot automatically receive and retransmit simultaneously in every implementation. A working relay design must specify how reception, packet processing, retransmission, acknowledgements, and duplicate suppression are handled.

## 🔧 System Components

### 1. User Node

The user node is responsible for creating and transmitting emergency messages.

Potential responsibilities include:

- Accepting a short text message from a connected interface.
- Creating a packet containing the message and sequence number.
- Sending the packet through a LoRa module.
- Reporting transmission status through serial output.
- Supporting message validation and length limits.

**Example hardware:** ESP32 development board and a compatible LoRa module.

### 2. Balloon Relay Node

The relay node is intended to receive messages and provide an intermediate communication point.

Potential responsibilities include:

- Receiving radio packets.
- Reading packet signal strength.
- Checking packet validity.
- Detecting duplicate packets.
- Forwarding valid messages where the radio architecture supports it.
- Reporting telemetry to the ground station.
- Providing location data if a GPS module is installed.

The supplied relay firmware is a reference implementation. It must be adapted to the actual radio arrangement before it can serve as a complete multi-hop relay.

### 3. Ground Station

The ground station is the monitoring and data-receiving part of the project.

Its responsibilities may include:

- Receiving serial telemetry from compatible hardware.
- Displaying incoming packet information.
- Monitoring signal strength and available sensor values.
- Presenting warnings and system status.
- Providing an interface for testing telemetry packets.

### 4. GPS Module (Optional)

A GPS receiver can supply location information such as latitude and longitude.

GPS functionality requires a compatible module, correct UART wiring, appropriate antenna placement, and valid satellite reception. If no GPS data is available, the dashboard should not be interpreted as showing a verified device location.

### 5. Power System

The power system supplies energy to the controller, radio, and any sensors.

The final design must account for:

- Battery capacity and discharge limits.
- Controller and radio current consumption.
- Voltage-regulator efficiency.
- Sensor power requirements.
- Charging and protection circuitry.
- Temperature and enclosure conditions.

Battery runtime must be established through measurement rather than estimated from dashboard values.

---

## 📡 Communication Technology

### LoRa

**LoRa (Long Range)** is a radio modulation technology commonly used for low-data-rate wireless communication.

It can be useful for transmitting compact telemetry and short messages when configured appropriately.

Potential benefits include:

- Low data-rate communication.
- Long-range potential under suitable conditions.
- Low-power operating modes on compatible hardware.
- Support for point-to-point radio links.
- Suitability for small telemetry packets.

Actual performance depends on radio configuration, antennas, interference, terrain, obstacles, receiver sensitivity, transmit power, and applicable regulations.

### ESP32

The ESP32 is a microcontroller platform that can manage embedded application logic and communicate with peripherals through interfaces such as SPI, UART, and GPIO.

In this project, an ESP32 can be used to:

- Control a LoRa radio.
- Create and parse packets.
- Read sensors.
- Generate serial telemetry.
- Implement message validation and relay logic.

### Internet Independence

The local LoRa link does not require an internet connection to transmit radio packets between compatible nodes.

However, remote access to the dashboard, cloud logging, or online map services may require internet connectivity. The current static dashboard uses a visual demonstration map rather than a verified live geographic map.

---

## 🖥️ Ground Station Dashboard

The repository contains a responsive web dashboard under `dashboard/`.

### Dashboard Features

| Dashboard element | Purpose |
|---|---|
| Link RSSI | Displays received signal strength |
| Battery | Displays reported battery percentage |
| Temperature | Displays reported temperature |
| Packet counter | Counts ingested telemetry packets |
| Mission position | Displays available GPS coordinates |
| Critical logs and alerts | Presents warning and critical events |
| Mission status | Displays a mission-state label |
| Signal status | Summarizes the link state |
| JSON-lines terminal | Shows telemetry packets and messages |
| Manual packet ingestion | Allows a JSON packet to be pasted for testing |

### Open the Dashboard

1. Extract the repository ZIP.
2. Open the `dashboard` folder.
3. Open `index.html` in a modern browser.
4. Observe the simulated telemetry.
5. Pause or resume the demonstration using the dashboard control.
6. Paste a valid JSON telemetry packet into the input field and select **INGEST**.

### Demo Mode Versus Live Mode

The dashboard currently starts in **demo mode**.

Demo mode generates simulated values so that the user interface can be evaluated without radio hardware.

To display real values, a hardware integration layer must supply actual telemetry to the dashboard. The current static page does not itself guarantee direct access to USB serial hardware.

**Do not use demo values as experimental measurements or evidence of actual communication range, battery performance, or GPS accuracy.**

---

## 📂 Repository Structure

```text
zonezap-dzk1/
│
├── README.md
├── LICENSE
├── CONTRIBUTING.md
├── .gitignore
│
├── .github/
│   └── ISSUE_TEMPLATE/
│       └── bug_report.md
│
├── dashboard/
│   ├── index.html
│   ├── style.css
│   └── app.js
│
├── firmware/
│   ├── user_node/
│   │   └── user_node.ino
│   ├── balloon_relay/
│   │   └── balloon_relay.ino
│   └── ground_station/
│       └── serial_bridge.ino
│
├── hardware/
│   └── pinmap-template.md
│
├── docs/
│   ├── architecture.md
│   ├── bill-of-materials.md
│   ├── experimental-protocol.md
│   ├── media-inventory.md
│   ├── packet-format.md
│   ├── project-abstract.md
│   └── safety-and-compliance.md
│
├── media/
│   ├── README.md
│   ├── images/
│   │   ├── zonezap_logo.png
│   │   ├── balloon_payload_prototype.png
│   │   ├── ground_station_photo.png
│   │   ├── mobile_dashboard.png
│   │   └── prototype_ground_station.png
│   └── videos/
│       ├── prototype_demo_01.mp4
│       ├── prototype_demo_02.mp4
│       └── prototype_demo_03.mp4
│
└── tests/
    └── README.md
```

Some image filenames may have been converted during ZIP compression. Use the actual filenames in `media/images/` when updating this tree.

---

## 🧰 Hardware Requirements

The final bill of materials must match the components physically used in your prototype.

| Component | Purpose | Status |
|---|---|---|
| ESP32 development board | Embedded processing | Required for the reference firmware |
| Compatible LoRa module | Radio transmission and reception | Required |
| Frequency-matched antenna | Radio link | Required |
| GPS module | Location telemetry | Optional |
| Battery and regulator | Portable power | Required for battery-powered operation |
| USB cable or USB-UART interface | Programming and serial communication | Required for relevant development workflows |
| Buzzer or LEDs | Local status indication | Optional |
| Balloon and payload enclosure | Elevated relay experiment | Optional; requires a safety review |
| Ground-station computer | Dashboard and telemetry monitoring | Required for browser-based monitoring |

### Hardware Compatibility

Before wiring the system:

1. Identify the exact ESP32 board.
2. Identify the exact LoRa module and supported frequency.
3. Confirm the module's supply voltage and logic levels.
4. Verify SPI pin assignments.
5. Verify chip-select, reset, and interrupt connections.
6. Confirm the antenna connector and antenna frequency.
7. Confirm whether a GPS module is actually installed.
8. Update `hardware/pinmap-template.md` with verified connections.

The example pin assignments in the firmware are not a substitute for a verified circuit.

---

## 💻 Software Requirements

| Software or library | Purpose |
|---|---|
| Arduino IDE | Editing and uploading embedded firmware |
| ESP32 board package | Compiling for compatible ESP32 boards |
| LoRa library by Sandeep Mistry | Basic LoRa radio interface |
| Browser | Running the dashboard |
| Serial Monitor | Debugging firmware and viewing packet output |
| Git | Version control |
| GitHub account | Hosting the repository |

If GPS functionality is added to the firmware, a GPS parsing library such as TinyGPSPlus may be useful. It is not required by the supplied basic radio examples.

---

## ⚙️ Installation and Setup

### Step 1: Download the Repository

Download the ZIP archive and extract it.

Open the extracted project folder in your preferred code editor or browse its files directly.

### Step 2: Run the Dashboard

1. Navigate to `dashboard/`.
2. Open `index.html`.
3. Verify that the dashboard loads.
4. Confirm that the demo telemetry updates.
5. Test the manual JSON input.
6. Check that warnings appear when warning-level data is supplied.

No backend server is required for the basic static demonstration.

### Step 3: Install the ESP32 Board Package

1. Open Arduino IDE.
2. Install or select a compatible ESP32 board package.
3. Connect the board through USB.
4. Select the correct board and serial port.
5. Verify that a simple serial sketch can be uploaded.

### Step 4: Install the LoRa Library

Install the **LoRa library by Sandeep Mistry** through Arduino IDE's Library Manager.

The reference transmitter and relay sketches use this library.

### Step 5: Configure the Radio

Before uploading firmware:

1. Open the relevant `.ino` file.
2. Verify the radio frequency against the module and local regulations.
3. Replace template pin assignments with the verified wiring.
4. Confirm the antenna is appropriate for the radio frequency.
5. Ensure both communicating radios use compatible configurations.

Do not assume that all LoRa modules use the same frequency or pinout.

### Step 6: Test the User Node

Upload `firmware/user_node/user_node.ino` after adapting its configuration.

Open Serial Monitor at **115200 baud**. Enter a short message and press Enter.

The reference sketch attempts to transmit the message and prints a serial status record.

### Step 7: Test the Relay Node

Upload `firmware/balloon_relay/balloon_relay.ino` to the compatible receiving node after verifying its wiring.

Start with a short, controlled bench test. Check whether packets are received and whether the serial output reports telemetry.

The supplied sketch logs received packets; a complete multi-hop forwarding arrangement requires additional hardware and firmware integration where applicable.

### Step 8: Integrate the Ground Station

Connect a compatible receiver or serial bridge to the computer.

The dashboard's manual JSON input can be used to validate telemetry formatting before live serial integration is attempted.

A live hardware connection requires a suitable bridge or browser serial implementation.

---

## 📦 Telemetry Data Format

The dashboard accepts JSON objects through its manual ingestion form.

Example:

```json
{
  "type": "telemetry",
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

**All values in this example are illustrative, not measured results.**

### Field Descriptions

| Field | Description |
|---|---|
| `type` | Packet category |
| `node` | Identifier of the transmitting node |
| `seq` | Packet sequence number |
| `rssi` | Received signal strength, typically expressed in dBm |
| `battery` | Battery percentage, if measured and supplied |
| `temperature` | Temperature in degrees Celsius, if measured |
| `lat` | Latitude, if valid GPS data is available |
| `lon` | Longitude, if valid GPS data is available |
| `alert` | System state such as `NORMAL` or `LOW_BATTERY` |

Missing fields should be handled safely. A value should not be presented as measured if it was simulated, unavailable, or estimated.

For radio transmission, a compact packet format may be more appropriate than transmitting the complete JSON representation over the air. The firmware and dashboard must agree on how radio packets are translated into dashboard telemetry.

---

## 🧪 Testing and Validation

Testing is necessary to determine whether the system performs as intended.

### 1. Bench Test

Place compatible nodes a short distance apart in a controlled environment.

Verify:

- Both nodes initialize successfully.
- Packets can be transmitted and received.
- Sequence numbers are recorded correctly.
- Invalid or empty messages are handled appropriately.
- Radio settings are compatible.

### 2. Packet Delivery Test

Send a known number of numbered packets and record how many unique packets are received.

Packet delivery ratio can be calculated as:

\[
\text{PDR} = \frac{\text{Unique packets received}}{\text{Packets transmitted}}\times100\%
\]

Record the number of transmitted packets, received packets, duplicates, and failed transmissions.

### 3. Distance Test

Increase the distance between nodes in documented increments.

Record:

- Distance between nodes.
- Antenna height and orientation.
- Radio configuration.
- RSSI and SNR, if available.
- Number of packets transmitted.
- Number of packets received.
- Environmental conditions.

Do not claim a maximum range based on a single successful packet.

### 4. Relay Test

Compare direct communication with the proposed relay path under comparable conditions.

Record whether each packet was received, forwarded, duplicated, or lost.

Confirm that the relay arrangement actually forwards packets between the intended nodes.

### 5. Latency Test

Record timestamps for message creation, transmission, reception, and final delivery.

Calculate latency using synchronized timestamps or a documented timing method.

Distinguish one-way latency from round-trip latency.

### 6. Power Test

Measure the current drawn by the controller, radio, and other modules under a documented workload.

Record battery voltage and elapsed time to estimate actual runtime.

### 7. Dashboard Test

Verify that:

- The page opens in the target browser.
- Demo mode is clearly distinguishable from live telemetry.
- Valid JSON can be ingested.
- Invalid JSON produces an error.
- Missing values do not produce misleading readings.
- Alerts are displayed correctly.
- The interface is usable on desktop and mobile screens.

### Experimental Results

No specific communication range, packet delivery ratio, latency, or battery-runtime result is claimed in this README. Add these results only after collecting repeatable measurements from the actual hardware.

Refer to `docs/experimental-protocol.md` for the suggested logging procedure.

---

## 🌐 Applications

Potential applications to investigate include:

- Disaster-response communication experiments.
- Temporary communication links in remote areas.
- Emergency telemetry demonstrations.
- Search-and-rescue communication research.
- Environmental and infrastructure monitoring.
- Student projects involving embedded systems and wireless networking.
- Research into portable communication infrastructure.

These are potential applications, not evidence of deployment or certification.

## ✅ Advantages

- Explores communication without requiring internet access on the local LoRa link.
- Uses modular embedded hardware.
- Provides a dashboard for visualizing telemetry.
- Supports experimental evaluation of packet delivery and signal strength.
- Allows individual components to be developed and tested independently.
- Provides a foundation for further research in resilient communication systems.

## ⚠️ Limitations

- LoRa supports relatively low data rates and is not designed for high-bandwidth media streaming.
- Actual coverage depends on the radio configuration, antennas, environment, and interference.
- An elevated relay introduces mechanical, environmental, and operational challenges.
- The current dashboard demo does not prove live hardware connectivity.
- The reference relay firmware is not a complete production-grade multi-hop protocol.
- Security, authentication, and encryption require additional design and testing.
- GPS functionality depends on compatible hardware and valid GPS reception.
- The system is not certified for life-safety or public emergency use.

## 🔮 Future Scope

1. **Live Telemetry:** Integrate a verified serial or wireless telemetry bridge.
2. **Map Integration:** Display validated GPS coordinates on a real map when suitable connectivity and map data are available.
3. **Reliable Routing:** Implement packet acknowledgements, retry handling, and duplicate suppression.
4. **Security:** Add message authentication and suitable encryption.
5. **Power Optimization:** Measure energy consumption and optimize battery runtime.
6. **Data Logging:** Store timestamped measurements for later analysis.
7. **Relay Validation:** Compare direct and relay-enabled communication experimentally.
8. **Hardware Integration:** Produce verified circuit diagrams and a documented PCB design if needed.
9. **User Interface:** Add message history and clearer node-status indicators.
10. **Field Evaluation:** Conduct controlled tests after safety and regulatory reviews.

## 🛡️ Safety and Regulatory Considerations

This project is an experimental prototype.

Before any outdoor or elevated deployment:

- Check applicable radio regulations and permitted operating parameters.
- Verify the radio module's supported frequency and antenna requirements.
- Assess balloon tethering, wind, weather, payload weight, and recovery arrangements.
- Check applicable aviation and local permissions.
- Protect batteries against short circuits, overheating, and mechanical damage.
- Keep the system away from people and infrastructure where it could create a hazard.
- Do not transmit sensitive personal information in unsecured demonstration packets.
- Do not use the prototype as a substitute for certified emergency communications.

Any balloon deployment must undergo an appropriate safety and regulatory review before being attempted.

## 🎥 Project Demonstration

The repository contains project images and supplied demonstration videos under:

- `media/images/`
- `media/videos/`

These files can be used to document the prototype and dashboard.

Before publishing, confirm that the media may be shared publicly and add captions explaining what each photograph or video actually demonstrates.

### Suggested demonstration sequence

1. Introduce the problem of communication loss during emergencies.
2. Present the user node and relay hardware.
3. Explain the LoRa communication path.
4. Demonstrate a controlled message transmission.
5. Show received telemetry in the ground station.
6. Explain the dashboard's demo and live-data distinctions.
7. Present measured results, limitations, and future improvements.

## 🔬 Research and Development

ZONEZAP can support research into resilient wireless communication by providing a test platform for studying:

- Packet delivery under different distances and obstructions.
- Relay-assisted versus direct communication.
- RSSI and SNR trends.
- Message latency and packet loss.
- Recovery after node resets or temporary link failures.
- Battery consumption under different traffic patterns.
- Telemetry visualization and logging.

A useful experimental report should document the hardware, firmware revision, radio settings, antenna details, test environment, sample size, and measurement method.

Research claims should be supported by collected data and repeatable tests.

## 🤝 Contributing

Contributions that improve the documentation, firmware, dashboard, test procedures, and hardware integration are welcome.

1. Fork the repository.
2. Create a feature branch.
3. Describe the proposed change.
4. Test the change on the target hardware or browser.
5. Document the test conditions and results.
6. Submit a pull request.

Please avoid committing credentials, private telemetry, or unsupported performance claims.

See `CONTRIBUTING.md` for additional guidance.

## 📄 License

The code and documentation are provided under the MIT License, subject to the terms in `LICENSE`.

Project images, logos, and videos may have separate ownership or usage restrictions. Obtain permission before redistributing them if necessary.

## 🙏 Acknowledgements

This project brings together embedded systems, LoRa wireless communication, telemetry monitoring, and disaster-management concepts.

Thanks to everyone who contributes to its development, testing, documentation, and improvement.

---

<p align="center">
  <b>ZONEZAP — DEAD ZONE KILLER (DZK-1)</b><br>
  <i>Exploring resilient communication when conventional networks are unavailable.</i>
</p>
