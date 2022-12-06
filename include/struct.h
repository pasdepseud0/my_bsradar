/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** struct of project
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/CircleShape.h>

    typedef struct window {
        sfRenderWindow *window;
    } window_t;

    typedef struct circle {
        sfCircleShape *circle;
    } circle_t;

    typedef struct global {
        window_t a_window;
        circle_t a_circle;
    } global_t;

    #define sfcf sfTexture_createFromFile
    #define sfcw sfRenderWindow_create
    #define sfst sfSprite_setTexture
    #define sfss sfSprite_setScale
    #define sfsp sfSprite_setPosition
    #define sfds sfRenderWindow_drawSprite
    #define sfFRc sfFloatRect_contains
    #define sftr sfSprite_setTextureRect
    #define sfmgp sfMouse_getPositionRenderWindow
    #define sfdCS sfRenderWindow_drawCircleShape

#endif
