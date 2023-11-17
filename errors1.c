#include "shell.h"

int _erratoi(char *s)
{
    int i = 0;
    unsigned long int result = 0;

    while (*s != '\0')
    {
        while (*s >= '0' && *s <= '9')
        {
            result *= 10;
            result += (*s - '0');
            if (result > INT_MAX)
                return -1;
            s++;
        }
        if (*s != '\0')
            return -1;
        s++;
    }
    return result;
}

void print_error(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
}

int print_d(int input, int fd)
{
    int (*__putchar)(char) = _putchar;
    int i, count = 0;
    unsigned int _abs_, current;

    if (fd == STDERR_FILENO)
        __putchar = _eputchar;
    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        count++;
    }
    else
        _abs_ = input;
    current = _abs_;
    while (current > 1)
    {
        if (_abs_ / current)
        {
            __putchar('0' + current / 10);
            count++;
        }
        current %= 10;
    }
    __putchar('0' + current);
    count++;

    return count;
}

char *convert_number(long int num, int base, int flags)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }
    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;
    return ptr;
}

void remove_comments(char *buf)
{
    int i = 0;

    while (buf[i] != '\0')
    {
        if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
        {
            buf[i] = '\0';
            break;
        }
        i++;
    }
}

