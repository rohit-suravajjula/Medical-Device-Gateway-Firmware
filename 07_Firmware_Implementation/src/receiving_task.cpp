#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "receiving_task.h"

char receiveBuffer[500];
uint16_t bufferIndex = 0;
uint8_t receivedByte;
bool packetComplete = false;

void ReceivingTask(void *pvParameters)
{
    while (1)
    {
        
        vTaskDelay(1); 
    }
}
