/*
 * led.c
 *
 *  Created on: 9 jul. 2020
 *      Author: fernando
 */
#include "led.h"

void prenderLed(char letra)
{
   switch(letra){
      case 'r':;
         gpioWrite(LED2,1);
         break;
      case 'a':
         gpioWrite(LED1,1);
         break;
      case 'v':
         gpioWrite(LED3,1);
         break;
      case 't':
         gpioWrite(LED1,1);
         gpioWrite(LED2,1);
         gpioWrite(LED3,1);
         break;
      default:
    	  break;
   }
}

void apagarLed(char letra)
{
   switch(letra){
      case 'r':;
         gpioWrite(LED2,0);
         break;
      case 'a':
         gpioWrite(LED1,0);
         break;
      case 'v':
         gpioWrite(LED3,0);
         break;
      case 't':
         gpioWrite(LED1,0);
         gpioWrite(LED2,0);
         gpioWrite(LED3,0);
         break;
      default:
    	  break;
   }
}

void invertirLed(char letra)
{
   switch(letra){
      case 'r':
    	  gpioToggle(LED2);
          break;
      case 'a':
         gpioToggle(LED1);
         break;
      case 'v':
         gpioToggle(LED3);
         break;
      default:
         break;
   }
}
