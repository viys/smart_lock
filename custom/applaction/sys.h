#pragma once

/* UART资源 */
#define LOG_UART            CM_UART_DEV_0   //日志输出串口
#define FP_UART             CM_UART_DEV_1   //指纹交互串口

/* GPIO资源 */
#define LIGHT_NET_GPIO_NUM  CM_GPIO_NUM_0   //网络指示灯
#define LIGHT_NET_GPIO_PIN  CM_IOMUX_PIN_16
#define LIGHT_NET_ON        CM_GPIO_LEVEL_HIGH
#define LIGHT_NET_OFF       CM_GPIO_LEVEL_LOW

#define BUTTON_GPIO_NUM     CM_GPIO_NUM_13  //门铃按钮
#define BUTTON_GPIO_PIN     CM_IOMUX_PIN_77
#define LIGHT_NET_ENABLE    CM_GPIO_LEVEL_HIGH
#define LIGHT_NET_DISABLE   CM_GPIO_LEVEL_LOW

#define AUDIO_EN_GPIO_NUM   CM_GPIO_NUM_4   //音频使能io
#define AUDIO_EN_GPIO_PIN   CM_IOMUX_PIN_51

#define HALL_EN_GPIO_NUM    CM_GPIO_NUM_20  //霍尔使能io
#define HALL_EN_GPIO_PIN    CM_IOMUX_PIN_86

#define HALL1_GPIO_NUM      CM_GPIO_NUM_17  //Hall1
#define HALL1_GPIO_PIN      CM_IOMUX_PIN_83

#define HALL2_GPIO_NUM      CM_GPIO_NUM_21  //Hall2
#define HALL2_GPIO_PIN      CM_IOMUX_PIN_87

#define HALL3_GPIO_NUM      CM_GPIO_NUM_1   //Hall3
#define HALL3_GPIO_PIN      CM_IOMUX_PIN_25

#define HALL_ON             CM_GPIO_LEVEL_LOW
#define HALL_OFF            CM_GPIO_LEVEL_HIGH

#define FP_EN_GPIO_NUM      CM_GPIO_NUM_3   //指纹使能io
#define FP_EN_GPIO_PIN      CM_IOMUX_PIN_50
#define FP_EN_ENABLE        CM_GPIO_LEVEL_HIGH
#define FP_EN_DISABLE       CM_GPIO_LEVEL_LOW

#define FP_INT_GPIO_NUM     CM_GPIO_NUM_14  //指纹触摸io
#define FP_INT_GPIO_PIN     CM_IOMUX_PIN_78

#define MOTOR_IN0_GPIO_NUM  CM_GPIO_NUM_19  //电机IN0
#define MOTOR_IN0_GPIO_PIN  CM_IOMUX_PIN_85

#define MOTOR_IN1_GPIO_NUM  CM_GPIO_NUM_18  //电机IN1
#define MOTOR_IN1_GPIO_PIN  CM_IOMUX_PIN_84

#define MOTOR_IN2_GPIO_NUM  CM_GPIO_NUM_2   //电机IN2
#define MOTOR_IN2_GPIO_PIN  CM_IOMUX_PIN_49

#define MOTOR_INT_ON         CM_GPIO_LEVEL_HIGH
#define MOTOR_INT_OFF        CM_GPIO_LEVEL_LOW

/* ADC资源 */
#define BATE_ADC            CM_ADC_0        //电池ADC



