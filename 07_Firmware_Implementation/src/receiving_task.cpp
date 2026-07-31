#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "receiving_task.h"

void ReceivingTask(void *pvParameters)
{
    while (1)
    {
        
        vTaskDelay(1); 
    }
}
