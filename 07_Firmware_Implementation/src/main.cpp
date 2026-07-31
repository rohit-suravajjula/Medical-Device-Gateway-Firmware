#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "data_packet.h"

#include "receiving_task.h"
#include "parser_task.h"
#include "transmit_task.h"
#include "parser_task.h"
#include "transmit_task.h"
#include "network_task.h"

/* Queue Handles */
QueueHandle_t receiveQueue;
QueueHandle_t parserQueue;
QueueHandle_t transmitQueue;

/* Task Handles */
TaskHandle_t receivingTaskHandle;
TaskHandle_t parserTaskHandle;
TaskHandle_t transmitTaskHandle;
TaskHandle_t networkTaskHandle;

void setup()
{
    Serial.begin(115200);

    Serial.println("================================");
    Serial.println(" Medical Device Gateway Firmware");
    Serial.println(" System Booting...");
    Serial.println("================================");

/**************************************************************************
 * Create Receive Queue
 *************************************************************************/
receiveQueue = xQueueCreate(500, sizeof(uint8_t));

/**************************************************************************
 * Create Parser Queue
 *************************************************************************/
 parserQueue = xQueueCreate(10, sizeof(DataPacket));

 /*************************************************************************
  * Create Transmit Queue
 *************************************************************************/
 transmitQueue = xQueueCreate(10, sizeof(DataPacket));

 /*************************************************************************
  * Create Receiving Task
 *************************************************************************/ 
xTaskCreate(
    ReceivingTask,
    "ReceivingTask",
    4096,
    NULL,
    4,
    &receivingTaskHandle
);
}

void loop()
{

}