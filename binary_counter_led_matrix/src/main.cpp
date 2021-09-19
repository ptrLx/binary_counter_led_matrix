#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 1
#define CLK_PIN 13
#define DATA_PIN 11
#define CS_PIN 3

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
#define DELAYTIME 1000

uint64_t i = 0;

void setup() {
    mx.begin();
    mx.clear();
}

void loop() {
    for (uint8_t col = 0; col < 8; col++) {
        uint8_t bit_sequence = i >> col*8;
        mx.setColumn(col, bit_sequence);
    }
    delay(DELAYTIME);
    i++;
}