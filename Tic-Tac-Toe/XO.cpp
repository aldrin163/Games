#include<iostream>
using namespace std;
int main()
{
int i,j,n;
char x='x',o='o',ch;
char n1,n2,n3,n4,n5,n6,n7,n8,n9;

cout<<"\t\t\tTic-Tac-Toe\n";
cout<<"\t\t\t-----------\n";
cout<<"\t\t\t\tCreated by Aldrin Jenson\n";
start:
int flag=0;
n1=n2=n3=n4=n5=n6=n7=n8=n9='-';
for(n=1;n<=4;n++)
{
cout<<"\n\nPlayer 1,Enter x in fields 1 to 9 ";
cin>>i;
switch(i)
	{
	case 1:
	n1=x;
	break;
	case 2:
	n2=x;
	break;
	case 3:
	n3=x;
	break;
	case 4:
	n4=x;
	break;
	case 5:
	n5=x;
	break;
	case 6:
	n6=x;
	break;
	case 7:
	n7=x;
	break;
	case 8:
	n8=x;
	break;
	case 9:
	n9=x;
	break;
	}
cout<<" \n\t"<<n7<<" \t"<<n8<<"\t"<<n9;
cout<<" \n\t"<<n4<<" \t"<<n5<<" \t"<<n6;
cout<<" \n\t"<<n1<<" \t"<<n2<<" \t"<<n3;


	if(n1==n2&&n2==n3&&n2!='-'||n4==n5&&n5==n6&&n5!='-'||n7==n8&&n8==n9&&n8!='-')
		{
		cout<<"\nCongratulations!!\nYou have won the game ";
		flag=1;
		break;
		}
	else if(n1==n4&&n4==n7&&n4!='-'||n2==n5&&n5==n8&&n2!='-'||n3==n6&&n6==n9&&n6!='-')
		{
		cout<<"\nCongratulations!!\nYou have won the game ";
		flag=1;
		break;
		}
	else if(n1==n5&&n5==n9&&n5!='-'||n3==n5&&n5==n7&&n7!='-')
		{
		cout<<"\nCongratulations!!\nYou have won the game ";
		flag=1;
		break;
		}

cout<<"\nPlayer 2,Enter o in fields 1 to 9 ";
cin>>j;
switch(j)
	{
	case 1:
	n1=o;
	break;
	case 2:
	n2=o;
	break;
	case 3:
	n3=o;
	break;
	case 4:
	n4=o;
	break;
	case 5:
	n5=o;
	break;
	case 6:
	n6=o;
	break;
	case 7:
	n7=o;
	break;
	case 8:
	n8=o;
	break;
	case 9:
	n9=o;
	break;
	}
cout<<" \n\t"<<n7<<" \t"<<n8<<"\t"<<n9;
cout<<" \n\t"<<n4<<" \t"<<n5<<" \t"<<n6;
cout<<" \n\t"<<n1<<" \t"<<n2<<" \t"<<n3;


	if(n1==n2&&n2==n3&&n2!='-'||n4==n5&&n5==n6&&n5!='-'||n7==n8&&n8==n9&&n8!='-')
		{
		cout<<"\nCongratulations!!\nYou have won the game ";
		flag=1;
		break;
		}
	else if(n1==n4&&n4==n7&&n4!='-'||n2==n5&&n5==n8&&n2!='-'||n3==n6&&n6==n9&&n6!='-')
		{
		cout<<"\nCongratulations!!\nYou have won the game ";
		flag=1;
		break;
		}
	else if(n1==n5&&n5==n9&&n5!='-'||n3==n5&&n5==n7&&n7!='-')
		{
		cout<<"\nCongratulations!!\nYou have won the game ";
		flag=1;
		break;
		}
}
	if(flag==0)
	{
	cout<<"\nTie Game!!";
	cout<<"\nBetter Luck next time";
	}
cout<<"\n\nDo you want to play again?(y/n)";
cin>>ch;
if(ch=='y'||ch=='Y')
goto start;  //Aldrin is awesome and i know it
}
