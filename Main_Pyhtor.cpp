#include "IOText.h"


int main(){
	
	char data;
	
	editor.hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	Inisialisasi();
	while(1){
		
		SetConsoleCursorPosition(editor.hstdout, editor.destcord);
		data = getch();
		Insertion(data);
		system("cls");
		Print_Text();
		setCursor();
	}
	
	return 0;
}
