//server 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


static int bit = 0;
static int flag = 0;

void sig_handler1(int signum) {
	if(signum == SIGUSR1) {
		bit = 0;
	} else bit = 1;
}

void sig_handler2(int signum) {
	flag = 1;
}

int main() {

	printf("The server's pid: %d\n", getpid());
	signal(SIGUSR1, sig_handler1);
	signal(SIGUSR2, sig_handler1);
	signal(SIGTERM, sig_handler2);
	char *arr = (char*)malloc(100);
	char sym = 0;
	for(int j = 0; j<100; ++j) {
		for(int i = 0; i<8; ++i) {
			pause();
			sym <<= 1;
			if(flag == 1) {
				break;
			}
			sym |= bit;
		}	
		arr[j] = sym;
		if(flag == 1) {
			break;
		}
		sym = 0;
	}
	printf("%s", arr);
	free(arr);
	return 0;

}

