#include "IOText.h"
#include "tampilanUI.h"
#include "kelolafile.h"



int main()
{
	
	/* Proses Menampilkan awal app */
//	boxTampilanAwalApp();
	screenBuffer();
	Inisialisasi();
	screenSize();
//	Inisialisasi();
	
	/* Proses Insertion / Proses edit text */
//	system("cls");
//	color(7);	
//	createFile();
//	renameFile();
//	removeFile();
//	openFile();
	boxmenu();
	BoxPilihMenu();
  
	return 0;
}
