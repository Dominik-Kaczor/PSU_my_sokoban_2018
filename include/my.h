/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef PROT_F_
#define PROT_F_

#include <ncurses.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

int my_putstr(char const *str);
void scan_size(maps_t *maps, char *buffer);
int primat(maps_t *maps, int fd, int size_d);
void description(void);
void checkout_end(maps_t *maps);
void position(maps_t *maps);
void pos_ini(maps_t *maps);
int center_maps(maps_t *maps, char *buffer);
void maps_array(maps_t *maps, char *buffer);
void move_up(maps_t *maps, int x, int y);
void move_down(maps_t *maps, int x, int y);
void move_left(maps_t *maps, int x, int y);
void move_right(maps_t *maps, int x, int y);

#endif /* PROT_F_ */
