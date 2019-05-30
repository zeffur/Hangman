#include "menu.h"
#include "output.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow(
            "HANGMAN",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            700,
            500,
            0);

    if (!win) {
        SDL_Quit();
        return 1;
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend) {
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Surface* surface_loading = IMG_Load("./files/images/loading.bmp");
    if (!surface_loading) {
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* tex_load = SDL_CreateTextureFromSurface(rend, surface_loading);
    SDL_FreeSurface(surface_loading);
    if (!tex_load) {
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect rect;
    SDL_QueryTexture(tex_load, NULL, NULL, &rect.w, &rect.h);

    rect.w = 420;
    rect.h = 60;
    rect.x = 140;
    rect.y = 193;

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_load, NULL, &rect);
    SDL_RenderPresent(rend);

    SDL_Surface** surface_let
            = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 26);
    if (!surface_let) {
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture** tex_let = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 26);
    if (!tex_let) {
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    char path[256] = "./files/images/A.png";
    for (int l = 0; l < 26; l++) {
        surface_let[l] = IMG_Load(path);
        tex_let[l] = SDL_CreateTextureFromSurface(rend, surface_let[l]);
        path[15] = 'B' + l;
    }
    SDL_FreeSurface(*surface_let);

    SDL_Surface** surface_all
            = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 26);
    if (!surface_all) {
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Texture** tex_all = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 26);
    if (!tex_all) {
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    char pathth[256] = "./files/images/a.bmp";
    for (int l = 0; l < 26; l++) {
        surface_all[l] = IMG_Load(pathth);
        tex_all[l] = SDL_CreateTextureFromSurface(rend, surface_all[l]);
        pathth[15] = 'b' + l;
    }
    SDL_FreeSurface(*surface_all);

    Menu(rend, win, tex_all, tex_let);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
