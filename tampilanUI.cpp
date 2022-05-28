#include "tampilanUI.h"


//Get Console Handle
void screenBuffer(){
		COORD koordinat;
	
	koordinat.Y = 9001;
	koordinat.X = 500;
	
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), koordinat); 
}

void screenSize(){
	
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


void boxTampilanMenu()
{
	gotoxy(0,25);  printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC");
	
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

void boxmenu(){
	
	gotoxy(0,28); printf("%c",201); // box atas Kiri
	gotoxy(120,28); printf("%c",187); // box atas Kanan
	gotoxy(5,28);printf("%c",205);
		for(int i=0;i<1;i++){ // vertikal kiri
			gotoxy(5,29+i);
			printf("%c",186);
		} 
	gotoxy(1,28); 
		for(int i=0;i<119;i++)//PrintBox Vertikal Atas
			{ 
			printf("%c",205);
			}
	gotoxy(120,30); printf("%c",188);// Box siku kanan bawah
		for(int i=0;i<1;i++){ // vertikal kanan
			gotoxy(120,29+i);
			printf("%c",186);
		}
	for(int i=0;i<1;i++){ // vertikal kiri
		gotoxy(0,29+i);
		printf("%c",186);
	} 
	gotoxy(0,30);printf("%c",200); //Print Box Kotak kiri bawah
		for(int i=0;i<119;i++)//Print Vertikal bawah
		{ 
			printf("%c",205);
		}
	gotoxy(2,29);
	printf("F1");	
}

void BoxPilihMenu(){
	
	int x=2, y=2;
	int Set[]={7,7,7,7};
	int counter= 3;
	char key;
	for (int i=0 ;;)
	{
		
		boxmenu();
			
		gotoxy(8,29);
		color(Set[0]);
		printf("Open File");
		
		gotoxy(20,29);
		color(Set[1]);
		printf(" Save(Ctrl+S)");
		
		gotoxy(37,29);
		color(Set[2]);
		printf(" Help");
		
		gotoxy(45,29);
		color(Set[3]);
		printf(" Exit");

		key= _getch();
		
		
		if(key == 75 && (counter>1 && counter <=4)) //72 = Arow left
			{
				counter = counter - 1;
			}
		if(key == 77 && (counter>=1 && counter <4)) //80 = Arow Right
			{
				counter = counter + 1;
			}
		
		if(key == '\r') //Carriage return = enter key
			{
				if(counter == 1 )
					{
						gotoxy(88,30);
						printf("Menu 1 is open");
					}
				if(counter == 2 )
					{
						gotoxy(88,30);
						printf("Menu 2 is open");
					}
				if(counter == 3 )
					{
						gotoxy(88,30);
						printf("Menu 3 is open");
					}
				if(counter == 4 )
					{
						gotoxy(88,30);
//						color(Set[4]);
						printf("Close");
					}
			}
			
		Set[0]= 7; //defaut white colour
		Set[1]= 7; //defaut white colour
		Set[2]= 7; //defaut white colour
		Set[3]= 7; //default white colour		
		if(counter== 1)
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
	}
}
