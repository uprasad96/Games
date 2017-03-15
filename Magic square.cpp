#include<iostream>
using namespace std;
#include<math.h>
#include<iomanip>
#include<conio.h>
int getkey(void);
int main()
{
int k;
cout<<"Enter Odd number: ";
cin>>k;
int ksq,sq[k][k],x=0,y,i,j,n=1;
y=(k-1)/2;
ksq=pow(k,2);

	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		sq[i][j]=0;		
	}
	sq[x][y]=n;
	
cout<<"\n\n";	
while(1)
{
	if(x==0)
	x=k-1;
	else
	x--;
	if(y==k-1)
	y=0;
	else
	y++;
	n++;
	if(sq[x][y]==0)
	sq[x][y]=n;
	else
	{
	if(x==k-1)
	x=0;
	else
	x++;
	if(y==0)
	y=k-1;
	else
	y--;
	if(x==k-1)
	x=0;
	else
	x++;
	sq[x][y]=n;
	}	
	if(n==ksq)
	break;		
}

for(i=0;i<k;i++)
{
	for(j=0;j<k;j++)
	{
	cout<<setw(5)<<sq[i][j];
	}
	cout<<"\n\n";
}
getkey();
return 0;
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

