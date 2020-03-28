#include<iostream>
using namespace std;

int C[7]={4,2,0,6,4,2,0};//To calculate the century code
//Program to calculate the day of the entered date

int yearcode(int);
int centurycode(int);
int leapcheck(int);

int main()
{
int A[12]={0,3,3,6,1,4,6,2,5,0,3,5},d,m,y;
char D[7][12]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
char month[][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};

cout<<"Enter day: ";
cin>>d;
cout<<"Enter month(no.): ";
cin>>m;
cout<<"Enter year(1700 to 2300): ";
cin>>y;

int yc=yearcode(y);
int lc=leapcheck(y);
int cc=centurycode(y);
int mc=A[m-1];
int dc=d;

//Day Code = (Year Code + Month Code + Century Code + Date Number – Leap Year Code) mod 7

int day=(yc+mc+cc+dc-lc);
if((m==1||m==2)&&lc==1)
    day--;
day%=7;
cout<<endl<<d<<" "<<month[m-1]<<" "<<y<<" is a ";
cout<<endl<<D[day]<<endl;
}


int yearcode(int y)
{
int r; //(YY + (YY div 4)) mod 7
r=y%100;
int yby4=r/4;
int ycode=(r+yby4)%7;
return ycode;
}

int leapcheck(int y)
{
int f=0;
if(y%100!=0)
    if(y%4==0)
    f=1;
if(y%400==0)
    f=1;
return f;
}


int centurycode(int y)
{
int x=y/100;
int z=C[x-17];
return z;
}