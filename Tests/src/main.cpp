#include <Arduino.h>
#include <Esp.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("Flash Chip Info");
}

void loop() {
  uint32_t realSize = ESP.getFlashChipSize();
  uint32_t ideSize = ESP.getFlashChipSize();
  FlashMode_t ideMode = ESP.getFlashChipMode();
  Serial.printf("Flash real size: %u bytes\n", realSize);
  Serial.printf("Flash ide size: %u bytes\n", ideSize);
  Serial.printf("Flash ide speed: %u Hz\n", ESP.getFlashChipSpeed());
  Serial.printf("Flash ide mode: %s\n\n", 
    (ideMode == FM_QIO ? "QIO" :
    ideMode == FM_QOUT ? "QOUT" :
    ideMode == FM_DIO ? "DIO" :
    ideMode == FM_DOUT ? "DOUT" :
    ideMode == FM_FAST_READ ? "FAST_READ" :
    ideMode == FM_SLOW_READ ? "SLOW_READ" :
    "UNKNOWN"));
}
