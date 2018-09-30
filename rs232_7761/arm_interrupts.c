#include "mbed.h"

DigitalOut myled1(LED1);
DigitalOut myled4(LED4);

Serial pc(USBTX, USBRX);
Serial uart(p9,p10);//tx,rx
LocalFileSystem local("local"); 

void createAndWriteToFile(FILE *fp);
void readFromFile(FILE *fp/*,char buffer[]*/);
void txIsr(); 


char buffer[31];
int i = 0;

/*program to transmit the content of a file*/


int main() {
    
    FILE *fp;
   
   
    uart.attach(&txIsr,Serial::TxIrq);
    createAndWriteToFile(fp);
    readFromFile(fp/*,buffer*/); 
    uart.putc('h');
    
        
   
}

void txIsr(){
    
    myled1 = 1;  
    wait(0.5);
    myled1 = 0;
    wait(0.5); 
    if(i<30){        //30 is the length of the phrase i used
        uart.putc(buffer[i]);
        i++;
    }
    
}

void createAndWriteToFile(FILE *fp){
    myled4 = 1;
    wait(1.0);
    fp = fopen("/local/HELLO.txt","w");
    //write to file
    fprintf(fp,"Hello PC!This is mbed calling!");   
    fclose(fp);
    myled4 = 0;
    wait(1.0);
}

void readFromFile(FILE *fp/*,char buffer[31]*/){
    myled4 = 1;
    wait(1.0); 
    fp = fopen("/local/Panos.txt","r");
    bool ret =  (fgets(buffer, 31, fp)) ;//64
       //ch = fgetc(fp);
       //pc.printf("%s\n",buffer);  
    myled4 = 0;
    wait(1.0);
    fclose(fp);
}