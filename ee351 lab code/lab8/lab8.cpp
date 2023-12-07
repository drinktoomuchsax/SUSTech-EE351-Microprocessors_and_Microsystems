#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define BASE 0x40 // 0x40
#define A0 BASE + 0
#define A1 BASE + 1
#define A2 BASE + 2
#define A3 BASE + 3
#define SW 2

int main(void)
{
    wiringPiSetup();
    pinMode(SW, INPUT);
    unsigned char value;
    pcf8591Setup(BASE, 0x48);
    while (true)
    {
        int value_Y = analogRead(A2);
        int value_X = analogRead(A3);
        int value_SW = digitalRead(SW);
        analogWrite(A0, value_X);
        printf("X: %d\n", value_X);
        printf("Y: %d\n", value_Y);
        printf("SW: %d\n", value_SW);
        if (value_SW != 0)
        {
            printf("stick been pressed");
        }
        delay(20);
    }
}