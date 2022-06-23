/*
** EPITECH PROJECT, 2021
** mystruct
** File description:
** struct init
*/

#include "struct.h"
#ifndef MY_H_
    #define MY_H_

int my_printf(char const*, ...);
int my_strcmp(char const*, char const*);
int handle_error(char **map,  p_t*);
char **create_map(char *file);
int start_game(char **map, char **savemap, p_t *p);
void restart_game(char **map, char **savemap, p_t *p);
void get_input(char **map, p_t *p, int key, char **savemap);
#endif
