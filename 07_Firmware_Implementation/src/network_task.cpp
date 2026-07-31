#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "network_task.h"

/*===============================
  Network Task
================================*/
const char *ssid = "YOUR_WIFI_NAME";
const char *password = "YOUR_WIFI_PASSWORD";

WiFiServer server(80);
WiFiClient client;

void NetworkTask(void *pvParameters)
{
    DataPacket packet;

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(pdMS_TO_TICKS(500));
    }

    Serial.println("WiFi Connected");
    Serial.print("IP Address : ");
    Serial.println(WiFi.localIP());

    server.begin();

    while (1)
    {
        if (!client || !client.connected())
        {
            client = server.available();
        }

        if (xQueueReceive(transmitQueue,
                          &packet,
                          pdMS_TO_TICKS(10)) == pdTRUE)
        {
            if (client && client.connected())
            {
                client.write((uint8_t *)packet.data,
                             packet.length);

                client.flush();
            }
        }

        if (WiFi.status() != WL_CONNECTED)
        {
            WiFi.disconnect();
            WiFi.begin(ssid, password);

            while (WiFi.status() != WL_CONNECTED)
            {
                vTaskDelay(pdMS_TO_TICKS(500));
            }

            server.begin();
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}