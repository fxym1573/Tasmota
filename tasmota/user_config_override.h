// --------------------------
// 双配网：SoftAP + SmartConfig
// --------------------------
#define WIFI_SMARTCONFIG 1
#define WIFI_SOFT_AP 1

// --------------------------
// 巴法云 MQTT
// --------------------------
#define MQTT_HOST       "bemfa.com"
#define MQTT_PORT       9501
#define MQTT_USER       "64f296db08d24d4e91a14fbf9001b320"
#define MQTT_PASS       "64f296db08d24d4e91a14fbf9001b320"
#define MQTT_TOPIC      "pc001"

// 适配巴法云原生协议
#define MQTT_FULLTOPIC  "%topic%"
#define MQTT_BUTTON_RETAIN 0

// --------------------------
// 硬件模板
// --------------------------
#define MODULE 18
#define USER_TEMPLATE "{\"NAME\":\"PC-CTRL\",\"GPIO\":[0,0,0,0,32,289,0,0,290,291,0,0,225,226,1,0],\"FLAG\":0,\"BASE\":18}"

// --------------------------
// 功能
// --------------------------
#define USE_RULES 1
#define USE_SWITCHES 1
#define USE_OTA 1
#define USE_OTA_FALLBACK 1

#undef USE_RF
#undef USE_IR_REMOTE
#undef USE_DOMOTICZ
#undef USE_HOME_ASSISTANT

// --------------------------
// 【最终完整版规则】
// ON = 开机
// OFF = 关机
// restart = 重启
// upgrade xxx.bin = OTA远程升级
// --------------------------
#define USER_RULE1 \
"ON MQTT#Received=ON DO Backlog Power1 1; Delay 5; Power1 0 ENDON " \
"ON MQTT#Received=OFF DO Backlog Power1 1; Delay 5; Power1 0 ENDON " \
"ON MQTT#Received=restart DO Backlog Power2 1; Delay 5; Power2 0 ENDON " \
"ON System#Boot DO Backlog Delay 2; Power1 %Switch1% ENDON " \
"ON Switch1#State DO Publish %topic% %value% ENDON " \
"ON MQTT#Received~^upgrade DO OTA %value% ENDON "

#define USER_RULE1_ON 1

#define SWITCH_MODE1 1
