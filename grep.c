//mini grep programm
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	struct stat buf;
	char *arr;;
	int fd = open(argv[2], O_RDWR);
	if(fd == -1) {
		printf("File open failed\n");
	}
	stat(argv[2], &buf);
	off_t size = buf.st_size;
	char sym = ' ';
	int count = 0;
	for(int i = 0; i<size;) {
		if(sym != '\n' || sym==EOF){
			read(fd, &sym, 1);
			++count;
			++i;
			continue;
		} else {
			arr = (char*)malloc(count);
			lseek(fd, -1*count, SEEK_CUR);
			ssize_t t = read(fd, arr, count);
				if(t == -1) {
					printf("error");
				}
			count = 0;
			if(argc == 4 && (strcmp(argv[3], "-l") == 0)) {
				if((strcasestr(arr, argv[1]) != NULL)) {
					printf("%s", arr);
				}
			} else { 
				if(strstr(arr, argv[1]) != NULL) {
					printf("%s", arr);
				}
			}
			sym = '0';
			free(arr);
		}
	}
}			
			
