/*
** EPITECH PROJECT, 2022
** core.c
** File description:
** core of project
*/

#include "struct.h"
#include "my_radar.h"

int main(void)
{
    global_t all = create_all(all);
    sfEvent event;

    loop(all, event);
    return (0);
}
