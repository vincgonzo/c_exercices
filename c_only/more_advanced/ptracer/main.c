#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int is_debugger_attached() {
    // Try to trace ourselves — if already being traced, this will fail
    if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
        return EXIT_FAILURE; // Debugger detected
    }
    ptrace(PTRACE_DETACH, 0, NULL, NULL); // Detach if not being debugged
    return EXIT_SUCCESS;
}
int main(void) {
    if (is_debugger_attached()) {
        printf("Debugger detected! Exiting...\n");
        exit(EXIT_FAILURE);
    }

    printf("No debugger detected. Running normally.\n");

    // Example payload
    for (int i = 5; i > 0; --i) {
        printf("Doing work... %d\n", i);
        sleep(1);
    }

    printf("All done!\n");
    return EXIT_SUCCESS;
}
