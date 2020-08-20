/*
 * pantalla.c
 *
 *  Created on: 18 ago. 2020
 *      Author: fernando
 */
#include "pantalla.h"
#include "sapi.h"

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

int pantallaPrevia=100; //para imprimir una sola vez la pantalla

void iniciarPantalla()
{
   uartConfig(UART_USB, 115200);
}

void muestraPantalla(int pantalla)
{
   switch( pantalla ){
      case PANTALLA_A:
	     if(pantalla != pantallaPrevia){
            uartWriteString(UART_USB, "Seleccione la opcion que desea mediante el uso de los pulsadores.\r\n");
			uartWriteString(UART_USB, "1.Calibracion\r\n2.Titulacion\r\n3.Configuracion\r\n4.Conexion.\r\n\n");
			pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_B:
         if(pantalla != pantallaPrevia){
		    uartWriteString(UART_USB, "Seleccione el patron con el cual desea calibrar el titulador:.\r\n");
			uartWriteString(UART_USB, "1.Buffer A\r\n2.Buffer B\r\n3.Buffer C\r\n4.Regresar.\r\n\n");
			pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_B1:
	     if(pantalla != pantallaPrevia){
		    uartWriteString(UART_USB, "Se calibro el Buffer A. Presione 4 para regresar.\r\n\n");
			pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_B2:
	     if(pantalla != pantallaPrevia){
		 uartWriteString(UART_USB, "Se calibro el Buffer B. Presione 4 para regresar.\r\n\n");
		 pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_B3:
	     if(pantalla != pantallaPrevia){
		 uartWriteString(UART_USB, "Se calibro el Buffer C. Presione 4 para regresar.\r\n\n");
		 pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_C:
	     if(pantalla != pantallaPrevia){
		    uartWriteString(UART_USB, "Se esta realizando la titulacion. Presione 4 para finalizar y regresar al menu anterior.\r\n\n");
			pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_D:
	     if(pantalla != pantallaPrevia){
		    uartWriteString(UART_USB, "Seleccione la opcion que desea mediante el uso de los pulsadores.\r\n");
			uartWriteString(UART_USB, "1.Configurar buffers\r\n2.Seleccionar volumen de corte\r\n3.Limpiar bomba\r\n4.Regresar al menu anterior\r\n\n");
			pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_D1:
	     if(pantalla != pantallaPrevia){
		 uartWriteString(UART_USB, "En esta pantalla se podra cargar el valor correspondiente a cada uno de los tres patrones (buffers) a utilizar en la calibracion.\r\n");
		 uartWriteString(UART_USB, "Presione 4 para finalizar y regresar al menu anterior.\r\n\n");
		 pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_D2:
	     if(pantalla != pantallaPrevia){
		    uartWriteString(UART_USB, "En esta pantalla se podra cargar el valor correspondiente al volumen de corte.\r\n");
			uartWriteString(UART_USB, "Presione 4 para finalizar y regresar al menu anterior.\r\n\n");
			pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_D3:
	     if(pantalla != pantallaPrevia){
		    uartWriteString(UART_USB, "Limpiando la bomba...\r\n");
			uartWriteString(UART_USB, "Presione 4 para finalizar y regresar al menu anterior.\r\n\n");
			pantallaPrevia = pantalla;
	     }
	     break;

      case PANTALLA_E:
	     if(pantalla != pantallaPrevia){
		    uartWriteString(UART_USB, "En esta pantalla se mostraran los datos para conectarse al dispositivo mediante una red wifi.\r\n");
		    uartWriteString(UART_USB, "Presione 4 para finalizar y regresar al menu anterior.\r\n\n");
			pantallaPrevia = pantalla;
	     }
	     break;
      default:
	     break;
	  }
}
