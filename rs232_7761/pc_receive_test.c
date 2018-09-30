#include <stdlib.h>
#include <stdio.h>
#include "com.h"
#include "pc.h"

int main(void){
        int com_new;
        //int status=com_status(0);
        com_new=com_init(0,0xE6);
      //  printf("%d",status);
      FILE *fp;

  	   fp = fopen("test.txt", "w+");
  	    
		
   
      char c;
      int i;
        for(i=0;i<5;i++){
                //status=com_status(0);
                //if((0x20&status) == 0x20){
                        com_receive(0,&c);
                        fprintf(fp, "%c",c);
                //}
        }
        fclose(fp);
        return 0;
}