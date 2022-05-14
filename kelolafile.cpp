
#include "kelolafile.h"




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

void saveFile(address* AwalNotepad, char filename[20])
{
		address ptr = *AwalNotepad;
		ptr = ptr->right;
		
		FILE *fp;
		fp = fopen(filename,"w");
		
		if(fp == NULL){
			printf("File Tidak ada");
		}else{
			while (ptr != NULL)
			{
				fprintf(fp,"%c",ptr->data);
				ptr = ptr->right;	
			}
		}
		fclose(fp);
}


