#include "drv_audio.h"
#include "drv_uart.h"

#define DBG_NAME "audio"

uint32_t my_audio_init(uint8_t volume, uint8_t gain)
{
    uint32_t ret = 0;
    uint8_t volume_temp = volume;
    uint8_t volume_re = gain;
    /*设置声音大小*/
    ret = cm_audio_play_set_cfg(CM_AUDIO_PLAY_CFG_VOLUME, &volume_temp);
    ret = cm_audio_record_set_cfg(CM_AUDIO_RECORD_CFG_GAIN, &volume_re);
    return ret;
}

//录音回调函数，Demo实现将录音数据存入内存，可供播放，pu8Frames为录音的音频数据，length为该数据的长度
static void __cm_record_cb(cm_audio_record_event_e event, void *param)
{
    /* 通知事件为中断触发，不可阻塞，不可做耗时较长的操作，例如不可使用UART打印log */

    cm_audio_record_data_t *record_data = (cm_audio_record_data_t *)param;

    if (CM_AUDIO_RECORD_EVENT_DATA == event)
    {

    }
}

int my_record_start(void (*record_cb)(cm_audio_record_event_e event, void *param))
{
    int ret = EOF;
    // cm_audio_sample_param_t frame = {.sample_format = CM_AUDIO_SAMPLE_FORMAT_16BIT, .rate = CM_AUDIO_SAMPLE_RATE_8000HZ, .num_channels = CM_AUDIO_SOUND_MONO};
    // ret = cm_audio_recorder_start(CM_AUDIO_RECORD_FORMAT_PCM, &frame, (cm_audio_record_callback_t)__cm_record_cb, "PCM");
    // ret = cm_audio_recorder_start(CM_AUDIO_RECORD_FORMAT_AMRNB_475, NULL, (cm_audio_record_callback_t)__cm_record_cb, "475");
    // ret = cm_audio_recorder_start(CM_AUDIO_RECORD_FORMAT_AMRNB_1220, &MyRecordFrame, (cm_audio_record_callback_t)__cm_record_cb, "1220");
    ret = cm_audio_recorder_start(CM_AUDIO_RECORD_FORMAT_AMRNB_1220, NULL, (cm_audio_record_callback_t)record_cb, "1220");
    return ret;
}

void my_audio_play_stop(void)
{
    cm_audio_player_stop();
}

void my_record_stop(void)
{
    cm_audio_recorder_stop();
}

//播放回调函数
static void __cm_player_process_event(cm_audio_play_event_e event, void *param)
{
    if (event == CM_AUDIO_PLAY_EVENT_FINISHED)                      //判断播放结束
    {   
        /* 通知事件为中断触发，不可阻塞，不可做耗时较长的操作，例如不可使用UART打印log */

    }
}

int my_ringtone_play(const char *path)
{
    int ret = 0;
    ret = cm_audio_play_file(path, CM_AUDIO_PLAY_FORMAT_AMRNB, NULL, __cm_player_process_event, "FILEAMR");
    return ret;
}

int my_ring_play(const char *path, void (*player_callback)(cm_audio_play_event_e event, void *param))
{
    int ret = 0;
    ret = cm_audio_play_file(path, CM_AUDIO_PLAY_FORMAT_AMRNB, NULL, player_callback, "FILEAMR");
    return ret;
}

int my_open_audio_stream(void)
{
    int ret = EOF;
    
    ret = cm_audio_player_stream_open(CM_AUDIO_PLAY_FORMAT_AMRNB, NULL);
    return ret;
}


int my_push_audio_stream(char* data, int size)
{
    int ret = EOF;

    ret = cm_audio_player_stream_push((uint8_t *)data, (uint32_t)size);
    return ret;
}

void my_close_audio_stream(void)
{
    /*关闭音频数据流传输*/
    cm_audio_player_stream_close();
}


