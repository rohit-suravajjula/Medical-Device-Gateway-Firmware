# Firmware Boundary

## Goal

Define firmware responsibility and divide firmware functions into separate modules.

## Firmware Boundary

```text
Medical Machine
      | 
      ▼ 
ESP32 Firmware
      |
      ▼
External System
```
## Firmware Flow

```text
Receiving Module
      |
      ▼
Parser Module
      |
      ▼
Validation Module
      |
      ▼
Transmit Module
```
## Responsibilities

### Receiving Module
- Receives data from the medical machine.
- Collects incoming data.

### Parser Module
- Converts raw data into meaningful data.
- Extracts required information.

### Validation Module
- Checks data correctness.
- Verifies received data.

### Transmit Module
- Sends processed data to the external system.