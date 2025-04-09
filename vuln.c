#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void vuln() {
    int password_size = 0xa;
    char buf1[8];
    char secret[8]="12345678";
    char buf2[8];
    printf("User >>> ");
    fflush(stdout);
    read(0, buf1, password_size);
    printf("Password >>> ");
    fflush(stdout);
    read(0, buf2, password_size);
    if (strncmp(secret, "CSE5272!",8) == 0) {
        printf("\nYou have won!\n");
    } else {
        printf("\n<<< Incorrect password: %s\n",&secret);
    }
}

int main (int argc, char *argv[]) {
    vuln();
}

