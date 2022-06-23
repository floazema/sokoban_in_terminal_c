/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** sokoban
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "struct.h"

extern const char str[];

int args_error(char **av, int ac)
{
    if (ac != 2) {
        my_printf("%s\n", str);
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        my_printf("%s\n", str);
        return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    int k = 1;
    p_t *p = malloc(sizeof(p_t));
    char **map = NULL;
    char **savemap = NULL;
    if (args_error(av, ac) == 84)
        return 84;
    map = create_map(av[1]);
    savemap = create_map(av[1]);
    k = handle_error(map, p);
    if (k == 84)
        return 84;
    if (start_game(map, savemap, p) == 0) {
        refresh();
        endwin();
        return 0;
    } else {
        refresh();
        endwin();
        return 1;
    }
}
