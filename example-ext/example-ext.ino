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
        uint32_t count = 0;
        YtDataLink::getResult(message, &count, {VS_MODEL_FACE_DETECTION});

        for (int i = 0; i < min(1, (int)count); i ++)
        {
            YtVisionSeedResultTypeRect rect;
            YtVisionSeedResultTypePoints points = {.count = 0, .p = 0};
            YtVisionSeedResultTypeArray pose = {.count =0, .p = 0};

            // 获取检测框（模型ID路径：人脸检测/index）
            if (!YtDataLink::getResult(message, &rect, {VS_MODEL_FACE_DETECTION, i}))
            {
                continue;
            }
            // 获取人脸姿态（模型ID路径：人脸检测/index/人脸姿态）
            if (!YtDataLink::getResult(message, &pose, {VS_MODEL_FACE_DETECTION, i, VS_MODEL_FACE_POSE}))
            {
                continue;
            }
            // 获取人脸关键点定位结果（模型ID路径：人脸检测/index/人脸配准）
            if (!YtDataLink::getResult(message, &points, {VS_MODEL_FACE_DETECTION, i, VS_MODEL_FACE_LANDMARK}))
            {
                continue;
            }

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
