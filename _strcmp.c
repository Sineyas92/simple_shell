#include "main.h"

/**
 * _strcmp - compare deux chaînes de caractères.
 * @str1: première chaîne
 * @str2: deuxième chaîne
 * Return: zéro si str1 == str2.
 */
int _strcmp(char *str1, char *str2)
{
int index = 0, diff = 0;
while (1)
{
if (str1[index] == '\0' && str2[index] == '\0')
break;
else if (str1[index] == '\0')
{
diff = str2[index];
break;
}
else if (str2[index] == '\0')
{
diff = str1[index];
break;
}
else if (str1[index] != str2[index])
{
diff = str1[index] - str2[index];
break;
}
else
index++;
}
return(diff);
}

