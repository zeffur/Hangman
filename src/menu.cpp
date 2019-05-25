#include "menu.h"
#include "output.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
using namespace std;

int Menu(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all,
         SDL_Texture **tex_let) {
  // cout << "zdes";
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex_all[0], NULL, NULL);
  SDL_RenderPresent(rend);
  int close_requested = 0;
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
        if (mouse_x > 448 && mouse_x < 587 && mouse_y > 307 && mouse_y < 360) {
          graphics(1, rend, win, tex_all);
          //////////////////////////////////////////////////////////////////////
          /*    SDL_Rect playbut;
              SDL_QueryTexture(tex_all[13], NULL, NULL, &playbut.w, &playbut.h);
              playbut.w = 234;
              playbut.h = 105;
              playbut.x = 407;
              playbut.y = 284;
              SDL_RenderCopy(rend, tex_all[13], NULL, &playbut);
              SDL_RenderPresent(rend);
              SDL_Delay(100);
              // printf("lol \n");
              SDL_RenderClear(rend);
              SDL_RenderCopy(rend, tex_all[1], NULL, NULL);
              SDL_RenderPresent(rend);*/
          //////////////////////////////////////////////////////////////////////
          Levels(rend, win, tex_all, tex_let);
        }

        if (mouse_x > 443 && mouse_x < 593 && mouse_y > 397 && mouse_y < 453) {
          graphics(2, rend, win, tex_all);
          //////////////////////////////////////////////////////////////////////
          /*SDL_Rect helpbut;
          SDL_QueryTexture(tex_all[14], NULL, NULL, &helpbut.w, &helpbut.h);
          helpbut.w = 302;
          helpbut.h = 136;
          helpbut.x = 373;
          helpbut.y = 358;
          SDL_RenderCopy(rend, tex_all[14], NULL, &helpbut);
          SDL_RenderPresent(rend);
          SDL_Delay(100);
          // printf("lol \n");
          SDL_RenderClear(rend);
          SDL_RenderCopy(rend, tex_all[16], NULL, NULL);
          SDL_RenderPresent(rend);*/
          //////////////////////////////////////////////////////////////////////
          Help(rend, win, tex_all, tex_let);
        }
        if (mouse_x > 447 && mouse_x < 574 && mouse_y > 484 && mouse_y < 537) {
          graphics(3, rend, win, tex_all);
          //////////////////////////////////////////////////////////////////////
          /*SDL_Rect quitbut;
          SDL_QueryTexture(tex_all[15], NULL, NULL, &quitbut.w, &quitbut.h);
          quitbut.w = 298;
          quitbut.h = 146;
          quitbut.x = 376;
          quitbut.y = 439;
          SDL_RenderCopy(rend, tex_all[15], NULL, &quitbut);
          SDL_RenderPresent(rend);
          SDL_Delay(5);*/
          //////////////////////////////////////////////////////////////////////
          // printf("lol \n");
          SDL_DestroyRenderer(rend);
          SDL_DestroyWindow(win);
          SDL_Quit();
          return 0;
        }
      }
    }
  }
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  // SDL_Quit();

  return 0;
}

void graphics(int r, SDL_Renderer *rend, SDL_Window *win,
              SDL_Texture **tex_all) {
  if (r == 1) {
    SDL_Rect playbut;
    SDL_QueryTexture(tex_all[13], NULL, NULL, &playbut.w, &playbut.h);
    playbut.w = 234;
    playbut.h = 105;
    playbut.x = 407;
    playbut.y = 284;
    SDL_RenderCopy(rend, tex_all[13], NULL, &playbut);
    SDL_RenderPresent(rend);
    SDL_Delay(100);
    // printf("lol \n");
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[1], NULL, NULL);
    SDL_RenderPresent(rend);
  }
  if (r == 2) {
    SDL_Rect helpbut;
    SDL_QueryTexture(tex_all[14], NULL, NULL, &helpbut.w, &helpbut.h);
    helpbut.w = 302;
    helpbut.h = 136;
    helpbut.x = 373;
    helpbut.y = 358;
    SDL_RenderCopy(rend, tex_all[14], NULL, &helpbut);
    SDL_RenderPresent(rend);
    SDL_Delay(100);
    // printf("lol \n");
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[16], NULL, NULL);
    SDL_RenderPresent(rend);
  }
  if (r == 3) {
    SDL_Rect quitbut;
    SDL_QueryTexture(tex_all[15], NULL, NULL, &quitbut.w, &quitbut.h);
    quitbut.w = 298;
    quitbut.h = 146;
    quitbut.x = 376;
    quitbut.y = 439;
    SDL_RenderCopy(rend, tex_all[15], NULL, &quitbut);
    SDL_RenderPresent(rend);
    SDL_Delay(5);
  }
}
