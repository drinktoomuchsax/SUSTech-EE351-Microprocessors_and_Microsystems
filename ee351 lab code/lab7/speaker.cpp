#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define sig 0

int main(void){
    wiringPiSetup();	
    pinMode(sig,PWM_OUTPUT);
    int freq = 0;
    pwmSetRange(1024);              // pwm脉宽范围 0~1024
    pwmSetClock(75);                // 250Hz，19.2MHz / 75 / 1024 = 250Hz
    while(1)
    {
        for(freq; freq <= 1024; freq++)
        {
            printf("%d\n",freq);
            pwmWrite(sig,freq);
            sleep(2);//in seconds
        }

    }
    return 0;

}
