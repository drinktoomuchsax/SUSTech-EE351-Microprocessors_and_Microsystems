#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define sig 0

int main(void){
    wiringPiSetup();	
    pinMode(sig,OUTPUT);
    while(true)
    {
        digitalWrite(sig,HIGH);
        sleep(5);
        digitalWrite(sig,LOW);
        sleep(5);
        digitalWrite(sig,HIGH);
        sleep(5);
    }    
    

}
