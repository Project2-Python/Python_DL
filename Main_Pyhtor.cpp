#include "IOText.h"
#include "tampilanUI.h"
#include "kelolafile.h"



int main()
{
	/* Proses Menampilkan awal app */
	boxTampilanAwalApp();
	
	/* Proses Insertion / Proses edit text */
	system("cls");
	color(7);
	keyProsess();
	
	
	createFile();
	renameFile();
	removeFile();
  
	return 0;
}
