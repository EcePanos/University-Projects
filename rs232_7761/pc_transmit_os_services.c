#include <stdio.h>
#define COM1 0
#include <dos.h>
#define RS232_INIT_FUNCTION 0
#define RS232_STATUS_FUNCTION 3
#define RS232_SEND_FUNCTION 1
void rs232init(int port, unsigned init_code)
{
union REGS inregs;
inregs.x.dx = port;
inregs.h.ah = RS232_INIT_FUNCTION;
inregs.h.al = init_code;
int86(0x14,&inregs,&inregs);
}
unsigned char rs232send(int port, char ch)
{
union REGS inregs;
inregs.x.dx = port;
inregs.h.ah = RS232_SEND_FUNCTION;
inregs.h.al = ch;
int86(0x14,&inregs,&inregs);
return (inregs.h.ah);
}
unsigned int rs232status(int port)
{
union REGS inregs;
inregs.x.dx = port;
inregs.h.ah = RS232_STATUS_FUNCTION;
int86(0x14,&inregs,&inregs);
return (inregs.x.ax);
}
int main ()
{
	rs232init( COM1 , 0xEB ) ;
	unsigned int status ;
	unsigned char b ;
	int i ;
	for ( i =0 ; i<30 ; i++)
	{
				
		while((0x20&rs232status(COM1) )) ;//busy waiting
					
		b = rs232send( COM1 , 'c'+i) ;
		printf("a");
			
	}
   return(0);
}