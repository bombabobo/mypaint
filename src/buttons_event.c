/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** atoi_and_event
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/settings.h"
#include "../include/struct.h"
#include "../include/my.h"
#include <math.h>

static void desac_all_but(grid_s *grid, int nb)
{
    grid->button1.state = (nb == 1) ? PRESSED : NONE;
    grid->button2.state = (nb == 2) ? PRESSED : NONE;
    grid->button3.state = (nb == 3) ? PRESSED : NONE;
    grid->button4.state = (nb == 4) ? PRESSED : NONE;
    grid->button5.state = (nb == 5) ? PRESSED : NONE;
    grid->button6.state = (nb == 6) ? PRESSED : NONE;
    grid->button7.state = (nb == 7) ? PRESSED : NONE;
    grid->button8.state = (nb == 8) ? PRESSED : NONE;
}

void is_clicked(button_s *but, sfVector2i mouse, int *C_but, sfEvent *event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(but->rect);
    int isitin = sfFloatRect_contains(&rect, mouse.x, mouse.y);

    if (!isitin && but->state == CLICKED)
        but->state = PRESSED;
    if (!isitin && but->state == UNCLICKED)
        but->state = NONE;
    if (isitin && but->state == HOVER && event->type == EMBP_){
        but->state = CLICKED;
        *C_but = but->number;
    }
    if (isitin && but->state == PRESSED && event->type == EMBP_)
        but->state = UNCLICKED;
    if (but->state == CLICKED && event->type == EMBR_)
        but->state = PRESSED;
    if (but->state == UNCLICKED && event->type == EMBR_)
        but->state = NONE;
}

void is_hover(button_s *button, sfVector2i mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);
    int isitin = sfFloatRect_contains(&rect, mouse.x, mouse.y);

    if (button->state == HOVER)
            button->state = NONE;
    if (isitin)
        if (button->state == NONE)
            button->state = HOVER;
}

void test_button(button_s *button, sfEvent *event, grid_s *grid
    , sfVector2i mouse_pos)
{
    sfMouseButtonEvent mouse_button_event;

    button->is_hover(button, mouse_pos);
    if (event->mouseButton.button == sfMouseLeft)
        button->is_clicked(button, mouse_pos, &grid->currentbutton, event);
}

void test_buttons(grid_s *grid, sfRenderWindow *window, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (event->type == sfEvtMouseMoved) {
        mouse_pos.x = event->mouseMove.x;
        mouse_pos.y = event->mouseMove.y;
    }
    desac_all_but(grid, grid->currentbutton);
    test_button(&grid->button1, event, grid, mouse_pos);
    test_button(&grid->button2, event, grid, mouse_pos);
    test_button(&grid->button3, event, grid, mouse_pos);
    test_button(&grid->button4, event, grid, mouse_pos);
    test_button(&grid->button5, event, grid, mouse_pos);
    test_button(&grid->button6, event, grid, mouse_pos);
    test_button(&grid->button7, event, grid, mouse_pos);
    test_button(&grid->button8, event, grid, mouse_pos);
}
