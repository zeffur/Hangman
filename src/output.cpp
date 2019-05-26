#include "output.h"
#include "menu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

int Hang(SDL_Renderer *rend, SDL_Window *win, char *word, SDL_Texture **tex_all,
         SDL_Texture **tex_let) {
  cout << word;
  unsigned int i, c = 0;
  int close_requested = 0, failure = 0;
  int status[26], estnet[26];

  memset(status, 0, sizeof(status));
  memset(estnet, 0, sizeof(estnet));
  while (!close_requested) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        close_requested = 1;
        exit(0);
      }
      int mouse_x, mouse_y;
      int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons && SDL_BUTTON(SDL_BUTTON_LEFT) &&
          event.type == SDL_MOUSEBUTTONDOWN) {

        if (mouse_x > 66 && mouse_x < 123 && mouse_y > 83 && mouse_y < 128 &&
            status[0] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'a') {
              if (estnet[0] == 0)
                estnet[0] = 1;
              ++c;
              graphics_let(200, rend, tex_all, tex_let, i);
            }
          }

          if (estnet[0] == 0) {

            ++failure;
            graphics_let(300, rend, tex_all, tex_let, i);
          }

          status[0] = 1;
        }

        if (mouse_x > 158 && mouse_x < 204 && mouse_y > 83 && mouse_y < 128 &&
            status[1] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'b') {
              if (estnet[1] == 0)
                estnet[1] = 1;
              ++c;
              graphics_let(201, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[1] == 0) {
            ++failure;
            graphics_let(301, rend, tex_all, tex_let, i);
          }

          status[1] = 1;
        }

        if (mouse_x > 239 && mouse_x < 285 && mouse_y > 83 && mouse_y < 128 &&
            status[2] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'c') {
              if (estnet[2] == 0)
                estnet[2] = 1;
              ++c;
              graphics_let(202, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[2] == 0) {
            ++failure;
            graphics_let(302, rend, tex_all, tex_let, i);
          }

          status[2] = 1;
        }
        if (mouse_x > 325 && mouse_x < 373 && mouse_y > 83 && mouse_y < 128 &&
            status[3] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'd') {
              if (estnet[3] == 0)
                estnet[3] = 1;
              ++c;
              graphics_let(203, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[3] == 0) {
            ++failure;
            graphics_let(303, rend, tex_all, tex_let, i);
          }

          status[3] = 1;
        }
        if (mouse_x > 414 && mouse_x < 452 && mouse_y > 83 && mouse_y < 128 &&
            status[4] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'e') {
              if (estnet[4] == 0)
                estnet[4] = 1;
              ++c;
              graphics_let(204, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[4] == 0) {
            ++failure;
            graphics_let(304, rend, tex_all, tex_let, i);
          }

          status[4] = 1;
        }
        if (mouse_x > 491 && mouse_x < 531 && mouse_y > 83 && mouse_y < 128 &&
            status[5] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'f') {
              if (estnet[5] == 0)
                estnet[5] = 1;
              ++c;
              graphics_let(205, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[5] == 0) {
            ++failure;
            graphics_let(305, rend, tex_all, tex_let, i);
          }

          status[5] = 1;
        }
        if (mouse_x > 567 && mouse_x < 621 && mouse_y > 83 && mouse_y < 128 &&
            status[6] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'g') {
              if (estnet[6] == 0)
                estnet[6] = 1;
              ++c;
              graphics_let(206, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[6] == 0) {
            ++failure;
            graphics_let(306, rend, tex_all, tex_let, i);
          }

          status[6] = 1;
        }
        if (mouse_x > 71 && mouse_x < 120 && mouse_y > 159 && mouse_y < 216 &&
            status[7] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'h') {
              if (estnet[7] == 0)
                estnet[7] = 1;
              ++c;
              graphics_let(207, rend, tex_all, tex_let, i);
            }
          }

          if (estnet[7] == 0) {
            ++failure;
            graphics_let(307, rend, tex_all, tex_let, i);
          }

          status[7] = 1;
        }

        if (mouse_x > 162 && mouse_x < 193 && mouse_y > 159 && mouse_y < 216 &&
            status[8] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'i') {
              if (estnet[8] == 0)
                estnet[8] = 1;
              ++c;
              graphics_let(208, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[8] == 0) {
            ++failure;
            graphics_let(308, rend, tex_all, tex_let, i);
          }

          status[8] = 1;
        }

        if (mouse_x > 239 && mouse_x < 283 && mouse_y > 159 && mouse_y < 216 &&
            status[9] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'j') {
              if (estnet[9] == 0)
                estnet[9] = 1;
              ++c;
              graphics_let(209, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[9] == 0) {
            ++failure;
            graphics_let(309, rend, tex_all, tex_let, i);
          }

          status[9] = 1;
        }
        if (mouse_x > 325 && mouse_x < 376 && mouse_y > 159 && mouse_y < 216 &&
            status[10] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'k') {
              if (estnet[10] == 0)
                estnet[10] = 1;
              ++c;
              graphics_let(210, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[10] == 0) {
            ++failure;
            graphics_let(310, rend, tex_all, tex_let, i);
          }

          status[10] = 1;
        }
        if (mouse_x > 413 && mouse_x < 451 && mouse_y > 159 && mouse_y < 216 &&
            status[11] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'l') {
              if (estnet[11] == 0)
                estnet[11] = 1;
              ++c;
              graphics_let(211, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[11] == 0) {
            ++failure;
            graphics_let(311, rend, tex_all, tex_let, i);
          }

          status[11] = 1;
        }
        if (mouse_x > 480 && mouse_x < 544 && mouse_y > 159 && mouse_y < 216 &&
            status[12] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'm') {
              if (estnet[12] == 0)
                estnet[12] = 1;
              ++c;
              graphics_let(212, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[12] == 0) {
            ++failure;
            graphics_let(312, rend, tex_all, tex_let, i);
          }

          status[12] = 1;
        }
        if (mouse_x > 567 && mouse_x < 619 && mouse_y > 159 && mouse_y < 216 &&
            status[13] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'n') {
              if (estnet[13] == 0)
                estnet[13] = 1;
              ++c;
              graphics_let(213, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[13] == 0) {
            ++failure;
            graphics_let(313, rend, tex_all, tex_let, i);
          }

          status[13] = 1;
        }

        if (mouse_x > 70 && mouse_x < 128 && mouse_y > 235 && mouse_y < 288 &&
            status[14] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'o') {
              if (estnet[14] == 0)
                estnet[14] = 1;
              ++c;
              graphics_let(214, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[14] == 0) {
            ++failure;
            graphics_let(314, rend, tex_all, tex_let, i);
          }

          status[14] = 1;
        }

        if (mouse_x > 158 && mouse_x < 200 && mouse_y > 235 && mouse_y < 288 &&
            status[15] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'p') {
              if (estnet[15] == 0)
                estnet[15] = 1;
              ++c;
              graphics_let(215, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[15] == 0) {
            ++failure;
            graphics_let(315, rend, tex_all, tex_let, i);
          }

          status[15] = 1;
        }
        if (mouse_x > 234 && mouse_x < 291 && mouse_y > 235 && mouse_y < 288 &&
            status[16] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'q') {
              if (estnet[16] == 0)
                estnet[16] = 1;
              ++c;
              graphics_let(216, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[16] == 0) {
            ++failure;
            graphics_let(316, rend, tex_all, tex_let, i);
          }

          status[16] = 1;
        }
        if (mouse_x > 323 && mouse_x < 373 && mouse_y > 235 && mouse_y < 288 &&
            status[17] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'r') {
              if (estnet[17] == 0)
                estnet[17] = 1;
              ++c;
              graphics_let(217, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[17] == 0) {
            ++failure;
            graphics_let(317, rend, tex_all, tex_let, i);
          }

          status[17] = 1;
        }
        if (mouse_x > 410 && mouse_x < 453 && mouse_y > 235 && mouse_y < 288 &&
            status[18] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 's') {
              if (estnet[18] == 0)
                estnet[18] = 1;
              ++c;
              graphics_let(218, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[18] == 0) {
            ++failure;
            graphics_let(318, rend, tex_all, tex_let, i);
          }

          status[18] = 1;
        }
        if (mouse_x > 486 && mouse_x < 537 && mouse_y > 235 && mouse_y < 288 &&
            status[19] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 't') {
              if (estnet[19] == 0)
                estnet[19] = 1;
              ++c;
              graphics_let(219, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[19] == 0) {
            ++failure;
            graphics_let(319, rend, tex_all, tex_let, i);
          }

          status[19] = 1;
        }
        if (mouse_x > 570 && mouse_x < 619 && mouse_y > 235 && mouse_y < 288 &&
            status[20] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'u') {
              if (estnet[20] == 0)
                estnet[20] = 1;
              ++c;
              graphics_let(220, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[20] == 0) {
            ++failure;
            graphics_let(320, rend, tex_all, tex_let, i);
          }

          status[20] = 1;
        }
        if (mouse_x > 147 && mouse_x < 205 && mouse_y > 310 && mouse_y < 357 &&
            status[21] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'v') {
              if (estnet[21] == 0)
                estnet[21] = 1;
              ++c;
              graphics_let(221, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[21] == 0) {
            ++failure;
            graphics_let(321, rend, tex_all, tex_let, i);
          }

          status[21] = 1;
        }
        if (mouse_x > 226 && mouse_x < 304 && mouse_y > 310 && mouse_y < 357 &&
            status[22] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'w') {
              if (estnet[22] == 0)
                estnet[22] = 1;
              ++c;
              graphics_let(222, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[22] == 0) {
            ++failure;
            graphics_let(322, rend, tex_all, tex_let, i);
          }

          status[22] = 1;
        }
        if (mouse_x > 323 && mouse_x < 375 && mouse_y > 310 && mouse_y < 357 &&
            status[23] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'x') {
              if (estnet[23] == 0)
                estnet[23] = 1;
              ++c;
              graphics_let(223, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[23] == 0) {
            ++failure;
            graphics_let(323, rend, tex_all, tex_let, i);
          }

          status[23] = 1;
        }
        if (mouse_x > 403 && mouse_x < 459 && mouse_y > 310 && mouse_y < 357 &&
            status[24] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'y') {
              if (estnet[24] == 0)
                estnet[24] = 1;
              ++c;
              graphics_let(224, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[24] == 0) {
            ++failure;
            graphics_let(324, rend, tex_all, tex_let, i);
          }

          status[24] = 1;
        }
        if (mouse_x > 491 && mouse_x < 539 && mouse_y > 310 && mouse_y < 357 &&
            status[25] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'z') {
              if (estnet[25] == 0)
                estnet[25] = 1;
              ++c;
              graphics_let(225, rend, tex_all, tex_let, i);
            }
          }
          if (estnet[25] == 0) {
            ++failure;
            graphics_let(325, rend, tex_all, tex_let, i);
          }

          status[25] = 1;
        }

        if (mouse_x > 900 && mouse_x < 1080 && mouse_y > 600 && mouse_y < 720) {
          Menu(rend, win, tex_all, tex_let);
        }
        graphics(failure, rend, tex_all);

        SDL_RenderPresent(rend);
        if (failure == 6) {
          return 7;
        }

        if (c == strlen(word)) {
          return 5;
        }
      }
    }
  }
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  return 0;
}

int File1(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all,
          SDL_Texture **tex_let) {

  int i = 0, l, b = 0, k, h;
  srand(time(NULL));
  char word[256];

  FILE *file = fopen("./files/Length1.txt", "r");
  if (file == NULL) {
    cout << "file not found";
    cout << endl;
  }
  k = rand() % 10;
  while (i < k) {
    fscanf(file, "%s", word);
    l = strlen(word);

    i++;
  }
  fclose(file);

  cout << word;
  cout << l;
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex_all[2], NULL, NULL);

  SDL_Rect rect;
  while (b < l) {
    SDL_QueryTexture(tex_all[3], NULL, NULL, &rect.w, &rect.h);

    rect.w = 70;
    rect.h = 30;
    rect.x = 25 + (b * 70);
    rect.y = 600;
    SDL_RenderCopy(rend, tex_all[3], NULL, &rect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 60);
    b++;
  }
  h = Hang(rend, win, word, tex_all, tex_let);

  if (h == 0)
    return 0;

  if (h == 7) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[4], NULL, NULL);
    SDL_RenderPresent(rend);

  } else if (h == 5) {
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[5], NULL, NULL);
    SDL_RenderPresent(rend);
  }
  int close_requested = 0;
  while (!close_requested) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        close_requested = 1;
        exit(0);
      }
      int mouse_x, mouse_y;
      int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons && SDL_BUTTON(SDL_BUTTON_LEFT) &&
          event.type == SDL_MOUSEBUTTONDOWN) {
        if (mouse_x > 900 && mouse_x < 1080 && mouse_y > 600 && mouse_y < 720) {
          Menu(rend, win, tex_all, tex_let);
        }
      }
    }
  }
}

int File2(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all,
          SDL_Texture **tex_let) {

  int i = 0, l, b = 0, k, h;
  srand(time(NULL));
  char word[256];

  FILE *file = fopen("./files/Length2.txt", "r");
  if (file == NULL) {
    cout << "file not found";
    cout << endl;
  }
  k = rand() % 10;
  while (i < k) {
    fscanf(file, "%s", word);
    l = strlen(word);

    i++;
  }
  fclose(file);

  cout << word;
  cout << l;
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex_all[2], NULL, NULL);

  SDL_Rect rect;
  while (b < l) {
    SDL_QueryTexture(tex_all[3], NULL, NULL, &rect.w, &rect.h);

    rect.w = 70;
    rect.h = 30;
    rect.x = 25 + (b * 70);
    rect.y = 600;
    SDL_RenderCopy(rend, tex_all[3], NULL, &rect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 60);
    b++;
  }
  h = Hang(rend, win, word, tex_all, tex_let);
  if (h == 0)
    return 0;

  if (h == 7) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[4], NULL, NULL);
    SDL_RenderPresent(rend);
  } else if (h == 5) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[5], NULL, NULL);
    SDL_RenderPresent(rend);
  }
  int close_requested = 0;
  while (!close_requested) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        close_requested = 1;
        exit(0);
      }
      int mouse_x, mouse_y;
      int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons && SDL_BUTTON(SDL_BUTTON_LEFT) &&
          event.type == SDL_MOUSEBUTTONDOWN) {
        if (mouse_x > 900 && mouse_x < 1080 && mouse_y > 600 && mouse_y < 720) {
          Menu(rend, win, tex_all, tex_let);
        }
      }
    }
  }
}

int File3(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all,
          SDL_Texture **tex_let) {

  int i = 0, l, b = 0, k, h;
  srand(time(NULL));
  char word[256];

  FILE *file = fopen("./files/Length3.txt", "r");
  if (file == NULL) {
    cout << "file not found";
    cout << endl;
  }
  k = rand() % 10;
  while (i < k) {
    fscanf(file, "%s", word);
    l = strlen(word);

    i++;
  }
  fclose(file);

  // cout << word;
  // cout << l;
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex_all[2], NULL, NULL);
  // cout << "yolo" << endl;

  SDL_Rect rect;
  while (b < l) {
    SDL_QueryTexture(tex_all[3], NULL, NULL, &rect.w, &rect.h);

    rect.w = 70;
    rect.h = 30;
    rect.x = 25 + (b * 70);
    rect.y = 600;
    SDL_RenderCopy(rend, tex_all[3], NULL, &rect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 60);
    b++;
  }
  h = Hang(rend, win, word, tex_all, tex_let);

  if (h == 0)
    return 0;

  if (h == 7) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[4], NULL, NULL);
    SDL_RenderPresent(rend);
  } else if (h == 5) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[5], NULL, NULL);
    SDL_RenderPresent(rend);
  }
  int close_requested = 0;
  while (!close_requested) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        close_requested = 1;
        exit(0);
      }
      int mouse_x, mouse_y;
      int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons && SDL_BUTTON(SDL_BUTTON_LEFT) &&
          event.type == SDL_MOUSEBUTTONDOWN) {
        if (mouse_x > 900 && mouse_x < 1080 && mouse_y > 600 && mouse_y < 720) {
          Menu(rend, win, tex_all, tex_let);
        }
      }
    }
  }
}

int Help(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all,
         SDL_Texture **tex_let) {
  int close_requested = 0;
  while (!close_requested) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        close_requested = 1;
        exit(0);
      }
      int mouse_x, mouse_y;
      int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons && SDL_BUTTON(SDL_BUTTON_LEFT) &&
          event.type == SDL_MOUSEBUTTONDOWN) {
        // cout << "uhuhu" << endl;

        if (mouse_x > 900 && mouse_x < 1080 && mouse_y > 600 && mouse_y < 720) {
          Menu(rend, win, tex_all, tex_let);
        }
      }
    }
  }
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  return 0;
}

int Levels(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all,
           SDL_Texture **tex_let) {
  int close_requested = 0;
  while (!close_requested) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        close_requested = 1;
        exit(0);
      }
      int mouse_x, mouse_y;
      int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
      if (buttons && SDL_BUTTON(SDL_BUTTON_LEFT) &&
          event.type == SDL_MOUSEBUTTONDOWN) {
        if (mouse_x > 400 && mouse_x < 600 && mouse_y > 300 && mouse_y < 360) {

          File1(rend, win, tex_all, tex_let);
          return 0;
        }
        if (mouse_x > 400 && mouse_x < 600 && mouse_y > 400 && mouse_y < 460) {

          File2(rend, win, tex_all, tex_let);
          return 0;
        }
        if (mouse_x > 400 && mouse_x < 600 && mouse_y > 500 && mouse_y < 560) {

          File3(rend, win, tex_all, tex_let);
          return 0;
        }
      }
    }
  }
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);

  return 0;
}
