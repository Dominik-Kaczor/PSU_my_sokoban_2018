/*
** EPITECH PROJECT, 2018
** sokoban.h
** File description:
** prototyp all function
*/

#ifndef NAME_H_
#define NAME_H_

typedef struct maps{
    char **maps_array;
    char **maps_sauvg;
    int size;
    int maps_cols;
    int maps_lines;
    int x;
    int y;
    int key;
    int k;
    int g;
    int counter_x;
    int omax;
}maps_t;

#endif /* NAME_H_ */
