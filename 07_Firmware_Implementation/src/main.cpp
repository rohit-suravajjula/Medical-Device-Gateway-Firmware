#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

/* Queue Handles */
QueueHandle_t receiveQueue;
QueueHandle_t parserQueue;
QueueHandle_t transmitQueue;

void setup()
{
    Serial.begin(115200);

    Serial.println("================================");
    Serial.println(" Medical Device Gateway Firmware");
    Serial.println(" System Booting...");
    Serial.println("================================");
}

void loop()
{

}