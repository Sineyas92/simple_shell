#include "minishell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * readline_error - User input reading error
 *
 * Return: nothing
 */
void readline_error(void)
{
    const char *program_name = "minishell";  // Replace with your actual program name
    const char *error_message = "error while reading input\n";

    // Allocate memory for the concatenated string
    size_t len = strlen(program_name) + strlen(": ") + strlen(error_message) + 1;
    char *err = (char *)malloc(len);
    
    // Check if memory allocation was successful
    if (err != NULL) {
        // Create the concatenated string
        snprintf(err, len, "%s: %s", program_name, error_message);

        // Write the error message to stderr
        write(2, err, strlen(err));

        // Free the allocated memory
        free(err);
    }

    // Exit with failure status
    exit(EXIT_FAILURE);
}

