#include <stdio.h>
#include <wiringPi.h>
// #include "../timercpp.h"

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// everytime press the button the led change
#define LEDr     23
#define LEDg     24
#define LEDb     25
#define switchSig 22

void lightUpLED (int whichToLight) 
{
    digitalWrite (whichToLight, 1) ;  
    return;
}

void shutUpLED (int whichToShut) 
{
    digitalWrite(whichToShut,0) ; 
    return;
}

bool scanSwitch ()
{
    if(digitalRead(switchSig) == HIGH) //HIGH for releasing the button
        return false;
    
    while(digitalRead(switchSig) == LOW) //LOW for pressing the button
        delay(20); //waiting for releasing
    return true;
}

int main (void)
{
  printf ("Raspberry Pi - start switch\n") ;

  wiringPiSetup () ;

  pinMode (LEDr, OUTPUT) ;
  pinMode (LEDg, OUTPUT) ;
  pinMode (LEDb, OUTPUT) ;
  pinMode (switchSig,INPUT);
  int ledArr[3] = {LEDr,LEDg,LEDb};
  int i = 0;
  
  
  for (;;)
  {
    if(scanSwitch())
    {
        if(i<3)
        {
            shutUpLED(ledArr[i]);
            i++;       
            lightUpLED(ledArr[i]);
        }
        if(i>=4)
        {
            shutUpLED(ledArr[i]);
            shutUpLED(ledArr[i+1]);
            i++;    
            lightUpLED(ledArr[i]);
        }
        if(i==4)
        {
            i=0;
        }
    }
  }


  return 0 ;
}
