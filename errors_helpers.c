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
    const char *program_name = "minishell";
    const char *error_message = "error while reading input\n";
    size_t len = strlen(program_name) + strlen(": ") + strlen(error_message);
    char *err = (char *)malloc(len);

    if (err == NULL) 
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    snprintf(err, len, "%s: %s", program_name, error_message);

    write(2, err, strlen(err));

    free(err);

    /* Exit with failure status */
    exit(EXIT_FAILURE);
}


