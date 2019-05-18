#include "menu.h"
#include "output.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

int main() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *win = SDL_CreateWindow("HANGMAN", SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED, 1080, 720, 0);

  if (!win) {
    printf("error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // create a renderer, which sets up the graphics hardware
  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);
  if (!rend) {
    printf("error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  SDL_Surface *surface_loading = IMG_Load("./files/images/loading.png");
  if (!surface_loading) {
    printf("error creating surface\n");
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  SDL_Texture *tex_load = SDL_CreateTextureFromSurface(rend, surface_loading);
  SDL_FreeSurface(surface_loading);
  if (!tex_load) {
    printf("error creating texture: %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex_load, NULL, NULL);
  SDL_RenderPresent(rend);

  /*
    SDL_Surface *surface_main = IMG_Load("./files/images/main.png");
    if (!surface_main) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    // load the image data into the graphics hardware's memory
    SDL_Texture *tex_main = SDL_CreateTextureFromSurface(rend, surface_main);
    SDL_FreeSurface(surface_main);
    if (!tex_main) {
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }
    SDL_Surface *surface_secmain = IMG_Load("./files/images/main2.png");
    if (!surface_secmain) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_secmain =
        SDL_CreateTextureFromSurface(rend, surface_secmain);
    SDL_FreeSurface(surface_secmain);
    if (!tex_secmain) {
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_gameplay = IMG_Load("./files/images/gameplay.png");
    if (!surface_gameplay) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_game = SDL_CreateTextureFromSurface(rend,
    surface_gameplay); SDL_FreeSurface(surface_gameplay); if (!tex_game) {
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_blank = IMG_Load("./files/images/blank.png");
    if (!surface_blank) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_blank = SDL_CreateTextureFromSurface(rend, surface_blank);
    SDL_FreeSurface(surface_blank);
    if (!tex_blank) {
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_loss = IMG_Load("./files/images/loss.png");
    if (!surface_loss) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_loss = SDL_CreateTextureFromSurface(rend, surface_loss);
    SDL_FreeSurface(surface_loss);
    if (!tex_loss) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_win = IMG_Load("./files/images/win.png");
    if (!surface_win) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_win = SDL_CreateTextureFromSurface(rend, surface_win);
    SDL_FreeSurface(surface_win);
    if (!tex_win) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_right = IMG_Load("./files/images/right.png");
    if (!surface_right) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_right = SDL_CreateTextureFromSurface(rend, surface_right);
    SDL_FreeSurface(surface_right);
    if (!tex_right) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_wrong = IMG_Load("./files/images/wrong.png");
    if (!surface_wrong) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_wrong = SDL_CreateTextureFromSurface(rend, surface_wrong);
    SDL_FreeSurface(surface_wrong);
    if (!tex_wrong) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_fm = IMG_Load("./files/images/fm.png");
    if (!surface_fm) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_fm = SDL_CreateTextureFromSurface(rend, surface_fm);
    SDL_FreeSurface(surface_fm);
    if (!tex_fm) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }
    SDL_Surface *surface_sm = IMG_Load("./files/images/sm.png");
    if (!surface_sm) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_sm = SDL_CreateTextureFromSurface(rend, surface_sm);
    SDL_FreeSurface(surface_sm);
    if (!tex_sm) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }
    SDL_Surface *surface_tm = IMG_Load("./files/images/tm.png");
    if (!surface_tm) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_tm = SDL_CreateTextureFromSurface(rend, surface_tm);
    SDL_FreeSurface(surface_tm);
    if (!tex_tm) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }
    SDL_Surface *surface_fom = IMG_Load("./files/images/fom.png");
    if (!surface_fom) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_fom = SDL_CreateTextureFromSurface(rend, surface_fom);
    SDL_FreeSurface(surface_fom);
    if (!tex_fom) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }
    SDL_Surface *surface_fim = IMG_Load("./files/images/fim.png");
    if (!surface_fim) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_fim = SDL_CreateTextureFromSurface(rend, surface_fim);
    SDL_FreeSurface(surface_fim);
    if (!tex_fim) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_playbut = IMG_Load("./files/images/playbut.png");
    if (!surface_playbut) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_playbut =
        SDL_CreateTextureFromSurface(rend, surface_playbut);
    SDL_FreeSurface(surface_playbut);
    if (!tex_playbut) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_helpbut = IMG_Load("./files/images/helpbut.png");
    if (!surface_helpbut) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_helpbut =
        SDL_CreateTextureFromSurface(rend, surface_helpbut);
    SDL_FreeSurface(surface_helpbut);
    if (!tex_helpbut) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_quitbut = IMG_Load("./files/images/quitbut.png");
    if (!surface_quitbut) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_quitbut =
        SDL_CreateTextureFromSurface(rend, surface_quitbut);
    SDL_FreeSurface(surface_quitbut);
    if (!tex_quitbut) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Surface *surface_help = IMG_Load("./files/images/Help.png");
    if (!surface_help) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_help = SDL_CreateTextureFromSurface(rend, surface_help);
    SDL_FreeSurface(surface_help);
    if (!tex_help) {
      SDL_DestroyRenderer(rend);
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }*/

  SDL_Surface **surface_all =
      (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 26);
  if (!surface_all) {
    printf("error creating surface\n");
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  SDL_Texture **tex_all = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * 26);
  if (!tex_all) {
    SDL_DestroyRenderer(rend);
    printf("error creating texture: %s\n", SDL_GetError());
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  char path[256] = "./files/images/a.png";
  for (int l = 0; l < 26; l++) {
    surface_all[l] = IMG_Load(path);
    tex_all[l] = SDL_CreateTextureFromSurface(rend, surface_all[l]);
    path[15] = 'a' + l;
  }

  Menu(rend, win, tex_all);

  return 0;
}
