#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(void)
{
        int i;
        char *argv[][4] = { {"/bin/sh", "-c", "echo First", 0},
                            {"/bin/sh", "-c", "echo Second", 0},
                            {"/bin/sh", "-c", "echo Third", 0} };



        for (i = 0; i < 3; i++)
        {

                 if (fork() == 0) {
                         execve(argv[i][0], &argv[i][0], NULL);
                         fprintf(stderr, "Shouldn't have gotten here!\n");
                         exit(1);
                 }

		 else {
			wait(NULL);
	         }                 

        }

        wait(NULL);
        printf("This is original parent\n");
        exit(0);
}

   

