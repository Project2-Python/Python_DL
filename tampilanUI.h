#ifndef tampilanUI_H
#define tampilanUI_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>


struct box{
	int a = 0;
	int b = 1;
	int c = 9;
	int d = 28;
	int e = 29;
	int f = 30; 
	int g = 120;
	int h = 2;
	int i = 11;
	int j = 35;
	int k = 56;
	int l = 79;
	int m = 101;
	int n = 115; 
	
};

int getbarisBox();
int getkolomBox();
void setKoordinatBox(char data, int before, int after);
void setCursorXY(COORD cursor);
void clearScreen(COORD startPoint);
void screenSize();
void screenBuffer();
void boxTampilanAwalApp(); 
void color(int color);
void gotoxy(int x, int y); 
int BoxPilihMenu();
void boxmenu();


#endif
