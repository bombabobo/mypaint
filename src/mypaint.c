/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** mypaint
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

sfRenderWindow *create_render_window(sfRenderWindow *window)
{
    sfVideoMode videoMode = {V_MODE};
    sfImage *icon = sfImage_createFromFile(LOGO);
    sfVector2u iconSize = sfImage_getSize(icon);
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);

    window = sfRenderWindow_create(videoMode, TITLE, BSTYLE, 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, iconSize.x, iconSize.y, pixels);
    sfImage_destroy(icon);
    return window;
}

void end(gstruct *gstruct)
{
    sfRectangleShape_destroy(gstruct->ui->canva.background);
    sfRectangleShape_destroy(gstruct->ui->canva.dz_bg);
    sfSprite_destroy(gstruct->ui->canva.drawzone);
    sfRectangleShape_destroy(gstruct->ui->palette.rect);
    sfRectangleShape_destroy(gstruct->ui->palette.grid1.button1.rect);
    sfRectangleShape_destroy(gstruct->ui->palette.grid1.button2.rect);
    sfRectangleShape_destroy(gstruct->ui->palette.grid1.button3.rect);
    sfRectangleShape_destroy(gstruct->ui->palette.grid1.button4.rect);
    sfRectangleShape_destroy(gstruct->ui->palette.grid1.button5.rect);
    sfRectangleShape_destroy(gstruct->ui->palette.grid1.button6.rect);
    sfRectangleShape_destroy(gstruct->ui->palette.grid1.button7.rect);
    sfRectangleShape_destroy(gstruct->ui->palette.grid1.button8.rect);
    sfTexture_destroy(gstruct->ui->palette.grid1.buttons_texture);
    sfTexture_destroy(gstruct->ui->palette.grid1.texture);
    sfTexture_destroy(gstruct->ui->canva.texture_bg);
    sfTexture_destroy(gstruct->ui->canva.texture_dz);
    sfTexture_destroy(gstruct->ui->palette.texture);
    sfTexture_destroy(gstruct->ui->canva.texture_buffer);
    free(gstruct->ui);
}

int my_paint(gstruct *gstruct)
{
    sfRenderWindow *window = create_render_window(window);
    sfEvent event;

    gstruct->gameclock = sfClock_create();
    upd_ui(gstruct, window);
    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_clear(window, sfBlack);
        upd_ui(gstruct, window);
        analyse_events(window, &event, gstruct);
        sfRenderWindow_display(window);
    }
    end(gstruct);
}

int main(int ac, char **av)
{
    gstruct gstruct = create_gamestruct();

    if (av[1] && !my_strcmp(av[1], "-h")){
        my_printf("Use key 1 to 8 to change color\nUse echap to quit\n");
        my_printf("Use mouse wheel to change the size of the brush\n");
        my_printf("only the eraser, pencil and 3rd button are working.\n");
        my_printf("the brush is painting rounds, the 3rd button is");
        my_printf("painting squares.\n");
        return 0;
    }
    if (ac > 1)
        return 84;
    my_paint(&gstruct);
    return 0;
}
