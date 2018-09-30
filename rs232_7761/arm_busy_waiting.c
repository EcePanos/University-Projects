#include "mbed.h"
DigitalOut myled1(LED1);//check if uart.putc is blocking
Serial uart(p9,p10);

/*receive characters from pc and show them on terminal so as to check*/
int main() {
    uart.baud(9600);
    uart.format(8,SerialBase::None,1);
    char ch ;
    
    while(true){
        myled1 = 1;
        wait(0.2);
        //while(!uart.readable());
        ch = uart.getc();
        myled1 = 0;
        wait(1.0);  
        uart.putc(ch);
    }
}