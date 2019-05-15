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
    path[15] = 'B' + l;
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
        if (mouse_x > 80 && mouse_x < 140 && mouse_y > 80 && mouse_y < 140 &&
            status[0] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'a') {
              printf("aaa \n");
              SDL_Rect rect;
              SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
            }
          }
          status[0] = 1;
        }

        if (mouse_x > 140 && mouse_x < 200 && mouse_y > 80 && mouse_y < 140 &&
            status[1] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'b') {
              printf("bbb \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[1], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[1], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[1] = 1;
        }

        if (mouse_x > 200 && mouse_x < 260 && mouse_y > 80 && mouse_y < 140 &&
            status[2] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'c') {
              printf("ccc \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[2], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[2], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[2] = 1;
        }
        if (mouse_x > 260 && mouse_x < 320 && mouse_y > 80 && mouse_y < 140 &&
            status[3] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'd') {
              printf("ddd \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[3], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[3], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[3] = 1;
        }
        if (mouse_x > 320 && mouse_x < 380 && mouse_y > 80 && mouse_y < 140 &&
            status[4] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'e') {
              printf("eee \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[4], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[4], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[4] = 1;
        }
        if (mouse_x > 380 && mouse_x < 440 && mouse_y > 80 && mouse_y < 140 &&
            status[5] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'f') {
              printf("fff \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[5], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[5], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[5] = 1;
        }
        if (mouse_x > 440 && mouse_x < 500 && mouse_y > 80 && mouse_y < 140 &&
            status[6] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'g') {
              printf("ggg \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[6], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[6], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[6] = 1;
        }
        if (mouse_x > 80 && mouse_x < 140 && mouse_y > 140 && mouse_y < 210 &&
            status[7] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'h') {
              printf("hhh \n");
              SDL_Rect rect;
              SDL_QueryTexture(tex_let[7], NULL, NULL, &rect.w, &rect.h);

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[7], NULL, &rect);
            }
          }
          status[7] = 1;
        }

        if (mouse_x > 140 && mouse_x < 200 && mouse_y > 140 && mouse_y < 210 &&
            status[8] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'i') {
              printf("iii \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[8], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[8], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[8] = 1;
        }

        if (mouse_x > 200 && mouse_x < 260 && mouse_y > 140 && mouse_y < 210 &&
            status[9] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'j') {
              printf("jjj \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[9], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[9], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[9] = 1;
        }
        if (mouse_x > 260 && mouse_x < 320 && mouse_y > 140 && mouse_y < 210 &&
            status[10] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'k') {
              printf("kkk \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[10], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[10], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[10] = 1;
        }
        if (mouse_x > 320 && mouse_x < 380 && mouse_y > 140 && mouse_y < 210 &&
            status[11] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'l') {
              printf("lll \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[11], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[11], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[11] = 1;
        }
        if (mouse_x > 380 && mouse_x < 440 && mouse_y > 140 && mouse_y < 210 &&
            status[12] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'm') {
              printf("mmm \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[12], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[12], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[12] = 1;
        }
        if (mouse_x > 440 && mouse_x < 500 && mouse_y > 140 && mouse_y < 210 &&
            status[13] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'n') {
              printf("nnn \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[13], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[13], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[13] = 1;
        }

        if (mouse_x > 80 && mouse_x < 140 && mouse_y > 210 && mouse_y < 280 &&
            status[14] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'o') {
              printf("ooo \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[14], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[14], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[14] = 1;
        }

        if (mouse_x > 140 && mouse_x < 200 && mouse_y > 210 && mouse_y < 280 &&
            status[15] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'p') {
              printf("ppp \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[15], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[15], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[15] = 1;
        }
        if (mouse_x > 200 && mouse_x < 260 && mouse_y > 210 && mouse_y < 280 &&
            status[16] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'q') {
              printf("qqq \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[16], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[16], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[16] = 1;
        }
        if (mouse_x > 260 && mouse_x < 320 && mouse_y > 210 && mouse_y < 280 &&
            status[17] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'r') {
              printf("rrr \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[17], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[17], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[17] = 1;
        }
        if (mouse_x > 320 && mouse_x < 380 && mouse_y > 210 && mouse_y < 280 &&
            status[18] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 's') {
              printf("sss \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[18], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[18], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[18] = 1;
        }
        if (mouse_x > 380 && mouse_x < 440 && mouse_y > 210 && mouse_y < 280 &&
            status[19] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 't') {
              printf("ttt \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[19], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[19], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[19] = 1;
        }
        if (mouse_x > 440 && mouse_x < 500 && mouse_y > 210 && mouse_y < 280 &&
            status[20] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'u') {
              printf("uuu \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[20], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[20], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[20] = 1;
        }
        if (mouse_x > 140 && mouse_x < 200 && mouse_y > 210 && mouse_y < 350 &&
            status[21] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'v') {
              printf("vvv \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[21], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[21], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[21] = 1;
        }
        if (mouse_x > 200 && mouse_x < 260 && mouse_y > 210 && mouse_y < 350 &&
            status[22] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'w') {
              printf("www \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[22], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[22], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[22] = 1;
        }
        if (mouse_x > 260 && mouse_x < 320 && mouse_y > 210 && mouse_y < 350 &&
            status[23] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'x') {
              printf("xxx \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[23], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[23], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[23] = 1;
        }
        if (mouse_x > 320 && mouse_x < 380 && mouse_y > 210 && mouse_y < 350 &&
            status[24] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'y') {
              printf("yyy \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[24], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[24], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[24] = 1;
        }
        if (mouse_x > 380 && mouse_x < 440 && mouse_y > 210 && mouse_y < 350 &&
            status[25] == 0) {
          for (i = 0; i < strlen(word); i++) {
            if (word[i] == 'z') {
              printf("zzz \n");
              SDL_Rect rect;
              if (SDL_QueryTexture(tex_let[25], NULL, NULL, &rect.w, &rect.h))
                cout << "DSDSDSDSD";

              rect.w = 58;
              rect.h = 70;
              rect.x = 28 + i * 70;
              rect.y = 550;
              SDL_RenderCopy(rend, tex_let[25], NULL, &rect);
            }
            //  SDL_RenderPresent(rend);
            // SDL_Delay(1000 / 60);
            //  SDL_RenderClear(rend);
          }
          status[25] = 1;
        }

        /*  if (mouse_x > 200 && mouse_x < 260 && mouse_y > 210 && mouse_y < 350
          && status[2] == 0) { for (i = 0; i < strlen(word); i++) { if (word[i]
          == 'c') { printf("ccc \n"); SDL_Rect rect;
                SDL_QueryTexture(tex_let[2], NULL, NULL, &rect.w, &rect.h);

                rect.w = 58;
                rect.h = 70;
                rect.x = 28 + i * 70;
                rect.y = 550;
                SDL_RenderCopy(rend, tex_let[2], NULL, &rect);
              }
              SDL_RenderPresent(rend);
            }
            status[2] = 1;
          }*/
        SDL_RenderPresent(rend);
      }
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
    rect.x = 25 + (b * 70);
    rect.y = 600;
    SDL_RenderCopy(rend, tex_blank, NULL, &rect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / 60);
    b++;
  }
  Hang(rend, win, word);
}

void File2(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
           SDL_Texture *tex_blank) {
  cout << "yolo" << endl;

  srand(time(NULL));
  int i = 0, l, b = 0, k;
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
  Hang(rend, win, word);
}

void File3(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game,
           SDL_Texture *tex_blank) {
  cout << "yolo" << endl;

  srand(time(NULL));
  int i = 0, l, b = 0, k;
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
