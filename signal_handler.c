#include <signal.h>
#include <unistd.h>
#include "minishell.h"

/**
 * signal_handler - Handles the SIGINT signal and prints a new prompt
 * @signo: Signal number
 *
 * Return: void
 */
void signal_handler(int signo)
{
    if (signo == SIGINT)
    {
        char *prompt = "\n($) ";
        ssize_t written;

        // Reinstall the signal handler to catch SIGINT again
        signal(SIGINT, signal_handler);

        // Write the new prompt to the standard output
        written = write(STDOUT_FILENO, prompt, strlen(prompt));
        if (written == -1)
        {
            // Handle error if write fails (consider writing to STDERR)
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
}

