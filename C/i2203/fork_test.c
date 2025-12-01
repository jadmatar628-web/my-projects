#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Start\n");

    if (fork() == 0) {
        // First child branch
        printf("Child 1 created\n");

        if (fork() == 0) {
            printf("Child 1.1 created\n");
        } else {
            printf("Back to Child 1\n");
        }

    } else {
        // Parent branch
        printf("Parent still running\n");
    }

    return 0;
}
