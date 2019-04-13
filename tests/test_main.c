/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** game sokoban
*/

#include <ncurses.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/sokoban.h"

void checkout_box_b(maps_t *maps, int a, int b)
{
    if (maps->maps_array[a][b] == 'X' &&
        maps->maps_array[a - 1][b] == '#' &&
        maps->maps_array[a][b + 1] == '#' &&
        maps->maps_sauvg[a][b] != 'O')
        maps->k = 1;
    if (maps->maps_array[a][b] == 'X' &&
        maps->maps_array[a - 1][b] == '#' &&
        maps->maps_array[a][b - 1] == '#' &&
        maps->maps_sauvg[a][b] != 'O')
        maps->k = 1;
}

void checkout_box(maps_t *maps)
{
    for (int a = 0; a < maps->maps_lines; a++) {
        for (int b = 0; b < maps->maps_cols; b++) {
            if (maps->maps_array[a][b] == 'X' &&
                maps->maps_array[a + 1][b] == '#' &&
                maps->maps_array[a][b + 1] == '#' &&
                maps->maps_sauvg[a][b] != 'O')
                maps->k = 1;
            if (maps->maps_array[a][b] == 'X' &&
                maps->maps_array[a + 1][b] == '#' &&
                maps->maps_array[a][b - 1] == '#' &&
                maps->maps_sauvg[a][b] != 'O')
                maps->k = 1;
            checkout_box_b(maps, a ,b);
        }
    }
}

int center_maps_b(maps_t *maps)
{
    clear();
    for (int i = 0; i != maps->maps_lines; i++) {
        mvprintw((LINES / 2 - maps->maps_lines / 2) + i,
                 (COLS - maps->maps_cols) / 2,
                 "%s", maps->maps_array[i]);
    }
    refresh();
    keypad(stdscr, TRUE);
    maps->key = getch();
    position(maps);
}

int center_maps(maps_t *maps, char *buffer)
{
    pos_ini(maps);
    initscr();
    while (1) {
        curs_set(0);
        center_maps_b(maps);
        checkout_box(maps);
        checkout_end(maps);
        if (maps->key == ' ' || maps->key == KEY_BACKSPACE || maps->k == 1)
            break;
    }
    if (maps->key  == ' ')
        maps_array(maps, buffer);
    endwin();
    if (maps->k == 1)
        exit (1);
    if (maps->key == KEY_BACKSPACE)
        exit (0);
}

int test_main(int ac, char **av)
{
    maps_t maps;

    struct stat s;
    stat(av[1], &s);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        description();
    } else if (ac != 2) {
        write(2, "error of file\n", 14);
        return (84);
    }
    int fd = open(av[1], O_RDONLY);
    if (s.st_size == 0) {
        write(2, "error of size\n", 14);
        return (84);
    }else if (fd == -1) {
        write(2, "error\n", 6);
        return (84);
    }
    primat(&maps, fd, s.st_size);
}
