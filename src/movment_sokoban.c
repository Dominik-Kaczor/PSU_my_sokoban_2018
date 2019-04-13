/*
** EPITECH PROJECT, 2018
** movment
** File description:
** moving in the maps
*/

#include "include/my.h"
#include "include/sokoban.h"

void move_up(maps_t *maps, int xp, int yp)
{
    if (maps->maps_array[xp - 1][yp] != '#' &&
        maps->maps_array[xp - 1][yp] != 'X') {
        maps->maps_array[xp][yp] = ' ';
        maps->maps_array[xp - 1][yp] = 'P';
        maps->x = xp - 1;
    } else if (maps->maps_array[xp - 1][yp] != '#' &&
               maps->maps_array[xp - 2][yp] != '#') {
        if (maps->maps_array[xp - 1][yp] == 'X' &&
            maps->maps_array[xp - 2][yp] != 'X') {
            maps->maps_array[xp][yp] = ' ';
            maps->maps_array[xp - 1][yp] = 'P';
            maps->maps_array[xp - 2][yp] = 'X';
            maps->x = xp - 1;
        }
    }
}

void move_right(maps_t *maps, int xp, int yp)
{
    if (maps->maps_array[xp][yp + 1] != '#' &&
        maps->maps_array[xp][yp + 1] != 'X') {
        maps->maps_array[xp][yp] = ' ';
        maps->maps_array[xp][yp + 1] = 'P';
        maps->y = yp + 1;
    } else if (maps->maps_array[xp][yp + 1] != '#' &&
               maps->maps_array[xp][yp + 2] != '#') {
        if (maps->maps_array[xp][yp + 1] == 'X' &&
            maps->maps_array[xp][yp + 2] != 'X') {
            maps->maps_array[xp][yp] = ' ';
            maps->maps_array[xp][yp + 1] = 'P';
            maps->maps_array[xp][yp + 2] = 'X';
            maps->y = yp + 1;
        }
    }
}

void move_down(maps_t *maps, int xp, int yp)
{
    if (maps->maps_array[xp + 1][yp] != '#' &&
        maps->maps_array[xp + 1][yp] != 'X') {
        maps->maps_array[xp][yp] = ' ';
        maps->maps_array[xp + 1][yp] = 'P';
        maps->x = xp + 1;
    } else if (maps->maps_array[xp + 1][yp] != '#' &&
               maps->maps_array[xp + 2][yp] != '#') {
        if (maps->maps_array[xp + 1][yp] == 'X' &&
            maps->maps_array[xp + 2][yp] != 'X') {
            maps->maps_array[xp][yp] = ' ';
            maps->maps_array[xp + 1][yp] = 'P';
            maps->maps_array[xp + 2][yp] = 'X';
            maps->x = xp + 1;
        }
    }
}

void move_left(maps_t *maps, int xp, int yp)
{
    if (maps->maps_array[xp][yp - 1] != '#' &&
        maps->maps_array[xp][yp - 1] != 'X') {
        maps->maps_array[xp][yp] = ' ';
        maps->maps_array[xp][yp - 1] = 'P';
        maps->y = yp - 1;
    } else if (maps->maps_array[xp][yp - 1] != '#' &&
               maps->maps_array[xp][yp - 2] != '#') {
        if (maps->maps_array[xp][yp - 1] == 'X' &&
            maps->maps_array[xp][yp - 2] != 'X') {
            maps->maps_array[xp][yp] = ' ';
            maps->maps_array[xp][yp - 1] = 'P';
            maps->maps_array[xp][yp - 2] = 'X';
            maps->y = yp - 1;
        }
    }
}
