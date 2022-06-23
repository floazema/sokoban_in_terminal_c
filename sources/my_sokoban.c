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

void create_tab(char **map, p_t *p)
{
    p->hole_pos = malloc(sizeof(int) * p->h_number * 2);
    for (int x = 0, y = 0, i = 0; map[y] != NULL; x++) {
        if (map[y][x] == 'O') {
            p->hole_pos[i] = y;
            p->hole_pos[i + 1] = x;
            i += 2;
        }
        if (map[y][x] == '\0')
            x = -1, y++;
    }
    p->box_pos = malloc(sizeof(int) * p->b_number * 2);
    for (int x = 0, y = 0, i = 0; map[y] != NULL; x++) {
        if (map[y][x] == 'O') {
            p->box_pos[i] = y;
            p->box_pos[i + 1] = x;
            i += 2;
        }
        if (map[y][x] == '\0')
            x = -1, y++;
    }
}

void init_window(char **map, p_t *p)
{
    curs_set(0);
    create_tab(map, p);
    for (int i = 0; map[i] != NULL; printw("%s\n", map[i]), i++);
    keypad(stdscr, TRUE);
}

void restart_game(char **map, char **savemap, p_t *p)
{
    p->p_x = p->save_p_x;
    p->p_y = p->save_p_y;
    p->blocked_box = 0;
    for (int x = 0, y = 0; map[y] != NULL; x++) {
        map[y][x] = savemap[y][x];
        if (map[y][x] == '\0') {
            x = -1;
            y++;
        }
    }
}

int hole_appear(char **map, p_t *p)
{
    for (int i = 0; i != p->h_number * 2;) {
        if (map[p->hole_pos[i]][p->hole_pos[i + 1]] != 'X'
        && map[p->hole_pos[i]][p->hole_pos[i + 1]] != 'P')
            map[p->hole_pos[i]][p->hole_pos[i + 1]] = 'O';
        i += 2;
    }
    for (int i = 0; i != p->h_number * 2;) {
        if (map[p->hole_pos[i]][p->hole_pos[i + 1]] != 'X')
            return 0;
        i += 2;
    }
    return 1;
}

int start_game(char **map, char **savemap, p_t *p)
{
    int key = 0;
    int k = 0;
    initscr();
    init_window(map, p);
    while (k < 1) {
        key = getch();
        get_input(map, p, key, savemap);
        if (p->blocked_box == p->b_number)
            k = 2;
        if (hole_appear(map, p) == 1)
            k = 1;
        for (int i = 0; map[i] != NULL; printw("%s\n", map[i]), i++);
    }
    if (k == 1) {
        return 0;
    } else
        return 1;
}
