/*
** EPITECH PROJECT, 2022
** B-MUL-100-REN-1-1-myhunter-ludwig.vandenberghe
** File description:
** set_struct
*/

#include "my.h"
#include "struct.h"
#include "my_radar.h"
#include "list.h"

window_t create_window(window_t window)
{
    sfVideoMode mode = {1920, 1080, 32};
    char *name = "My Radar";

    window.window = sfcw(mode, name, sfResize | sfClose, NULL);
    return (window);
}

static circle_t create_circle(circle_t circle)
{
    circle.circle = sfCircleShape_create();
    return (circle);
}

global_t create_all(global_t global)
{
    window_t window = create_window(window);
    circle_t circle = create_circle(circle);
    global.a_window = window;
    global.a_circle = circle;
    return (global);
}
