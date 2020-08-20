/*
 * menu.c
 *
 *  Created on: 20 ago. 2020
 *      Author: fernando
 */
#include "menu.h"
#include "pantalla.h"
#include "led.h"

// Nombres de los estados de la MEF
typedef enum{
   PANTALLA_A,
   PANTALLA_B,
   PANTALLA_B1,
   PANTALLA_B2,
   PANTALLA_B3,
   PANTALLA_C,
   PANTALLA_D,
   PANTALLA_D1,
   PANTALLA_D2,
   PANTALLA_D3,
   PANTALLA_E,
} pantalla_t;

// Variable para el estado actual
pantalla_t pantalla;

// Función para controlar errores de la MEF (Error handler)
void errorMEF( void )
{
   pantalla = PANTALLA_A;
}

// Función para iniciar la MEF
void iniciarMEF( void )
{
   pantalla = PANTALLA_A;   // Set initial state
}

// Función para actualizar la MEF
void actualizarMEF( int opcion )
{
   switch( pantalla ){
      case PANTALLA_A:
    	  muestraPantalla(PANTALLA_A);
    	  switch (opcion){
             case 1:
            	 pantalla = PANTALLA_B;
            	 break;
             case 2:
            	 pantalla = PANTALLA_C;
                 break;
             case 3:
            	 pantalla = PANTALLA_D;
                 break;
             case 4:
            	 pantalla = PANTALLA_E;
                 break;
             default:
            	 pantalla = PANTALLA_A;
            	 break;
    	  }
    	  break;

      case PANTALLA_B:
         muestraPantalla(PANTALLA_B);
    	 switch (opcion){
            case 1:
               pantalla = PANTALLA_B1;
               break;
            case 2:
               pantalla = PANTALLA_B2;
               break;
            case 3:
               pantalla = PANTALLA_B3;
               break;
            case 4:
               pantalla = PANTALLA_A;
               break;
            default:
               pantalla = PANTALLA_B;
               break;
    	 }
         break;

      case PANTALLA_B1:
         muestraPantalla(PANTALLA_B1);
    	 if(opcion==4){
            pantalla = PANTALLA_B;
    	 }
    	 break;

      case PANTALLA_B2:
         muestraPantalla(PANTALLA_B2);
    	 if(opcion==4){
            pantalla = PANTALLA_B;
    	 }
    	 break;

      case PANTALLA_B3:
         muestraPantalla(PANTALLA_B3);
    	 if(opcion==4){
            pantalla = PANTALLA_B;
    	 }
    	 break;

      case PANTALLA_C:
         muestraPantalla(PANTALLA_C);
    	 prenderLed('v');
    	 if(opcion==4){
    	    pantalla = PANTALLA_A;
    		apagarLed('v');
    	 }
    	 break;

      case PANTALLA_D:
         muestraPantalla(PANTALLA_D);
    	 switch (opcion){
            case 1:
               pantalla = PANTALLA_D1;
               break;
            case 2:
               pantalla = PANTALLA_D2;
               break;
            case 3:
               pantalla = PANTALLA_D3;
               break;
            case 4:
               pantalla = PANTALLA_A;
               break;
            default:
               pantalla = PANTALLA_D;
               break;
    	 }
    	 break;

      case PANTALLA_D1:
         muestraPantalla(PANTALLA_D1);
    	 if(opcion==4){
            pantalla = PANTALLA_D;
    	 }
    	 break;

      case PANTALLA_D2:
    	 muestraPantalla(PANTALLA_D2);
    	 if(opcion==4){
            pantalla = PANTALLA_D;
    	 }
    	 break;

      case PANTALLA_D3:
    	 muestraPantalla(PANTALLA_D3);
    	 prenderLed('v');
    	 if(opcion==4){
            pantalla = PANTALLA_D;
            apagarLed('v');
    	 }
    	 break;

      case PANTALLA_E:
    	 muestraPantalla(PANTALLA_E);
    	 if(opcion==4){
            pantalla = PANTALLA_A;
    	 }
    	 break;

      default:
    	 errorMEF();
    	 break;
   }
}
