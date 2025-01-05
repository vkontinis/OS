#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum) {
    printf("Child received signal %d\n", signum);
}

int main() {
    if (fork() == 0) {
        signal(SIGUSR1, handler);
        pause(); // Wait for signal
    } else {
        sleep(1);
        kill(getpid() + 1, SIGUSR1);
    }
    return 0;
}
