# Firmware Boundary

## Goal

Define firmware responsibility and divide firmware functions into separate modules.

## Firmware Boundary

```text
Medical Machine
      |
      ▼
   Firmware
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
Transmit Module
      |
      ▼
Network Module
```

## Responsibilities

### Receiving Module
- Receives data from the medical machine.
- Collects incoming data.
- Detects complete data frames.

### Parser Module
- Converts raw data into a structured format.
- Extracts required information.

### Transmit Module
- Forwards parsed data to the Network Module.

### Network Module
- Sends data to the external system.
- Handles network communication.