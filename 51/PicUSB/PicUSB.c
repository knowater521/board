/////////////////////////////////////////////////////////////////////////
////                            PicUSB.c                             ////
////                                                                 ////
//// Este ejemplo muestra como desarrollar un sencillo dispositivo   ////
//// USB con el PIC18F2550, aunque puede ser facilmente adaptado     ////
//// para la serie 18Fxx5x. Se suministra el PicUSB.exe, así como    ////
//// su código fuente para Visual C# 2005, podréis encontrar tb      ////
//// los drivers para el dispositivo. No se suministra esquema de    ////
//// conexión puesto que está pensado para ser usado en el GTP USB,  ////
//// cualquiera de las tres versiones disponibles, si aun no teneis  ////
//// el programador, podeis utilizar el esquema de ese proyecto.     ////
////                                                                 ////
//// Cuando el dispositivo sea conectado al PC, saldrá el asistente  ////
//// para la instalación del driver. Instala el suministrado junto   ////
//// a este ejemplo, lo encontrareis dentro de la carpeta Driver.    ////
//// Una vez instalado podreis usar el PicUSB.exe para encender o    ////
//// apagar el led bicolor del GTP USB, y para realizar la suma de   ////
//// dos números introducidos.                                       ////
////                                                                 ////
//// Realizado con el compilador CCS PCWH 3.227                      ////
////                                                                 ////
//// Por: Jaime Fernández-Caro Belmonte        hobbypic@hotmail.com  ////
////                                                                 ////
//// http://www.hobbypic.com                                         ////
/////////////////////////////////////////////////////////////////////////
#include <18F2550.h>
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL3,CPUDIV1,VREGEN
#use delay(clock=48000000)


/////////////////////////////////////////////////////////////////////////////
//
// CCS Library dynamic defines.  For dynamic configuration of the CCS Library
// for your application several defines need to be made.  See the comments
// at usb.h for more information
//
/////////////////////////////////////////////////////////////////////////////
#define USB_HID_DEVICE     FALSE             //deshabilitamos el uso de las directivas HID
#define USB_EP1_TX_ENABLE  USB_ENABLE_BULK   //turn on EP1(EndPoint1) for IN bulk/interrupt transfers
#define USB_EP1_RX_ENABLE  USB_ENABLE_BULK   //turn on EP1(EndPoint1) for OUT bulk/interrupt transfers
#define USB_EP1_TX_SIZE    1                 //size to allocate for the tx endpoint 1 buffer
#define USB_EP1_RX_SIZE    3                 //size to allocate for the rx endpoint 1 buffer


/////////////////////////////////////////////////////////////////////////////
//
// If you are using a USB connection sense pin, define it here.  If you are
// not using connection sense, comment out this line.  Without connection
// sense you will not know if the device gets disconnected.
//       (connection sense should look like this:
//                             100k
//            VBUS-----+----/\/\/\/\/\----- (I/O PIN ON PIC)
//                     |
//                     +----/\/\/\/\/\-----GND
//                             100k
//        (where VBUS is pin1 of the USB connector)
//
/////////////////////////////////////////////////////////////////////////////
//#define USB_CON_SENSE_PIN PIN_B2  //CCS 18F4550 development kit has optional conection sense pin

/////////////////////////////////////////////////////////////////////////////
//
// Include the CCS USB Libraries.  See the comments at the top of these
// files for more information
//
/////////////////////////////////////////////////////////////////////////////
#include <pic18_usb.h>     //Microchip PIC18Fxx5x Hardware layer for CCS's PIC USB driver
#include <PicUSB.h>	      //Configuración del USB y los descriptores para este dispositivo
#include <usb.c>        	//handles usb setup tokens and get descriptor reports


/////////////////////////////////////////////////////////////////////////////
//
// Al conectar el PicUSB al PC encendemos el Led Rojo hasta que el dispositivo
// halla sido configurado por el PC, en ese momento encederemos el Led Verde.
// Esperaremos hasta que se reciba un paquete proveniente del PC. Comprobaremos
// el primer byte del paquete recibido para comprobar si queremos entrar en el
// modo Suma, donde se realizará una suma de dos operandos, que corresponderan
// con los dos bytes restantes del paquete recibido; una vez realizada la suma
// enviaremos el paquete con el resultado de vuelta al PC. Si entramos en el
// modo Led comprobaremos el segundo byte del paquete recibido para comprobar
// si deberemos apagar los leds, encender el verder o el rojo.
//
/////////////////////////////////////////////////////////////////////////////
#define LEDV    PIN_B6
#define LEDR    PIN_B7
#define LED_ON  output_high
#define LED_OFF output_low

#define modo      recibe[0]
#define param1    recibe[1]
#define param2    recibe[2]
#define resultado envia[0]


void main(void) {

   int8 recibe[3];                  //declaramos variables
   int8 envia[1];

   LED_OFF(LEDV);                   //encendemos led rojo
   LED_ON(LEDR);

   usb_init();                      //inicializamos el USB

   usb_task();                      //habilita periferico usb e interrupciones
   usb_wait_for_enumeration();      //esperamos hasta que el PicUSB sea configurado por el host

   LED_OFF(LEDR);
   LED_ON(LEDV);                    //encendemos led verde

   while (TRUE)
   {
      if(usb_enumerated())          //si el PicUSB está configurado
      {
         if (usb_kbhit(1))          //si el endpoint de salida contiene datos del host
         {
            usb_get_packet(1, recibe, 3); //cojemos el paquete de tamaño 3bytes del EP1 y almacenamos en recibe

            if (modo == 0) // Modo_Suma
            {
               resultado = param1 + param2;  //hacemos la suma

               usb_put_packet(1, envia, 1, USB_DTS_TOGGLE); //enviamos el paquete de tamaño 1byte del EP1 al PC
            }

            if (modo == 1) // Modo_Led
            {
               if (param1 == 0) {LED_OFF(LEDV); LED_OFF(LEDR);} //apagamos los leds
               if (param1 == 1) {LED_ON(LEDV); LED_OFF(LEDR);} //encendemos led verde
               if (param1 == 2) {LED_OFF(LEDV); LED_ON(LEDR);} //encendemos led rojo
            }
         }
      }
   }
}
