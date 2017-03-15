#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define VLINE(X,Y) { \
					  gotoxy(X,Y);\
					  printf("%c",179);\
                   }


int main()
{
	
	int grid[4][4]={
				   {1,4,15,7},
				   {8,10,2,11},
				   {14,3,6,13},
				   {12,9,5,}
				   };
	int i,j,k,y,ch,*blank,*temp,num,m,n,stp=0,hscr;
	FILE *fp;
	char chf;
	
	
	
	printf("THE SLIDING PUZZLE GAME\nYOU HAVE TO ARRANGE THE NUMBERS IN AN ASCENDING ORDER TO WIN\n\n\n");
		
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(grid[i][j]==0)
			printf("     ");
			else
			printf("%5d",grid[i][j]);
			
		}
		printf("\n\n");
			
	}
	gotoxy(24,5);
	printf("\tSteps");
	gotoxy(24,6);
	printf("\t%d",stp);
	fp=fopen("highscore.txt","r");
	gotoxy(40,5);
	printf("High score");
	gotoxy(40,6);
	while(1)
	{
		chf=fgetc(fp);
		if(chf==EOF)
		break;
		printf("%c",chf);
	}
	fclose(fp);
	ch=getkey();
	while(1)
	{
	    
	    if(ch==56)
	    {
	    for(i=0;i<4;i++)
	    	{
	    		for(j=0;j<4;j++)
	    		{
	    			num=grid[i][j];
	    			if(num==0)
	    			{
	    				m=i;
	    				n=j;
					}
				}
			}
			if(m!=3)
			{			
	    	blank= &grid[m][n];
	    	temp=blank;
	    	blank=blank+4;
	    	*temp=grid[m+1][n];
	    	*blank=0;
	        }
	    	
	    	gotoxy(0,4);
	    	for(i=0;i<4;i++)
	    	{
	    		for(j=0;j<4;j++)
	    		{
	    			if(grid[i][j]==0)
	    			printf("     ");
	    			else
	    			printf("%5d",grid[i][j]);
				}
				printf("\n\n");
			}
			stp++;
			gotoxy(24,5);
			printf("\tSteps");
			gotoxy(24,6);
			printf("\t%d",stp);
	    		
		}
		
		   if(ch==53)
	    {
	    for(i=0;i<4;i++)
	    	{
	    		for(j=0;j<4;j++)
	    		{
	    			num=grid[i][j];
	    			if(num==0)
	    			{
	    				m=i;
	    				n=j;
					}
				}
			}
	    	blank= &grid[m][n];
	    	temp=blank;
	    	blank=blank-4;
	    	*temp=grid[m-1][n];
	    	*blank=0;
	    	
	    	gotoxy(0,4);
	    	for(i=0;i<4;i++)
	    	{
	    		for(j=0;j<4;j++)
	    		{
	    			if(grid[i][j]==0)
	    			printf("     ");
	    			else
	    			printf("%5d",grid[i][j]);
				}
				printf("\n\n");
			}
			stp++;
			gotoxy(24,5);
			printf("\tSteps");
			gotoxy(24,6);
			printf("\t%d",stp);
	    		
		}
		    if(ch==52)
	    {
	    		for(i=0;i<4;i++)
	    	{
	    		for(j=0;j<4;j++)
	    		{
	    			num=grid[i][j];
	    			if(num==0)
	    			{
	    				m=i;
	    				n=j;
					}
				}
			}
			if(n!=3)
			{
	    	blank= &grid[m][n];
	    	temp=blank;
	    	blank=blank+1;
	    	*temp=grid[m][n+1];
	    	*blank=0;
	        }
	    	gotoxy(0,4);
	    	for(i=0;i<4;i++)
	    	{
	    		for(j=0;j<4;j++)
	    		{
	    			if(grid[i][j]==0)
	    			printf("     ");
	    			else
	    			printf("%5d",grid[i][j]);
				}
				printf("\n\n");
			}
	    	stp++;
	    	gotoxy(24,5);
			printf("\tSteps");
			gotoxy(24,6);
			printf("\t%d",stp);
	    
		}
		    if(ch==54)
	    {
	    	for(i=0;i<4;i++)
	    	{
	    		for(j=0;j<4;j++)
	    		{
	    			num=grid[i][j];
	    			if(num==0)
	    			{
	    				m=i;
	    				n=j;
					}
				}
			}
			if(n!=0)
			{
	    	blank= &grid[m][n];
	    	temp=blank;
	    	blank=blank-1;
	    	*temp=grid[m][n-1];
	    	*blank=0;
	        }
	    	
	    	gotoxy(0,4);
	    	for(i=0;i<4;i++)
	    	{
	    		for(j=0;j<4;j++)
	    		{
	    			if(grid[i][j]==0)
	    			printf("     ");
	    			else
	    			printf("%5d",grid[i][j]);
				}
				printf("\n\n");
			}
			stp++;
			gotoxy(24,5);
			printf("\tSteps");
			gotoxy(24,6);
			printf("\t%d",stp);
	    	
		}
		
	if((grid[0][0]==1)&&(grid[0][1]==2)&&(grid[0][2]==3)&&(grid[0][3]==4)&&(grid[1][0]==5)&&(grid[1][1]==6)&&(grid[1][2]==7)&&(grid[1][3]==8)&&(grid[2][0]==9)&&(grid[2][1]==10)&&(grid[2][2]==11)&&(grid[2][3]==12)&&(grid[3][0]==13)&&(grid[3][1]==14)&&(grid[3][2]==15)&&(grid[3][3]==0))
	{
	break;	
    }
	ch=getkey();	
	}
	fp=fopen("highscore.txt","r");
	fscanf(fp,"%d",&hscr);
	fclose(fp);
	if(stp>hscr)
	{
	gotoxy(2,14);
	printf("\nYOU TOOK %d STEPS TO WIN",stp);
	}
	
	if(stp<hscr)
	{
		fopen("highscore.txt","w");
		fprintf(fp,"%d",stp);
		fclose(fp);
		gotoxy(2,14);
		printf("YOU TOOK %d STEPS TO WIN",stp);
		gotoxy(2,15);
		printf("It is the high score!!");
	}
	fp=fopen("highscore.txt","r");
	gotoxy(40,5);
	printf("High score");
	gotoxy(40,6);
	while(1)
	{
		chf=fgetc(fp);
		if(chf==EOF)
		break;
		printf("%c",chf);
	}
	fclose(fp);
		
	getkey();
	
	    	    
	return 0;
	
	
}
void gotoxy(short col,short row)
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position={col,row};
	SetConsoleCursorPosition(h,position);
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
