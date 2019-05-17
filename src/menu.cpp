#include "menu.h"
#include "output.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

using namespace std;

int Menu() {
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

  // load the image into memory using SDL_image library function
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

  SDL_Texture *tex_game = SDL_CreateTextureFromSurface(rend, surface_gameplay);
  SDL_FreeSurface(surface_gameplay);
  if (!tex_game) {
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
  }

  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex_main, NULL, NULL);
  SDL_RenderPresent(rend);
  // draw the image to the window
  int close_requested = 0;
  int status = 1;

  while (!close_requested) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        close_requested = 1;
      }
      int mouse_x, mouse_y;
      int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons && SDL_BUTTON(SDL_BUTTON_LEFT) &&
          event.type == SDL_MOUSEBUTTONDOWN) {
        if (mouse_x > 448 && mouse_x < 587 && mouse_y > 307 && mouse_y < 360 &&
            status == 1) {
          SDL_Rect playbut;
          SDL_QueryTexture(tex_playbut, NULL, NULL, &playbut.w, &playbut.h);
          playbut.w = 234;
          playbut.h = 105;
          playbut.x = 407;
          playbut.y = 284;
          SDL_RenderCopy(rend, tex_playbut, NULL, &playbut);
          SDL_RenderPresent(rend);
          SDL_Delay(100);
          printf("lol \n");
          SDL_RenderClear(rend);
          SDL_RenderCopy(rend, tex_secmain, NULL, NULL);
          SDL_RenderPresent(rend);
        }
        if (mouse_x > 443 && mouse_x < 593 && mouse_y > 397 && mouse_y < 453 &&
            status == 1) {
          SDL_Rect helpbut;
          SDL_QueryTexture(tex_helpbut, NULL, NULL, &helpbut.w, &helpbut.h);
          helpbut.w = 302;
          helpbut.h = 136;
          helpbut.x = 373;
          helpbut.y = 358;
          SDL_RenderCopy(rend, tex_helpbut, NULL, &helpbut);
          SDL_RenderPresent(rend);
          SDL_Delay(100);
          printf("lol \n");
          SDL_RenderClear(rend);
          SDL_RenderCopy(rend, tex_help, NULL, NULL);
          SDL_RenderPresent(rend);
        }
        if (mouse_x > 447 && mouse_x < 574 && mouse_y > 484 && mouse_y < 537 &&
            status == 1) {
          SDL_Rect quitbut;
          SDL_QueryTexture(tex_quitbut, NULL, NULL, &quitbut.w, &quitbut.h);
          quitbut.w = 298;
          quitbut.h = 146;
          quitbut.x = 376;
          quitbut.y = 439;
          SDL_RenderCopy(rend, tex_quitbut, NULL, &quitbut);
          SDL_RenderPresent(rend);
          SDL_Delay(5);
          printf("lol \n");
          SDL_DestroyRenderer(rend);
          SDL_DestroyWindow(win);
          SDL_Quit();
          return 0;
        }

        //  SDL_Delay(5000);
      }
      if (event.type == SDL_MOUSEBUTTONUP && status == 1)
        ++status;
      // buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        if (mouse_x > 400 && mouse_x < 600 && mouse_y > 300 && mouse_y < 360 &&
            status == 2) {

          File1(rend, win, tex_game, tex_blank, tex_loss, tex_win, &tex_fm,
                &tex_sm, &tex_tm, &tex_fom, &tex_fim, &tex_right, &tex_wrong);
        }
        if (mouse_x > 400 && mouse_x < 600 && mouse_y > 400 && mouse_y < 460 &&
            status == 2) {

          File2(rend, win, tex_game, tex_blank, tex_loss, tex_win, &tex_fm,
                &tex_sm, &tex_tm, &tex_fom, &tex_fim, &tex_right, &tex_wrong);
        }
        if (mouse_x > 400 && mouse_x < 600 && mouse_y > 500 && mouse_y < 560 &&
            status == 2) {

          File3(rend, win, tex_game, tex_blank, tex_loss, tex_win, &tex_fm,
                &tex_sm, &tex_tm, &tex_fom, &tex_fim, &tex_right, &tex_wrong);
        }
      }
    }
  }

  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
