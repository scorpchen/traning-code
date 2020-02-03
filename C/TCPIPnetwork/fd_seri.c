#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main(void)
{
    int fd1, fd2, fd3;
    fd1 = socket(PF_INET, SOCK_STREAM, 0);
    fd2 = open("tast.dat", O_CREAT|O_WRONLY|O_TRUNC);
    fd3 = socket(PF_INET, SOCK_DGRAM, 0);

    printf("file descriptor 1: %d \n"
            "file descriptor 2: %d \n"
            "file descriptor 3: %d \n", fd1, fd2, fd3);
    
    close(fd1); close(fd2); close(fd3);
    return 0;
}