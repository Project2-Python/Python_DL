#include "IOText.h"
#include "tampilanUI.h"
#include "kelolafile.h"



int main(int argc, char *argv[])
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
	if(argv[1] != NULL)
		openFile(true, argv[1]);
	keyProsess();

	return 0;
}
