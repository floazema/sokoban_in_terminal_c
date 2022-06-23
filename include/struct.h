/*
** EPITECH PROJECT, 2021
** mystruct
** File description:
** struct init
*/

#ifndef __MY_STRUCT__
    #define __MY_STRUCT__

typedef struct sokoban {
    int p_number;
    int p_x;
    int p_y;
    int save_p_x;
    int save_p_y;
    int b_number;
    int h_number;
    int blocked_box;
    int *hole_pos;
    int *box_pos;
} p_t;

#endif/*__MY_STRUCT__*/
