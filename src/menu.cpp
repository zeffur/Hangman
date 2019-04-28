#include "menu.h"
#include "output.h"
//#include <conio.h>
#include <iostream>

using namespace std;

int SecMenu() {
  cout << "Select difficulty level:" << endl;
  cout << "1.Easy" << endl;
  cout << "2.Normal" << endl;
  cout << "3.Hard" << endl;
  cout << "4.Go Back" << endl;
  cout << endl;
  int k = 0;
  cin >> k;
  //	while (bool l = true) {
  /*if (k == 50 || k == 49 || k == 51)
    Game(k);
  else if (k == 52)
    return 1;*/
  switch (k) {
  case 1:
    Game(k);
    break;
  case 2:
    Game(k);
    break;
  case 3:
    Game(k);
    break;
  case 4:
    return 1;
  default:
    cout << "Error\n";
    break;
  }

  return 0;
}

int Menu() {
  int l = 0, k = 0;
  cout << "1.Game" << endl;
  cout << "2.Help" << endl;
  cout << "3.Exit" << endl;
  //	while (bool l = true) {
  cin >> k;
  switch (k) {
  case 1:
    l = SecMenu();
    break;
  case 2:
    l = Help();
    break;
  case 3: /* l = false;*/
    return 0;
    // default??
    //		}
  }
  if (l)
    Menu();
  return 0;
}
