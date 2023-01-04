/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** step02
*/

#include <SFML/Graphics.h>

int is_intersecting_circles(sfCircleShape* c1, sfCircleShape* c2)
{
    sfVector2f pos1 = sfCircleShape_getPosition(c1);
    float radius1 = sfCircleShape_getRadius(c1);
    sfVector2f pos2 = sfCircleShape_getPosition(c2);
    float radius2 = sfCircleShape_getRadius(c2);

    if ((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) *
        (pos1.y - pos2.y) <= (radius1 + radius2) * (radius1 + radius2))
        return 1;
    else
        return 0;
}
