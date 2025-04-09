#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CANARY 0xDEADBEEF

void vuln() {
    int password_size = 0xa;
    char buf1[8];
    char secret[8] = "12345678";
    char buf2[8];
    unsigned int canary = CANARY;

    printf("User >>> ");
    fflush(stdout);
    read(0, buf1, password_size);
    printf("Password >>> ");
    fflush(stdout);
    read(0, buf2, password_size);

    if (canary != CANARY) {
        fprintf(stderr, "Stack corruption detected!\n");
        exit(EXIT_FAILURE);
    }

    if (strncmp(secret, "CSE5272!", 8) == 0) {
        printf("\nYou have won!\n");
    } else {
        printf("\n<<< Incorrect password: %s\n", secret);
    }
}

int main(void) {
    vuln();
    return 0;
}
