#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd, fd1;

	fd = open("tmp.aaa", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Create tmp.aaa");
		exit(1);
	}

	close(1);

	fd1 = dup(fd); // 파일 기술자 복사
	
	printf("DUP FD=%d\n", fd1);
	printf("Standard Ouput Redirection\n");
	
	close(fd);

	return 0;
}
