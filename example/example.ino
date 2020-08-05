//author: chenliang @ Youtu Lab, Tencent
#include <DataLinkArduino.h>
#include <pb_decode.h>
#include <math.h>

#define LED_OK 13

YtDataLink dl(new YtSerialPortArduino(&Serial));

float distance(YtVisionSeedResultTypePoints::Point &a, YtVisionSeedResultTypePoints::Point &b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

void setup()
{
    pinMode(LED_OK, OUTPUT);
    digitalWrite(LED_OK, LOW);
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
            if (points.count == 90)
            {
                #define IDX_MOUTH 45
                openess = distance(points.p[IDX_MOUTH + 14], points.p[IDX_MOUTH + 19]) / distance(points.p[IDX_MOUTH + 0], points.p[IDX_MOUTH + 6]) * 10;
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
