#include "clock.h"
#include <Wire.h>
#include <RtcDS3231.h>

RtcDS3231<TwoWire> Rtc(Wire);

void printDateTime(const RtcDateTime& dt)
{
    char datestring[26];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
}

void clock_init(void){
    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

    if (!Rtc.IsDateTimeValid()){
        Rtc.SetDateTime(compiled);
    }

    if (!Rtc.GetIsRunning()){
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled){
        Rtc.SetDateTime(compiled);
    }
}

void clock_print_date_time(void){
    RtcDateTime now = Rtc.GetDateTime();
    printDateTime(now);
    Serial.println();
}