#include <wiringPi.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <unistd.h>

#define trigger 28
#define echo 26
#define usSpeed 342

int main(void){
    while (true)
    {
        // setup
        wiringPiSetup () ;
        pinMode(trigger,OUTPUT);
        pinMode(echo,INPUT);
        digitalWrite(trigger,LOW);
        digitalWrite(trigger,HIGH);
        sleep(0.0001);//in microseconds
        digitalWrite(trigger,LOW);
        // distance
        while (true)
        {
            if(digitalRead(echo) == 1)
                break;
        }
        const clock_t begin = clock();
        while (true)
        {
            if(digitalRead(echo) == 0)
                break;
        }
        const clock_t end = clock();
        // ultrasound speed = 342 m/s
        float distance = ((end - begin)/1000)*usSpeed;
        if (distance < 1)
        {
            printf("the distance is: %.30f cm\n", distance*100);      
        }else if (distance <1000 && distance > 1)
        {
            printf("the distance is: %.2f m\n", distance);
        }
        else if (distance == 0)
        {
            printf("something wrong with you timer dude \n");
        }
        
    }       
}