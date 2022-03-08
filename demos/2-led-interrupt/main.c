//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= ~LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}


void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  static unsigned char ticker = 0;
  ticker++;
  if(ticker == 125){ //other than 1 sec i hve it at every half a second 
    P1OUT |= ~LED_RED;//turn its on at every haf a second 
  }
  else{
    P1OUT |= LED_RED; 
    //0 |= 1 = 1
  }
}
//to turn off use & using the compliment of the light you are using
//to turn on use the | using the light you are using
//P1out ^ led_your_using
// 1 ^ 1 = 0
// 0 ^ 1 = 1

