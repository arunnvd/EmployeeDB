#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define your bash command
    const char* command = "bash bash_test.sh db";

    // Open a pipe to capture the output of the command
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        perror("popen");
        return EXIT_FAILURE;
    }

    // Read the output of the command
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }

    // Close the pipe
    pclose(pipe);

    return EXIT_SUCCESS;
}

