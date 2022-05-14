#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "kelolafile.h"
#include "IOText.h"



void createFile(){
	
	FILE *fp1;
	char filename[20];
	
	printf("\t\tMasukkan nama file : ");
	scanf("%s",filename);
	
	fp1 = fopen(filename,"w");
	fclose(fp1);
	system("cls");
	keyProsess(filename);
  
}

void saveFile(char filename[20])
{
		address ptr = editor.head_of_notepad;
		
		FILE *fp;
		fp = fopen(filename,"w");
		
		if(fp == NULL){
			printf("File Tidak ada");
		}else{
			while (ptr != NULL)
			{
				fprintf(fp,"%c",ptr);
				ptr = ptr->right;	
			}
		}
}


