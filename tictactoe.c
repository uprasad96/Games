#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define DISPLAY             \
							for(i=0;i<3;i++)\
							{\
								gotoxy(25,(2*i)+6);\
								for(j=0;j<3;j++)\
								{\
								printf("%5c",tictac[i][j]);\
								}\
							}\
							for(i=0;i<7;i++)\
							{\
							gotoxy(32,i+5);\
							printf("|");\
							}\
							for(i=0;i<7;i++)\
							{\
							gotoxy(36,i+5);\
							printf("|");\
							}\
							for(i=0;i<15;i++)\
							{\
							gotoxy(27+i,7);\
							printf("-");\
							}\
							for(i=0;i<15;i++)\
							{\
							gotoxy(27+i,9);\
							printf("-");\
							}\
							
#define ENTRY 	key=getkey();\
	if(key==49)\
	tictac[2][0]=ent;\
	if(key==50)\
	tictac[2][1]=ent;\
	if(key==51)\
	tictac[2][2]=ent;\
	if(key==52)\
	tictac[1][0]=ent;\
	if(key==53)\
	tictac[1][1]=ent;\
	if(key==54)\
	tictac[1][2]=ent;\
	if(key==55)\
	tictac[0][0]=ent;\
	if(key==56)\
	tictac[0][1]=ent;\
	if(key==57)\
	tictac[0][2]=ent;
#define WIN \
			printf("\n\n\n\n\nI win!!");
#define TIE \
			printf("\n\n\n\n\nYou made a tie!!");
			
int getkey(void);
void gotoxy(short col,short row);

							
int main()
{
	int i,j,p,q,key,choice;
  
	char tictac[3][3],ent,comp;
	for(i=0;i<3;i++)
		{
			
			for(j=0;j<3;j++)
			{
			  tictac[i][j]=' ';
			}			
		} 

	printf("The tic-tac-toe game\n");
	printf("Zero or Cross?\nPress 1 for Zero and 2 for Cross\n");
	choice=getkey();
	if(choice==49)
	{
	printf("Ok!I move first");
	ent='O';
	comp='X';
	}
	if(choice==50)
	{
	printf("Ok!You move first");
	ent='X';
	comp='O';
	}
	gotoxy(60,12);
	printf("Instructions:");
	gotoxy(60,13);
	printf("Use the Numpad for");
	gotoxy(60,14);
	printf("corresponding entries");
	
	/*Comp moves first*/
	
	if(choice==49)
	{
	tictac[2][2]=comp;
    DISPLAY
	ENTRY
	DISPLAY
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		if(tictac[i][j]==ent)
		{
		p=i;
		q=j;
		}
	}
	
	if((p==0||p==1)&&(q==0||q==2))
	{
	tictac[2][0]=comp;
	DISPLAY
	ENTRY
	DISPLAY
		if(tictac[2][1]==' ')
			{
			tictac[2][1]=comp;
			DISPLAY
			printf("\n\n\n\n\nI win!!");
			exit(1);
			}
		if(q==0)
		{		
		tictac[0][2]=comp;
		DISPLAY
		ENTRY
		DISPLAY
			if(tictac[1][1]==' ')
			tictac[1][1]=comp;
			else
			tictac[1][2]=comp;
			DISPLAY			
		}
		if(q==2)
		{
		tictac[0][0]=comp;
		DISPLAY
		ENTRY
		DISPLAY
				if(tictac[1][0]==' ')
			tictac[1][0]=comp;
			else
			tictac[1][1]=comp;
			DISPLAY
		}
    }
		
	if((p==2&&q==0)||(p==2&&q==1)||(p==0&&q==1))
	{
	tictac[0][2]=comp;
	DISPLAY
	ENTRY
	DISPLAY
		if(tictac[1][2]==' ')
		{
		tictac[1][2]=comp;
		DISPLAY
		printf("\n\n\n\n\nI win!!");
		exit(1);
		}
		if(p==2)
		{
		tictac[0][0]=comp;
    	DISPLAY
    	ENTRY
    	DISPLAY	
			if(tictac[0][1]==' ')
			tictac[0][1]=comp;
			else
			tictac[1][1]=comp;
			DISPLAY			
		}
		if(p==0)
		{
		tictac[2][0]=comp;
		DISPLAY
		ENTRY
		DISPLAY
			if(tictac[1][1]==' ')
			tictac[1][1]=comp;
			else
			tictac[2][1]=comp;
			DISPLAY	
		}
    }
	if(p==1&&q==1)
	{
		tictac[0][0]=comp;
		DISPLAY
		ENTRY
		DISPLAY
			if(tictac[0][2]==ent)
			{
			tictac[2][0]=comp;
			DISPLAY
			ENTRY
			DISPLAY
				if(tictac[2][1]==ent)
				{
				tictac[1][0]=comp;
				DISPLAY
				printf("\n\n\n\n\nI win!!");
				exit(1);
				}
				else
				{
				tictac[2][1]=comp;
				DISPLAY
				printf("\n\n\n\n\nI win!!");
				exit(1);
				}
			}
			if(tictac[2][0]==ent)
			{
			tictac[0][2]=comp;
			DISPLAY
			ENTRY
			DISPLAY
				if(tictac[0][1]==ent)
				{
				tictac[1][2]=comp;
				DISPLAY
				printf("\n\n\n\n\nI win!!");
				exit(1);
				}
				else
				{
				tictac[0][1]=comp;
				DISPLAY
				printf("\n\n\n\n\nI win!!");
				exit(1);
				}
			}
			if(tictac[0][1]==ent)
			{
				tictac[2][1]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
					if(tictac[2][0]==' ')
					{
						tictac[2][0]=comp;
						DISPLAY
						printf("\n\n\n\n\n\nI win!!");
						exit(1);
					}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					if(tictac[1][2]==' ')
					{
						tictac[1][2]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
					}
					tictac[1][0]=comp;
					DISPLAY
					printf("\n\n\n\n\nYou made a tie!!");
					exit(1);
			}
			if(tictac[1][2]==ent)
			{
				tictac[1][0]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
					if(tictac[2][0]==' ')
					{
						tictac[2][0]=comp;
						DISPLAY
						printf("\n\n\n\n\n\nI win!!");
						exit(1);
					}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					if(tictac[0][1]==' ')
					{
						tictac[1][2]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
					}
					tictac[2][1]=comp;
					DISPLAY
					printf("\n\n\n\n\nYou made a tie!!");
					exit(1);
			}
			if(tictac[2][1]==ent)
			{
				tictac[0][1]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
					if(tictac[0][2]==' ')
					{
						tictac[0][2]=comp;
						DISPLAY
						printf("\n\n\n\n\n\nI win!!");
						exit(1);
					}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					if(tictac[1][0]==' ')
					{
						tictac[1][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
					}
					tictac[1][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nYou made a tie!!");
					exit(1);
			}
			if(tictac[1][0]==ent)
			{
				tictac[1][2]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
					if(tictac[0][2]==' ')
					{
						tictac[0][2]=comp;
						DISPLAY
						printf("\n\n\n\n\n\nI win!!");
						exit(1);
					}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					if(tictac[2][1]==' ')
					{
						tictac[2][1]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
					}
					tictac[0][1]=comp;
					DISPLAY
					printf("\n\n\n\n\nYou made a tie!!");
					exit(1);
			}
	}	
    printf("\n\n\n\n\nI win!!");
    exit(1);
	}
	if(choice==50)
	{
		DISPLAY 
		ENTRY
		DISPLAY
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(tictac[i][j]==ent)
				{
				p=i;
				q=j;
				}
			}
		}
		/*Not centre move*/
		if(p!=1||q!=1)
		{
			tictac[1][1]=comp;
			DISPLAY
			ENTRY
			DISPLAY
			/*Move is 22*/			
			if(p==2&&q==2)
			{
				/*22 then 00*/
				if(tictac[0][0]==ent)
				{
				tictac[0][1]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[2][1]==' ')
					{
					tictac[2][1]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[2][0]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[0][2]==' ')
					{
					tictac[0][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[1][2]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
				printf("\n\n\n\n\nYou made a tie!!");
				exit(1);				
				}
				/*22 then 01*/
					else 
					if(tictac[0][1]==ent)
					{
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
						tictac[1][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
						if(tictac[0][2]==' ')
						{
						tictac[0][2]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*22 then 02*/
					else
					if(tictac[0][2]==ent)
					{
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*22 then 10*/
					else
					if(tictac[1][0]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*22 then 12*/
					else
					if(tictac[1][2]==ent)
					{
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*22 then 20*/
					else
					if(tictac[2][0]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*22 then 21*/
					else
					if(tictac[2][1]==ent)
					{
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
											
			}
			else
				if(p==0&&q==0)
				{
				/*00 then 01*/
				if(tictac[0][1]==ent)
				{
				tictac[0][2]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[2][0]==' ')
					{
					tictac[2][0]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[1][0]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[1][2]==' ')
					{
					tictac[1][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[2][2]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
				printf("\n\n\n\n\nYou made a tie!!");
				exit(1);				
				}
				/*00 then 02*/
					else 
					if(tictac[0][2]==ent)
					{
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
						tictac[2][1]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
						if(tictac[1][0]==' ')
						{
						tictac[1][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*00 then 10*/
					else
					if(tictac[1][0]==ent)
					{
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*00 then 12*/
					else
					if(tictac[1][2]==ent)
					{
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*00 then 20*/
					else
					if(tictac[2][0]==ent)
					{
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
							tictac[1][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*00 then 21*/
					else
					if(tictac[2][1]==ent)
					{
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
							tictac[1][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*00 then 22*/
					else
					if(tictac[2][2]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
											
			}
			else
				if(p==0&&q==2)
				{
				/*02 then 01*/
				if(tictac[0][1]==ent)
				{
				tictac[0][0]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[2][2]==' ')
					{
					tictac[2][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[1][2]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[1][0]==' ')
					{
					tictac[1][0]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[2][0]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
				printf("\n\n\n\n\nYou made a tie!!");
				exit(1);				
				}
				/*02 then 00*/
					else 
					if(tictac[0][0]==ent)
					{
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
						tictac[2][1]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
						if(tictac[1][0]==' ')
						{
						tictac[1][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*02 then 10*/
					else
					if(tictac[1][0]==ent)
					{
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*02 then 12*/
					else
					if(tictac[1][2]==ent)
					{
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*02 then 20*/
					else
					if(tictac[2][0]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*02 then 21*/
					else
					if(tictac[2][1]==ent)
					{
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
							tictac[1][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*02 then 22*/
					else
					if(tictac[2][2]==ent)
					{
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
											
			}
			else
				if(p==2&&q==0)
				{
				/*20 then 00*/
				if(tictac[0][0]==ent)
				{
				tictac[1][0]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[1][2]==' ')
					{
					tictac[1][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[0][1]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[2][1]==' ')
					{
					tictac[2][1]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[0][2]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
				printf("\n\n\n\n\nYou made a tie!!");
				exit(1);				
				}
				/*20 then 01*/
					else 
					if(tictac[0][1]==ent)
					{
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
						tictac[1][2]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
						if(tictac[0][0]==' ')
						{
						tictac[0][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*20 then 02*/
					else
					if(tictac[0][2]==ent)
					{
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*20 then 10*/
					else
					if(tictac[1][0]==ent)
					{
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*20 then 12*/
					else
					if(tictac[1][2]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*20 then 21*/
					else
					if(tictac[2][1]==ent)
					{
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
							tictac[1][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*20 then 22*/
					else
					if(tictac[2][2]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
											
			}
			else
				if(p==0&&q==1)
				{
				/*01 then 00*/
				if(tictac[0][0]==ent)
				{
				tictac[0][2]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[2][0]==' ')
					{
					tictac[2][0]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[1][0]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[1][2]==' ')
					{
					tictac[1][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[2][2]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
				printf("\n\n\n\n\nYou made a tie!!");
				exit(1);				
				}
				/*01 then 02*/
					else 
					if(tictac[0][2]==ent)
					{
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
						tictac[2][2]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
						if(tictac[1][0]==' ')
						{
						tictac[1][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*01 then 10*/
					else
					if(tictac[1][0]==ent)
					{
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*01 then 12*/
					else
					if(tictac[1][2]==ent)
					{
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*01 then 21*/
					else
					if(tictac[2][1]==ent)
					{
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*01 then 22*/
					else
					if(tictac[2][2]==ent)
					{
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*01 then 20*/
					else
					if(tictac[2][0]==ent)
					{
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}											
			}
			else
				if(p==1&&q==0)
				{
				/*10 then 00*/
				if(tictac[0][0]==ent)
				{
				tictac[2][0]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[0][2]==' ')
					{
					tictac[0][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[0][1]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[2][1]==' ')
					{
					tictac[2][1]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[2][2]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
				printf("\n\n\n\n\nYou made a tie!!");
				exit(1);				
				}
				/*10 then 01*/
					else 
					if(tictac[0][1]==ent)
					{
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
						tictac[2][2]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
						if(tictac[0][2]==' ')
						{
						tictac[0][2]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*10 then 02*/
					else
					if(tictac[0][2]==ent)
					{
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*10 then 12*/
					else
					if(tictac[1][2]==ent)
					{
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*10 then 20*/
					else
					if(tictac[2][0]==ent)
					{
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*10 then 21*/
					else
					if(tictac[2][1]==ent)
					{
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*10 then 22*/
					else
					if(tictac[2][2]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}											
			}
			else
				if(p==1&&q==2)
				{
				/*12 then 00*/
				if(tictac[0][0]==ent)
				{
				tictac[0][1]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[2][1]==' ')
					{
					tictac[2][1]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[2][0]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[0][2]==' ')
					{
					tictac[0][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[2][2]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
				printf("\n\n\n\n\nYou made a tie!!");
				exit(1);				
				}
				/*12 then 01*/
					else 
					if(tictac[0][1]==ent)
					{
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
						tictac[2][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
						if(tictac[0][0]==' ')
						{
						tictac[0][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*12 then 02*/
					else
					if(tictac[0][2]==ent)
					{
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][1]==' ')
						{
							tictac[2][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*12 then 10*/
					else
					if(tictac[1][0]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*12 then 20*/
					else
					if(tictac[2][0]==ent)
					{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*12 then 21*/
					else
					if(tictac[2][1]==ent)
					{
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*12 then 22*/
					else
					if(tictac[2][2]==ent)
					{
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][0]==' ')
						{
							tictac[2][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}											
			}
			else
				if(p==2&&q==1)
				{
				/*21 then 00*/
				if(tictac[0][0]==ent)
				{
				tictac[1][0]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[1][2]==' ')
					{
					tictac[1][2]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[0][2]=comp;
				DISPLAY
				ENTRY
				DISPLAY
					if(tictac[2][0]==' ')
					{
					tictac[2][0]=comp;
					DISPLAY
					printf("\n\n\n\n\nI win!!");
					exit(1);
					}
				tictac[2][2]=comp;
				DISPLAY
				ENTRY 
				DISPLAY
				printf("\n\n\n\n\nYou made a tie!!");
				exit(1);				
				}
				/*21 then 01*/
					else 
					if(tictac[0][1]==ent)
					{
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
						tictac[1][2]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[0][2]=comp;
					DISPLAY
					ENTRY
						if(tictac[2][0]==' ')
						{
						tictac[2][0]=comp;
						DISPLAY
						printf("\n\n\n\n\nI win!!");
						exit(1);
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*21 then 02*/
					else
					if(tictac[0][2]==ent)
					{
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[2][2]==' ')
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*21 then 10*/
					else
					if(tictac[1][0]==ent)
					{
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*21 then 12*/
					else
					if(tictac[1][2]==ent)
					{
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*21 then 20*/
					else
					if(tictac[2][0]==ent)
					{
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][0]==' ')
						{
							tictac[0][0]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
							tictac[1][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}
				/*21 then 22*/
					else
					if(tictac[2][2]==ent)
					{
					tictac[2][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][2]==' ')
						{
							tictac[0][2]=comp;
							DISPLAY
							WIN
							exit(1);							
						}
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==' ')
						{
							tictac[1][0]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					TIE
					exit(1);
				}											
			}						
											
		}
		
		else
			if(p==1&&q==1)
			{
			tictac[0][2]=comp;
			DISPLAY
			ENTRY
			DISPLAY
			/*11 then 00*/
				if(tictac[0][0]==ent)
				{
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
							tictac[1][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==ent)
						{
							tictac[2][1]=comp;
							DISPLAY
							ENTRY
							DISPLAY
							TIE
							exit(1);
						}
						else
							if(tictac[2][1]==ent)
							{
								tictac[0][1]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								TIE
								exit(1);
							}
						else
						{
							tictac[0][1]=comp;
							DISPLAY
							ENTRY
							DISPLAY
							TIE
							exit(1);
						}
				}
					/*11 then 20*/
				else
				if(tictac[2][0]==ent)
				{
					tictac[2][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][2]==' ')
						{
							tictac[1][2]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==ent)
						{
							tictac[2][1]=comp;
							DISPLAY
							ENTRY
							DISPLAY
							TIE
							exit(1);
						}
						else
							if(tictac[2][1]==ent)
							{
								tictac[0][1]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								TIE
								exit(1);
							}
						else
						{
							tictac[0][1]=comp;
							DISPLAY
							ENTRY
							DISPLAY
							TIE
							exit(1);
						}
				}
					/*11 then 22*/
				else
				if(tictac[2][2]==ent)
				{
					tictac[0][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[0][1]==' ')
						{
							tictac[0][1]=comp;
							DISPLAY
							WIN
							exit(1);
						}
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
						if(tictac[1][0]==ent)
						{
							tictac[1][2]=comp;
							DISPLAY
							ENTRY
							DISPLAY
							TIE
							exit(1);
						}
						else
							if(tictac[1][2]==ent)
							{
								tictac[1][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								TIE
								exit(1);
							}
						else
						{
							tictac[1][0]=comp;
							DISPLAY
							ENTRY
							DISPLAY
							TIE
							exit(1);
						}
				}
				/*11 then 01*/
				else
				if(tictac[0][1]==ent)
				{
					tictac[2][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					/*11 then 01 then 00*/
						if(tictac[0][0]==ent)
						{
							tictac[2][2]=comp;
							DISPLAY
							ENTRY
							DISPLAY
								if(tictac[1][2]==' ')
								{
									tictac[1][2]=comp;
									DISPLAY
									WIN
									exit(1);
								}
								else
									{
										tictac[2][0]=comp;
										DISPLAY
										WIN
										exit(1);
									}							
						}
					/*11 then 01 then 10*/
						else 
							if(tictac[1][0]==ent)
							{
								tictac[1][2]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								if(tictac[2][2]==' ')
								{
									tictac[2][2]=comp;
									DISPLAY
									WIN
									exit(1);
								}
								tictac[0][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								TIE
								exit(1);
							}
					/*11 then 01 then 12*/
						else
							if(tictac[1][2]==ent)
							{
								tictac[1][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								
								if(tictac[0][0]==ent)
								{
									tictac[2][2]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
								else
									if(tictac[2][2]==ent)
									{
										tictac[0][0]=comp;
										DISPLAY
										ENTRY
										DISPLAY
										TIE
										exit(1);
									}
							 	else
							 	{
							 		tictac[2][2]=comp;
							 		DISPLAY
							 		ENTRY
							 		DISPLAY
							 		TIE
							 		exit(1);
								 }
								
							}
							/*11 then 01 then 20*/
						else
							if(tictac[2][0]==ent)
							{
								tictac[2][2]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								
								if(tictac[1][2]==' ')
								{
									tictac[1][2]=comp;
									DISPLAY
									WIN
									exit(1);
								}
								
								tictac[1][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								TIE
							}
							/*11 then 01 then 22*/
						else
							if(tictac[2][2]==ent)
							{
								tictac[0][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								
								if(tictac[1][2]==ent)
								{
									tictac[1][0]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
								else
									if(tictac[1][0]==ent)
									{
									tictac[1][2]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
									}
								else
								{
									tictac[1][2]==ent;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
								
							}
				
				
				}
				/*11 then 21*/
				else
				if(tictac[2][1]==ent)
				{
					tictac[0][1]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					/*11 then 21 then 00*/
						if(tictac[0][0]==ent)
						{
							tictac[2][2]=comp;
							DISPLAY
							ENTRY
							DISPLAY
								if(tictac[1][2]==' ')
								{
									tictac[1][2]=comp;
									DISPLAY
									WIN
									exit(1);
								}
								tictac[1][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								TIE
								exit(1);							
						}
					/*11 then 21 then (10/12/20/22)*/
						else 
							if(tictac[1][0]==ent||tictac[1][2==ent||tictac[2][0]==ent||tictac[2][2]==ent])
							{
								tictac[0][0]=comp;
								DISPLAY
								WIN
								exit(1);
				
							}				
				
				}
				/*11 then 10*/
				else
				if(tictac[1][0]==ent)
				{
					tictac[1][2]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					/*11 then 10 then (00/01/20/21)*/
						if(tictac[0][0]==ent||tictac[0][1]==ent||tictac[2][0]==ent||tictac[2][1]==ent)
						{
							tictac[2][2]=comp;
							DISPLAY
							WIN
							exit(1);					
						}
							/*11 then 10 then 22*/
						else
							if(tictac[2][2]==ent)
							{
								tictac[0][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								
								if(tictac[0][1]==' ')
								{
									tictac[0][1]=comp;
									DISPLAY
									WIN
									exit(1);
								}
								tictac[2][1]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								TIE
								exit(1);
							}
				
				
				}
				/*11 then 12*/
				else
				if(tictac[1][2]==ent)
				{
					tictac[1][0]=comp;
					DISPLAY
					ENTRY
					DISPLAY
					/*11 then 12 then 00*/
						if(tictac[0][0]==ent)
						{
							tictac[2][2]=comp;
							DISPLAY
							ENTRY
							DISPLAY
								if(tictac[0][1]==ent)
								{
									tictac[2][1]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
								else
								if(tictac[2][1]==ent)
								{
									tictac[0][1]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
								else
								{
									tictac[0][1]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
															
						}
					/*11 then 12 then 01*/
						else 
							if(tictac[0][1]==ent)
							{
								tictac[2][1]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								if(tictac[2][2]==ent)
								{
									tictac[0][0]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
								else
									if(tictac[0][0]==ent)
								{
									tictac[2][2]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
								else
								{
									tictac[2][2]=comp;
									DISPLAY
									ENTRY
									DISPLAY
									TIE
									exit(1);
								}
							}
					/*11 then 12 then 20*/
						else
							if(tictac[2][0]==ent)
							{
								tictac[0][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								
								if(tictac[0][1]==' ')
								{
									tictac[0][1]=comp;
									DISPLAY
									WIN
									exit(1);
								}
							tictac[2][1]=comp;
							DISPLAY
							ENTRY
							DISPLAY
							TIE
							exit(1);							
								
							}
							/*11 then 12 then 21*/
						else
							if(tictac[2][1]==ent)
							{
								tictac[0][1]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								
								if(tictac[0][0]==' ')
								{
									tictac[0][0]=comp;
									DISPLAY
									WIN
									exit(1);
								}
								
								tictac[2][2]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								TIE
							}
							/*11 then 12 then 22*/
						else
							if(tictac[2][2]==ent)
							{
								tictac[0][0]=comp;
								DISPLAY
								ENTRY
								DISPLAY
								
								if(tictac[0][1]=' ')
								{
									tictac[0][1]=comp;
									DISPLAY
									WIN
									exit(1);
									
								}
								else 
									if(tictac[2][0]=' ')
									{
										tictac[2][0]=comp;
										DISPLAY
										WIN
										exit(1);
									}						
						
								
							}
					}
				
				
				}		
		}
		printf("\n\n");
		
	}

	

int getkey()
{
	int ch;
	ch=getch();
	if(ch==0)
	{
		ch=getch();
		return ch;
	}
	return ch;
}
void gotoxy(short col,short row)
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position={col,row};
	SetConsoleCursorPosition(h,position);
}
