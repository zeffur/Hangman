#ifndef MENU_H
#define MENU_H
#include "output.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

void graphics(int r, SDL_Renderer *rend, SDL_Window *win,
              SDL_Texture **tex_all);
int Menu(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all,
         SDL_Texture **tex_let);

#endif
