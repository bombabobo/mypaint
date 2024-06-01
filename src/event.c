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

static void key_events(sfRenderWindow *window, gstruct *gstruct)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
        COLOR_ = sfBlack;
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        COLOR_ = sfWhite;
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
        COLOR_ = sfRed;
    if (sfKeyboard_isKeyPressed(sfKeyNum4))
        COLOR_ = sfGreen;
    if (sfKeyboard_isKeyPressed(sfKeyNum5))
        COLOR_ = sfBlue;
    if (sfKeyboard_isKeyPressed(sfKeyNum6))
        COLOR_ = sfYellow;
    if (sfKeyboard_isKeyPressed(sfKeyNum7))
        COLOR_ = sfMagenta;
    if (sfKeyboard_isKeyPressed(sfKeyNum8))
        COLOR_ = sfCyan;
}

void draw_it(gstruct *gstruct, sfVector2i ij, sfVector2i dxy, sfColor color)
{
    if (dxy.x * dxy.x + dxy.y * dxy.y <= RADIUS_ * RADIUS_)
        sfImage_setPixel(gstruct->ui->canva.image_buffer, ij.x, ij.y, color);
}

static void drawcircle(gstruct *gstruct, sfVector2i mousepos, sfColor color)
{
    int x = mousepos.x / 0.75 - C_DZ_POS_X;
    int y = mousepos.y / 0.75 - C_DZ_POS_Y;
    int dx;
    int dy;

    if (x < (RADIUS_ + 2) || y < (RADIUS_ + 2) || x > 1920 - (RADIUS_ + 2) ||
        y > 1080 - (RADIUS_ + 2))
        return;
    for (int i = x - RADIUS_; i <= x + RADIUS_; ++i) {
        for (int j = y - RADIUS_; j <= y + RADIUS_; ++j) {
            dx = i - x;
            dy = j - y;
            draw_it(gstruct, (sfVector2i){i, j}, (sfVector2i){dx, dy}, color);
        }
    }
}

static void drawsquare(gstruct *gstruct, sfVector2i mousepos, sfColor color)
{
    int x = mousepos.x / 0.75 - C_DZ_POS_X;
    int y = mousepos.y / 0.75 - C_DZ_POS_Y;
    int halfSideLength = RADIUS_;
    int startX = x - halfSideLength;
    int startY = y - halfSideLength;
    sfVector2i pixelPos;

    if (x < halfSideLength + 2 || y < halfSideLength + 2 ||
        x > 1920 - (halfSideLength + 2) ||
        y > 1080 - (halfSideLength + 2))
        return;
    startX = x - halfSideLength;
    startY = y - halfSideLength;
    for (int i = startX; i <= startX + 2 * halfSideLength; ++i) {
        for (int j = startY; j <= startY + 2 * halfSideLength; ++j) {
            pixelPos = (sfVector2i){i, j};
            draw_it(gstruct, pixelPos, (sfVector2i){0, 0}, color);
        }
    }
}

void draw(gstruct *gstruct, sfVector2i mouspos)
{
    if (CURR_BUT_ == 1)
        drawcircle(gstruct, mouspos, sfTransparent);
    if (CURR_BUT_ == 2)
        drawcircle(gstruct, mouspos, COLOR_);
    if (CURR_BUT_ == 3)
        drawsquare(gstruct, mouspos, COLOR_);
}

void analyse_events(sfRenderWindow *window, sfEvent *event, gstruct *gstruct)
{
    while (sfRenderWindow_pollEvent(window, event)){
        if (event->type == sfEvtKeyPressed)
            key_events(window, gstruct);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event->type == sfEvtMouseButtonPressed && EMB_ == sfMouseLeft)
            gstruct->ui->canva.is_drawing = sfTrue;
        if (event->type == sfEvtMouseButtonReleased && EMB_ == sfMouseLeft)
            gstruct->ui->canva.is_drawing = sfFalse;
        if (event->type == sfEvtMouseWheelScrolled && EMWS_ > 0)
            RADIUS_++;
        if (event->type == sfEvtMouseWheelScrolled && EMWS_ < 0)
            RADIUS_ -= (RADIUS_ > 1) ? 1 : 0;
        if (gstruct->ui->canva.is_drawing)
            draw(gstruct, MGPRW_(window));
    }
    test_buttons(&gstruct->ui->palette.grid1, window, event);
}
