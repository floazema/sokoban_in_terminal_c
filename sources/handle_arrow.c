/*
** EPITECH PROJECT, 2022
** error handling sokoban
** File description:
** sokoban
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "struct.h"

void left_key(char **map, p_t *p)
{
    if (map[p->p_y][p->p_x - 1] != '#') {
        if (map[p->p_y][p->p_x - 1] == 'X' && map[p->p_y][p->p_x - 2] == 'X')
            return;
        if (map[p->p_y][p->p_x - 1] == 'X' && map[p->p_y][p->p_x - 2] != '#') {
            map[p->p_y][p->p_x - 2] = 'X';
        }
        if (map[p->p_y][p->p_x - 2] == 'X' && map[p->p_y][p->p_x - 3]
        != ' ' && map[p->p_y - 1][p->p_x - 2] != ' ')
            p->blocked_box += 1;
        else if (map[p->p_y][p->p_x - 2] == 'X' && map[p->p_y][p->p_x - 3]
        != ' ' && map[p->p_y + 1][p->p_x - 2] != ' ')
            p->blocked_box += 1;
        if (map[p->p_y][p->p_x - 1] == 'X' && map[p->p_y][p->p_x - 2] == '#')
            return;
        map[p->p_y][p->p_x - 1] = map[p->p_y][p->p_x];
        map[p->p_y][p->p_x] = ' ';
        p->p_x -= 1;
    }
}

void right_key(char **map, p_t *p)
{
    if (map[p->p_y][p->p_x + 1] != '#') {
        if (map[p->p_y][p->p_x + 1] == 'X' && map[p->p_y][p->p_x + 2] == 'X')
            return;
        if (map[p->p_y][p->p_x + 1] == 'X' && map[p->p_y][p->p_x + 2] != '#') {
            map[p->p_y][p->p_x + 2] = 'X';
        }
        if (map[p->p_y][p->p_x + 2] == 'X' && map[p->p_y][p->p_x + 3]
        != ' ' && map[p->p_y + 1][p->p_x + 2] != ' ')
            p->blocked_box += 1;
        else if (map[p->p_y][p->p_x + 2] == 'X' && map[p->p_y][p->p_x + 3]
        != ' ' && map[p->p_y -1][p->p_x + 2] != ' ')
            p->blocked_box += 1;
        if (map[p->p_y][p->p_x + 1] == 'X' && map[p->p_y][p->p_x + 2] == '#')
            return;
        map[p->p_y][p->p_x + 1] = map[p->p_y][p->p_x];
        map[p->p_y][p->p_x] = ' ';
        p->p_x += 1;
    }
}

void up_key(char **map, p_t *p)
{
    if (map[p->p_y - 1][p->p_x] != '#') {
        if (map[p->p_y - 1][p->p_x] == 'X' && map[p->p_y - 2][p->p_x] == 'X')
            return;
        if (map[p->p_y - 1][p->p_x] == 'X' && map[p->p_y - 2][p->p_x] != '#') {
            map[p->p_y - 2][p->p_x] = 'X';
        }
        if (map[p->p_y - 2][p->p_x] == 'X' && map[p->p_y - 3][p->p_x]
        != ' ' && map[p->p_y - 2][p->p_x + 1] != ' ')
            p->blocked_box += 1;
        else if (map[p->p_y - 2][p->p_x] == 'X' && map[p->p_y - 3][p->p_x]
        != ' ' && map[p->p_y - 2][p->p_x - 1] != ' ')
            p->blocked_box += 1;
        if (map[p->p_y - 1][p->p_x] == 'X' && map[p->p_y - 2][p->p_x] == '#')
            return;
        map[p->p_y - 1][p->p_x] = map[p->p_y][p->p_x];
        map[p->p_y][p->p_x] = ' ';
        p->p_y -= 1;
    }
}

void down_key(char **map, p_t *p)
{
    if (map[p->p_y + 1][p->p_x] != '#') {
        if (map[p->p_y + 1][p->p_x] == 'X' && map[p->p_y + 2][p->p_x] == 'X')
            return;
        if (map[p->p_y + 1][p->p_x] == 'X' && map[p->p_y + 2][p->p_x] != '#') {
            map[p->p_y + 2][p->p_x] = 'X';
        }
        if (map[p->p_y + 2][p->p_x] == 'X' && map[p->p_y + 3][p->p_x] != ' ' &&
        map[p->p_y + 2][p->p_x - 1] != ' ')
            p->blocked_box += 1;
        else if (map[p->p_y + 2][p->p_x] == 'X' && map[p->p_y + 3][p->p_x]
        != ' ' && map[p->p_y + 2][p->p_x + 1] != ' ')
            p->blocked_box += 1;
        if (map[p->p_y + 1][p->p_x] == 'X' && map[p->p_y + 2][p->p_x] == '#')
            return;
        map[p->p_y + 1][p->p_x] = map[p->p_y][p->p_x];
        map[p->p_y][p->p_x] = ' ';
        p->p_y += 1;
    }
}

void get_input(char **map, p_t *p, int key, char **savemap)
{
    if (key == 260)
        left_key(map, p);
    if (key == 261)
        right_key(map, p);
    if (key == 259)
        up_key(map, p);
    if (key == KEY_DOWN)
        down_key(map, p);
    if (key == ' ')
        restart_game(map, savemap, p);
    clear();
}