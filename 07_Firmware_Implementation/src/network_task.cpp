#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "network_task.h"

void NetworkTask(void *pvParameters)
{
    while (1)
    {
        
        vTaskDelay(1); 
    }
}
