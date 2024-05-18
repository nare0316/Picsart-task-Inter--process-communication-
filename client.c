//client 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
	pid_t pid = atoi(argv[1]);
	

	for(int i = 2; i<argc; ++i) {
		char *msg = argv[i];
		for(int j = 0; msg[j] != '\0'; ++j) {
			char sym = msg[j];
			for(int k = 7; k>=0; --k) {
				int bit = (sym>>k)&1;
				if(bit == 0) {
					kill(pid, SIGUSR1);
				} else {
					kill(pid, SIGUSR2);
				}
				usleep(1000);
			}
		}
	usleep(1000);
	kill(pid, SIGTERM);
	}
	return 0;
}



