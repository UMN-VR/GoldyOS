#include "frame_main.h"
#include "frame_setting.h"
#include "frame_keyboard.h"
#include "frame_factorytest.h"
#include "frame_wifiscan.h"
#include "frame_lifegame.h"
#include "frame_fileindex.h"
#include "frame_compare.h"
#include "frame_home.h"

#include "frame_rCtr.h"
#include "frame_OTA.h"

enum {
    kKeyFactoryTest = 0,
    kKeySetting,
    kKeyKeyboard,
    kKeyWifiScan,
    kKeySDFile,
    kKeyCompare,
    kKeyHome,
    kKeyLifeGame,
    kKeyRobot,
    kKeyWiFiUpdate,
    kKeyTestRemote,
    kKeyDemoMode,
    kKeyShutdown,
    kKeyReboot,
    kKeyM0,
    kKeyM1
};


#define KEY_W 92
#define KEY_H 92

void key_setting_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_Setting");
    if (frame == NULL) {
        frame = new Frame_Setting();
        EPDGUI_AddFrame("Frame_Setting", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_keyboard_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_Keyboard");
    if (frame == NULL) {
        frame = new Frame_Keyboard(0);
        EPDGUI_AddFrame("Frame_Keyboard", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_factorytest_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_FactoryTest");
    if (frame == NULL) {
        frame = new Frame_FactoryTest();
        EPDGUI_AddFrame("Frame_FactoryTest", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_wifiscan_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_WifiScan");
    if (frame == NULL) {
        frame = new Frame_WifiScan();
        EPDGUI_AddFrame("Frame_WifiScan", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_lifegame_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_Lifegame");
    if (frame == NULL) {
        frame = new Frame_Lifegame();
        EPDGUI_AddFrame("Frame_Lifegame", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_sdfile_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = new Frame_FileIndex("/");
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_compare_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_Compare");
    if (frame == NULL) {
        frame = new Frame_Compare();
        EPDGUI_AddFrame("Frame_Compare", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_home_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_Home");
    if (frame == NULL) {
        frame = new Frame_Home();
        EPDGUI_AddFrame("Frame_Home", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_rCtr_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_rCtr");
    if (frame == NULL) {
        frame = new Frame_rCtr();
        EPDGUI_AddFrame("Frame_rCtr", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_ota_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_OTA");
    if (frame == NULL) {
        frame = new Frame_OTA();
        EPDGUI_AddFrame("Frame_OTA", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

Frame_Main::Frame_Main(void) : Frame_Base(false) {
    _frame_name = "Frame_Main";
    _frame_id   = 1;

    _bar = new M5EPD_Canvas(&M5.EPD);
    _bar->createCanvas(790, 44);
    _bar->setTextSize(26);

    _names = new M5EPD_Canvas(&M5.EPD);
    _names->createCanvas(540, 32);
    _names->setTextDatum(CC_DATUM);
    
    //Load App Icon buttons
    for (int i0 = 0; i0 < NUM_Rows; i0++) {
         for (int i = 0; i < NUM_Cols; i++) {
            _key[(4*i0)+i] = new EPDGUI_Button("BTN", 20 + i * 136, 90+(150*i0), KEY_W, KEY_H);
        }
    }


//ROW 0 App Icons

    //key0
    _key[kKeySetting]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_setting_92x92);
    *(_key[kKeySetting]->CanvasPressed()) =
        *(_key[kKeySetting]->CanvasNormal());
    _key[kKeySetting]->CanvasPressed()->ReverseColor();
    _key[kKeySetting]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                               (void *)(&_is_run));
    _key[kKeySetting]->Bind(EPDGUI_Button::EVENT_RELEASED, key_setting_cb);

    //key1
    _key[kKeyKeyboard]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_keyboard_92x92);
    *(_key[kKeyKeyboard]->CanvasPressed()) =
        *(_key[kKeyKeyboard]->CanvasNormal());
    _key[kKeyKeyboard]->CanvasPressed()->ReverseColor();
    _key[kKeyKeyboard]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kKeyKeyboard]->Bind(EPDGUI_Button::EVENT_RELEASED, key_keyboard_cb);

    //key2
    _key[kKeyFactoryTest]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_factorytest_92x92);
    *(_key[kKeyFactoryTest]->CanvasPressed()) =
        *(_key[kKeyFactoryTest]->CanvasNormal());
    _key[kKeyFactoryTest]->CanvasPressed()->ReverseColor();
    _key[kKeyFactoryTest]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                   (void *)(&_is_run));
    _key[kKeyFactoryTest]->Bind(EPDGUI_Button::EVENT_RELEASED,
                                key_factorytest_cb);

    //key3
    _key[kKeyWifiScan]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_wifi_92x92);
    *(_key[kKeyWifiScan]->CanvasPressed()) =
        *(_key[kKeyWifiScan]->CanvasNormal());
    _key[kKeyWifiScan]->CanvasPressed()->ReverseColor();
    _key[kKeyWifiScan]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kKeyWifiScan]->Bind(EPDGUI_Button::EVENT_RELEASED, key_wifiscan_cb);


//ROW 1 App Icons

    //key4
    _key[kKeyLifeGame]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_lifegame_92x92);
    *(_key[kKeyLifeGame]->CanvasPressed()) =
        *(_key[kKeyLifeGame]->CanvasNormal());
    _key[kKeyLifeGame]->CanvasPressed()->ReverseColor();
    _key[kKeyLifeGame]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kKeyLifeGame]->Bind(EPDGUI_Button::EVENT_RELEASED, key_lifegame_cb);

    //key5
    _key[kKeySDFile]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kKeySDFile]->CanvasPressed()) = *(_key[kKeySDFile]->CanvasNormal());
    _key[kKeySDFile]->CanvasPressed()->ReverseColor();
    _key[kKeySDFile]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                              (void *)(&_is_run));
    _key[kKeySDFile]->Bind(EPDGUI_Button::EVENT_RELEASED, key_sdfile_cb);

    //key6
    _key[kKeyCompare]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_compare_92x92);
    *(_key[kKeyCompare]->CanvasPressed()) =
        *(_key[kKeyCompare]->CanvasNormal());
    _key[kKeyCompare]->CanvasPressed()->ReverseColor();
    _key[kKeyCompare]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                               (void *)(&_is_run));
    _key[kKeyCompare]->Bind(EPDGUI_Button::EVENT_RELEASED, key_compare_cb);

    //key7
    _key[kKeyHome]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_home_92x92);
    *(_key[kKeyHome]->CanvasPressed()) = *(_key[kKeyHome]->CanvasNormal());
    _key[kKeyHome]->CanvasPressed()->ReverseColor();
    _key[kKeyHome]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                            (void *)(&_is_run));
    _key[kKeyHome]->Bind(EPDGUI_Button::EVENT_RELEASED, key_home_cb);



//ROW 2 App Icons

    //key8
    _key[kKeyRobot]->CanvasNormal()->pushImage(0, 0, 92, 92, ImageResource_main_rCTR_92x92);
    *(_key[kKeyRobot]->CanvasPressed()) =
        *(_key[kKeyRobot]->CanvasNormal());
    _key[kKeyRobot]->CanvasPressed()->ReverseColor();
    _key[kKeyRobot]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kKeyRobot]->Bind(EPDGUI_Button::EVENT_RELEASED, key_rCtr_cb);

    //key9
    _key[kKeyWiFiUpdate]->CanvasNormal()->pushImage(0, 0, 92, 92, ImageResource_main_ota_92x92);
    *(_key[kKeyWiFiUpdate]->CanvasPressed()) = *(_key[kKeyWiFiUpdate]->CanvasNormal());
    _key[kKeyWiFiUpdate]->CanvasPressed()->ReverseColor();
    _key[kKeyWiFiUpdate]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                              (void *)(&_is_run));
    _key[kKeyWiFiUpdate]->Bind(EPDGUI_Button::EVENT_RELEASED, key_ota_cb);

    //key10
    _key[kKeyTestRemote]->CanvasNormal()->pushImage(0, 0, 92, 92, ImageResource_main_reTest_92x92);
    *(_key[kKeyTestRemote]->CanvasPressed()) =
        *(_key[kKeyTestRemote]->CanvasNormal());
    _key[kKeyTestRemote]->CanvasPressed()->ReverseColor();
    _key[kKeyTestRemote]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                               (void *)(&_is_run));
    _key[kKeyTestRemote]->Bind(EPDGUI_Button::EVENT_RELEASED, key_compare_cb);

    //key11
    _key[kKeyDemoMode]->CanvasNormal()->pushImage(0, 0, 92, 92, ImageResource_home_icon_light_on_92x92);
    *(_key[kKeyDemoMode]->CanvasPressed()) = *(_key[kKeyDemoMode]->CanvasNormal());
    _key[kKeyDemoMode]->CanvasPressed()->ReverseColor();
    _key[kKeyDemoMode]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                            (void *)(&_is_run));
    _key[kKeyDemoMode]->Bind(EPDGUI_Button::EVENT_RELEASED, key_home_cb);


    
//ROW 3 App Icons

    //key12
    _key[kKeyShutdown]->CanvasNormal()->pushImage(0, 0, 92, 92, ImageResource_main_icon_shutdown_92x92);
    *(_key[kKeyShutdown]->CanvasPressed()) =
        *(_key[kKeyShutdown]->CanvasNormal());
    _key[kKeyShutdown]->CanvasPressed()->ReverseColor();
    _key[kKeyShutdown]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kKeyShutdown]->Bind(EPDGUI_Button::EVENT_RELEASED, key_lifegame_cb);

    //key13
    _key[kKeyReboot]->CanvasNormal()->pushImage(0, 0, 92, 92, ImageResource_main_icon_restart_92x92);
    *(_key[kKeyReboot]->CanvasPressed()) = *(_key[kKeyReboot]->CanvasNormal());
    _key[kKeyReboot]->CanvasPressed()->ReverseColor();
    _key[kKeyReboot]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                              (void *)(&_is_run));
    _key[kKeyReboot]->Bind(EPDGUI_Button::EVENT_RELEASED, key_sdfile_cb);

    //key14
    _key[kKeyM0]->CanvasNormal()->pushImage(0, 0, 92, 92, ImageResource_main_icon_todo_92x92);
    *(_key[kKeyM0]->CanvasPressed()) =
        *(_key[kKeyM0]->CanvasNormal());
    _key[kKeyM0]->CanvasPressed()->ReverseColor();
    _key[kKeyM0]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                               (void *)(&_is_run));
    _key[kKeyM0]->Bind(EPDGUI_Button::EVENT_RELEASED, key_compare_cb);

    //key15
    _key[kKeyM1]->CanvasNormal()->pushImage(0, 0, 92, 92, ImageResource_main_icon_todo_92x92);
    *(_key[kKeyM1]->CanvasPressed()) = *(_key[kKeyM1]->CanvasNormal());
    _key[kKeyM1]->CanvasPressed()->ReverseColor();
    _key[kKeyM1]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                            (void *)(&_is_run));
    _key[kKeyM1]->Bind(EPDGUI_Button::EVENT_RELEASED, key_home_cb);




    _time             = 0;
    _next_update_time = 0;
}

Frame_Main::~Frame_Main(void) {
    for (int i = 0; i < NUM_Keys; i++) {
        delete _key[i];
    }
}

void Frame_Main::AppName(m5epd_update_mode_t mode) {

    if (!_names->isRenderExist(20)) {
        _names->createRender(20, 26);
    }

    //ROW 0 App Names
    _names->setTextSize(20);
    _names->fillCanvas(0);
    _names->drawString("WLAN", 20 + 46 + 3 * 136, 16);
    _names->drawString("Test", 20 + 46, 16);
    _names->drawString("Setting", 20 + 46 + 136, 16);
    _names->drawString("Keyboard", 20 + 46 + 2 * 136, 16);
    _names->pushCanvas(0, 186, mode);

    //ROW 1 App Names
    _names->fillCanvas(0);
    _names->drawString("Storage", 20 + 46, 16);
    _names->drawString("Compare", 20 + 46 + 136, 16);
    _names->drawString("Home", 20 + 46 + 2 * 136, 16);
    _names->drawString("LifeGame", 20 + 46 + 3 * 136, 16);
    _names->pushCanvas(0, 337, mode);

    //ROW 2 App Names
    _names->fillCanvas(0);
    _names->drawString("Robot Ctr", 20 + 46, 16);
    _names->drawString("WiFi Update", 20 + 46 + 136, 16);
    _names->drawString("Test Remote", 20 + 46 + 2 * 136, 16);
    _names->drawString("Demo Mode", 20 + 46 + 3 * 136, 16);
    _names->pushCanvas(0, 488, mode);

    //ROW 3 App Names
    _names->fillCanvas(0);
    _names->drawString("Shutdown", 20 + 46, 16);
    _names->drawString("Reboot", 20 + 46 + 136, 16);
    _names->drawString("Tests M0", 20 + 46 + 2 * 136, 16);
    _names->drawString("Tests M1", 20 + 46 + 3 * 136, 16);
    _names->pushCanvas(0, 639, mode);
}

void Frame_Main::StatusBar(m5epd_update_mode_t mode) {
    if ((millis() - _time) < _next_update_time) {
        return;
    }
    char buf[20];
    _bar->fillCanvas(0);
    _bar->drawFastHLine(0, 43, 540, 15);
    _bar->setTextDatum(CL_DATUM);
    _bar->drawString(OS_Version, 10, 27);

    // Battery
    _bar->setTextDatum(CR_DATUM);
    _bar->pushImage(498, 8, 32, 32, ImageResource_status_bar_battery_32x32);
    uint32_t vol = M5.getBatteryVoltage();

    if (vol < 3300) {
        vol = 3300;
    } else if (vol > 4350) {
        vol = 4350;
    }
    float battery = (float)(vol - 3300) / (float)(4350 - 3300);
    if (battery <= 0.01) {
        battery = 0.01;
    }
    if (battery > 1) {
        battery = 1;
    }
    uint8_t px = battery * 25;
    sprintf(buf, "%d%%", (int)(battery * 100));
    _bar->drawString(buf, 498 - 10, 27);
    _bar->fillRect(498 + 3, 8 + 10, px, 13, 15);
    // _bar->pushImage(498, 8, 32, 32, 2,
    // ImageResource_status_bar_battery_charging_32x32);

    // Time
    rtc_time_t time_struct;
    rtc_date_t date_struct;
    M5.RTC.getTime(&time_struct);
    M5.RTC.getDate(&date_struct);
    sprintf(buf, "%2d:%02d", time_struct.hour, time_struct.min);
    _bar->setTextDatum(CC_DATUM);
    _bar->drawString(buf, 270, 27);
    _bar->pushCanvas(0, 0, mode);

    _time             = millis();
    _next_update_time = (60 - time_struct.sec) * 1000;
}

int Frame_Main::init(epdgui_args_vector_t &args) {
    _is_run = 1;

    M5.EPD.Clear();
    M5.EPD.WriteFullGram4bpp(GetWallpaper());
    
    for (int i = 0; i < NUM_Keys; i++) {
        EPDGUI_AddObject(_key[i]);
    }
    _time             = 0;
    _next_update_time = 0;
    StatusBar(UPDATE_MODE_NONE);
    AppName(UPDATE_MODE_NONE);
    return 9;
}

int Frame_Main::run() {
    Frame_Base::run();
    StatusBar(UPDATE_MODE_GL16);
    return 1;
}