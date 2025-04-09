#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln() {
    char buf1[8];
    char secret[8] = "12345678";
    char buf2[8];

    printf("User >>> ");
    fflush(stdout);
    if (fgets(buf1, sizeof(buf1), stdin) == NULL) {
        perror("fgets error");
        exit(EXIT_FAILURE);
    }
    buf1[strcspn(buf1, "\n")] = '\0';

    printf("Password >>> ");
    fflush(stdout);
    if (fgets(buf2, sizeof(buf2), stdin) == NULL) {
        perror("fgets error");
        exit(EXIT_FAILURE);
    }
    buf2[strcspn(buf2, "\n")] = '\0';

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
