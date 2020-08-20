/*=============================================================================
 * Author: Fernando Ezequiel Daniele <fernandodaniele1993@gmai.com>
 * Date: 2020/08/12
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "PDM_TP_Final.h"
#include "sapi.h"
#include "pantalla.h"
#include "teclas.h"
#include "menu.h"

/*=====[Definition macros of private constants]==============================*/

#define TIEMPO_MEF_MENU  100
#define TIEMPO_MEF_PULSADOR  100

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

int pulsador=0, ultimoBoton = 0; //variable para guardar el ultimo pulsador que permite el cambio de estado

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
// ----- Configuración -----------------------------------
   delay_t mefMenu;
   delay_t mefPulsadores;
   delayInit( &mefMenu, TIEMPO_MEF_MENU );
   delayInit( &mefPulsadores, TIEMPO_MEF_PULSADOR );
   boardInit();
   iniciarMEF();
   iniciarPantalla();
   iniciarTeclas();
// ----- Bucle infinito-------------------------
   while( true ) {
   //---Se actualiza MEF del menu cada 100 mS
      if( delayRead(&mefMenu)){
      actualizarMEF(ultimoBoton);
      ultimoBoton = 0;
      }
   //---Se actualiza la MEF de los botones cada 50 mS
      if( delayRead(&mefPulsadores) ) {
      actualizarTeclas();
      pulsador = consultarTeclas();
      }
      else{
         pulsador = 0;
      }
      if (pulsador != 0){
         ultimoBoton = pulsador;
      }
   }
   return 0;
}
