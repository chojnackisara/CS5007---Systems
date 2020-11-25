#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>                                                                   
int main(){

        char* myargv[16];
        myargv[0]="/bin/ls";
        myargv[1]="-F";
        myargv[2]=NULL;


        char* myargv2[16];
        myargv2[0]="/bin/cat";
        myargv2[1]="-F";
        myargv2[2]=NULL;
                                                                                      

        if(fork()==0){
                execve(myargv2[0],myargv2,NULL);
               // execve(myargv[0],myargv,NULL);                                        
                printf("Child: Should never get here\n");
                exit(1);  
        }
	else{
                wait(NULL); !
                printf("This always prints last\n");
        }                                                                             
        return 0;
}

