#include "tampilanUI.h"
#include "kelolafile.h"

struct box koordinat; 

void setCursor(COORD cursor)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}


void clearScreen(COORD startPoint = {0,0})
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	GetConsoleScreenBufferInfo(console, &info);
	
	DWORD written;
	
	FillConsoleOutputCharacter( console, ' ', info.dwSize.X, startPoint, &written );
	FillConsoleOutputAttribute( console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, info.dwSize.X, startPoint, &written );
	
	setCursor(startPoint);
}


void screenBuffer()
{
	COORD layar;
	
	layar.Y = 9001;
	layar.X = 500;
	
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), layar); 
}


void screenSize()
{
	SMALL_RECT windowSize = {0, 0, 120, 30};	//LEFT TOP RIGHT BOTTOM
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
	
	if(getkoordinatX() % 120 == 0 && getkoordinatX() != 0)
	{
		
		
		koordinat.a += 120;
		koordinat.b += 120;
		koordinat.c += 120;
		koordinat.g += 120;
		koordinat.h += 120;
		koordinat.i += 120;
		koordinat.j += 120;
		koordinat.k += 120;
		koordinat.l += 120;
		koordinat.m += 120;
		koordinat.n += 120;
		
		short data = koordinat.d;
	
		for(int i=0; i < 3; i++)
		{
			COORD line{ 0, data++ };
	        setCursor( line );
	        clearScreen( line );
		}
	}
	else if(getkoordinatX() < 120)
	{
		koordinat.a = 0;
		koordinat.b = 1;
		koordinat.c = 9;
		koordinat.g = 120; 
		koordinat.h = 2;
		koordinat.i = 11;
		koordinat.j = 35;
		koordinat.k = 56;
		koordinat.l = 79;
		koordinat.m = 101;
		koordinat.n = 115; 
		
		short data = koordinat.d;
	
		for(int i=0; i < 3; i++)
		{
			COORD line{ 0, data++ };
	        setCursor( line );
	        clearScreen( line );
		}
	} 
	
	
	if(getkoordinatY() >= 26 && getData() == '\n')
	{
		
		
		koordinat.d++;
		koordinat.e++;
		koordinat.f++;
		
	}
	
	
	gotoxy(koordinat.a,koordinat.d); printf("%c",201); 		// box atas Kiri
	gotoxy(koordinat.g,koordinat.d); printf("%c",187); 		// box atas Kanan

	// vertikal kiri bagian dalam box 
	for(int i=0;i<1;i++)
	{ 					
		gotoxy(koordinat.c,koordinat.e+i);
		printf("%c",186);
	} 
	
	//PrintBox horizontal Atas atau garis box atas
	gotoxy(koordinat.b,koordinat.d); 
	for(int i=0;i<119;i++)				
	{ 
		printf("%c",205);
	}
	
	gotoxy(koordinat.g,koordinat.f); printf("%c",188);		// Box siku kanan bawah
	
	// vertikal kanan box
	for(int i=0;i<1;i++)
	{ 					
		gotoxy(koordinat.g,koordinat.e+i);
		printf("%c",186);
	}
	
	// vertikal kiri box
	for(int i=0;i<1;i++){ 					
		gotoxy(koordinat.a,koordinat.e+i);
		printf("%c",186);
	} 
	
	gotoxy(koordinat.a,koordinat.f);printf("%c",200); 			//Print Box Kotak kiri bawah
	
	//Print horizontal bawah atau garis box bawah
	for(int i=0;i<119;i++)				
	{ 
		printf("%c",205);
	}
	
	gotoxy(koordinat.h,koordinat.e);
	printf("CTRL_T");	
	
	gotoxy(koordinat.i,koordinat.e);
	printf("Save(Ctrl+S)");
	
	gotoxy(koordinat.j,koordinat.e);
	printf("Open File");
	
	gotoxy(koordinat.k,koordinat.e);
	printf("Rename File");
	
	gotoxy(koordinat.l,koordinat.e);
	printf("Remove File");
		
	gotoxy(koordinat.m,koordinat.e);
	printf("Help");
	
	gotoxy(koordinat.n,koordinat.e);
	printf("Exit");
}


int BoxPilihMenu()
{
	int Set[]={7,7,7,7,7,7};
	int counter = 2;
	char key;
	
	/* Proses menampilkan box menu */
	boxmenu();	
	
	for (int i=0 ;;)
	{
		gotoxy(koordinat.i,koordinat.e);
		color(Set[0]);
		printf("Save(Ctrl+S)");
		
		gotoxy(koordinat.j,koordinat.e);
		color(Set[1]);
		printf("Open File");
		
		gotoxy(koordinat.k,koordinat.e);
		color(Set[2]);
		printf("Rename File");
		
		gotoxy(koordinat.l,koordinat.e);
		color(Set[3]);
		printf("Remove File");
			
		gotoxy(koordinat.m,koordinat.e);
		color(Set[4]);
		printf("Help");
		
		gotoxy(koordinat.n,koordinat.e);
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
