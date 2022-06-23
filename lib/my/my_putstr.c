/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** putstr
*/

#include <unistd.h>

void my_putchar(char);
int my_strlen(char*);

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
