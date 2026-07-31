#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "transmit_task.h"

void TransmitTask(void *pvParameters)
{
    while (1)
    {
        
        vTaskDelay(1); 
    }
}
