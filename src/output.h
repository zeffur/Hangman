#ifndef OUTPUT_H
#define OUTPUT_H
#include "menu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
using namespace std;

void File1(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
           SDL_Texture *tex_blank);
void File2();
void File3();
int Hang(SDL_Renderer *rend, SDL_Window *win, char *word);
int Help();

#endif
