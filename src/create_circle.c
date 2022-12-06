/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "list.h"
#include "my_radar.h"
#include "my.h"
#include "struct.h"

void find_event(global_t all, sfEvent event)
{
    while (sfRenderWindow_pollEvent(all.a_window.window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(all.a_window.window);
        }
        if (event.key.code == sfKeyEscape) {
            sfRenderWindow_close(all.a_window.window);
        }
    }
}

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setPosition(circle, position);
    return (circle);
}

sfCircleShape *create_circle_white(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setFillColor(circle, sfWhite);
    sfCircleShape_setPosition(circle, position);
    return (circle);
}

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    float radc1;
    float radc2;
    sfVector2f vecc1;
    sfVector2f vecc2;
    int res;

    radc1 = sfCircleShape_getRadius(c1);
    radc2 = sfCircleShape_getRadius(c2);
    vecc1 = sfCircleShape_getPosition(c1);
    vecc2 = sfCircleShape_getPosition(c2);
    res = ((vecc1.x - vecc2.x) * (vecc1.x - vecc2.x))
            + ((vecc1.y - vecc2.y) * (vecc1.y - vecc2.y));
    if (res <= ((radc1 + radc2) * (radc1 + radc2)))
        return (1);
    return (0);
}

void loop(global_t global, sfEvent event)
{
    float rad = 200;
    sfCircleShape *circle_1 = create_circle((sfVector2f) {200.50, 200.50}, rad);
    sfCircleShape *circle_2 = create_circle((sfVector2f) {700.50, 700.50}, rad);

    if (is_intersecting_circles(circle_1, circle_2) == 1) {
        circle_1 = create_circle_white((sfVector2f) {200.50, 200.50}, rad);
        circle_2 = create_circle_white((sfVector2f) {700.50, 700.50}, rad);
    }
    while (sfRenderWindow_isOpen(global.a_window.window)) {
        sfRenderWindow_clear(global.a_window.window, sfBlack);
        sfdCS(global.a_window.window, circle_1, NULL);
        sfdCS(global.a_window.window, circle_2, NULL);
        sfRenderWindow_display(global.a_window.window);
        find_event(global, event);
    }
}
