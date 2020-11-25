#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

#define MAX_BUFFER_SIZE 80

//The signal handler.
void sigint_handler(int sig){

	write(1,"Terminating through signal handler\n",35);
	exit(0);
}

//Parses the user input.
char** parse(char* input) {

        char** myArray = malloc(sizeof(char*)*40);
        char* beforePipe;
        char* afterPipe;
        char* pipe;
        char* token;
        int i = 0;
	int j = 0;
        char* parsed;
	parsed = strtok(input, " ");
	int length = strlen(parsed);
        while (parsed != NULL){
		
		int found = 0;
                pipe = "|";
                //parsed[length] = '\0';
	
		
                for(j=0; j<length; j++) {
                        if (parsed[j]=='|' && length == 1){
                                found = 1;
                                myArray[i++] = pipe;
                                break;
                        }
                        if (parsed[j] == '|') {
                                beforePipe = malloc(sizeof(char)*(j+1));
                                beforePipe = strncpy(beforePipe, parsed, j);
				
                                myArray[i++] = beforePipe;
                                myArray[i++] = pipe;
                                afterPipe = malloc(sizeof(char)*(length - j + 2));
									
                                afterPipe = strcpy(afterPipe, parsed+j+1);
							
                                myArray[i++] = afterPipe;
                                found = 1;
                        }
                }
		
                if (found == 0) {
                	token = malloc(strlen(parsed)*sizeof(char));
			token = strcpy(token, parsed);
                        myArray[i] = token;
                        i++;
                }
                parsed = strtok(NULL, " /t");
        }
 
	printf("%s\n", myArray[0]);
	printf("%s\n", myArray[1]);
	

        myArray[i++] = NULL;
		
	
	return myArray;
}


//Function to quit the shell.
void quit(){

        printf("Exiting mini-shell...\n");
        exit(0);

}

//Lists the information about all the possible commands.
void help(){

        printf("\nexit: This command will terminate the shell.\n");
        printf("\nhelp: This command provides information about the");
        printf("built-in functions available in the shell.\n");
        printf("\ncd: This command takes one argument which ");
        printf("is the name or the path of the directory that user ");
        printf("wants to switch to.\n");
        printf("\ncalculator: This command launches a calculator. ");
        printf("You must first enter an operator and then two operands.\n");
	exit(0);
}

//The change directory function.
int cd(char* args[]){
        int result;
        if(args[1]==NULL){
                fprintf(stderr, "No path was specified.\n");
        }

        result = chdir(args[1]);
        if(result==0){
                printf("Changed directory to: %s\n", args[1]);
        }
        else if(result!=0){
		printf("Attempted to change to: %s\n", args[1]);
                printf("Unable to change directory.\n");
        }
        exit(0);
}



//Built in calculator function.
void calculator() {
	char operator;
	double first, second;
	printf("Enter an operator (+, -, *, /): ");
	scanf("%c", &operator);
	printf("Enter two operands: ");
	scanf("%lf %lf", &first, &second);

	switch (operator) {
	case '+':
        	printf("\n%.1lf + %.1lf = %.1lf\n", first, second, first + second);
        	break;

	case '-':
        	printf("\n%.1lf - %.1lf = %.1lf\n", first, second, first - second);
        	break;

	case '*':
        	printf("\n%.1lf * %.1lf = %.1lf\n", first, second, first * second);
        	break;

	case '/':
        	printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
        	break;


    	default:
        	printf("Invalid operator.");
   	}
	exit(0);
        
}

//This prints out the current directory at the top of the shell.
void printDir() 
{ 
	char cwd[1024]; 
	getcwd(cwd, sizeof(cwd)); 
    	printf("\e[1;34m\nDir: %s\n\e[0m", cwd); 
} 

//Frees an array
char** freeArray(char** cmdArray) {
	int i;
	for (i = 0; i < 20; i++){
		if (cmdArray[i] == "|") {
			continue;
		}
        	if (cmdArray[i] == NULL) {
                	break;
                }
                free(cmdArray[i]);
        }
        if (cmdArray){
       		free(cmdArray);
        }
        return cmdArray;

}

int checkPipe(char** myArray){

        char *pipe = "|";
	int i;
        for(i = 0; i < 40; i++){
                if(myArray[i]==NULL){
                        break;
                }
                else if (*myArray[i] == *pipe){
                        return 1;
                }
        }
	        return 0;
}

int cmdHandler(char** cmdArray, int i, int len) {
	
	if(strncmp(cmdArray[i], "cd", len)==0){
                        cd(cmdArray);
			return 1;
        }
        else if(strncmp(cmdArray[i],"help", len)==0){
                        help();
        }
        else if (strncmp(cmdArray[i], "calculator", len)==0){
                        calculator();
        }
	
	
	else {
		return -1;	
	}
	
	return 0;
}

//The main function.
int main(){
	char line[MAX_BUFFER_SIZE];
	int pipefd[2];
	signal(SIGINT, sigint_handler);
	printf("\nPlease add a SPACE after each command!\n");
	while(1){
		printDir();	
		printf("\e[1;35mmini-shell>\e[0m");
		fgets(line, MAX_BUFFER_SIZE, stdin);
		if(line==NULL){
			printf("\nCommand was null.\n");
			exit(0);
		}
		else if(strlen(line) > MAX_BUFFER_SIZE) {
			printf("\nCommand was too long.\n");
			exit(0);
		}
		char **cmdArray = parse(line);	
		int len = strlen(cmdArray[0]);
	

		if(checkPipe(cmdArray) >= 0){
			if(pipe(pipefd)<0){
				printf("pipe error\n");
			}
		}
                if (strncmp(cmdArray[0],"exit", len)==0){
				freeArray(cmdArray);
                                quit();
                }
		int next = 2;
		if (strncmp(cmdArray[0], "cd", len) == 0) {
			next = 3;
		}
		int pid = fork();
		if(pid==0){
			int temp = cmdHandler(cmdArray, 0, len);
	       		if ((temp) < 0) {
		
				if (checkPipe(cmdArray) >= 0){
					close(pipefd[0]);
					dup2(pipefd[1], 1);
					close(pipefd[1]);
				}
				printf("Invalid command\n");
				int x = execvp(cmdArray[0], cmdArray);
				//cmdArray = freeArray(cmdArray);
				exit(0);
			}
		}
		else {
			wait(NULL);
			if(checkPipe(cmdArray) > 0){
	                        if (strncmp(cmdArray[next],"exit", len)==0){
                        	        quit();
					freeArray(cmdArray);
					exit(0);
         		        }

				printf("pipe found\n");
				if (cmdHandler(cmdArray, next, len) < 0) {
                                	printf("Invalid command\n");
                                	int x = execvp(cmdArray[next], cmdArray);
                                }
			
                       	}
			else {
					wait(NULL);
			}
		}
	         		
		cmdArray = freeArray(cmdArray);
		
	}
	return 0;
}



