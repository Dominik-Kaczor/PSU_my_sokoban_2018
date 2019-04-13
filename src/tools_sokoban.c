/*
** EPITECH PROJECT, 2018
** tools_sokoban
** File description:
** tools_sokoban
*/

#include "include/my.h"
#include "include/sokoban.h"

void maps_array(maps_t *maps, char *buffer)
{
    int g = 0;

    for (int a = 0; a < maps->maps_lines; a++) {
        for (int b = 0; b < maps->maps_cols; b++) {
            if (buffer[g] != '\n') {
                maps->maps_array[a][b] = buffer[g];
                maps->maps_sauvg[a][b] = buffer[g];
                g++;
            }
            if (buffer[g] == '\n' && b + 1 == maps->maps_cols) {
                maps->maps_array[a][b + 1] = '\n';
                maps->maps_sauvg[a][b + 1] = '\n';
                g++;
            } else if (buffer[g] == '\n' && b < maps->maps_cols) {
                maps->maps_array[a][b + 1] = ' ';
                maps->maps_sauvg[a][b + 1] = ' ';
            }
        }
    }
    center_maps(maps, buffer);
}

void scan_size(maps_t *maps, char *buffer)
{
    int max = 0;
    int count = 0;

    for (int g = 0; g != maps->size; g++) {
        if (buffer[g] == '\n') {
            maps->maps_lines++;
            if (count > max)
                max = count;
            count = 0;
        }
        count++;
    }
    maps->maps_cols = max;
    maps->maps_lines++;
    maps->maps_array = malloc(sizeof(char *) * maps->maps_lines);
    maps->maps_sauvg = malloc(sizeof(char *) * maps->maps_lines);
    for (int i = 0; i != maps->maps_lines; i++) {
        maps->maps_array[i] = malloc(sizeof(char) * maps->maps_cols);
        maps->maps_sauvg[i] = malloc(sizeof(char) * maps->maps_cols);
    }
}

int primat_b(maps_t *maps, char *buffer)
{
    int o = 0;
    maps->counter_x = 0;

    for (int k = 0; k != maps->size; k++) {
        if (buffer[k] == 'X')
            maps->counter_x++;
        if (buffer[k] == 'O')
            o++;
    }
    if (maps->counter_x != o) {
        write(2, "error of characters\n", 20);
        return (84);
    }
    scan_size(maps, buffer);
    maps_array(maps, buffer);
    free(buffer);
}

int primat(maps_t *maps, int fd, int size_d)
{
    char *buffer = malloc(sizeof(char) * size_d);
    int p = 0;

    read(fd, buffer, size_d);
    maps->size = size_d;
    for (int k = 0; k != maps->size; k++) {
        if (buffer[k] != 'O' && buffer[k] != 'X' && buffer[k] != 'P' &&
            buffer[k] != '#' && buffer[k] != ' ' && buffer[k] != '\n') {
            write(2, "error of characters\n", 20);
            return (84);
        }
        if (buffer[k] == 'P')
            p++;
    }
    if (p != 1) {
        write(2, "error of characters\n", 20);
        return (84);
    }
    primat_b(maps, buffer);
}

void description(void)
{
    my_putstr("USAGE\n");
    my_putstr("   ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, containing '#'");
    my_putstr(" for walls,\n");
    my_putstr("         'P' for the player, 'X' for boxes and 'O' for");
    my_putstr(" storage locations.\n");
    exit (0);
}
