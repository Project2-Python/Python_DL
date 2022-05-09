#include "IOText.h"


address Alokasi(){
	
	address AlokasiNode;
	
	AlokasiNode = (address)malloc(sizeof(TextEditor));
	if(AlokasiNode != NULL){
		
		AlokasiNode->data = '\0';
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
			
		if (editor.head_of_notepad == NULL)
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
			while (temp->right != NULL)
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
}

void Print_Text()
	{
		address ptr = editor.head_of_notepad;
		while (ptr != NULL)
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
		while (ptr != NULL)
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
	  if( data == '\b'){
	  	Deletion();
	  	system("cls");
	  	Print_Text();
	  	
	  } else {
	  	
	  Insertion(data);
		system("cls");
		Print_Text();
	  }
		setCursor();
	 }
}

void Deletion()
	{
		address tempfordel = editor.cursor;
		if (editor.cursor == editor.head_of_notepad)
			return;
		if (tempfordel->right == NULL)
		{
			editor.cursor = editor.cursor->left;
			editor.cursor->right = NULL;
			if (tempfordel->up != NULL)
				tempfordel->up->down = NULL;
			tempfordel->up = NULL;
			if (tempfordel->down != NULL)
				tempfordel->down->up = NULL;
			tempfordel->down = NULL;
			delete tempfordel;
		}
		else if (tempfordel->right != NULL)
		{
			editor.cursor = editor.cursor->left;
			while (tempfordel->right->data != '\n') 
			{
				swap(tempfordel->data, tempfordel->right->data);
				tempfordel = tempfordel->right;
				if (tempfordel->right == NULL)
					break;
			}
				tempfordel->left->right = tempfordel->right;
				if (tempfordel->right != NULL)
					tempfordel->right->left = tempfordel->left;

			if(tempfordel->up!=NULL)
				tempfordel->up->down = NULL;
			tempfordel->up = NULL;
			if(tempfordel->down!=NULL)
				tempfordel->down->up = NULL;
			tempfordel->down = NULL;
			delete tempfordel;
		}
	}
	
void swap(char tempfordel1, char tempfordel2){
	
	char temp;
	temp = tempfordel1;
	tempfordel1 = tempfordel2;
	tempfordel2 = temp;
	
}
