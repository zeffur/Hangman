#include "output.h"
#include "menu.h"
#include <fstream>
#include <iostream>
using namespace std;

int File1() {
  srand(time(NULL));
  int i = 0;
  fstream Theme;
  string path = "./files/Length1.txt";
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

int File2() {
  srand(time(NULL));
  int i = 0;
  fstream Theme;
  string path = "./files/Length2.txt";
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

int File3() {
  srand(time(NULL));
  int i = 0;
  fstream Theme;
  string path = "./files/Length3.txt";
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

int Hang(string slovo) {
  int k = 0, i = 0, o, LIFE = 5;
  cout << "\t NACHALO" << endl;
  cout << "VVEDITE LETTER" << endl;
  string Buffer;
  char temp;
  for (int i = 0; i < slovo.length(); i++)
    Buffer += "_";
  cout << Buffer << "\tLife:" << LIFE << endl;
  while (LIFE > 0 && (slovo != Buffer)) {
    cin >> temp;
    k = 0;
    for (int i = 0; i < slovo.length(); i++) {
      if (slovo[i] == temp) {
        k++;
        Buffer[i] = temp;
      }
    }
    if (k == 0)
      LIFE--;
    cout << Buffer << "\tLife:" << LIFE << endl;
  }
  if (LIFE > 0) {
    cout << "POBEEDAAAAAA";
    cout << endl;
    system("PAUSE");
    Menu();
  } else {
    cout << "SMEERTb";
    cout << endl;
    system("PAUSE");
    Menu();
  }

  int Help() {
    system("CLS");
    int k;
    fstream Help;
    Help.open("Help.txt");
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
