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

int Hang(SDL_Renderer *rend, SDL_Window *win, char *word) {

  SDL_Surface **surface_let =
      (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 26);
  if (!surface_let) {
    printf("error creating surface\n");
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }
  SDL_Texture **tex_let = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * 26);
  if (!tex_let) {
    SDL_DestroyRenderer(rend);
    printf("error creating texture: %s\n", SDL_GetError());
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

  cout << word;
  unsigned int i;
  int close_requested = 0, failure = 0, c = 0;
  int status[26], estnet[26];

  status[0] = 0;
  memset(status, 0, sizeof(status));
  memset(estnet, 0, sizeof(estnet));
  status[2] = 0;
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
        cout << "uhuhu" << endl;
        if (mouse_x > 66 && mouse_x < 123 && mouse_y > 83 && mouse_y < 128 &&
            status[0] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'a') {
              printf("aaa \n");
              if (estnet[0] == 0)
                estnet[0] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 66;
              right.y = 83;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[0] == 0) {
            {
              ++failure;
              SDL_Rect wrong;
              SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
              wrong.w = 58;
              wrong.h = 70;
              wrong.x = 58;
              wrong.y = 75;
              SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
            }
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[0] = 1;
        }

        if (mouse_x > 158 && mouse_x < 204 && mouse_y > 83 && mouse_y < 128 &&
            status[1] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'b') {
              printf("bbb \n");
              if (estnet[1] == 0)
                estnet[1] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              SDL_QueryTexture(tex_let[1], NULL, NULL, &rect.w, &rect.h);
              right.w = 58;
              right.h = 70;
              right.x = 158;
              right.y = 83;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[1], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[1] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 150;
            wrong.y = 75;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[1] = 1;
        }

        if (mouse_x > 239 && mouse_x < 285 && mouse_y > 83 && mouse_y < 128 &&
            status[2] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'c') {
              printf("ccc \n");
              if (estnet[2] == 0)
                estnet[2] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              SDL_QueryTexture(tex_let[2], NULL, NULL, &rect.w, &rect.h);
              right.w = 58;
              right.h = 70;
              right.x = 239;
              right.y = 83;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[2], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[2] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 231;
            wrong.y = 75;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[2] = 1;
        }
        if (mouse_x > 325 && mouse_x < 373 && mouse_y > 83 && mouse_y < 128 &&
            status[3] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'd') {
              printf("ddd \n");
              if (estnet[3] == 0)
                estnet[3] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              SDL_QueryTexture(tex_let[3], NULL, NULL, &rect.w, &rect.h);
              right.w = 58;
              right.h = 70;
              right.x = 325;
              right.y = 83;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[3], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[3] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 317;
            wrong.y = 75;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[3] = 1;
        }
        if (mouse_x > 414 && mouse_x < 452 && mouse_y > 83 && mouse_y < 128 &&
            status[4] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'e') {
              printf("eee \n");
              if (estnet[4] == 0)
                estnet[4] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              SDL_QueryTexture(tex_let[4], NULL, NULL, &rect.w, &rect.h);
              right.w = 58;
              right.h = 70;
              right.x = 414;
              right.y = 83;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[4], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[4] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 406;
            wrong.y = 75;

            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[4] = 1;
        }
        if (mouse_x > 491 && mouse_x < 531 && mouse_y > 83 && mouse_y < 128 &&
            status[5] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'f') {
              printf("fff \n");
              if (estnet[5] == 0)
                estnet[5] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              SDL_QueryTexture(tex_let[5], NULL, NULL, &rect.w, &rect.h);
              right.w = 58;
              right.h = 70;
              right.x = 491;
              right.y = 83;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[5], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[5] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 483;
            wrong.y = 75;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[5] = 1;
        }
        if (mouse_x > 567 && mouse_x < 621 && mouse_y > 83 && mouse_y < 128 &&
            status[6] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'g') {
              printf("ggg \n");
              if (estnet[6] == 0)
                estnet[6] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              SDL_QueryTexture(tex_let[6], NULL, NULL, &rect.w, &rect.h);
              right.w = 58;
              right.h = 70;
              right.x = 576;
              right.y = 83;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[6], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[6] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 568;
            wrong.y = 75;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[6] = 1;
        }
        if (mouse_x > 71 && mouse_x < 120 && mouse_y > 159 && mouse_y < 216 &&
            status[7] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'h') {
              printf("hhh \n");
              if (estnet[7] == 0)
                estnet[7] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[7], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 71;
              right.y = 159;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[7], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }

          if (estnet[7] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 64;
            wrong.y = 151;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[7] = 1;
        }

        if (mouse_x > 162 && mouse_x < 193 && mouse_y > 159 && mouse_y < 216 &&
            status[8] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'i') {
              printf("iii \n");
              if (estnet[8] == 0)
                estnet[8] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              SDL_QueryTexture(tex_let[8], NULL, NULL, &rect.w, &rect.h);
              right.w = 58;
              right.h = 70;
              right.x = 162;
              right.y = 159;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[8], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[8] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 154;
            wrong.y = 151;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[8] = 1;
        }

        if (mouse_x > 239 && mouse_x < 283 && mouse_y > 159 && mouse_y < 216 &&
            status[9] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'j') {
              printf("jjj \n");
              if (estnet[9] == 0)
                estnet[9] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              SDL_QueryTexture(tex_let[9], NULL, NULL, &rect.w, &rect.h);
              right.w = 58;
              right.h = 70;
              right.x = 239;
              right.y = 159;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[9], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[9] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 231;
            wrong.y = 151;

            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[9] = 1;
        }
        if (mouse_x > 325 && mouse_x < 376 && mouse_y > 159 && mouse_y < 216 &&
            status[10] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'k') {
              printf("kkk \n");
              if (estnet[10] == 0)
                estnet[10] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[10], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 325;
              right.y = 159;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[10], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[10] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 317;
            wrong.y = 151;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[10] = 1;
        }
        if (mouse_x > 413 && mouse_x < 451 && mouse_y > 159 && mouse_y < 216 &&
            status[11] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'l') {
              printf("lll \n");
              if (estnet[11] == 0)
                estnet[11] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[11], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 413;
              right.y = 159;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[11], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[11] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 405;
            wrong.y = 151;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[11] = 1;
        }
        if (mouse_x > 480 && mouse_x < 544 && mouse_y > 159 && mouse_y < 216 &&
            status[12] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'm') {
              printf("mmm \n");
              if (estnet[12] == 0)
                estnet[12] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[12], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 480;
              right.y = 159;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[12], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[12] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 472;
            wrong.y = 151;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[12] = 1;
        }
        if (mouse_x > 567 && mouse_x < 619 && mouse_y > 159 && mouse_y < 216 &&
            status[13] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'n') {
              printf("nnn \n");
              if (estnet[13] == 0)
                estnet[13] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[13], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 576;
              right.y = 159;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[13], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[13] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 568;
            wrong.y = 151;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[13] = 1;
        }

        if (mouse_x > 70 && mouse_x < 128 && mouse_y > 235 && mouse_y < 288 &&
            status[14] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'o') {
              printf("ooo \n");
              if (estnet[14] == 0)
                estnet[14] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[14], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 70;
              right.y = 235;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[14], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[14] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 62;
            wrong.y = 247;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[14] = 1;
        }

        if (mouse_x > 158 && mouse_x < 200 && mouse_y > 235 && mouse_y < 288 &&
            status[15] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'p') {
              printf("ppp \n");
              if (estnet[15] == 0)
                estnet[15] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[15], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 158;
              right.y = 235;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[15], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[15] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 150;
            wrong.y = 227;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[15] = 1;
        }
        if (mouse_x > 234 && mouse_x < 291 && mouse_y > 235 && mouse_y < 288 &&
            status[16] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'q') {
              printf("qqq \n");
              if (estnet[16] == 0)
                estnet[16] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[16], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 234;
              right.y = 235;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[16], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[16] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 226;
            wrong.y = 227;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[16] = 1;
        }
        if (mouse_x > 323 && mouse_x < 373 && mouse_y > 235 && mouse_y < 288 &&
            status[17] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'r') {
              printf("rrr \n");
              if (estnet[17] == 0)
                estnet[17] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[17], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 323;
              right.y = 235;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[17], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[17] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 315;
            wrong.y = 227;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[17] = 1;
        }
        if (mouse_x > 410 && mouse_x < 453 && mouse_y > 235 && mouse_y < 288 &&
            status[18] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 's') {
              printf("sss \n");
              if (estnet[18] == 0)
                estnet[18] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[18], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 410;
              right.y = 235;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[18], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[18] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 402;
            wrong.y = 227;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[18] = 1;
        }
        if (mouse_x > 486 && mouse_x < 537 && mouse_y > 235 && mouse_y < 288 &&
            status[19] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 't') {
              printf("ttt \n");
              if (estnet[19] == 0)
                estnet[19] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[19], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 486;
              right.y = 235;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[19], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[19] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 478;
            wrong.y = 227;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[19] = 1;
        }
        if (mouse_x > 570 && mouse_x < 619 && mouse_y > 235 && mouse_y < 288 &&
            status[20] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'u') {
              printf("uuu \n");
              if (estnet[20] == 0)
                estnet[20] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[20], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 570;
              right.y = 235;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[20], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[20] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 562;
            wrong.y = 227;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[20] = 1;
        }
        if (mouse_x > 147 && mouse_x < 205 && mouse_y > 310 && mouse_y < 357 &&
            status[21] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'v') {
              printf("vvv \n");
              if (estnet[21] == 0)
                estnet[21] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[21], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 147;
              right.y = 310;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[21], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[21] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 139;
            wrong.y = 302;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[21] = 1;
        }
        if (mouse_x > 226 && mouse_x < 304 && mouse_y > 310 && mouse_y < 357 &&
            status[22] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'w') {
              printf("www \n");
              if (estnet[22] == 0)
                estnet[22] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[22], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 226;
              right.y = 310;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[22], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[22] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 218;
            wrong.y = 302;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[22] = 1;
        }
        if (mouse_x > 323 && mouse_x < 375 && mouse_y > 310 && mouse_y < 357 &&
            status[23] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'x') {
              printf("xxx \n");
              if (estnet[23] == 0)
                estnet[23] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[23], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 323;
              right.y = 310;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[23], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[23] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 315;
            wrong.y = 302;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[23] = 1;
        }
        if (mouse_x > 403 && mouse_x < 459 && mouse_y > 310 && mouse_y < 357 &&
            status[24] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'y') {
              printf("yyy \n");
              if (estnet[24] == 0)
                estnet[24] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[24], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 403;
              right.y = 310;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[24], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[24] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 395;
            wrong.y = 302;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[24] = 1;
        }
        if (mouse_x > 491 && mouse_x < 539 && mouse_y > 310 && mouse_y < 357 &&
            status[25] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'z') {
              printf("zzz \n");
              if (estnet[25] == 0)
                estnet[25] = 1;
              SDL_Rect rect;
              SDL_Rect right;
              ++c;
              SDL_QueryTexture(tex_let[25], NULL, NULL, &rect.w, &rect.h);
              SDL_QueryTexture(tex_right, NULL, NULL, &right.w, &right.h);
              right.w = 58;
              right.h = 70;
              right.x = 491;
              right.y = 310;

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[25], NULL, &rect);
              SDL_RenderCopy(rend, tex_right, NULL, &right);
            }
          }
          if (estnet[25] == 0) {
            ++failure;
            SDL_Rect wrong;
            SDL_QueryTexture(tex_wrong, NULL, NULL, &wrong.w, &wrong.h);
            wrong.w = 58;
            wrong.h = 70;
            wrong.x = 483;
            wrong.y = 302;
            SDL_RenderCopy(rend, tex_wrong, NULL, &wrong);
          }
          cout << endl;
          cout << failure << endl;
          cout << c << endl;

          status[25] = 1;
        }

        SDL_RenderPresent(rend);
        if (failure == 5) {
          cout << "YOU LOST!!";
          return 7;
        }
        if (c == strlen(word)) {
          cout << "YOU WON!!";
          return 5;
        }
      }
    }
  }
  return 0;
}
void File1(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
           SDL_Texture *tex_blank, SDL_Texture *tex_loss,
           SDL_Texture *tex_win) {
  cout << "yolo" << endl;

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
  SDL_RenderCopy(rend, tex_game, NULL, NULL);

  SDL_Rect rect;
  while (b < l) {
    SDL_QueryTexture(tex_blank, NULL, NULL, &rect.w, &rect.h);

    rect.w = 70;
    rect.h = 30;
    rect.x = 25 + (b * 70);
    rect.y = 600;
    SDL_RenderCopy(rend, tex_blank, NULL, &rect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 60);
    b++;
  }
  h = Hang(rend, win, word);

  if (h == 7) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_loss, NULL, NULL);
    SDL_RenderPresent(rend);

  } else if (h == 5) {
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_win, NULL, NULL);
    SDL_RenderPresent(rend);
  }
}

void File2(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
           SDL_Texture *tex_blank, SDL_Texture *tex_loss,
           SDL_Texture *tex_win) {
  cout << "yolo" << endl;

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
  SDL_RenderCopy(rend, tex_game, NULL, NULL);

  SDL_Rect rect;
  while (b < l) {
    SDL_QueryTexture(tex_blank, NULL, NULL, &rect.w, &rect.h);

    rect.w = 70;
    rect.h = 30;
    rect.x = 25 + (b * 70);
    rect.y = 600;
    SDL_RenderCopy(rend, tex_blank, NULL, &rect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 60);
    b++;
  }
  h = Hang(rend, win, word);
  if (h == 7) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_loss, NULL, NULL);
    SDL_RenderPresent(rend);
  } else if (h == 5) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_win, NULL, NULL);
    SDL_RenderPresent(rend);
  }
}

void File3(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
           SDL_Texture *tex_blank, SDL_Texture *tex_loss,
           SDL_Texture *tex_win) {
  cout << "yolo" << endl;

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

  cout << word;
  cout << l;
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex_game, NULL, NULL);

  SDL_Rect rect;
  while (b < l) {
    SDL_QueryTexture(tex_blank, NULL, NULL, &rect.w, &rect.h);

    rect.w = 70;
    rect.h = 30;
    rect.x = 25 + (b * 70);
    rect.y = 600;
    SDL_RenderCopy(rend, tex_blank, NULL, &rect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 60);
    b++;
  }
  h = Hang(rend, win, word);
  if (h == 7) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_loss, NULL, NULL);
    SDL_RenderPresent(rend);

  } else if (h == 5) {

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_win, NULL, NULL);
    SDL_RenderPresent(rend);
  }
}

int Help() {
  int k;
  fstream Help;
  Help.open("../files/Help.txt");
  if (!Help.is_open()) {
    cout << "Can't find file" << endl;
    Menu();
  } else {
    string str;
    while (!Help.eof()) {
      str = "";
      getline(Help, str);
      cout << str << endl;
    }
  }
  cout << "- Click 1 to go back" << endl;
  cin >> k;
  if (k == 1)
    return 1;
  else
    return 0;
}
