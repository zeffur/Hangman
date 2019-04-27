#include"graphics.h"
#include <iostream>
#include <string.h>
#define ESC 27 
#define ENTER 13
#define UP 72
#define DOWN 80
#define r 12

enum Color {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
void shar(int x, int y, Color C) {
	setcolor(C);
	setfillstyle(1, C);
	fillellipse(x, y, r, r);
}

void intro() {
	char title[8] = "Hangman";
	char s[2];
	int x[7] = { 20, 50, 70, 90, 110, 140, 160 }, y, dy = 5;
	for (int i = 0; i < 8; i++) {
		y = 0;
		strnset(s, title[i], 1);
		s[1] = '\0';
		setcolor(White);
		settextstyle(1, 0, 3);
		outtextxy(x[i], y, s);
		while (y < 100) {
			delay(20);
			setcolor(Black);
			outtextxy(x[i], y, s);
			y = y + dy;
			setcolor(Red);
			outtextxy(x[i], y, s);

		}

	}
}
int MainMenu() {
	int y[3]{ 20,80,140 }, x = 50;
	char key = 0;
	settextstyle(1, 0, 3);
	setcolor(White);
	for (int i = 0; i < 3; i++) {
		switch (i) {
		case 0: outtextxy(x, y[i], "Game"); shar(x / 2, y[i], White); break;
		case 1: outtextxy(x, y[i], "Help");  break;
		case 2: outtextxy(x, y[i], "Exit");  break;
		}
	}
	int nomer = 0;
	do {
		if (kbhit()) {
			key = getch();
			shar(x / 2, 20 + nomer * 60, Black);
			switch (key) {
			case UP:if (nomer > 0)nomer--; break;
			case DOWN:if (nomer < 2)nomer++; break;
			case ENTER: return nomer;
			}
			shar(x / 2, 20 + nomer * 60, White);
		}

	} while (key != ESC);


}
int DiffMenu() {
	int y[4]{ 20,80,140,200 }, x = 50;
	char key = 0;
	settextstyle(1, 0, 3);
	setcolor(White);
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0: outtextxy(x, y[i], "Easy"); shar(x / 2, y[i], White); break;
		case 1: outtextxy(x, y[i], "Medium");  break;
		case 2: outtextxy(x, y[i], "Hard");  break;
		case 3: outtextxy(x, y[i], "Go Back");  break;
		}
	}
	int nomer = 0;
	do {
		if (kbhit()) {
			key = getch();
			shar(x / 2, 20 + nomer * 60, Black);
			switch (key) {
			case UP:if (nomer > 0)nomer--; break;
			case DOWN:if (nomer < 3)nomer++; break;
			case ENTER: return nomer;
			}
			shar(x / 2, 20 + nomer * 60, White);
		}

	} while (key != ESC);


}

int main() {
	int n,k;
	initwindow(325, 300, "Hangman");
	intro();
	cleardevice();
	TryAgain:
	n=MainMenu();
	if (!n) {
		cleardevice();
		k = DiffMenu();
		if (k > 2) {
			cleardevice();
			switch (k) {
			case 0:
			case 1:
			case 2:
			}

		}
		else {
			cleardevice();
			goto TryAgain;
		}
	}
	
	

