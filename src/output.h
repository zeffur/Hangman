#ifndef OUTPUT_H
#define OUTPUT_H
#include "menu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
using namespace std;

void File1(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all);
void File2(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all);
void File3(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all);
int Hang(SDL_Renderer *rend, SDL_Window *win, char *word,
         SDL_Texture **tex_all);
void Help(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all);
void Levels(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all);

#endif
