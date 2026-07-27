# System Architecture

## Goal

Understand the complete system before writing the firmware.

## Architecture
```text
Medical Machine
      |
      ▼
  Firmware
      |
      ▼
Communication
      |
      ▼
PC Software
      |
      ▼
User Interface
```
## Responsibilities

### Medical Machine
- Generates patient data.

### Embedded Firmware
- Receives the data.
- Processes the data.
- Sends the data.

### Communication
- Transfers data between the firmware and the computer.

### PC Software
- Receives the data.
- Creates the patient report.

### User Interface
- Displays the patient report.