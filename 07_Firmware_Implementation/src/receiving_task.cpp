#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "receiving_task.h"

#define ANALYZER_VID   0x0483
#define ANALYZER_PID   0x5740
#define ANALYZER_BAUD  115200

EspUsbHost usb;
EspUsbHostCdcSerial CdcSerial(usb);

char receiveBuffer[500];
uint16_t bufferIndex = 0;
uint8_t receivedByte;
bool packetComplete = false;

void ReceivingTask(void *pvParameters)
{
    usb.onDeviceConnected(onAnalyzerConnected);
    usb.onDeviceDisconnected(onAnalyzerDisconnected);

    if (!usb.begin())
    {
        Serial.println("USB Host Initialization Failed");
        vTaskDelete(NULL);
    }

    CdcSerial.begin(ANALYZER_BAUD);

    uint32_t lastByteTime = 0;

    while (1)
    {
        if (CdcSerial.connected())
        {
            while (CdcSerial.available())
            {
                receivedByte = (uint8_t)CdcSerial.read();

                lastByteTime = millis();

                if (bufferIndex < sizeof(receiveBuffer) - 1)
                {
                    receiveBuffer[bufferIndex++] = receivedByte;
                }

                if (receivedByte == '^')
                {
                    packetComplete = true;
                    break;
                }
            }
        }

        /* Smart Flush (300 ms timeout) */
        if (!packetComplete &&
            bufferIndex > 0 &&
            (millis() - lastByteTime) > 300)
        {
            if (bufferIndex < sizeof(receiveBuffer) - 1)
            {
                receiveBuffer[bufferIndex++] = '^';
            }

            packetComplete = true;

            Serial.println("Synthetic '^' Added");
        }

        if (packetComplete)
        {
            DataPacket packet;

            memset(&packet, 0, sizeof(DataPacket));

            memcpy(packet.data,
                   receiveBuffer,
                   bufferIndex);

            packet.length = bufferIndex;

            xQueueSend(receiveQueue,
                       &packet,
                       portMAX_DELAY);

            memset(receiveBuffer,
                   0,
                   sizeof(receiveBuffer));

            bufferIndex = 0;

            packetComplete = false;
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}