
#include "kelolafile.h"




//void createFile(){
//	
//	FILE *fp1;
//	char filename[20];
//	
//	printf("\t\tMasukkan nama file : ");
//	scanf("%s",filename);
//	
//	fp1 = fopen(filename,"w");
//	fclose(fp1);
//	system("cls");
//	keyProsess();
//  
//}

void saveFile(address* AwalNotepad)
{
		address ptr = *AwalNotepad;
		
		FILE *fp;
		fp = fopen("TesSave.txt","w");
		
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


