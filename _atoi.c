#include "main.h"
/**
 * _atoi - changes a string to an int
 * @s: the string to be changed
 *
 * Return: the converted int
 */

int _atoi(char *c)
{
int j = 1;
unsigned int num = 0;
do {
if (*c == '-')
j *= -1;
else if (*c >= '0' && *c <= '9')
num = num * 10 + (*c - '0');
else if (num > 0)
 break;
} while (*c++);
return (num * j);
}

