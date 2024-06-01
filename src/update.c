/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** update
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

static void draw_button(button_s button, sfRenderWindow *window)
{
    sfRectangleShape_setTextureRect(button.rect, button.texture_rect);
    sfRenderWindow_drawRectangleShape(window, button.rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button.sym_rec, NULL);
}

void render_buttons(button_s button, sfRenderWindow *window)
{
    switch (button.state) {
        case HOVER:
            button.texture_rect.left = (1 * T_S);
            break;
        case CLICKED:
            button.texture_rect.left = (2 * T_S);
            break;
        case UNCLICKED:
            button.texture_rect.left = (2 * T_S);
            break;
        case PRESSED:
            button.texture_rect.left = (3 * T_S);
            break;
        default:
            button.texture_rect.left = 0;
            break;
    }
    draw_button(button, window);
}

static void render_8xgrids(grid_s *grid, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, grid->rect, NULL);
    render_buttons(grid->button1, window);
    render_buttons(grid->button2, window);
    render_buttons(grid->button3, window);
    render_buttons(grid->button4, window);
    render_buttons(grid->button5, window);
    render_buttons(grid->button6, window);
    render_buttons(grid->button7, window);
    render_buttons(grid->button8, window);
    if (grid->currentbutton == -1)
        grid->button1.state = PRESSED;
}

void render_palette(palette_s palette, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, palette.rect, NULL);
    render_8xgrids(&palette.grid1, window);
}

void render_canva(canva_t canva, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, canva.background, NULL);
    sfRenderWindow_drawRectangleShape(window, canva.dz_bg, NULL);
    sfTexture_updateFromImage(canva.texture_buffer, canva.image_buffer, 0, 0);
    sfSprite_setTexture(canva.drawzone, canva.texture_buffer, sfTrue);
    sfSprite_setScale(canva.drawzone, (sfVector2f){0.75, 0.75});
    sfSprite_setPosition(canva.drawzone, (sfVector2f){C_DZ_POS_X, C_DZ_POS_Y});
    sfRenderWindow_drawSprite(window, canva.drawzone, NULL);
}

void render_ui(ui_struct *ui, sfRenderWindow *window)
{
    render_canva(ui->canva, window);
    render_palette(ui->palette, window);
}

void upd_ui(gstruct *gstruct, sfRenderWindow *window)
{
    render_ui(gstruct->ui, window);
}
