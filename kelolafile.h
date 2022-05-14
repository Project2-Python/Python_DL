#ifndef KELOLAFILE_H
#define KELOLAFILE_H
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "IOText.h"

void createFile();
void saveFile(address* AwalNotepad, char filename[20]);
void removeFile();
void renameFile();

#endif


