#ifndef OUTPUT_H
#define OUTPUT_H
#include "menu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
using namespace std;

int File1(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
          SDL_Texture *tex_blank, SDL_Texture *tex_loss, SDL_Texture *tex_win,
          SDL_Texture **tex_fm, SDL_Texture **tex_sm, SDL_Texture **tex_tm,
          SDL_Texture **tex_fom, SDL_Texture **tex_fim, SDL_Texture **tex_right,
          SDL_Texture **tex_wrong);
int File2(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
          SDL_Texture *tex_blank, SDL_Texture *tex_loss, SDL_Texture *tex_win,
          SDL_Texture **tex_fm, SDL_Texture **tex_sm, SDL_Texture **tex_tm,
          SDL_Texture **tex_fom, SDL_Texture **tex_fim, SDL_Texture **tex_right,
          SDL_Texture **tex_wrong);
int File3(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
          SDL_Texture *tex_blank, SDL_Texture *tex_loss, SDL_Texture *tex_win,
          SDL_Texture **tex_fm, SDL_Texture **tex_sm, SDL_Texture **tex_tm,
          SDL_Texture **tex_fom, SDL_Texture **tex_fim, SDL_Texture **tex_right,
          SDL_Texture **tex_wrong);
int Hang(SDL_Renderer *rend, SDL_Window *win, char *word, SDL_Texture **tex_fm,
         SDL_Texture **tex_sm, SDL_Texture **tex_tm, SDL_Texture **tex_fom,
         SDL_Texture **tex_fim, SDL_Texture **tex_right,
         SDL_Texture **tex_wrong);
int Help();

#endif
