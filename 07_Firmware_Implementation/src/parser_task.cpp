#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "parser_task.h"

void ParserTask(void *pvParameters)
{
    while (1)
    {
        
        vTaskDelay(1); 
    }
}
