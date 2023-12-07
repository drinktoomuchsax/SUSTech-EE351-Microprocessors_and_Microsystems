#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define BASE 0x40 // 0x40
#define A0 BASE + 0
#define A1 BASE + 1
#define A2 BASE + 2
#define A3 BASE + 3

int main(void)
{
    unsigned char value;
    pcf8591Setup(BASE, 0x48);
    while (true)
    {
        value = analogRead(A1);
        printf("AOUT: %d\n", value);
        delay(20);
    }
}