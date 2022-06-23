/*
** EPITECH PROJECT, 2022
** alloc map
** File description:
** alloc map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "my.h"

char **alloc_map(char *str)
{
    char **map = NULL;
    int line_number = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            line_number++;
    map = malloc(sizeof(char*) * (line_number + 1));
    for (int i = 0, x = 0, y = 0; str[i] != '\0';) {
        if (str[i] == '\n') {
            map[y] = malloc(sizeof(char) * (x + 1));
            x = 0;
            y++;
        }
        i++;
        x++;
        if (str[i] == '\0' && str[i - 1] != '\n')
            map[y] = malloc(sizeof(char) * (x + 1));
    }
    map[line_number] = NULL;
    return map;
}

char **make_map(char *str, char **map)
{
    for (int i = 0, x = 0, y = 0; str[i] != '\0'; i++, x++) {
        if (str[i] == '\n' || str[i] == '\0') {
            map[y][x] = '\0';
            x = -1;
            y++;
            continue;
        }
        map[y][x] = str[i];
    }
    return map;
}

char **create_map(char *file)
{
    char **map = NULL;
    char *str = NULL;
    struct stat buff;
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return NULL;
    stat(file, &buff);
    str = malloc((buff.st_size) + 1);
    read(fd, str, (buff.st_size));
    str[buff.st_size] = '\0';
    map = alloc_map(str);
    map = make_map(str, map);
    return map;
}
