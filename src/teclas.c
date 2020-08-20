/*
 * teclas.c
 *
 *  Created on: 18 ago. 2020
 *      Author: fernando
 */
#include "teclas.h"
#include "sapi.h"

#define BUTTON_LOGIC BUTTON_ONE_IS_UP

#define BUTTON1 TEC1
#define BUTTON2 TEC2
#define BUTTON3 TEC3
#define BUTTON4 TEC4

// Button objects
button_t myButton1;
button_t myButton2;
button_t myButton3;
button_t myButton4;

void iniciarTeclas(){
   buttonInit( &myButton1,                  // Button structure (object)
               BUTTON1, BUTTON_LOGIC,       // Pin and electrical connection
               50,                          // Button scan time [ms]
               TRUE,                        // checkPressedEvent
               TRUE,                       // checkReleasedEvent
               TRUE,                        // checkHoldPressedEvent
               2000,                        // holdPressedTime [ms]
               0,                           // pressedCallback
               0,                           // releasedCallback
               0                            // holdPressedCallback
             );

    buttonInit( &myButton2,                  // Button structure (object)
                BUTTON2, BUTTON_LOGIC,       // Pin and electrical connection
                50,                          // Button scan time [ms]
                TRUE,                        // checkPressedEvent
                TRUE,                        // checkReleasedEvent
                TRUE,                        // checkHoldPressedEvent
                2000,                        // holdPressedTime [ms]
                0,                           // pressedCallback
                0,                           // releasedCallback
                0                            // holdPressedCallback
               );

   buttonInit( &myButton3,                  // Button structure (object)
               BUTTON3, BUTTON_LOGIC,       // Pin and electrical connection
               50,                          // Button scan time [ms]
               TRUE,                        // checkPressedEvent
               TRUE,                        // checkReleasedEvent
               TRUE,                        // checkHoldPressedEvent
               2000,                        // holdPressedTime [ms]
               0,                           // pressedCallback
               0,                           // releasedCallback
               0                            // holdPressedCallback
             );

   buttonInit( &myButton4,                  // Button structure (object)
	           BUTTON4, BUTTON_LOGIC,       // Pin and electrical connection
	           50,                          // Button scan time [ms]
	           TRUE,                        // checkPressedEvent
	           TRUE,                        // checkReleasedEvent
	           TRUE,                        // checkHoldPressedEvent
	           2000,                        // holdPressedTime [ms]
	           0,                           // pressedCallback
	           0,                           // releasedCallback
	           0                            // holdPressedCallback
	          );
}
//actualiza la MEF de cada pulsador
void actualizarTeclas()
{
   buttonFsmUpdate( &myButton1 );
   buttonFsmUpdate( &myButton2 );
   buttonFsmUpdate( &myButton3 );
   buttonFsmUpdate( &myButton4 );
}
//consulta si hubo un evento RELEASED en alguno de los pulsadores
int consultarTeclas()
{
   if( (buttonEventGet( &myButton1 ) == BUTTON_RELEASED) ) {
      buttonEventHandled( &myButton1 );
      return 1;
   }
   else if( (buttonEventGet( &myButton2 ) == BUTTON_RELEASED) ) {
      buttonEventHandled( &myButton2 );
      return 2;
   }
   else if( (buttonEventGet( &myButton3 ) == BUTTON_RELEASED) ) {
      buttonEventHandled( &myButton3 );
      return 3;
   }
   else if( (buttonEventGet( &myButton4 ) == BUTTON_RELEASED) ) {
      buttonEventHandled( &myButton4 );
      return 4;
   }
   else{
      return 0;
   }
}


