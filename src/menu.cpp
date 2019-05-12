#include "menu.h"
#include "output.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

using namespace std;

int SecMenu() {

  /*  cout << "Select difficulty level:" << endl;
    cout << "1.Easy" << endl;
    cout << "2.Normal" << endl;
    cout << "3.Hard" << endl;
    cout << "4.Go Back" << endl;
    cout << endl;
    int k = 0;
    cin >> k;
    switch (k) {
    case 1:
      File1();
      break;
    case 2:
      File2();
      break;
    case 3:
      File3();
      break;
    case 4:
      return 1;
    default:
      cout << "Error\n";
      break;
    }*/

  return 0;
}

int Menu() {
  //  int l = 0, k = 0;
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

  // load the image into memory using SDL_image library function
  SDL_Surface *surface = IMG_Load("./files/images/main.png");
  if (!surface) {
    printf("error creating surface\n");
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  // load the image data into the graphics hardware's memory
  SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);
  SDL_FreeSurface(surface);
  if (!tex) {
    printf("error creating texture: %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }
  SDL_Surface *surface2 = IMG_Load("./files/images/main2.png");
  if (!surface2) {
    printf("error creating surface\n");
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  SDL_Texture *tex2 = SDL_CreateTextureFromSurface(rend, surface2);
  SDL_FreeSurface(surface2);
  if (!tex) {
    printf("error creating texture: %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex, NULL, NULL);
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
        if (mouse_x > 450 && mouse_x < 600 && mouse_y > 345 && mouse_y < 400 &&
            status == 1) {
          printf("lol \n");
          SDL_RenderClear(rend);
          SDL_RenderCopy(rend, tex2, NULL, NULL);
          SDL_RenderPresent(rend);
        }

        //  SDL_Delay(5000);
      }
      if (event.type == SDL_MOUSEBUTTONUP && status == 1)
        ++status;
      // buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        if (mouse_x > 451 && mouse_x < 601 && mouse_y > 346 && mouse_y < 401 &&
            status == 2) {
          File1();
        }
      }
    }
    // SecMenu();
    // switch ()
    /* cout << "1.Game" << endl;
      cout << "2.Help" << endl;
      cout << "3.Exit" << endl;*/
    //  cin >> k;
    /*  switch (k) {
      case 1:
        l = SecMenu();
        break;
      case 2:
        l = Help();
        break;
      case 3:
        return 0;
      }
      if (l)
        Menu();*/
    SDL_Delay(1000 / 60);
  }

  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
