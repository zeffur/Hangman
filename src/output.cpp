#include "output.h"
#include "menu.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <time.h>
#include <vector>
using namespace std;

void File1() {
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
  }
}

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
}

void Hang(string slovo) {
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
