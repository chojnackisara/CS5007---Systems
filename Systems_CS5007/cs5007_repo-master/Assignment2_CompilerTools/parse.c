// Implement a working parser in this file that splits text into individual tokens.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {

	char* parsed;
	parsed = strtok (argv[1], " \t");
	while (parsed != NULL) {
		printf("%s\n", parsed);
		parsed = strtok (NULL, " \t");
	}
	
	
	return 0;

}

