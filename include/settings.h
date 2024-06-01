/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** settings
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#include "struct.h"
#ifndef SETTINGS_H_
    #define SETTINGS_H_
    // Macros concat
    #define CONCATENATE_HELPER(x, y, z) x##y##z
    #define CONCATENATE(x, y, z) CONCATENATE_HELPER(x, y, z)
    #define G_B_POSE(nb) (G_POS_X + (G_B_SIZE * (nb)))
    #define B_TEX(var) BUTTON_TEXTURE_##var
    // Macros racourcis function csfml
    #define EMBR_ sfEvtMouseButtonReleased
    #define EMBP_ sfEvtMouseButtonPressed
    #define BSTYLE sfClose | sfResize
    #define TITLE "my_paint"
    #define V_MODE 1920, 1080, 32
    #define LOGO "ressources/logo.jpg"
    #define EMB_ event->mouseButton.button
    #define EMWS_ event->mouseWheelScroll.delta
    #define MGPRW_ sfMouse_getPositionRenderWindow
    // Macros racourcis structs
    #define GRID_B_T grid.buttons_texture
    #define RADIUS_ gstruct->ui->canva.radius
    #define CURR_BUT_ gstruct->ui->palette.grid1.currentbutton
    #define COLOR_ gstruct->ui->canva.color
    // Macros racourcis macros
    #define B_S_TEX BUTTON_SYMBOLE_TEXTURE
    #define BASE_B_TEX BASE_BUTTON_TEXTURE
    #define G_TEX BASE_GRID_TEXTURE
    #define P_TEX PALETTE_TEXTURE
    #define P_SIZE_X PALETTE_SIZE_X
    #define P_SIZE_Y PALETTE_SIZE_Y
    #define P_POS_X PALETTE_POSITION_X
    #define P_POS_Y PALETTE_POSITION_Y
    #define G_SIZE_X GRID_SIZE_X
    #define G_SIZE_Y GRID_SIZE_Y
    #define G_POS_X GRID_POSITION_X
    #define G_POS_Y GRID_POSITION_Ybut
    #define G_B_SIZE GRID_BUTTON_SIZE
    #define C_BG ui.canva.background
    #define C_DZ ui.canva.dz_bg
    #define C_BG_TEX CANVA_BACKGROUND_TEXTURE
    #define C_DZ_TEX CANVA_DRAWZONE_TEXTURE
    #define C_BG_SIZE_X CANVA_BG_SIZE_X
    #define C_BG_SIZE_Y CANVA_BG_SIZE_Y
    #define C_BG_POS_X CANVA_BG_POSITION_X
    #define C_BG_POS_Y CANVA_BG_POSITION_Y
    #define C_DZ_SIZE_X CANVA_DZ_SIZE_X
    #define C_DZ_SIZE_Y CANVA_DZ_SIZE_Y
    #define C_DZ_POS_X CANVA_DZ_POSITION_X
    #define C_DZ_POS_Y CANVA_DZ_POSITION_Y
    #define T_S TEXTURE_SIZE

    // Macros pour les textures
    #define BASE_BUTTON_TEXTURE "ressources/UI/button.png"
    #define BASE_GRID_TEXTURE "ressources/UI/grid_texture.png"
    #define BUTTON_SYMBOLE_TEXTURE "ressources/UI/buttons_symbol.png"
    #define TEXTURE_SIZE 160

    // Macros pour la grille
    #define GRID_SIZE_X 480
    #define GRID_SIZE_Y 60
    #define GRID_POSITION_X 160
    #define GRID_POSITION_Y 40
    #define GRID_BUTTON_SIZE 60

    // Macros pour la texture et position/taille de la palette
    #define PALETTE_TEXTURE "ressources/UI/palette_texture.png"
    #define PALETTE_SIZE_X 1920
    #define PALETTE_SIZE_Y 100
    #define PALETTE_POSITION_X 0
    #define PALETTE_POSITION_Y 0

    // Macros pour la texture et position/taille du canva
    #define CANVA_BACKGROUND_TEXTURE "ressources/UI/canva_bg_texture.png"
    #define CANVA_DRAWZONE_TEXTURE "ressources/UI/canva_dz_texture.png"
    #define CANVA_BG_SIZE_X 1920
    #define CANVA_BG_SIZE_Y 1080
    #define CANVA_BG_POSITION_X 0
    #define CANVA_BG_POSITION_Y 0
    #define CANVA_DZ_SIZE_X 16 * 90
    #define CANVA_DZ_SIZE_Y 9 * 90
    #define CANVA_DZ_POSITION_X ((P_SIZE_X > 920) ? 10 : P_SIZE_X + 10)
    #define CANVA_DZ_POSITION_Y ((P_SIZE_Y > 540) ? 10 : P_SIZE_Y + 10)

#endif /* !SETTINGS_H_ */
