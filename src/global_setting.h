#ifndef _GLOBAL_SETTING_H_
#define _GLOBAL_SETTING_H_

#include <M5EPD.h>
#include <nvs.h>

#define WALLPAPER_NUM 3
#define OS_Version "GoldyOSV6.0.2"
#define Robot_Name "GoldyDogV7.8"

// 是否开启自动关机省电
#define ENABLE_AUTO_POWER_SAVE true

// 1 minute reminder to shut down
static const uint32_t TIME_BEFORE_SHUTDOWN_PROMPT_MS = 60 * 1000;
// Show shutdown prompt for 60 seconds
static const uint32_t SHUTDOWN_PROMPT_DELAY_MS = 60 * 1000;
// 最终关机时间
static const uint32_t TIME_BEFORE_SHUTDOWN_MS =
    TIME_BEFORE_SHUTDOWN_PROMPT_MS + SHUTDOWN_PROMPT_DELAY_MS;

enum {
    LANGUAGE_EN = 0  // default, English
};

void SetLanguage(uint8_t language);
uint8_t GetLanguage(void);
void SetWallpaper(uint16_t wallpaper_id);
uint16_t GetWallpaperID(void);
const uint8_t* GetWallpaper(void);
const char* GetWallpaperName(uint16_t wallpaper_id);

esp_err_t LoadSetting(void);
esp_err_t SaveSetting(void);
void SetWifi(String ssid, String password);
String GetWifiSSID(void);
String GetWifiPassword(void);
uint8_t isWiFiConfiged(void);
bool SyncNTPTime(void);
int8_t GetTimeZone(void);
void SetTimeZone(int8_t time_zone);

uint16_t GetTextSize();
void SetTextSize(uint16_t size);

const uint8_t* GetLoadingIMG_32x32(uint8_t id);
void LoadingAnime_32x32_Start(uint16_t x, uint16_t y);
void LoadingAnime_32x32_Stop();

uint8_t isTimeSynced(void);
void SetTimeSynced(uint8_t val);

void SetTTFLoaded(uint8_t val);
uint8_t isTTFLoaded(void);
void SetInitStatus(uint8_t idx, uint8_t val);
uint8_t GetInitStatus(uint8_t idx);
void Shutdown();

#endif  //_GLOBAL_SETTING_H_