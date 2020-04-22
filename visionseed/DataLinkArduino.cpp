//author: chenliang @ Youtu Lab, Tencent

#include <Arduino.h>

#include <pb_encode.h>
#include <pb_decode.h>
#include "YtMsg.pb.h"

#include "DataLink.h"
#include "DataLinkArduino.h"

YtSerialPortArduino::YtSerialPortArduino(HardwareSerial *_serial) : serial(_serial), YtSerialPortBase("")
{
}
YtSerialPortArduino::~YtSerialPortArduino()
{
}

bool YtSerialPortArduino::isOpen()
{
    return mPortFd >= 0;
}
int YtSerialPortArduino::open()
{
    serial->begin(115200);
    mPortFd = 0;
    return 1;
}
int YtSerialPortArduino::close()
{
    mPortFd = -1;
    return 1;
}
int YtSerialPortArduino::read(void *buffer, size_t len)
{
    size_t p = 0;
    while (serial->available() > 0 && p < len)
    {
        ((uint8_t*)buffer)[p ++] = (uint8_t)(serial->read());
    }
    return p;
}
int YtSerialPortArduino::write(void *buffer, size_t len)
{
#if defined(ARDUINO_ARCH_STM32)
    return serial->write((const uint8 *)buffer, len);
#elif defined(ARDUINO_ARCH_ESP32)
    return serial->write((const uint8_t *)buffer, len);
#else
    return serial->write((const char *)buffer, len);
#endif
}

#include <stdarg.h>
#include <Arduino.h>

void vkprintf(const char *fmt, ...)
{
#define VKLOGBUFFER 64
#if defined(ARDUINO_ARCH_STM32)
    #define VKLOGPORT Serial2
#else
    #define VKLOGPORT Serial
#endif
    char temp[VKLOGBUFFER+1];
    va_list args;
    va_start(args, fmt);
    vsnprintf(temp, VKLOGBUFFER, fmt, args );
    va_end(args);

    VKLOGPORT.print(temp);
}
