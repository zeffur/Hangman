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
  switch (k) {
  case 1:
    File1();
    break;
  case 2:
    File2();
    break;
  case 3:
    File3();
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
  system("CLS");
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
  case 3:
    return 0;
  }
  if (l)
    Menu();
  return 0;
}
