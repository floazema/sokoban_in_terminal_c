/*
** EPITECH PROJECT, 2022
** error handling sokoban
** File description:
** sokoban
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

const char str[] = "USAGE\n\t./my_sokoban map\nDESCRIPTION\n"\
"\tmap file representing the warehouse map, containing ‘#’ for walls,"\
"\n\t\t‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.";

int map_error(char **map, p_t *p)
{
    for (int x = 0, y = 0; map[y] != NULL; x++) {
        if (map[y][x] != 'X' && map[y][x] != 'P' && map[y][x] != ' '
        && map[y][x] != '#' && map[y][x] != '\0' && map[y][x] != 'O')
            return 84;
        if (map[y][x] == 'P') {
            p->p_number += 1;
            p->p_x = x;
            p->p_y = y;
        }
        if (map[y][x] == 'O')
            p->h_number += 1;
        if (map[y][x] == 'X')
            p->b_number += 1;
        if (map[y][x] == '\0') {
            x = -1;
            y++;
        }
    }
    return 0;
}

int handle_error(char **map, p_t *p)
{
    if (map == NULL)
        return 84;
    map_error(map, p);
    if (p->p_number != 1)
        return 84;
    p->save_p_x = p->p_x;
    p->save_p_y = p->p_y;
    return 1;
}
