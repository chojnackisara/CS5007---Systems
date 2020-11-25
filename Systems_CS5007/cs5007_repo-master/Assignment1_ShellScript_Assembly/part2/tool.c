#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main(int argc, char * argv[]) {


	FILE * data;

	data = fopen(argv[1], "r");


	if (data == NULL) {

		printf("Count not open file\n");

		exit(1);

	}	

	char temp[257];

	int instructions = 0; 

	int cycles = 0; 

	int add_count = 0;
	int sub_count = 0;
	int mul_count = 0;
	int div_count = 0;
	int mov_count = 0;
	int lea_count = 0;
	int push_count = 0;
	int pop_count = 0;
	int ret_count = 0;

	char add_array[] = "add";
	char sub_array[] = "sub";
	char mul_array[] = "mul";
	char div_array[] = "div";
	char mov_array[] = "movq";
	char lea_array[] = "leaq";
	char push_array[] = "pushq";
	char pop_array[] = "popq";
	char ret_array[] = "ret";

		
	while (fscanf(data, "%256s", temp) != EOF) {

		if (strcmp(temp, add_array) == 0) {

			add_count++;
			instructions++;

		} 		
		else if (strcmp(temp, sub_array) == 0) {

			sub_count++;
			instructions++;
			
		}
		else if (strcmp(temp, mul_array) == 0) {

			mul_count++;
			instructions++;


		}
		else if (strcmp(temp, div_array) == 0) {

			div_count++;
			instructions++;

		}
		else if (strcmp(temp, mov_array) == 0) {
		
			mov_count++;
			instructions++;

		}
		else if (strcmp(temp, lea_array) == 0) {

			lea_count++;
			instructions++;

		}
		 else if (strcmp(temp, push_array) == 0) {

			push_count++;
			instructions++;

		}
		else if (strcmp(temp, pop_array) == 0) {

			pop_count++;
			instructions++;

		}

		else if (strcmp(temp, ret_array) == 0) {

			ret_count++;
			instructions++;

		} 
		else

			continue;

		}
		
	fclose(data);


	printf("\nADD: %d\n", add_count);
	printf("SUB: %d\n", sub_count);
	printf("MUL: %d\n", mul_count);
	printf("DIV: %d\n", div_count);
	printf("MOV: %d\n", mov_count);
	printf("LEA: %d\n", lea_count);
	printf("PUSH: %d\n", push_count);
	printf("POP: %d\n", pop_count);
	printf("RET: %d\n", ret_count);

	printf("\n\nTotal Instructions = %d", instructions);

	cycles += 1 * add_count;
	cycles += 1 * sub_count;
	cycles += 3 * mul_count;
	cycles += 32 * div_count;
	cycles += 1 * mov_count;
	cycles += 2 * lea_count;
	cycles += 5 * push_count;
	cycles += 2 * pop_count;
	cycles += 3 * ret_count;

	printf("\nTotal Cycles = %d\n", cycles);

	return 0;

}
