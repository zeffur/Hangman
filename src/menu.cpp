#include "menu.h"
#include "output.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

using namespace std;

/*int SecMenu() {

    cout << "Select difficulty level:" << endl;
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

//  return 0;
//}*/

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
        if (mouse_x > 400 && mouse_x < 600 && mouse_y > 300 && mouse_y < 360 &&
            status == 1) {
          printf("lol \n");
          SDL_RenderClear(rend);
          SDL_RenderCopy(rend, tex_secmain, NULL, NULL);
          SDL_RenderPresent(rend);
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
  }

  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
