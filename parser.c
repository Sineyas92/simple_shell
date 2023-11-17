#include "shell.h"

/**
 * is_command_executable - determines if a file is an executable command
 * @info: the info struct
 * @file_path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_command_executable(info_t *info, char *file_path)
{
    struct stat file_stat;

    (void)info;

    if (!file_path || stat(file_path, &file_stat))
        return 0;

    if (file_stat.st_mode & S_IFREG)
    {
        return 1;
    }
    return 0;
}

/**
 * duplicate_characters - duplicates characters
 * @path_string: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to a new buffer
 */
char *duplicate_characters(char *path_string, int start, int stop)
{
    static char buffer[1024];
    int index = 0, k = 0;

    for (k = 0, index = start; index < stop; index++)
        if (path_string[index] != ':')
            buffer[k++] = path_string[index];

    buffer[k] = 0;
    return buffer;
}

/**
 * find_command_path - finds this command in the PATH string
 * @info: the info struct
 * @path_string: the PATH string
 * @command: the command to find
 *
 * Return: full path of the command if found or NULL
 */
char *find_command_path(info_t *info, char *path_string, char *command)
{
    int index = 0, current_position = 0;
    char *path;

    if (!path_string)
        return NULL;

    if ((_strlen(command) > 2) && starts_with(command, "./"))
    {
        if (is_command_executable(info, command))
            return command;
    }

    while (1)
    {
        if (!path_string[index] || path_string[index] == ':')
        {
            path = duplicate_characters(path_string, current_position, index);

            if (!*path)
                _strcat(path, command);
            else
            {
                _strcat(path, "/");
                _strcat(path, command);
            }

            if (is_command_executable(info, path))
                return path;

            if (!path_string[index])
                break;

            current_position = index;
        }
        index++;
    }

    return NULL;
}

