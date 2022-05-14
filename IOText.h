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
	
};

static struct NotePad editor;



//Procedure And Function
address Alokasi();
void Inisialisasi();
void Insertion(int data);
void Print_Text();
void setCursor();
void keyProsess();
void Deletion();
void swap(char *tempfordel1, char *tempfordel2);
void UpDownLink(address ptr, char key);
void MoveCursor();
#endif
