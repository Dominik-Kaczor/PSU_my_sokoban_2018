/*
** EPITECH PROJECT, 2018
** position_xy
** File description:
** movment
*/

#include "include/my.h"
#include "include/sokoban.h"

void pos_ini(maps_t *maps)
{
    maps->omax = 0;

    for (int a = 0; a < maps->maps_lines; a++) {
        for (int b = 0; b < maps->maps_cols; b++) {
            if (maps->maps_array[a][b] == 'P') {
                maps->x = a;
                maps->y = b;
            }
            if (maps->maps_array[a][b] == 'O')
                maps->omax++;
        }
    }
}

void position(maps_t *maps)
{
    if (maps->key == KEY_UP)
        move_up(maps, maps->x, maps->y);
    if (maps->key == KEY_RIGHT)
        move_right(maps, maps->x, maps->y);
    if (maps->key == KEY_LEFT)
        move_left(maps, maps->x, maps->y);
    if (maps->key == KEY_DOWN)
        move_down(maps, maps->x, maps->y);
}

void checkout_end(maps_t *maps)
{
    int nb = 0;

    for (int a = 0; a < maps->maps_lines; a++) {
        for (int b = 0; b < maps->maps_cols; b++) {
            if (maps->maps_array[a][b] == 'X' &&
                maps->maps_sauvg[a][b] == 'O') {
                nb++;
            } else if (maps->maps_array[a][b] == ' ' &&
                       maps->maps_sauvg[a][b] == 'O')
                maps->maps_array[a][b] = 'O';
            if (nb == maps->omax)
                maps->key = KEY_BACKSPACE;
        }
    }
}
