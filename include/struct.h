/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** struct
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#ifndef STRUCT_H_
    #define STRUCT_H_
    enum e_gui_state {
    NONE = 0,
    PRESSED,
    CLICKED,
    UNCLICKED,
    HOVER,
    BLOCKED
};
typedef struct button_t {
    int number;
    sfRectangleShape *rect;
    sfIntRect texture_rect;
    void (*is_clicked)(struct button_t *, sfVector2i, int *, sfEvent *);
    void (*is_hover)(struct button_t *, sfVector2i);
    enum e_gui_state state;
    sfTexture *symbole;
    sfRectangleShape *sym_rec;
}button_s;
typedef struct grid_t {
    int currentbutton;
    sfRectangleShape *rect;
    sfTexture *buttons_texture;
    sfTexture *texture;
    button_s button1;
    button_s button2;
    button_s button3;
    button_s button4;
    button_s button5;
    button_s button6;
    button_s button7;
    button_s button8;
}grid_s;
typedef struct palette_t {
    sfRectangleShape *rect;
    sfTexture *texture;
    grid_s grid1;
}palette_s;
typedef struct canva_s {
    sfRectangleShape *background;
    sfTexture *texture_bg;
    sfRectangleShape *dz_bg;
    sfTexture *texture_dz;
    sfImage *image_buffer;
    sfTexture *texture_buffer;
    sfSprite *drawzone;
    sfBool is_drawing;
    int radius;
    sfColor color;
}canva_t;
typedef struct ui_struct {
    canva_t canva;
    palette_s palette;
}ui_struct;
typedef struct gamestruct {
    ui_struct *ui;
    sfFont *font;
    sfText *temps;
    sfClock *gameclock;
    int GameOver;
}gstruct;

#endif /* !STRUCT_H_ */
