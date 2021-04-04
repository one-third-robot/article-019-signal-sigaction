
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void sig_INT_handler(int s) {
    printf("caught signal %d, exit.\n", s);
    exit(1);
}

int main(int argc, char* argv[]) {

    signal(SIGINT, ( __sighandler_t )sig_INT_handler);

    for (;;) {
        printf("hello world\r\n");
        sleep(2);
    }
    return 0;
}
