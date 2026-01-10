#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void win() {
    printf("Access Granted! You have successfully overwritten the hook.\n");
    printf("Here is your shell...\n");
    system("/bin/sh");
}

void normal_log() {
    printf("Logging action... done.\n");
}

struct {
    char buffer[64];
    void (*hook)(void);
} target;

int main() {
    target.hook = normal_log;

    printf("Welcome to the Hook Overwrite Challenge!\n");
    printf("The 'win' function is located at: %p\n", win);
    printf("The 'target.hook' is located at: %p\n", &target.hook);
    printf("Send me your data to log: ");
    fflush(stdout);

    // Vulnerability: read allows overflow of target.buffer (64 bytes) into target.hook
    // 64 bytes for buffer + bytes to reach hook (packed?) + 8 bytes for address
    read(0, target.buffer, 128);

    printf("Executing hook...\n");
    target.hook();

    return 0;
}
