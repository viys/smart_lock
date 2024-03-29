/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-8-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "app.h"
#include "drv_gpio.h"
#include "drv_ntp.h"
#include "mqtt_client.h"
#include "transceiver.h"

osThreadId_t ThreadI_DT;   // 线程ID标识
osThreadAttr_t THREAD_CFG; // 线程配置结构体

/* 定时器 */
osTimerId_t HeartBeat_Timer = NULL;

/* 串口信号量 */
osSemaphoreId_t u0_uart_sem = NULL;
osSemaphoreId_t button_sem = NULL;
osMessageQueueId_t button_click_queue = NULL;
osMessageQueueId_t transceiver_queue = NULL;
osMessageQueueId_t mqtt_send_queue = NULL;
osMessageQueueId_t mqtt_recv_queue = NULL;

TRANSCEIVER* Transceiver = NULL;
TRANSCEIVER_IMPLEMENTS* phone = NULL;

MQTTCLIENT* MqttClient = NULL;
MQTTCLIENT_IMPLEMENTS* mqtt = NULL;

int cm_opencpu_entry(char *param)
{
	uart_open(CM_UART_DEV_0, 921600, u0_callback);
	u0_printf("ML307A Start\r\n");

	my_run_io_init();
	my_run_io_sw(1);

    Transceiver = TRANSCEIVER_CTOR();
    phone = (TRANSCEIVER_IMPLEMENTS*)Transceiver;

    MqttClient = MQTTCLIENT_CTOR();
	mqtt = (MQTTCLIENT_IMPLEMENTS*)MqttClient;
	
	/* 创建进程 */
	// osThreadCreat("dbg_th", dbg_th, 4, 1024*4);

	/* 创建Button进程 */
	osThreadCreat("click", Button_Click_Thread, 7, 1024);

	// /* 创建Transceiver进程 */
	osThreadCreat("Transceiver", Transceiver_Thread, 6, 1024*4);

	// /* 创建Transceiver进程 */
	osThreadCreat("mqtt_client", MQTT_Client_Thread, 5, 1024*4);
	osThreadCreat("mqtt_rcv_handle", MQTT_RECV_Handle, 6, 1024*4);

	// HeartBeat_Timer = osTimerCreat("HeartBeat",Heart_Beat_Timer,osTimerPeriodic);
	
	return 0;
}
