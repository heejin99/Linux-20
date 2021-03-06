#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	int pd, n;
	char msg[] = "Hello, FIFO";

	printf("Server =====\n");
	
	if (mkfifo("./TESTFIFO", 0666) == -1) { //FIFO 파일 생성 
		perror("mkfifo");
		exit(1);
	}

	if ((pd = open("./TESTFIFO", O_WRONLY)) == -1) { //FIFO 파일 쓰기모드로 열기 
		perror("open");
		exit(1);
	}

	printf("To Client : %s\n", msg);

	n = write(pd, msg, strlen(msg)+1); // FIFO파일에 문자열 출력 
	if (n == -1) {
		perror("write");
		exit(1);
	}
	close(pd);

	return 0;
}
