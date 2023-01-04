/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#define N 50

sfCircleShape* circles[N];

int is_intersecting_circles(sfCircleShape* c1, sfCircleShape* c2);
sfCircleShape *create_circle(sfVector2f position, float radius);

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    return sfRenderWindow_create(mode, "My Radar", sfClose, NULL);
}

void handle_window_events(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void draw_window_content(sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);

    for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
        if (is_intersecting_circles(circles[i], circles[j])) {
            sfCircleShape_setFillColor(circles[i], sfWhite);
            sfCircleShape_setFillColor(circles[j], sfWhite);
        }
    }
}
for (int i = 0; i < N; i++) {
    sfRenderWindow_drawCircleShape(window, circles[i], NULL);
}
sfRenderWindow_display(window);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    sfRenderWindow *window = create_window();

for (int i = 0; i < N; i++) {
    sfVector2f position = {rand() % 800, rand() % 600};
    circles[i] = create_circle(position, rand() % 50);
}

while (sfRenderWindow_isOpen(window)) {
    handle_window_events(window);
    draw_window_content(window);
}

for (int i = 0; i < N; i++)
    sfCircleShape_destroy(circles[i]);

sfRenderWindow_destroy(window);
return 0;
}
