/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "OLED.h"
#include <cstdio>
#include "OLED_Data.h" 
#include "OLED_font.h" 
char Date[]="Today:";
int main()
{
    OLED_Init();
    while(1)
    {
        //get time now
        time_t seconds = time(NULL)+55200;
        struct tm *now = localtime(&seconds);

        int year = now->tm_year + 1900;
        int month = now->tm_mon + 1;
        int day = now->tm_mday;

        char timeBuffer[9];
        char dateBuffer[11];
        strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", now);
        snprintf(dateBuffer, sizeof(dateBuffer), "%04d-%02d-%02d", year, month, day);

        OLED_Clear();
        OLED_ShowString(1, 1, Date,1);
        OLED_ShowString(2, 4, dateBuffer,1);
        OLED_ShowString(3, 4, timeBuffer,1);

        //Wait for 1s
        ThisThread::sleep_for(1000ms);
    }
}
