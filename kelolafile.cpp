
#include "kelolafile.h"
#include "tampilanUI.h"

struct file File;


void createFile()
{
	
	gotoxy(1,27);	printf("Masukkan nama file : ");
	scanf("%s",File.namaFile);
	gotoxy(1,27);	printf("                                                                   ");
	
	File.isFileEmpty = 0;
}


void saveFile(address* AwalNotepad)
{
	address ptr;
	FILE *fp;
	
	ptr = *AwalNotepad;
	ptr = ptr->right;
	
	if(File.isFileEmpty == 1)
	{
		createFile();
	}
	
	fp = fopen(File.namaFile,"w");
	
	while (ptr != NULL)
	{
		fprintf(fp,"%c",ptr->data);
		ptr = ptr->right;	
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
	
	if(status!= 0)
	{
		printf("\t\tFile Tidak Terhapus");
	}
	else
	{
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
	address feditor;
	char c, fileName[25];
	
	gotoxy(1,27);	printf("Masukkan nama file : ");
	scanf("%s",fileName);
	gotoxy(1,27);	printf("                                                                   ");
	
	fedit = fopen(fileName,"r");
	if(fedit == NULL)
	{
		
		printf("\t\tFile tidak ada");
		system("\t\tpause");
		File.isFileEmpty = 1;
		
	} 
	else
	{
		strcpy(File.namaFile, fileName);
		File.isFileEmpty = 0;
	}
	
	if(File.isFileEmpty != 1)
	{
		system("cls");
		Inisialisasi();
		while(!feof(fedit)){
			c = fgetc(fedit);
			if(c == -1){
				break;
			}
			Insertion(c);
		}
	}
	fclose(fedit);
	keyProsess();
}


