#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "parser_task.h"
#include "data_packet.h"

extern QueueHandle_t receiveQueue;
extern QueueHandle_t parserQueue;

void ParserTask(void *pvParameters)
{
    DataPacket receivedPacket;
    DataPacket parsedPacket;

    while (1)
    {
        if (xQueueReceive(receiveQueue, &receivedPacket, portMAX_DELAY) == pdTRUE)
        {
            memset(&parsedPacket, 0, sizeof(DataPacket));

            memcpy(parsedPacket.data,
                   receivedPacket.data,
                   receivedPacket.length);

            parsedPacket.length = receivedPacket.length;

            /* Remove CR/LF characters */
            uint16_t writeIndex = 0;

            for (uint16_t readIndex = 0;
                 readIndex < parsedPacket.length;
                 readIndex++)
            {
                char ch = parsedPacket.data[readIndex];

                if (ch != '\r' && ch != '\n')
                {
                    parsedPacket.data[writeIndex++] = ch;
                }
            }

            parsedPacket.length = writeIndex;

            /* Null terminate */
            if (parsedPacket.length < sizeof(parsedPacket.data))
            {
                parsedPacket.data[parsedPacket.length] = '\0';
            }

            xQueueSend(parserQueue,
                       &parsedPacket,
                       portMAX_DELAY);
        }
    }
}
