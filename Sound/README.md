** Sound Routines for M5Stack Core2 using internal speaker **  
** Based on the M5Stack Atom Speaker code **
   
This directory is for VS Code, running Platform IO Extension  
  
Src/main.cpp = Test Application  
   Place this in the PlatformIO Src directory  
   
Lib/Core2_Sounds/  
  Core2_Sounds.h
   Core2_Sounds.c
  Place these files in your platformIO Lib directory under a folder named "Core2_Sounds"
  
The library exposes two routines,


========================================================================================  
  @brief Plays a PCM sound array through the Core2's internal speaker.
  
  @param snd       The sound array[] to play
  @param size      The size of the sound array in bytes (i.e. sizeof(snd))
  @return int32_t  
       CORE2_SOUNDS_OK                             Success             
       CORE2_SOUNDS_I2S_WRITE_ERROR                Error
       CORE2_SOUNDS_I2S_DID_NOT_WRITE_ALL_BYTES    Error   
  
  @example int32_t err = soundsPlay(beepLong, sizeof(beepLong));
 
extern int32_t soundsPlay(const unsigned char *snd, size_t size);
========================================================================================  

========================================================================================  
  @brief Plays a specified beep through internal Core2 Speaker
  
  @param freqHz    Frequency in Hz, Range: 1000 to 5000 Hz
  @param timeMs    Time duration in mSec, Range: 100 to 1000 mSec
  @param volume    Volume level in %, Range: 0 to 100%
  @return int32_t 
       CORE2_SOUNDS_OK                             Success             
       CORE2_SOUNDS_MEMORY_ALLOC_ERROR             Error   
       CORE2_SOUNDS_I2S_WRITE_ERROR                Error
       CORE2_SOUNDS_I2S_DID_NOT_WRITE_ALL_BYTES    Error   
  
  @example int32_t err = soundsBeep(2000, 100, 5);
           Play 2000 Hz, 100 mSec, 5% volume
 
extern int32_t soundsBeep(uint16_t freqHz, uint16_t timeMs, uint8_t volume);
========================================================================================  

