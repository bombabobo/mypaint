/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** init
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/settings.h"
#include <stdlib.h>

static button_s create_but(sfTexture *texture, float x, float y, int nb)
{
    button_s button;
    sfIntRect symbole_rect = (sfIntRect){(nb - 1) * T_S, 0, T_S, T_S};

    button.number = nb;
    button.symbole = sfTexture_createFromFile(B_S_TEX, &symbole_rect);
    button.rect = sfRectangleShape_create();
    button.sym_rec = sfRectangleShape_create();
    button.texture_rect = (sfIntRect){0, 0, T_S, T_S};
    button.is_clicked = is_clicked;
    button.is_hover = is_hover;
    sfRectangleShape_setTextureRect(button.rect, button.texture_rect);
    sfRectangleShape_setPosition(button.rect, (sfVector2f){x, y});
    sfRectangleShape_setSize(button.rect, (sfVector2f){G_B_SIZE, G_B_SIZE});
    sfRectangleShape_setTexture(button.rect, texture, sfTrue);
    sfRectangleShape_setPosition(button.sym_rec, (sfVector2f){x, y});
    sfRectangleShape_setSize(button.sym_rec, (sfVector2f){G_B_SIZE, G_B_SIZE});
    sfRectangleShape_setTexture(button.sym_rec, button.symbole, sfTrue);
    return button;
}

static grid_s create_grid(void)
{
    grid_s grid;

    grid.texture = sfTexture_createFromFile(G_TEX, NULL);
    grid.buttons_texture = sfTexture_createFromFile(BASE_B_TEX, NULL);
    grid.rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(grid.rect, (sfVector2f){G_POS_X, G_POS_Y});
    sfRectangleShape_setSize(grid.rect, (sfVector2f){G_SIZE_X, G_SIZE_Y});
    grid.currentbutton = 1;
    grid.button1 = create_but(GRID_B_T, G_B_POSE(0), G_POS_Y, 1);
    grid.button2 = create_but(GRID_B_T, G_B_POSE(1), G_POS_Y, 2);
    grid.button3 = create_but(GRID_B_T, G_B_POSE(2), G_POS_Y, 3);
    grid.button4 = create_but(GRID_B_T, G_B_POSE(3), G_POS_Y, 4);
    grid.button5 = create_but(GRID_B_T, G_B_POSE(4), G_POS_Y, 5);
    grid.button6 = create_but(GRID_B_T, G_B_POSE(5), G_POS_Y, 6);
    grid.button7 = create_but(GRID_B_T, G_B_POSE(6), G_POS_Y, 7);
    grid.button8 = create_but(GRID_B_T, G_B_POSE(7), G_POS_Y, 8);
    sfRectangleShape_setTexture(grid.rect, grid.texture, sfTrue);
    return grid;
}

palette_s create_palette(void)
{
    palette_s palette;

    palette.texture = sfTexture_createFromFile(P_TEX, NULL);
    palette.rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(palette.rect, (sfVector2f){P_POS_X, P_POS_Y});
    sfRectangleShape_setSize(palette.rect, (sfVector2f){P_SIZE_X, P_SIZE_Y});
    palette.grid1 = create_grid();
    sfRectangleShape_setTexture(palette.rect, palette.texture, sfTrue);
    return palette;
}

ui_struct create_ui(void)
{
    ui_struct ui;

    ui.canva.image_buffer = sfImage_createFromColor(C_BG_SIZE_X, C_BG_SIZE_Y,
        sfWhite);
    ui.canva.radius = 5;
    ui.canva.texture_buffer = sfTexture_create(C_BG_SIZE_X, C_BG_SIZE_Y);
    ui.canva.texture_bg = sfTexture_createFromFile(C_BG_TEX, NULL);
    ui.canva.texture_dz = sfTexture_createFromFile(C_DZ_TEX, NULL);
    ui.canva.background = sfRectangleShape_create();
    ui.canva.dz_bg = sfRectangleShape_create();
    ui.canva.drawzone = sfSprite_create();
    sfRectangleShape_setPosition(C_BG, (sfVector2f){C_BG_POS_X, C_BG_POS_Y});
    sfRectangleShape_setSize(C_BG, (sfVector2f){C_BG_SIZE_X, C_BG_SIZE_Y});
    sfRectangleShape_setTexture(C_BG, ui.canva.texture_bg, sfTrue);
    sfRectangleShape_setPosition(C_DZ, (sfVector2f){C_DZ_POS_X, C_DZ_POS_Y});
    sfRectangleShape_setSize(C_DZ, (sfVector2f){C_DZ_SIZE_X, C_DZ_SIZE_Y});
    sfRectangleShape_setTexture(C_DZ, ui.canva.texture_dz, sfTrue);
    ui.palette = create_palette();
    return ui;
}

gstruct create_gamestruct(void)
{
    gstruct game;

    game.ui = malloc(sizeof(ui_struct));
    *game.ui = create_ui();
    game.ui->canva.is_drawing = sfFalse;
    game.ui->canva.color = sfBlack;
    game.ui->palette.grid1.currentbutton = 2;
    return game;
}
