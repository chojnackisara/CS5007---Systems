#include <stdio.h>
#include <time.h>
#include <sys/time.h>

static void *start;
static int counter = 0;
unsigned long get_time();

unsigned long get_time() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        unsigned long temp  = tv.tv_usec;
	temp /= 1000000;
        temp += (tv.tv_sec);
        return temp;
}

long start_time;

__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){
	if (counter == 0) {
		start_time = get_time();
	}
	counter += 1;
	printf("Function entered from %p\n", call_site);
	if (counter == 1) {
		start = call_site;
	}
	
}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){
	printf("Function exited from %p\n", call_site);
	if (call_site == start) {
   		printf("\nTotal functions called = %d\n", counter);
		printf("Time taken by program: %ld sec\n",
			get_time() - start_time);
	}

}


