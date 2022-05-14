#include "IOText.h"
#include "tampilanUI.h"
#include "kelolafile.h"


address Alokasi()
{
	/* Kamus Data Lokal */
	address AlokasiNode;
	
	/* Proses mengalokasikan node ke memori */
	AlokasiNode = (address)malloc(sizeof(TextEditor));
	
	/* Proses pengecekan apakah yang telah dialokasikan berhasil */
	if(AlokasiNode != NULL)
	{	
		AlokasiNode->data = '\0';
		AlokasiNode->right = NULL;
		AlokasiNode->left = NULL;
		AlokasiNode->up = NULL;
		AlokasiNode->down = NULL;
		AlokasiNode->linehead = NULL;	
	} 
	else 
	{	
		return 0;
	}
	return AlokasiNode;
}


void Inisialisasi()
{	
	editor.head_of_notepad = NULL;
	editor.cursor = NULL;
	editor.destcord.X = 0;
	editor.destcord.Y = 0;	
}


void Insertion(int data)
{
	/* Kamus Data Lokal */
	address nodeBaru; 
	
	/* Proses mengalokasikan node */	
	nodeBaru = Alokasi();
	
	/* Proses pengecekan data yang diinputkan */
	if (data == '\r')	// Enter
	{
		nodeBaru->data = '\n';
	}
	else
	{
		nodeBaru->data = data;
	}	
		
	if (editor.head_of_notepad == NULL)
	{
		address temp = Alokasi();
		temp->data = '\0';
		temp->linehead = temp;
		ptr->linehead = temp;
		temp->right = nodeBarus;
		nodeBaru->left = temp;
		editor.head_of_notepad = temp;
		editor.cursor = nodeBarus;
	}
	else if (editor.cursor->right!=NULL)
	{
		address tempformidinsert = editor.cursor->right;
		nodeBaru->linehead = editor.cursor->linehead;
		while (tempformidinsert->data != '\n')
		{
			swap(&nodeBaru->data, &tempformidinsert->data);
			if (tempformidinsert->right == NULL)
			{
				break;
			}
			tempformidinsert = tempformidinsert->right;
		}
		if (tempformidinsert->right == NULL)
		{
			nodeBaru->left = tempformidinsert;
			nodeBaru->right = NULL;
			tempformidinsert->right = nodeBaru;
			editor.cursor = editor.cursor->right;
		}
		else
		{
			nodeBaru->left = tempformidinsert->left;
			nodeBaru->left->right = nodeBaru;
			nodeBaru->right = tempformidinsert;
			tempformidinsert->left = nodeBaru;
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
			nodeBaru->left = temp;
			temp->right = nodeBaru;
			nodeBaru->linehead = nodeBaru->left->linehead;
		}
		else
		{
			nodeBaru->data = '\n';
			nodeBaru->linehead = nodeBaru;
			nodeBaru->left = temp;
			temp->right = nodeBaru;
		}
		editor.cursor = nodeBaru;
	}
	UpDownLink(nodeBaru, nodeBaru->data);
}


void UpDownLink(address node, char key)
{
	if (key != '\n')
	{
		if (node->left->up != NULL)
		{
			if (node->left->up->right == node->linehead)
			{	
				node->up = NULL;
			}
			else
			{
				node->up = node->left->up->right;
				node->up->down = node;
			}
		}
		else
		{
			node->up = NULL;
			
			if (node->left->down != NULL)
				if(node->left->down->right != NULL)
						
					if (node->left->down->right->data != '\n')
					{
						node->down = node->left->down->right;
						node->down->up = node;
					}
		}
				
	}
	else
	{
		node->up = node->left->linehead;
		node->up->down = node;
	}
}

	
<<<<<<< HEAD
void MoveCursor()
{
	char temp = _getch();
	
	if ((int)temp == 77)							// Right 
	{
		if (editor.cursor->right != NULL)
=======
void MoveCursor(){


		char temp = _getch();
		if ((int)temp == 77) 
>>>>>>> f4244e6 (tambah lagi)
		{
			editor.cursor = editor.cursor->right;
		}
	}
	else if ((int)temp == 72)						// UP 
	{
		if (editor.cursor->up == NULL)
		{
			while (editor.cursor->up == NULL && editor.cursor!=editor.cursor->linehead)
			{
				editor.cursor = editor.cursor->left;
			}
		}
	
		if(editor.cursor!=editor.cursor->linehead)
		{
			editor.cursor = editor.cursor->up;
		}
	}
	else if ((int)temp == 75)						// Left
	{
		if (editor.cursor != editor.head_of_notepad && editor.cursor->left != NULL)
		{
			editor.cursor = editor.cursor->left;
		}
	}
	else if ((int)temp == 80) 						// Down
	{
		if (editor.cursor->down == NULL)
		{
			while (editor.cursor->down == NULL && editor.cursor != editor.cursor->linehead)
			{
				editor.cursor = editor.cursor->left;
			}
		}
			
		if (editor.cursor != editor.cursor->linehead)
		{
			editor.cursor = editor.cursor->down;
		}
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

<<<<<<< HEAD
<<<<<<< HEAD


void keyProsess(char filename[20])
{

	char data;
=======
void keyProsess(){
	 char data=NULL;
>>>>>>> f4244e6 (tambah lagi)
=======
void keyProsess(char filename[20]){
	 char data=NULL;

>>>>>>> 1d5f037 (CreatedanSavefile Berhasil)
	
	/* Proses inisialisasi cursor */
	editor.hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	Inisialisasi(); 
	
<<<<<<< HEAD
	while(1)
	{ 
		/* Proses memperbaharui posisi cursor */
		SetConsoleCursorPosition(editor.hstdout, editor.destcord);
	  	
		/* Proses pengisian inputan keyboard */
		data = _getch();
		
		/* Proses pengecekan inputan keyboard */
	  	if( data == '\b')							// backspace
		{
	  		Deletion();
	  		system("cls");
	  		Print_Text();
	  	
	  	} 
		else if ((int)data == -32)                  // Arrow key
		{
			MoveCursor();
	  	}
		else if(data == CTRL_S){
	  		saveFile(filename);
	 	} 
	  	else 
		{	  	
	  		Insertion(data);
	  		system("cls");
	  		Print_Text();
	  	}
		setCursor();
=======
	 while(1){
	  SetConsoleCursorPosition(editor.hstdout, editor.destcord);
	  data = _getch();
	  if( data == '\b'){
	  	Deletion();
	  	system("cls");
	  	Print_Text();

	  } else if((int)data == (-32)){
	  	
	  	MoveCursor();
	  }
	  else if(data == CTRL_S){
	  	saveFile(&editor.head_of_notepad, filename);
	  } 
	  else {	  	
	  	
	  Insertion(data);
	  system("cls");
	  Print_Text();
	  
	  }
	setCursor();
>>>>>>> f4244e6 (tambah lagi)
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
				swap(&tempfordel->data, &tempfordel->right->data);
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
	
void swap(char *tempfordel1, char *tempfordel2){
	
	char temp;
	temp = *tempfordel1;
	*tempfordel1 = *tempfordel2;
	*tempfordel2 = temp;
	
}



