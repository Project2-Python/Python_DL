#include "IOText.h"
#include "tampilanUI.h"
#include "kelolafile.h"


char getDataNode()
{
	address temp = editor.head_of_notepad;
	
	if(temp == NULL)
	{
		return NULL;
	}
	
	while(temp != NULL)
	{
		if(temp->right == NULL)
		{
			break;
		}
		temp = temp->right;
	}
	
	if(temp->data == '\n')
	{
		return temp->data;
	}
}


int getkoordinatY()
{
	return editor.destcord.Y;
}


int getkoordinatX()
{
	return editor.destcord.X;
}

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
		nodeBaru->linehead = temp;
		temp->right = nodeBaru;
		nodeBaru->left = temp;
		editor.head_of_notepad = temp;
		editor.cursor = nodeBaru;
		printf("%c", nodeBaru->data);
		
	}
	else if (editor.cursor->right!=NULL)
	{
		address tempformidinsert = editor.cursor->right;
		nodeBaru->linehead = editor.cursor->linehead;
		
		while (tempformidinsert->data != '\n')
		{
			swap(&nodeBaru->data, &tempformidinsert->data);
			if(tempformidinsert->data == '\n')
			{
				short data = 1;

				for(int i=0; i < getbarisBox()-2; i++)
				{
					COORD line{ 0, data++ };
			        setCursorXY( line );
			        clearScreen( line );
				}
				
				editor.destcord.X = 0;
				editor.destcord.Y = 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), editor.destcord);
				
				address printfromhead = editor.head_of_notepad;
				while(printfromhead != tempformidinsert)
				{
					if (printfromhead->data == '\0')
					{
						printf("");	
					}	
					else
					{
					printf("%c", printfromhead->data);
					}
					
					printfromhead = printfromhead->right;
				}
			}
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
			Print_Text(editor.cursor);
		
		}
		else
		{
				
			nodeBaru->left = tempformidinsert->left;
			nodeBaru->left->right = nodeBaru;
			nodeBaru->right = tempformidinsert;
			tempformidinsert->left = nodeBaru;
			editor.cursor = editor.cursor->right;
			
			if(nodeBaru->data == '\n')
			{
				short data = 1;

				for(int i=0; i < getbarisBox()-2; i++)
				{
					COORD line{ 0, data++ };
			        setCursorXY( line );
			        clearScreen( line );
				}
				
				editor.destcord.X = 0;
				editor.destcord.Y = 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), editor.destcord);
				Print_Text(editor.head_of_notepad);
			}
			else
			{
				Print_Text(editor.cursor);
			}
			
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
		printf("%c", nodeBaru->data);
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

	
void MoveCursor()
{
	char temp = _getch();
	
	if ((int)temp == 77)							// Right 
	{
		if (editor.cursor->right != NULL)
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


void Print_Text(address temp)
{
	
	address ptr = temp;
	while (ptr != NULL)
		{
		if (ptr->data == '\0')
		{
			printf("");
		}
		else
		{
			printf("%c",ptr->data);
		}
				
		ptr = ptr->right;
	}

}


void setCursor()
	{
		editor.destcord.X = 0;
		editor.destcord.Y = 1;
		address ptr = editor.head_of_notepad->right;
		while (ptr != NULL)
		{
			if(editor.cursor == editor.head_of_notepad)
			{
				break;
			}
			
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


void keyProsess()
{

	char data;
	//char filename[25];
	int before, current; 

	editor.Modifier = 0;
	
	/* Proses inisialisasi cursor */
	editor.hstdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	editor.cursor = editor.head_of_notepad;
	editor.destcord.X = 0;
	editor.destcord.Y = 1;
	
	gotoxy(60,0); printf("%s", getNameFile());
	
	editor :
	while(1)
	{ 
		
		/* Menampilkan Menu Bar */
		boxmenu();
		
		/* Proses memperbaharui posisi cursor */
		SetConsoleCursorPosition(editor.hstdout, editor.destcord);
	  	
		/* Proses pengisian inputan keyboard */
			data = _getch();
		
				
		/* Proses pengecekan inputan keyboard */
	  	if( data == '\b')							// backspace
		{
	  		Deletion();
	  		editor.Modifier = 1; 
	  		gotoxy(getkolomBoxAkhir()-3,getbarisBox()-1); printf("[*]");
	  	
	  	} 
		else if ((int)data == -32)                  // Arrow key
		{
			MoveCursor();
	  	}
		else if(data == CTRL_S)
		{
	  		saveFile(&editor.head_of_notepad);
	  		editor.Modifier = 0;
	  		gotoxy(getkolomBoxAkhir()-3,getbarisBox()-1); printf("   ");
	 	} 
	 	else if(data == CTRL_Q || data == ESC)
	 	{
	 		if (editor.Modifier == 1)
	 		{
	 			printf("Belum di save\n");
			}
			else 
			{
				exit(1);
			}
		}
		else if(data == CTRL_T) 
		{
			int menu = BoxPilihMenu();  
			
			if(menu == 1)
			{
				saveFile(&editor.head_of_notepad);
	  			editor.Modifier = 0;
				
			} 
			else if(editor.Modifier == 1)
			{
				gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("Belum Di Save");
				Sleep(2000);
				gotoxy(getkolomBox()+1,getbarisBox()-1);	printf("                                                                   ");
			}
			else if(menu == 2)
			{
				openFile();
			}
			else if(menu == 3)
			{
				renameFile();
				goto editor;
			}
			else if(menu == 4)
			{
				removeFile();
				goto editor;
			}
			else if(menu == 5)
			{
				MenuAturan();
			}
			else if(menu == 6)
			{
				
			}
		}
	  	else 
		{	  	
	  		Insertion(data);
	  		editor.Modifier = 1;
	  		gotoxy(getkolomBoxAkhir()-3,getbarisBox()-1); printf("[*]");
	  	}
	  	before = getkoordinatY();
		setCursor();
		current = getkoordinatY();
		setKoordinatBox(data, before, current);
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
		
		editor.destcord.X -= 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), editor.destcord);
		printf(" ");
	}
	else if (tempfordel->right != NULL)
	{
		editor.cursor = editor.cursor->left;
		editor.destcord.X -= 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), editor.destcord);
		while (tempfordel->right->data != '\n') 
		{
			swap(&tempfordel->data, &tempfordel->right->data);
			printf("%c", tempfordel->data);
			tempfordel = tempfordel->right;
			if (tempfordel->right == NULL)
			{
				break;
			}
		}
		
		printf(" ");
		if(tempfordel->data == '\n')
		{
			short data = 1;

			for(int i=0; i < getbarisBox()-2; i++)
			{
				COORD line{ 0, data++ };
		        setCursorXY( line );
		        clearScreen( line );
			}
			
			editor.destcord.X = 0;
			editor.destcord.Y = 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), editor.destcord);
			
			Print_Text(editor.head_of_notepad);
		}
		
		
		tempfordel->left->right = tempfordel->right;
		
		if (tempfordel->right != NULL)
		{
			tempfordel->right->left = tempfordel->left;
		}

		if(tempfordel->up!=NULL)
		{
			tempfordel->up->down = NULL;
		}
		tempfordel->up = NULL;
		
		if(tempfordel->down!=NULL)
		{
			tempfordel->down->up = NULL;
		}
		tempfordel->down = NULL;
		delete tempfordel;
	}
}
	
	
void swap(char *data1, char *data2)
{	
	char temp;
	temp = *data1;
	*data1 = *data2;
	*data2 = temp;	
}



