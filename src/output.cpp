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

/*
srand(time(NULL));
int i = 0;


fstream Theme;
string path = "../files/Length1.txt";
Theme.open(path);
if (!Theme.is_open()) {
  cout << "Can't find file" << endl;
  SecMenu();
} else {
  string str, slovo;
  while (i < rand() % 10) {
    str = " ";
    getline(Theme, str);
    slovo = str;
    i++;
  }
  Theme.close();
  Hang(slovo);
}*/
// return 0;
//}
/*
void File2() {
  srand(time(NULL));
  int i = 0;
  fstream Theme;
  string path = "../files/Length2.txt";
  Theme.open(path);
  if (!Theme.is_open()) {
    cout << "Can't find file" << endl;
    SecMenu();
  } else {
    string str, slovo;
    while (i < rand() % 10) {
      str = " ";
      getline(Theme, str);
      slovo = str;
      i++;
    }
    Theme.close();
    Hang(slovo);
  }
}

void File3() {
  srand(time(NULL));
  int i = 0;
  fstream Theme;
  string path = "../files/Length3.txt";
  Theme.open(path);
  if (!Theme.is_open()) {
    cout << "Can't find file" << endl;
    SecMenu();
  } else {
    string str, slovo;
    while (i < rand() % 10) {
      str = " ";
      getline(Theme, str);
      slovo = str;
      i++;
    }
    Theme.close();
    Hang(slovo);
  }
}*/

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
    printf("error creating texture: %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }

  char path[256] = "./files/images/A.png";
  for (int l = 0; l < 26; l++) {
    surface_let[l] = IMG_Load(path);
    tex_let[l] = SDL_CreateTextureFromSurface(rend, surface_let[l]);
    path[16] = 'B' + l;
  }
  SDL_FreeSurface(*surface_let);
  /*  SDL_Surface *surface_A = IMG_Load("./files/images/A.png");
    if (!surface_A) {
      printf("error creating surface\n");
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }

    SDL_Texture *tex_A = SDL_CreateTextureFromSurface(rend, surface_A);
    SDL_FreeSurface(surface_A);
    if (!tex_A) {
      printf("error creating texture: %s\n", SDL_GetError());
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }
  */
  cout << word;
  unsigned int i;
  int close_requested = 0;
  int status[26];
  memset(status, 0, sizeof(status));
  status[0] = 0;
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
        if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
            status[0] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'a') {
              printf("aaa \n");
              SDL_Rect rect;
              SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

              rect.w = 58;
              rect.h = 70;
              rect.x = 105 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
            }
            SDL_RenderPresent(rend);
          }
          status[0] = 1;
        }

        if (mouse_x > 140 && mouse_x < 200 && mouse_y > 80 && mouse_y < 140 &&
            status[1] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'b') {
              printf("bbb \n");
              SDL_Rect rect;
              SDL_QueryTexture(tex_let[1], NULL, NULL, &rect.w, &rect.h);

              rect.w = 58;
              rect.h = 70;
              rect.x = 105 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[1], NULL, &rect);
            }
            SDL_RenderPresent(rend);
            SDL_Delay(1000 / 60);
          }
          status[1] = 1;
        }

        /*
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }

    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }
    if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
        status == 1) {
      for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a') {
          printf("aaa \n");
          SDL_Rect rect;
          SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

          rect.w = 58;
          rect.h = 70;
          rect.x = 105 + i * 70;
          rect.y = 550;
          SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
        }
        SDL_RenderPresent(rend);
      }
    }*/

        /*int k = 0, LIFE = 5;
        cout << "\t NACHALO" << endl;
        cout << "VVEDITE LETTER" << endl;
        string Buffer;
        char temp;
        // o = slovo.length();
        for (std::vector<double>::size_type i = 0; i < slovo.length(); i++)
        Buffer += "_";
        cout << Buffer << "\tLife:" << LIFE << endl;
        while (LIFE > 0 && (slovo != Buffer)) {
          cin >> temp;
          k = 0;
          for (std::vector<double>::size_type j = 0; j < slovo.length(); j++) {
            if (slovo[j] == temp) {
              k++;
              Buffer[j] = temp;
            }
          }
          if (k == 0)
          LIFE--;
          cout << Buffer << "\tLife:" << LIFE << endl;
        }
        if (LIFE > 0) {
          cout << "POBEEDAAAAAA";
          cout << endl;
          Menu();
        } else {
          cout << "SMEERTb";
          cout << endl;
          Menu();
        }*/
      }
      /*  if (event.type == SDL_MOUSEBUTTONUP && status == 1)
          ++status;*/
    }
  }
  return 0;
}

void File1(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
           SDL_Texture *tex_blank) {
  cout << "yolo" << endl;

  srand(time(NULL));
  int i = 0, l, b = 0, k;
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
    rect.x = 100 + (b * 70);
    rect.y = 600;
    SDL_RenderCopy(rend, tex_blank, NULL, &rect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 60);
    b++;
  }
  Hang(rend, win, word);
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
