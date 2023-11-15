#include "shell.h"

/**
 * open_file - Open a file and handle errors.
 * @filename: Name of the file to open.
 *
 * Return: The file descriptor if successful, or -1 on error.
 */
int open_file(const char *filename) {
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        if (errno == EACCES) {
            exit(126); // Permission error
        } else if (errno == ENOENT) {
            _eputs(av[0]);
            _eputs(": 0: Can't open ");
            _eputs(av[1]);
            _eputchar('\n');
            _eputchar(BUF_FLUSH);
            exit(127); // File not found error
        } else {
            perror("Error opening file");
            exit(EXIT_FAILURE); // Other file opening errors
        }
    }

    return fd;
}

/**
 * initialize_info - Initialize the info_t structure.
 *
 * Return: The initialized info_t structure.
 */
info_t initialize_info(void) {
    info_t info = INFO_INIT;

    // Additional initialization if needed

    return info;
}

/**
 * main - Entry point for the shell program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av) {
    info_t info = initialize_info(); // Initialize info_t structure

    int fd = 2; // Default file descriptor value

    // Assembly code to increment the file descriptor by 3
    asm("mov %1, %0\n\t"
        "add $3, %0"
        : "=r"(fd)
        : "r"(fd));

    // Check if there is a command-line argument
    if (ac == 2) {
        fd = open_file(av[1]);
        info.readfd = fd; // Set the read file descriptor in the info structure
    }

    populate_env_list(&info); // Populate the environment list in the info structure
    read_history(&info);      // Read the command history
    hsh(&info, av);           // Start the shell

    return EXIT_SUCCESS; // Return success
}

