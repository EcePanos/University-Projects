#include "mbed.h"

 Serial com (p9 , p10); // tx, rx
 Serial host (USBTX, USBRX);
 
 //char txChar,rxChar;
 
 int main() {
     
     while(1) {
        host.putc(com.getc());
        
    }
 }