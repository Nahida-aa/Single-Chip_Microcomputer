#include <reg52.h>

#include "fw_global.h"
// #include "lcd.h"
// #include "keypad.h"
// #include "delay.h"
// #include "uart.h"

void delay_ms(uint16_f ms){
    uint16_f i, j;
    for(i = 0; i < ms; i++){
        for(j = 0; j < 110; j++);
    }
}

volatile xdata * const test_reg = (volatile uint8_f xdata *)0x0000;

int main(void){
    static uint8_f test_cnt = 0;

    while(1){
        *test_reg = test_cnt;
        test_cnt ++;
        delay_ms(200);
    }
}