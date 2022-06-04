#include "tampilanUI.h"
#include "kelolafile.h"


void screenBuffer()
{
	COORD layar;
	
	layar.Y = 9001;
	layar.X = 500;
	
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), layar); 
}


void screenSize()
{
	SMALL_RECT windowSize = {0, 0, 120, 30};//LEFT TOP RIGHT BOTTOM
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, &windowSize);
}


void boxTampilanAwalApp()
{
	system("cls");
	
	gotoxy(0,25);  printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC");
	gotoxy(40,27); printf("S E L A M A T    D A T A N G    K A W A N");
	gotoxy(40,10); printf("OOOO   O   O  OOOOO  O   O   OOO   OOOO    ");
	gotoxy(40,11); printf("O   O   O O     O    O   O  O   O  O   O   "); 
	gotoxy(40,12); printf("OOOO     O      O    OOOOO  O   O  OOOO    ");
	gotoxy(40,13); printf("O        O      O    O   O  O   O  O  O    ");
	gotoxy(40,14); printf("O        O      O    O   O   OOO   O   O   ");	
	
	color(6); 
	gotoxy(40,16); printf("              ENTER: Lanjut");
	getch();
}


void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void gotoxy(int x, int y)
{
	COORD koordinat;
	
	koordinat.X = x;
	koordinat.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat); 
}


void boxmenu()
{
	/* Ubah warna tampilan menjadi warna default (putih) */
	color(7);
	
	gotoxy(0,28); 	printf("%c",201); 		// box atas Kiri
	gotoxy(120,28); printf("%c",187); 		// box atas Kanan
	gotoxy(5,28);	printf("%c",205);
	
	// vertikal kiri bagian dalam box 
	for(int i=0;i<1;i++)
	{ 					
		gotoxy(9,29+i);
		printf("%c",186);
	} 
	
	//PrintBox horizontal Atas atau garis box atas
	gotoxy(1,28); 
	for(int i=0;i<119;i++)				
	{ 
		printf("%c",205);
	}
	
	gotoxy(120,30); printf("%c",188);		// Box siku kanan bawah
	
	// vertikal kanan box
	for(int i=0;i<1;i++)
	{ 					
		gotoxy(120,29+i);
		printf("%c",186);
	}
	
	// vertikal kiri box
	for(int i=0;i<1;i++){ 					
		gotoxy(0,29+i);
		printf("%c",186);
	} 
	
	gotoxy(0,30);printf("%c",200); 			//Print Box Kotak kiri bawah
	
	//Print horizontal bawah atau garis box bawah
	for(int i=0;i<119;i++)				
	{ 
		printf("%c",205);
	}
	
	gotoxy(2,29);
	printf("CTRL_T");	
	
	gotoxy(11,29);
	printf("Save(Ctrl+S)");
	
	gotoxy(35,29);
	printf("Open File");
	
	gotoxy(56,29);
	printf("Rename File");
	
	gotoxy(79,29);
	printf("Remove File");
		
	gotoxy(101,29);
	printf("Help");
	
	gotoxy(115,29);
	printf("Exit");
}


int BoxPilihMenu()
{
	int Set[]={7,7,7,7,7,7};
	int counter= 2;
	char key;
	
	for (int i=0 ;;)
	{
		/* Proses menampilkan box menu */
		boxmenu();
		
		gotoxy(11,29);
		color(Set[0]);
		printf("Save(Ctrl+S)");
		
		gotoxy(35,29);
		color(Set[1]);
		printf("Open File");
		
		gotoxy(56,29);
		color(Set[2]);
		printf("Rename File");
		
		gotoxy(79,29);
		color(Set[3]);
		printf("Remove File");
			
		gotoxy(101,29);
		color(Set[4]);
		printf("Help");
		
		
		gotoxy(115,29);
		color(Set[5]);
		printf("Exit");	

		key= _getch();
		
		if(key == 75 && (counter>1 && counter <=6)) 		//72 = Arow left
		{
			counter = counter - 1;
		}
		
		if(key == 77 && (counter>=1 && counter <6)) 		//77 = Arow Right
		{
			counter = counter + 1;
		}
		
		if(key == CTRL_T)
		{
			return 20; 
		}
		
		if(key == '\r')	 									//Carriage return = enter key
			{
				if(counter == 1 )
				{
					return 1;
				}
				if(counter == 2 )
				{
					return 2;
				}
				if(counter == 3 )
				{
					return 3;
				}
				if(counter == 4 )
				{
					return 4; 
				}
				if(counter == 5)
				{
					return 5;
				}
				if(counter == 6)
				{
					return 6; 
				}
			}
			
		//defaut white colour	
		Set[0]= 7; 
		Set[1]= 7; 
		Set[2]= 7; 
		Set[3]= 7; 
		Set[4]= 7;
		Set[5]= 7;
				
		if(counter == 1)
		{
			Set[0]= 12;// 12 Colour is red
		}
		if(counter == 2)
		{
			Set[1]= 12;// 12 Colour is red
		}
		if(counter == 3)
		{
			Set[2]= 12;// 12 Colour is red 
		}
		if(counter == 4)
		{
			Set[3]= 12;// 12 Colour is red 
		}
		if(counter == 5)
		{
			Set[4]= 12;// 12 Colour is red 
		}
		if(counter == 6)
		{
			Set[5]= 12;// 12 Colour is red 
		}	
	}
}

void MenuAturan()
{
	FILE* file;
	
	//variabel length adalah variabel lokal bertipe array of char untuk memberi batas char dari file yang dibuka
	char length[6000];
	
	file=fopen("help.txt","r");
	
	system ("cls");
	while(fgets(length,6000,file)!=NULL){
		printf("%s", length);
	}
	
	fclose(file);
	printf("Tekan apapun untuk kembali ke menu utama.. "); 
	getch();
	system ("cls");

}
