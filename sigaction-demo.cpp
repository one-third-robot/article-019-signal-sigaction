
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

static void termination_handler(const int signal) {
    switch (signal) {
    case SIGINT:
        printf("\nSIGINT (Ctrl + C) signal caught.\n");
        break;
    case SIGTERM:
        printf("\nSIGTERM (`kill` or `killall`) signal caught.\n");
        break;
    default:
        printf("\nUnknown signal caught.\n");
        break;
    }
    exit(1);
}

static void set_sigaction(int signal, const struct sigaction* action) {
    if (sigaction(signal, action, NULL) == -1) {
        printf("failed to set signal to %i;\n  errno = %i: %s\n", signal, errno,
               strerror(errno));
    }
}

int main(int argc, char* argv[]) {

    struct sigaction action;
    action.sa_handler = termination_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    set_sigaction(SIGINT, &action);  // Ctrl + C

    for (;;) {
        printf("hello world\r\n");
        sleep(2);
    }
    return 0;
}
