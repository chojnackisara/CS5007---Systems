#include <stdio.h>


void msg(){
	printf("Hello!\n");
	sleep(2);
}


int main(){

	int i;
	for(i= 0;i  < 10; ++i){
		msg();
	}
	
	return 0;
}
