#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "transmit_task.h"

/*===============================
  Transmit Task
================================*/
void TransmitTask(void *pvParameters)
{
    DataPacket packet;

    while (1)
    {
        if (xQueueReceive(parserQueue, &packet, portMAX_DELAY) == pdTRUE)
        {
            xQueueSend(transmitQueue,
                       &packet,
                       portMAX_DELAY);
        }
    }
}
