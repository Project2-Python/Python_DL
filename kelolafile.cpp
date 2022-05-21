
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

void removeFile(){
	
	FILE *fp;
	int status;
	char filename[20];
	printf("\t\tMasukan Nama File :");
	scanf("%s",filename);
	status=remove(filename);
	if(status!= 0){
	printf("\t\tFile Tidak Terhapus");
	}else{
	printf("\t\tFile Terhapus");
	}
}

void renameFile()
{
    char oldName[100], newName[100];
	char filename[20];
    
    printf("\t\tMasukan nama file yang ingin diubah: ");
    scanf("%s", oldName);

    printf("\t\tMasukkan nama baru untuk file ini: ");
    scanf("%s", newName);

    if (rename(oldName, newName) == 0)
    {
    printf("\t\tNama file berhasil diubah.\n");
    }
    else
    {
    printf("\t\tError! Tidak dapat mengganti nama file ini.\n");
    }
 	printf("\t\t"); system("pause");
 
}

void openFile(){
	
	FILE *fedit;
	char c, filename[20];
	address feditor;
	
	printf("\t\tNama file : ");
	scanf("%s", filename);
	
	fedit = fopen(filename,"r");
	if(fedit == NULL)
	{
		
		printf("\t\tFile tidak ada");
		system("\t\tpause");
		
	} 
	
	system("cls");
	while(!feof(fedit)){
		
		fscanf(fedit, "%c", &c);
		if(c == -1){
			break;
		}
		Insertion(c);
	}
	
	fclose(fedit);
	Print_Text();
	keyProsess(filename);
}


