#include "IOText.h"


address Alokasi(){
	
	address AlokasiNode;
	
	AlokasiNode = (address)malloc(sizeof(TextEditor));
	if(AlokasiNode != NULL){
		
		AlokasiNode->data = NULL;
		AlokasiNode->right = NULL;
		AlokasiNode->left = NULL;
		AlokasiNode->up = NULL;
		AlokasiNode->down = NULL;
		AlokasiNode->linehead = NULL;
		
	} else {
		
		return 0;
	}
	
	return AlokasiNode;
	
}

void Inisialisasi(){
	
	editor.head_of_notepad = NULL;
	editor.cursor = NULL;
	editor.destcord.X = 0;
	editor.destcord.Y = 0;
	
}

void Insertion(int data){
	
	address ptr = Alokasi();
		if (data == '\r')
			ptr->data = '\n';
		else
			ptr->data = data;
			
		if (editor.head_of_notepad == nullptr)
		{
			address temp = Alokasi();
			temp->data = '\0';
			temp->linehead = temp;
			ptr->linehead = temp;
			temp->right = ptr;
			ptr->left = temp;
			editor.head_of_notepad = temp;
			editor.cursor = ptr;
		}

		else
		{
			address temp = editor.head_of_notepad;
			while (temp->right != nullptr)
			{
				temp = temp->right;
			}
			if (data != '\r')
			{
				ptr->left = temp;
				temp->right = ptr;
				ptr->linehead = ptr->left->linehead;
			}
			else
			{
				ptr->data = '\n';
				ptr->linehead = ptr;
				ptr->left = temp;
				temp->right = ptr;
			}
			editor.cursor = ptr;
		}
//		//call setupdown function
//		UpDownLink(ptr, ptr->data);
}

void Print_Text()
	{
		address ptr = editor.head_of_notepad;
		while (ptr != nullptr)
		{
			if (ptr->data == '\0')
				printf("");
			else
			{
				printf("%c",ptr->data);
			}
				
			ptr = ptr->right;
		}
	}
	
void setCursor()
	{
		address ptr = editor.head_of_notepad->right;
			editor.destcord.X = 0;
			editor.destcord.Y = 0;
		while (ptr != nullptr)
		{
			if (ptr->data == '\n')
			{
				editor.destcord.X = 0;
				editor.destcord.Y++;
			}
			else
			{
				editor.destcord.X++;
			}
			if (ptr == editor.cursor)
				return;
			ptr = ptr->right;
		}
	}


void keyProsess(){
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
 
  
}

