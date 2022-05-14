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
		else if (editor.cursor->right!=nullptr)
		{
			address tempformidinsert = editor.cursor->right;
			ptr->linehead = editor.cursor->linehead;
			while (tempformidinsert->data != '\n')
			{
				swap(ptr->data, tempformidinsert->data);
				if (tempformidinsert->right == nullptr)
					break;
				tempformidinsert = tempformidinsert->right;
			}
			if (tempformidinsert->right == nullptr)
			{
				ptr->left = tempformidinsert;
				ptr->right = nullptr;
				tempformidinsert->right = ptr;
				editor.cursor = editor.cursor->right;
			}
			else
			{
				ptr->left = tempformidinsert->left;
				ptr->left->right = ptr;
				ptr->right = tempformidinsert;
				tempformidinsert->left = ptr;
				editor.cursor = editor.cursor->right;
			}
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
		
		UpDownLink(ptr, ptr->data);
}

void UpDownLink(address ptr, char key)
	{
		if (key != '\n')
		{
			if (ptr->left->up != nullptr)
			{
				if (ptr->left->up->right == ptr->linehead)
					ptr->up = nullptr;
				else
				{
					ptr->up = ptr->left->up->right;
					ptr->up->down = ptr;
				}
			}
			else
			{
				ptr->up = nullptr;
				if (ptr->left->down != nullptr )
					if(ptr->left->down->right!=nullptr)
						if (ptr->left->down->right->data != '\n')
						{
							ptr->down = ptr->left->down->right;
							ptr->down->up = ptr;
						}
			}
				
		}
		else
		{
			ptr->up = ptr->left->linehead;
			ptr->up->down = ptr;
		}
	}
	
	void MoveCursor()
	{
		char temp = _getch();
		if ((int)temp == 77) 
		{
			if (editor.cursor->right!=nullptr)
				editor.cursor = editor.cursor->right;
		}
		else if ((int)temp == 72) 
		{
			if (editor.cursor->up == nullptr)
			{
				//node* temppointer = cursor;
				while (editor.cursor->up == nullptr && editor.cursor!=editor.cursor->linehead)
				{
					editor.cursor = editor.cursor->left;
				}
			}
			if(editor.cursor!=editor.cursor->linehead)
				editor.cursor = editor.cursor->up;
		}
		else if ((int)temp == 75) 
		{
			if (editor.cursor != editor.head_of_notepad && editor.cursor->left!=nullptr)
				editor.cursor = editor.cursor->left;
		}
		else if ((int)temp == 80) 
		{
			if (editor.cursor->down == nullptr)
			{
				while (editor.cursor->down == nullptr && editor.cursor != editor.cursor->linehead)
				{
					editor.cursor = editor.cursor->left;
				}
			}
			if (editor.cursor != editor.cursor->linehead)
				editor.cursor = editor.cursor->down;
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
	  	
	  } else if(data == -32){
	  	
	  	MoveCursor();
	  	
	  }
	  
	  else {
	  	
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

