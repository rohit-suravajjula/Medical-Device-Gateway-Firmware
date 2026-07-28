# RTOS Architecture

## Goal

Design a modular RTOS architecture that separates the firmware into independent tasks communicating through queues.

## RTOS Architecture

```text
Medical Machine
        │
        ▼
Receiving Task
        │
        ▼
Receive Queue
        │
        ▼
Parser Task
        │
        ▼
Parser Queue
        │
        ▼
Transmit Task
        │
        ▼
Transmit Queue
        │
        ▼
Network Task
        │
        ▼
Python TCP Server
        │
        ▼
Streamlit UI
```

## Task Responsibilities

### Receiving Task
- Receives raw data from the medical machine.
- Detects complete data frames.
- Sends complete frames to the Receive Queue.

### Parser Task
- Reads data from the Receive Queue.
- Converts raw machine data into a structured format.
- Sends parsed data to the Parser Queue.

### Transmit Task
- Reads parsed data from the Parser Queue.
- Forwards data to the Transmit Queue.

### Network Task
- Reads data from the Transmit Queue.
- Manages WiFi and TCP communication.
- Sends data to the Python TCP Server.
- Handles network reconnection.

## Queue Communication

- Receive Queue → Receiving Task to Parser Task
- Parser Queue → Parser Task to Transmit Task
- Transmit Queue → Transmit Task to Network Task

## Task Priority

| Priority | Task |
|----------|------|
| Highest | Receiving Task |
| High | Parser Task |
| Medium | Transmit Task |
| Lowest | Network Task |

## Design Principles

- Single responsibility for each task.
- Queue-based task communication.
- Modular firmware architecture.
- Hardware-independent communication.
- Automatic network recovery.