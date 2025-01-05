#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) {
        close(fd[1]);
        char message[100];
        read(fd[0], message, 100);
        printf("Child received: %s\n", message);
        close(fd[0]);
    } else {
        close(fd[0]);
        char message[] = "Hello from parent!";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    return 0;
}
