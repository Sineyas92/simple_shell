#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
    int exitcheck;

    while (info->argv[1])  /* While there is an exit argument */
    {
        exitcheck = _erratoi(info->argv[1]);
        if (exitcheck == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return (1);
        }
        info->err_num = _erratoi(info->argv[1]);
        return (-2);
    }

    info->err_num = -1;
    return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        _puts("TODO: >>getcwd failure emsg here<<\n");

    while (!info->argv[1])
    {
        dir = _getenv(info->envp, "HOME=");
        if (!dir)
            chdir_ret = chdir((dir = _getenv(info->envp, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
        break;  /* Assuming you want to break out of the loop after the first iteration */
    }

    while (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info->envp, "OLDPWD="))
        {
            _puts(s);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info->envp, "OLDPWD=")), _putchar('\n');
        chdir_ret = chdir((dir = _getenv(info->envp, "OLDPWD=")) ? dir : "/");
        break;  /* Assuming you want to break out of the loop after the first iteration */
    }

    while (info->argv[1])
    {
        chdir_ret = chdir(info->argv[1]);
        break;  /* Assuming you want to break out of the loop after the first iteration */
    }

    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]), _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info->envp, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    _puts("help call works. Function not yet implemented \n");
    while (0)
    {
        _puts(*arg_array); /* temp att_unused workaround */
        break;  /* Assuming you want to break out of the loop after the first iteration */
    }
    return (0);
}

