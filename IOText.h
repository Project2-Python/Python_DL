#ifndef IOTEXT_H
#define IOTEXT_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>



typedef struct node* address;
typedef struct node
{
	char data;
	address left;
	address right;
	address up;
	address down;
	address linehead;
	
}TextEditor;

struct NotePad{
	
	address head_of_notepad;
	address cursor;
	HANDLE hstdout;
	COORD destcord;
	int Modifier;
	
};

static struct NotePad editor;

enum KeyInput{
	
	ENTER = 13,
	CTRL_S = 19,
	CTRL_Q = 17,
	CTRL_T = 20,
	CTRL_I = 9,
	ESC = '\x1b'
	
};


//Procedure And Function
address Alokasi();
void Inisialisasi();
void Insertion(int data);
void Print_Text(address temp);
void setCursor();
void keyProsess();
void Deletion();
void swap(char *data1, char *data2);
void UpDownLink(address ptr, char key);
void MoveCursor();

#endif
