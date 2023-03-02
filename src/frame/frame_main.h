#ifndef _FRAME_MAIN_H_
#define _FRAME_MAIN_H_

#include "frame_base.h"

#define NUM_Keys 16

#define NUM_Rows 4
#define NUM_Cols 4

class Frame_Main : public Frame_Base {
   public:
    Frame_Main();
    ~Frame_Main();
    int run();
    int init(epdgui_args_vector_t &args);
    void StatusBar(m5epd_update_mode_t mode);
    void AppName(m5epd_update_mode_t mode);

   private:
    EPDGUI_Button *_key[NUM_Keys];
    M5EPD_Canvas *_bar;
    M5EPD_Canvas *_names;
    uint32_t _next_update_time;
    uint32_t _time;
};

#endif  //_FRAME_MAIN_H_