#ifndef KELOLAFILE_H
#define KELOLAFILE_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "IOText.h"

struct file{
	char namaFile[25];
	int isFileEmpty = 1;
};

void createFile();
void saveFile(address* AwalNotepad);
void removeFile();
void renameFile();
void openFile();
#endif


