#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
#include <cmath>

#define BASE 0x40 //0x40
#define A0 BASE + 0
#define A1 BASE + 1
#define A2 BASE + 2
#define A3 BASE + 3


double calTemp(int anaVoltage){
    double To = 298.15;
    int B = 3950;
    int Ro = 10000;
    double Vr = 0.0000001;
    
    Vr = 5*(anaVoltage/255);
    double Rt = 10000*Vr/(5-Vr);
    double T = 1/(((log(Rt)-log(Ro))/B) + 1/To);

    return T;
}

int main(void)
{
    pcf8591Setup(BASE, 0x48);
    while (true)
    {   float value = 5*analogRead(A1)/255;
        printf("A_voltage out: %.3f\n", value);
        printf("TEMP: %.0lf\n", calTemp(analogRead(A1)));
    }   
}