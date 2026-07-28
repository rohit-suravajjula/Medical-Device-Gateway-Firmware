# Module Design

## Goal

Define the internal modules and responsibilities of each RTOS task.

## Module Design

```text
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
```

## Receiving Task

- Receive data byte by byte.
- Build complete data frames.
- Detect the end marker (^).
- Wait for a short period if the end marker is not received.
- Generate the end marker (^) if required.
- Send the complete data frame to the Receive Queue.

## Receive Queue

- Store complete data frames temporarily.
- Maintain FIFO order.
- Wake up the Parser Task when new data is available.

## Parser Task

- Read data from the Receive Queue.
- Remove unwanted symbols.
- Organize data into a structured format.
- Preserve ^ and ===== END OF DATA =====.
- Send parsed data to the Parser Queue.

## Parser Queue

- Store parsed data temporarily.
- Maintain FIFO order.
- Wake up the Transmit Task when new data is available.

## Transmit Task

- Read the complete data block from the Parser Queue.
- Forward the data without modification.
- Send the complete data block to the Transmit Queue.

## Transmit Queue

- Store the complete data block temporarily.
- Maintain FIFO order.
- Wake up the Network Task when new data is available.

## Network Task

- Read WiFi username and password.
- Connect to the WiFi network.
- Monitor WiFi connection status.
- Obtain and display the assigned IP address.
- Read the complete data block from the Transmit Queue.
- Send the data through the TCP socket to the Python TCP Server.
- Wait for WiFi reconnection if disconnected.
- Reconnect automatically and continue transmitting pending data.

## Design Principles

- Single responsibility for each module.
- Queue-based communication.
- FIFO-based data flow.
- Modular firmware architecture.
- Hardware-independent design.