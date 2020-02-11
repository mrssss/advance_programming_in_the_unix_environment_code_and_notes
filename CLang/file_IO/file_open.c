#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("open.txt", O_RDONLY);
    if(fd==-1){
        printf("open file 'open.txt failed'\n");
    } else {
        printf("'open.txt' - file descriptor is: %d\n", fd);
    }
    close(fd);

    fd = open("non.txt", O_RDONLY);
    if(fd==-1){
        printf("open file 'non.txt' failed\n");
    } else {
        printf("'non.txt' - file descriptor is: %d\n", fd);
    }
    close(fd);

    fd = open("open.txt", O_RDONLY | O_CREAT);
    if (fd == -1){
        printf("open 'open.txt' with O_RDONLY | O_CREAT failed\n");
    } else {
        printf("open 'open.txt' with O_RDONLY | O_CREAT succeed\n file descriptor is : %d\n", fd);
    }
    close(fd);

    fd = open("open.txt", O_RDONLY | O_CREAT | O_EXCL);
    if (fd == -1){
        printf("open 'open.txt' with O_RDONLY | O_CREAT | O_EXCL failed\n");
    } else {
        printf("open 'open.txt' with O_RDONLY | O_CREAT | O_EXCL succeed\n file descriptor is : %d\n", fd);
    }
    close(fd);

}