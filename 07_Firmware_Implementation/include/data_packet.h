#ifndef DATA_PACKET_H
#define DATA_PACKET_H
#define MAX_PACKET_SIZE 500

typedef struct 
{
    char data[MAX_PACKET_SIZE];
    uint16_t length;
} DataPacket;

#endif