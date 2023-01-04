/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** step01
*/

#include <SFML/Graphics.h>

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1.0f);
    return circle;
}
