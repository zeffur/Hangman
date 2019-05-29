#ifndef OUTPUT_H
#define OUTPUT_H
#include "menu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

int File1(
        SDL_Renderer* rend,
        SDL_Window* win,
        SDL_Texture** tex_all,
        SDL_Texture** tex_let);
int File2(
        SDL_Renderer* rend,
        SDL_Window* win,
        SDL_Texture** tex_all,
        SDL_Texture** tex_let);
int File3(
        SDL_Renderer* rend,
        SDL_Window* win,
        SDL_Texture** tex_all,
        SDL_Texture** tex_let);
int Hang(
        SDL_Renderer* rend,
        SDL_Window* win,
        char* word,
        SDL_Texture** tex_all,
        SDL_Texture** tex_let);
int Help(
        SDL_Renderer* rend,
        SDL_Window* win,
        SDL_Texture** tex_all,
        SDL_Texture** tex_let);
int Levels(
        SDL_Renderer* rend,
        SDL_Window* win,
        SDL_Texture** tex_all,
        SDL_Texture** tex_let);
int FileRead(char* word, int s);

#endif
