#include "menu.h"
#include "output.h"
#include <conio.h>
#include <iostream>

using namespace std;

int SecMenu() {
  cout << "Select difficulty level:" << endl;
  cout << "1.Easy" << endl;
  cout << "2.Normal" << endl;
  cout << "3.Hard" << endl;
  cout << "4.Go Back" << endl;
  cout << endl;
  //	while (bool l = true) {
  int k = getch();
  if (k == 50 || k == 49 || k == 51)
    Game(k);
  else if (k == 52)
    return 1;

  return 0;
}

int Menu() {
  int k = 0;
  cout << "1.Game" << endl;
  cout << "2.Help" << endl;
  cout << "3.Exit" << endl;
  //	while (bool l = true) {
  switch (getch()) {
  case 49:
    k = SecMenu();
    break;
  case 50:
    k = Help();
    break;
  case 51: /* l = false;*/
    return 0;
    // default??
    //		}
  }
  if (k)
    Menu();
}
