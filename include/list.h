/*
** EPITECH PROJECT, 2022
** list.h
** File description:
** chained list
*/

#include <stdlib.h>

#ifndef LIST_H_
    #define LIST_H_

    typedef struct general_list_s {
        void *value;
        struct general_list_s *next;
        struct general_list_s *prev;
    } general_list_t;

    typedef struct list_s {
        general_list_t *head;
        general_list_t *tail;
        unsigned int size;
    } list_t;

#endif
