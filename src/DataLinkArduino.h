//author: chenliang @ Youtu Lab, Tencent
#ifndef YT_DATALINKARDUINO_H
#define YT_DATALINKARDUINO_H

#include "DataLink.h"

#define VSRPC(vs_request, vs_func, vs_params)   \
    YtMsg vs_request = YtMsg_init_default;   \
    vs_request.which_values = YtMsg_rpc_tag; \
    vs_request.values.rpc.func = VSPRC_FUNC_TYPE(vs_func); \
    vs_request.values.rpc.which_params = VSPRC_PARAM_TAG(vs_params);

class YtSerialPortArduino : public YtSerialPortBase
{
protected:
    HardwareSerial *serial;
public:
    YtSerialPortArduino(HardwareSerial *_serial);
    virtual ~YtSerialPortArduino();
    virtual bool isOpen();
    virtual int open();
    virtual int close();
    virtual int read(void *buffer, size_t len);
    virtual int write(void *buffer, size_t len);
};

#endif
