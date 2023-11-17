#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containing history file
 */
char *get_history_file(info_t *info)
{
    char *dir, *historyFile;

    dir = _getenv(info, "HOME=");
    if (!dir)
        return (NULL);

    historyFile = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
    if (!historyFile)
        return (NULL);

    historyFile[0] = 0;
    _strcpy(historyFile, dir);
    _strcat(historyFile, "/");
    _strcat(historyFile, HIST_FILE);

    return (historyFile);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
    ssize_t fileDescriptor;
    char *filename = get_history_file(info);
    list_t *node = NULL;

    if (!filename)
        return (-1);

    fileDescriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(filename);

    if (fileDescriptor == -1)
        return (-1);

    for (node = info->history; node; node = node->next)
    {
        _putsfd(node->str, fileDescriptor);
        _putfd('\n', fileDescriptor);
    }

    _putfd(BUF_FLUSH, fileDescriptor);
    close(fileDescriptor);

    return (1);
}

/**
 * read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
    int i, last = 0, linecount = 0;
    ssize_t fileDescriptor, readLength, fileSize = 0;
    struct stat st;
    char *buffer = NULL, *filename = get_history_file(info);

    if (!filename)
        return (0);

    fileDescriptor = open(filename, O_RDONLY);
    free(filename);

    if (fileDescriptor == -1)
        return (0);

    if (!fstat(fileDescriptor, &st))
        fileSize = st.st_size;

    if (fileSize < 2)
        return (0);

    buffer = malloc(sizeof(char) * (fileSize + 1));
    if (!buffer)
        return (0);

    readLength = read(fileDescriptor, buffer, fileSize);
    buffer[fileSize] = 0;

    if (readLength <= 0)
        return (free(buffer), 0);

    close(fileDescriptor);

    for (i = 0; i < fileSize; i++)
        if (buffer[i] == '\n')
        {
            buffer[i] = 0;
            build_history_list(info, buffer + last, linecount++);
            last = i + 1;
        }

    if (last != i)
        build_history_list(info, buffer + last, linecount++);

    free(buffer);
    info->histcount = linecount;

    while (info->histcount-- >= HIST_MAX)
        delete_node_at_index(&(info->history), 0);

    renumber_history(info);
    return (info->histcount);
}


