/*
** EPITECH PROJECT, 2022
** my_radar.h
** File description:
** all functions for projection my_radar
*/

#ifndef MY_RADAR_
    #define MY_RADAR_

    #include "struct.h"
    #include "list.h"

    list_t *list_create(void);
    unsigned int list_add(list_t *list, void *value);
    void *list_get(list_t *list, unsigned int index);
    general_list_t *list_get_node(list_t *list, unsigned int index);
    void list_remove(list_t *list, unsigned int index);
    void my_putstr(char const *str);
    int my_strlen(char const *str);
    global_t create_all(global_t global);
    void loop(global_t global, sfEvent event);

#endif
