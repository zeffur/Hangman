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

int File1(SDL_Renderer *rend, SDL_Window *win, SDL_Texture *tex_game) {
  cout << "yolo";

  srand(time(NULL));
  int i = 0;
  char word[256];

  FILE *file = fopen("./files/Length1.txt", "r");
  if (file == NULL) {
    cout << "file not found";
    cout << endl;
  }

  while (i < rand() % 10) {
    fscanf(file, "%s", word);
    //    l = strlen(word);
    i++;
  }
  cout << word;
  fclose(file);

  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, tex_game, NULL, NULL);
  SDL_RenderPresent(rend);
  // Hang(word,l);
  return 0;
} /*
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
/*
void Hang(char slovo) {
  int k = 0, LIFE = 5;
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
  }
}*/

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
