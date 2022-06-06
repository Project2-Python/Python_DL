
#include "kelolafile.h"
#include "tampilanUI.h"

struct file File;

char *getNameFile()
{	
	return File.namaFile;
}


void createFile()
{
	
	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Masukkan nama file : ");
	scanf("%s",File.namaFile);
	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
	
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
	
	gotoxy(60,0); printf("%s", getNameFile());
	
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
	
	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Masukkan nama file : ");
	scanf("%s",filename);
	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
	
	if(File.isFileEmpty == 0)
	{
		if(strcmp(File.namaFile, filename) == 0)
		{
			
		}
		else
		{
			status=remove(filename);
	
			if(status != 0)
			{
				gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("File Tidak Terhapus");
				gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
			}
			else
			{
				gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("File Terhapus");
				gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
			}
		}
	} 
	else
	{
		status=remove(filename);
	
		if(status != 0)
		{
			gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("File Tidak Terhapus");
			gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
		}
		else
		{
			gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("File Terhapus");
			gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
		}
	}
	
	
}


void renameFile()
{
    char oldName[100], newName[100];
	char filename[20];
    
    gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Masukkan Nama File Lama : ");
    scanf("%s", oldName);
    gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
    
    if(File.isFileEmpty == 0)
    {
    	if(strcmp(File.namaFile, oldName) == 0)
    	{
    		
		}
		else
		{
			gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Masukkan Nama File Baru : ");
		    scanf("%s", newName);
		    gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
		    
		    if(strcmp(File.namaFile, newName) == 0)
		    {
		    	
			}
			else
			{
				if (rename(oldName, newName) == 0)
			    {
			    	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Berhasil Diubah");
			    	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
			    }
			    else
			    {
			    	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Tidak Berhasil");
			    	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
			    }
			}
		}
	}
	else
	{
		gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Masukkan Nama File Baru : ");
	    scanf("%s", newName);
	    gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
	    
	    if(strcmp(File.namaFile, newName) == 0)
	    {
	    	
		}
		else
		{
			if (rename(oldName, newName) == 0)
		    {
		    	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Berhasil Diubah");
		    	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
		    }
		    else
		    {
		    	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Tidak Berhasil");
		    	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
		    }
		}
	} 
}


void openFile(){
	
	FILE *fedit;
	address feditor;
	char c, fileName[25];
	
	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Masukkan Nama File : ");
	scanf("%s",fileName);
	gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
	
	fedit = fopen(fileName,"r");
	if(fedit == NULL)
	{
		gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("File Tidak Ada");
		Sleep(2000);
		gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
		gotoxy(getkolomBox()+1,getbarisBox()-1);	system("pause");
		gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
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
		editor.destcord.X = 0;
		editor.destcord.Y = 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), editor.destcord);
		
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


