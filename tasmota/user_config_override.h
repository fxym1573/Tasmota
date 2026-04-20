// --------------------------
// 双配网：SoftAP + SmartConfig
// --------------------------
#define WIFI_SMARTCONFIG 1
#define WIFI_SOFT_AP 1

// --------------------------
// 巴法云 MQTT
// --------------------------
#define MQTT_HOST       "bemfa.com"
#define MQTT_PORT       1888
#define MQTT_USER       "你的巴法云UID"
#define MQTT_PASS       "你的巴法云UID"
#define MQTT_TOPIC      "pc001"

// 适配巴法云原生协议
#define MQTT_FULLTOPIC  "%topic%"
#define MQTT_BUTTON_RETAIN 0

// --------------------------
// 你的开机卡硬件模板
// --------------------------
#define MODULE 18
#define USER_TEMPLATE "{\"NAME\":\"PC-CTRL\",\"GPIO\":[0,0,0,0,32,288,0,0,296,289,0,0,224,225,1,0],\"FLAG\":0,\"BASE\":18}"

// --------------------------
// 功能开启
// --------------------------
#define USE_RULES 1
#define USE_SWITCHES 1
#define USE_OTA 1

// 关闭无用功能
#undef USE_RF
#undef USE_IR_REMOTE
#undef USE_DOMOTICZ
#undef USE_HOME_ASSISTANT

// --------------------------
// 【核心】巴法云指令规则
// ON   = 开机
// OFF  = 关机
// restart  = 重启
// --------------------------
#define USER_RULE1 \
"ON MQTT#Received=ON DO Backlog Power1 1; Delay 5; Power1 0 ENDON " \
"ON MQTT#Received=OFF DO Backlog Power1 1; Delay 5; Power1 0 ENDON " \
"ON MQTT#Received=restart DO Backlog Power2 1; Delay 5; Power2 0 ENDON " \
"ON System#Boot DO Backlog Delay 2; Power1 %Switch1% ENDON " \
"ON Switch1#State DO Publish %topic% %value% ENDON "

#define USER_RULE1_ON 1

// --------------------------
// 状态检测
// --------------------------
#define SWITCH_MODE1 1
