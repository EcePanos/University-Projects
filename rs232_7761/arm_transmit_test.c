#include <mbed.h>
#include <stdio.h>

Serial pc(p9,p10);
LocalFileSystem local("local");
int main(){
   
    char buff[128];
     FILE *fp = fopen("/local/test.txt","r");
    /*
    fscanf(fp, "%s", buff);
    fclose(fp);
    while(1){

           pc.printf("%s",buff);
           //pc.printf("hello"); 
        }
        return 0;
        */
     bool ret =  (fgets(buff, 64, fp)) ;
    
    if (ret)
    {
        pc.printf ("I read a line of text for you, ... \"%s\" \r\n", buff);
    }
    }