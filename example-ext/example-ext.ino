//author: chenliang @ Youtu Lab, Tencent
#include <DataLinkArduino.h>
#include <YtFaceAlignment.h>
#include <pb_decode.h>
#include <math.h>

#define LED_OK 13

#if defined(ARDUINO_ARCH_STM32)
YtDataLink dl(new YtSerialPortArduino(&Serial2));
#elif defined(ARDUINO_ARCH_ESP32)
YtDataLink dl(new YtSerialPortArduino(&Serial1));
#endif
YtFaceShape shape;

void setup()
{
    pinMode(LED_OK, OUTPUT);
    digitalWrite(LED_OK, LOW);

    //初始化调试信息输出端口
#if defined(ARDUINO_ARCH_STM32)
    Serial1.begin(115200);
#elif defined(ARDUINO_ARCH_ESP32)
    Serial.begin(115200);
#endif
}

bool lightup = false;
void loop()
{
    const uint8_t *message = dl.recvRunOnce();
    if (message)
    {
        uint8_t vs_path[3] = {VS_MODEL_FACE_DETECTION};
        uint32_t count = 0;
        YtDataLink::getResult(message, &count, vs_path, 1);

        for (int i = 0; i < min(1, (int)count); i ++)
        {
            YtVisionSeedResultTypeRect rect;
            YtVisionSeedResultTypeString faceName = {.conf = 0, .p = 0};
            YtVisionSeedResultTypePoints points = {.count =0, .p = 0};
            YtVisionSeedResultTypeArray pose = {.count =0, .p = 0};

            vs_path[1] = i;
            if (!YtDataLink::getResult(message, &rect, vs_path, 2))
            {
                continue;
            }
            vs_path[2] = VS_MODEL_FACE_LANDMARK;
            if (!YtDataLink::getResult(message, &points, vs_path, 3))
            {
                continue;
            }
            vs_path[2] = VS_MODEL_FACE_POSE;
            if (!YtDataLink::getResult(message, &pose, vs_path, 3))
            {
                continue;
            }
            vs_path[2] = VS_MODEL_FACE_RECOGNITION;
            YtDataLink::getResult(message, &faceName, vs_path, 3);

            float openess = 0;
            if (GetYtFaceShape(points, shape))
            {
                openess = cv::norm(shape.mouth[14] - shape.mouth[19]) / cv::norm(shape.mouth[0] - shape.mouth[6]) * 10;
            }

            int yaw = pose.p[1];
            if (abs(yaw) < 30)
            {
                lightup = (openess > 2);
                LOG_E("openess: %d yaw: %d\n", (int)(openess), yaw);
            }
        }
        digitalWrite(LED_OK, lightup ? HIGH : LOW);
    }
}
