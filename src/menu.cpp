#include "menu.h"
#include "output.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
using namespace std;

int Menu(SDL_Renderer *rend, SDL_Window *win, SDL_Texture **tex_all,
         SDL_Texture **tex_let) {

  SDL_SetRenderDrawColor(rend, 150, 0, 0, 150);
  SDL_RenderClear(rend);
  graphics(0, rend, tex_all);
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
        if (mouse_x > 297 && mouse_x < 388 && mouse_y > 197 && mouse_y < 243) {
          graphics(11, rend, tex_all);
          Levels(rend, win, tex_all, tex_let);
        }

        if (mouse_x > 285 && mouse_x < 387 && mouse_y > 260 && mouse_y < 305) {
          graphics(12, rend, tex_all);
          Help(rend, win, tex_all, tex_let);
        }
        if (mouse_x > 286 && mouse_x < 378 && mouse_y > 319 && mouse_y < 363) {
          graphics(13, rend, tex_all);
          exit(0);
        }
      }
    }
  }
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);

  return 0;
}

void graphics(int r, SDL_Renderer *rend, SDL_Texture **tex_all) {
  if (r == 0) {
    SDL_Rect title;
    SDL_Rect opt;
    SDL_QueryTexture(tex_all[0], NULL, NULL, &title.w, &title.h);
    SDL_QueryTexture(tex_all[17], NULL, NULL, &opt.w, &opt.h);
    title.w = 700;
    title.h = 100;
    title.x = 0;
    title.y = 0;

    opt.w = 115;
    opt.h = 190;
    opt.x = 281;
    opt.y = 190;
    SDL_RenderCopy(rend, tex_all[0], NULL, &title);
    SDL_RenderCopy(rend, tex_all[17], NULL, &opt);
    SDL_RenderPresent(rend);
  }
  if (r == 1) {
    SDL_Rect alph;
    SDL_Rect human;
    SDL_QueryTexture(tex_all[2], NULL, NULL, &alph.w, &alph.h);
    SDL_QueryTexture(tex_all[19], NULL, NULL, &human.w, &human.h);
    alph.w = 375;
    alph.h = 226;
    alph.x = 28;
    alph.y = 21;

    human.w = 84;
    human.h = 250;
    human.x = 518;
    human.y = 190;
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[2], NULL, &alph);
    SDL_RenderCopy(rend, tex_all[19], NULL, &human);
  }

  if (r == 11) {
    SDL_Rect playbut;
    SDL_Rect title;
    SDL_Rect levels;
    SDL_Rect back;

    SDL_QueryTexture(tex_all[13], NULL, NULL, &playbut.w, &playbut.h);
    SDL_QueryTexture(tex_all[0], NULL, NULL, &title.w, &title.h);
    SDL_QueryTexture(tex_all[1], NULL, NULL, &levels.w, &levels.h);
    SDL_QueryTexture(tex_all[18], NULL, NULL, &back.w, &back.h);

    playbut.w = 173;
    playbut.h = 92;
    playbut.x = 253;
    playbut.y = 176;

    title.w = 700;
    title.h = 100;
    title.x = 0;
    title.y = 0;

    levels.w = 368;
    levels.h = 223;
    levels.x = 168;
    levels.y = 138;

    back.w = 127;
    back.h = 71;
    back.x = 557;
    back.y = 415;
    SDL_RenderCopy(rend, tex_all[13], NULL, &playbut);
    SDL_RenderPresent(rend);
    SDL_Delay(100);

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[0], NULL, &title);
    SDL_RenderCopy(rend, tex_all[1], NULL, &levels);
    SDL_RenderCopy(rend, tex_all[18], NULL, &back);
    SDL_RenderPresent(rend);
  }
  if (r == 12) {
    SDL_Rect helpbut;
    SDL_Rect title;
    SDL_Rect back;
    SDL_Rect htp;
    SDL_Rect first;
    SDL_Rect second;
    SDL_Rect third;
    SDL_QueryTexture(tex_all[14], NULL, NULL, &helpbut.w, &helpbut.h);
    SDL_QueryTexture(tex_all[0], NULL, NULL, &title.w, &title.h);
    SDL_QueryTexture(tex_all[18], NULL, NULL, &back.w, &back.h);
    SDL_QueryTexture(tex_all[16], NULL, NULL, &htp.w, &htp.h);
    SDL_QueryTexture(tex_all[22], NULL, NULL, &first.w, &first.h);
    SDL_QueryTexture(tex_all[23], NULL, NULL, &second.w, &second.h);
    SDL_QueryTexture(tex_all[24], NULL, NULL, &third.w, &third.h);
    helpbut.w = 210;
    SDL_RenderPresent(rend);
    helpbut.h = 117;
    helpbut.x = 233;
    helpbut.y = 225;

    title.w = 700;
    title.h = 100;
    title.x = 0;
    title.y = 0;

    back.w = 127;
    back.h = 71;
    back.x = 557;
    back.y = 415;

    htp.w = 165;
    htp.h = 30;
    htp.x = 258;
    htp.y = 140;

    first.w = 620;
    first.h = 50;
    first.x = 33;
    first.y = 186;

    second.w = 621;
    second.h = 72;
    second.x = 38;
    second.y = 247;

    third.w = 621;
    third.h = 73;
    third.x = 33;
    third.y = 335;

    SDL_RenderCopy(rend, tex_all[14], NULL, &helpbut);
    SDL_RenderPresent(rend);
    SDL_Delay(100);

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[0], NULL, &title);
    SDL_RenderCopy(rend, tex_all[18], NULL, &back);
    SDL_RenderCopy(rend, tex_all[16], NULL, &htp);
    SDL_RenderCopy(rend, tex_all[22], NULL, &first);
    SDL_RenderCopy(rend, tex_all[23], NULL, &second);
    SDL_RenderCopy(rend, tex_all[24], NULL, &third);
    SDL_RenderPresent(rend);
  }
  if (r == 13) {
    SDL_Rect quitbut;
    SDL_QueryTexture(tex_all[15], NULL, NULL, &quitbut.w, &quitbut.h);
    quitbut.w = 211;
    quitbut.h = 112;
    quitbut.x = 233;
    quitbut.y = 286;

    SDL_RenderCopy(rend, tex_all[15], NULL, &quitbut);
    SDL_RenderPresent(rend);
    SDL_Delay(5);
  }
  if (r > 0 && r < 6) {
    SDL_Rect Hang;
    SDL_QueryTexture(tex_all[r + 7], NULL, NULL, &Hang.w, &Hang.h);
    Hang.w = 275;
    Hang.h = 475;
    Hang.x = 797;
    Hang.y = 150;

    // SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex_all[r + 7], NULL, &Hang);
    // SDL_RenderPresent(rend);
  }
}

void graphics_b(int r, SDL_Renderer *rend, SDL_Texture **tex_all, int b) {
  SDL_Rect rect;
  SDL_QueryTexture(tex_all[3], NULL, NULL, &rect.w, &rect.h);

  rect.w = 35;
  rect.h = 20;
  rect.x = 10 + (b * 35);
  rect.y = 400;
  SDL_RenderCopy(rend, tex_all[3], NULL, &rect);
  SDL_RenderPresent(rend);
  SDL_Delay(1000 / 60);
}

void graphics_let(int r, SDL_Renderer *rend, SDL_Texture **tex_all,
                  SDL_Texture **tex_let, int i) {
  if (r == 200) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[0], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 66;
    right.y = 83;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[0], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 201) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
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
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 202) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
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
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 203) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
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
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 204) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
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
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 205) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
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
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 206) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
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
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 207) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    SDL_QueryTexture(tex_let[7], NULL, NULL, &rect.w, &rect.h);
    right.w = 58;
    right.h = 70;
    right.x = 71;
    right.y = 159;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[7], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }

  if (r == 208) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
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
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 209) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
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
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }

  if (r == 210) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[10], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 325;
    right.y = 159;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[10], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 211) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[11], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 413;
    right.y = 159;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[11], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 212) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[12], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 480;
    right.y = 159;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[12], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 213) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[13], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 576;
    right.y = 159;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[13], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 214) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[14], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 70;
    right.y = 235;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[14], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 215) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[15], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 158;
    right.y = 235;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[15], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 216) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[16], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 234;
    right.y = 235;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[16], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 217) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[17], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 323;
    right.y = 235;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[17], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 218) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[18], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 410;
    right.y = 235;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[18], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 219) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[19], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 486;
    right.y = 235;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[19], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 220) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[20], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 570;
    right.y = 235;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[20], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 221) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[21], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 147;
    right.y = 310;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[21], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 222) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[22], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 226;
    right.y = 310;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[22], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 223) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[23], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 323;
    right.y = 310;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[23], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 224) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[24], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 403;
    right.y = 310;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[24], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }
  if (r == 225) {
    SDL_Rect rect;
    SDL_Rect right;
    SDL_QueryTexture(tex_let[25], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(tex_all[6], NULL, NULL, &right.w, &right.h);
    right.w = 58;
    right.h = 70;
    right.x = 491;
    right.y = 310;

    rect.w = 58;
    rect.h = 70;
    rect.x = 28 + i * 70;
    rect.y = 550;
    SDL_RenderCopy(rend, tex_let[25], NULL, &rect);
    SDL_RenderCopy(rend, tex_all[6], NULL, &right);
  }

  if (r == 300) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 58;
    wrong.y = 75;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 301) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 150;
    wrong.y = 75;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 302) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 231;
    wrong.y = 75;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 303) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 317;
    wrong.y = 75;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 304) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 406;
    wrong.y = 75;

    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 305) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 483;
    wrong.y = 75;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 306) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 568;
    wrong.y = 75;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 307) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 64;
    wrong.y = 151;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 307) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 64;
    wrong.y = 151;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 308) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 154;
    wrong.y = 151;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 309) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 231;
    wrong.y = 151;

    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 310) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 317;
    wrong.y = 151;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 311) {

    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 405;
    wrong.y = 151;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }

  if (r == 312) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 472;
    wrong.y = 151;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 313) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 568;
    wrong.y = 151;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 314) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 62;
    wrong.y = 247;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 315) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 150;
    wrong.y = 227;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 316) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 226;
    wrong.y = 227;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 317) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 315;
    wrong.y = 227;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 318) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 402;
    wrong.y = 227;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }

  if (r == 319) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 478;
    wrong.y = 227;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 320) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 562;
    wrong.y = 227;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 321) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 139;
    wrong.y = 302;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 322) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 218;
    wrong.y = 302;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 323) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 315;
    wrong.y = 302;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }

  if (r == 324) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 395;
    wrong.y = 302;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
  if (r == 325) {
    SDL_Rect wrong;
    SDL_QueryTexture(tex_all[7], NULL, NULL, &wrong.w, &wrong.h);
    wrong.w = 58;
    wrong.h = 70;
    wrong.x = 483;
    wrong.y = 302;
    SDL_RenderCopy(rend, tex_all[7], NULL, &wrong);
  }
}
