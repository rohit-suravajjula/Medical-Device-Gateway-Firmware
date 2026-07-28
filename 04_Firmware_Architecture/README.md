# Firmware Architecture

## Goal

Organize the firmware into layers to make it modular and easy to maintain.

## Firmware Architecture

```text
Application Layer
      |
      ▼
Service Layer
      |
      ▼
     HAL
      |
      ▼
Driver Layer
      |
      ▼
Hardware
```

## Layer Description

### Application Layer
- Controls the firmware logic.
- Decides what action should be performed.

### Service Layer
- Coordinates firmware modules.
- Provides services to the Application Layer.

### HAL
- Hides hardware-specific details.
- Provides a common interface to the Service Layer.

### Driver Layer
- Directly controls hardware peripherals.
- Communicates with the hardware.

### Hardware
- Physical devices such as STM32, USB, UART and Wi-Fi.

## Module Mapping

```text
Application Layer
    └── Firmware Control

Service Layer
    ├── Receiving Module
    ├── Parser Module
    ├── Transmit Module
    └── Network Module

HAL
    └── Hardware Interface

Driver Layer
    ├── USB Driver
    ├── UART Driver
    └── Wi-Fi Driver
```