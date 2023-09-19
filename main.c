#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

void enable(void);  
void comando(unsigned char y);
void datos(unsigned char x);
void retardoRTI(void);
void MCUInit(void);
void init(void);
void car(void);

void main(void) {
SOPT1=0x12; 
MCUInit();
init();
datos(0x41);  //	Letra A en codigo ASCII A DECIMAL
datos(0x52);  //	Letra R en codigo ASCII A DECIMAL
datos(0x49);  //	Letra I en codigo ASCII A DECIMAL
datos(0x45);  //	Letra E en codigo ASCII A DECIMAL
datos(0x4C);  //	Letra L en codigo ASCII A DECIMAL
datos(0x20);  //	ESPACIO
datos(0x32);  //	Numero 2 en codigo ASCII A DECIMAL
datos(0x30);  //	Numero 0 en codigo ASCII A DECIMAL
datos(0x31);  //	Numero 1 en codigo ASCII A DECIMAL
datos(0x31);  //	Numero 1 en codigo ASCII A DECIMAL
datos(0x30);  //	Numero 0 en codigo ASCII A DECIMAL
datos(0x33);  //	Numero 3 en codigo ASCII A DECIMAL
datos(0x32);  //	Numero 2 en codigo ASCII A DECIMAL
datos(0x37);  //	Numero 7 en codigo ASCII A DECIMAL

  for(;;) {
   
  } /* loop forever */
  /* please make sure that you never leave main */
}
void enable(void){
	PTAD_PTAD1=1; /*E*/ 
	retardoRTI();
	PTAD_PTAD1=0;
}
void comando(unsigned char y)
{ unsigned char tmp=0x00;
	tmp=y;
	PTAD_PTAD0=0; /*RS*/
	PTBD=y;
	enable();
}
void datos(unsigned char x)
{
	    PTAD_PTAD0=1;/*RS*/
		PTBD=x;
		enable();
		
}
void retardoRTI(void)
{
	SRTISC=0x05;
	while(SRTISC_RTIF==0); //ESPEREMOS EL TIEMPO
	SRTISC_RTIACK=1;       //APAGAR LA BANDERA
	SRTISC=0x00;           //DETENER RTI
}
void MCUInit(void)
{
	PTBDD=0xFF; // Salidas de PTBD PARA DATOS 
	PTADD=0x00; 
	PTADD_PTADD0=0x01; //RS
	PTADD_PTADD1=0x01; //E
}
void init(void)
{
	unsigned char i=0x00;
	unsigned char InitTabla[8]={0x38,0x38,0x38,0x38,0x0F,0x06,0x01,0x00}; //Array necesario para los comando e inicializar la pantalla en 8 Bits
	while(i!=8)
	{
		comando(InitTabla[i]);
				i++;
	}
}


