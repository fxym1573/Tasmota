// 双配网：SoftAP + SmartConfig 同时开启
#define WIFI_SMARTCONFIG 1
#define WIFI_SOFT_AP 1

// MQTT 巴法云（改成你自己的UID）
#define MQTT_HOST "bemfa.com"
#define MQTT_PORT 1883
#define MQTT_USER "你的巴法云UID"
#define MQTT_PASS "你的巴法云UID"
#define MQTT_TOPIC "pc001"

// 开机卡GPIO定义（和你之前模板一致）
#define MODULE 18 // Generic Module
#define USER_TEMPLATE "{\"NAME\":\"PC-CTRL\",\"GPIO\":[0,0,0,0,32,288,0,0,296,289,0,0,224,225,1,0],\"FLAG\":0,\"BASE\":18}"

// 开启规则、开关、脉冲
#define USE_RULES 1
#define USE_SWITCHES 1
#define USE_PULSES 1

// 关闭无用功能（减小体积）
#undef USE_433
#undef USE_IR_REMOTE
#undef USE_DISPLAY
