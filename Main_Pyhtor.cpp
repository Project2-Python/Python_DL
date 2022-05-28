#include "IOText.h"
#include "tampilanUI.h"
#include "kelolafile.h"



int main()
{
	/* Proses Mengubah layar console */
	screenBuffer();
	screenSize();
	
	/* Proses Menampilkan awal app */
	boxTampilanAwalApp();
	system("cls");
	
	/* Proses Awal Dari Text Editor */
	Inisialisasi();
	
	/* Proses Insertion / Proses edit text */
	color(7);
	keyProsess();
//	system("cls");
//	color(7);	
//	createFile();
//	renameFile();
//	removeFile();
//	openFile();

  
	return 0;
}
