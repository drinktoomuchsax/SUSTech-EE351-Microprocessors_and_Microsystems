#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
#define LEDr     23
#define LEDg     24
#define LEDb     25

int main (void)
{
  printf ("Raspberry Pi - start Blink\n") ;

  wiringPiSetup () ;

  pinMode (LEDr, OUTPUT) ;
  pinMode (LEDg, OUTPUT) ;
  pinMode (LEDb, OUTPUT) ;
  digitalWrite (LEDr, 1) ; 

  for (;;)
  {
    digitalWrite (LEDr, 1) ;    
    delay (500) ;               
    digitalWrite (LEDr, 0) ;    
    digitalWrite (LEDg, 1) ;    
    delay (500) ;
    digitalWrite (LEDg, 0) ;    
    digitalWrite (LEDb, 1) ;  
    delay (500) ;
    digitalWrite (LEDb, 0) ; 
  }
  return 0 ;
}