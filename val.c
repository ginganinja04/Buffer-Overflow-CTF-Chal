#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void vuln() {
    char tmp[100];   // Temporary buffer to hold input
    char buf1[8];
    char secret[8] = "12345678";
    char buf2[8];
    ssize_t bytes_read;

    printf("User >>> ");
    fflush(stdout);
    bytes_read = read(0, tmp, sizeof(tmp));
    if (bytes_read < 0) {
        perror("read error");
        exit(EXIT_FAILURE);
    }
    tmp[bytes_read] = '\0';
    if (bytes_read >= sizeof(buf1)) {
        fprintf(stderr, "Error: Input too long for user field!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(buf1, tmp);

    printf("Password >>> ");
    fflush(stdout);
    bytes_read = read(0, tmp, sizeof(tmp));
    if (bytes_read < 0) {
        perror("read error");
        exit(EXIT_FAILURE);
    }
    tmp[bytes_read] = '\0';
    if (bytes_read >= sizeof(buf2)) {
        fprintf(stderr, "Error: Input too long for password field!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(buf2, tmp);

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
