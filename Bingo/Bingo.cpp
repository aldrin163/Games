#include<iostream.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>


int i,j,n[25],bingp,bingc,turn;
int a[6][6],c[6][6],t[6][6];
char b[6]={"BINGO"};
void displayb(int a[][6])
{
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
           if(a[i][j]==0)
                {
                    cout<<"   --";
                }
            else
            {
                cout<<"   "<<a[i][j];
                if(a[i][j]<10)
                    cout<<" ";
            }

        }
        cout<<endl<<endl;
    }
}


void random_gen(int s[][6])
{
    randomize();
    int sack[25],k=0,pos;
    for(i=0;i<26;i++)
        sack[i]=i+1;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        {
            pos=random(25-k);
            s[i][j]=sack[pos];
            sack[pos]=sack[25-k];
            k++;
        }
}
int random_num()//computer number generator
{
    int f=1,x;
    while(f==1)
    {
        x=random(25)+1;
        f=0;
        for(j=0;j<turn;j++)
            if(x==n[j])
            {
                f=1;
                break;
            }

    }
    return x;
}

void cut(int x[][6])
{
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(n[turn]==x[i][j])
                x[i][j]=0;

}

int check(int x[][6])
{
    int f1,f2,f3=0,f4=0,bing;
    bing=0;
   for(i=0;i<5;i++)
    {
        f1=0;f2=0;
        for(j=0;j<5;j++)
        {
            if(x[i][j]!=0)//Row wice
               f1=1;
            if(x[j][i]!=0)//column wice
                f2=1;
            if(i==j&&x[i][j]!=0)
                f3=1;
            if(j==(4-i)&&x[i][j]!=0)
                f4=1;
        }
        if(f1==0) bing++;
        if(f2==0) bing++;
    }
    if(f3==0) bing++;
    if(f4==0) bing++;

  return bing;

}

void printbingo()
{
    cout<<"  ~~~~~~~~~~~~~~~~~~~~~~~~~~\n        B  I  N  G  O \n  ~~~~~~~~~~~~~~~~~~~~~~~~~~\n";    random_gen(c);
}
//************ MAIN FUNCTION OF BINGO *********************************
void bingo()
{
    char next;
    srand(time(NULL));

    int k=1,ch;
    printbingo();
    cout<<" ( 1 ) Enter 25 elements : \n ( 2 ) Auto-generate\n  ENTER CHOICE : ";
    cin>>ch;
    if(ch==1)
        for(i=0;i<5;i++)
            for(j=0;j<5;j++)
            {

                cin>>a[i][j];
            }
    else if(ch==2)
        random_gen(a);
    else
    {
        cout<<"Invalid Input";
        exit(0);
    }
    clrscr();
    printbingo();
    displayb(a);
    //display(c);
//while(!finished)
while(1)
{
    if(turn%2==0)//player's Turn
    {
        cout<<" Enter a number : ";
        cin>>n[turn];
        system("cls");
    }
    else// Computer's turn
    {
        n[turn]=random_num();
        cout<<" Computer choose : ";
        //usleep(1000000);
        cout<<n[turn];
        cout<<"\n Press Enter to continue: ";
        getch();
        system("cls");
    }
    printbingo();
    cut(a);
    cut(c);

    bingc=check(c);
    bingp=check(a);
    if(bingp>0)
    {
        for(i=0;i<bingp;i++)
            cout<<"  "<<b[i]<<" ";
        cout<<endl;
    }
        if(bingp>=5)
        {
            cout<<" \n\n    ~~~  YOU WON !! ~~~";
            break;
        }
        if(bingc>=3)
        {
            cout<<"YOU lost, computer won \n   BETTER LUCK NEXT TIME";
            break;
        }
    displayb(a);
    turn++;
}

}

//*************************tic tac toe****************X O************************
void xo()
{
    char a[10];
    int k=0,n,j,c,w,i,ch,p1,p2;



    while(k<10)
    {
         a[k]='_';
         ++k;
    }

    for(j=0;;j++)
    {
        system("cls");
        cout<<"\n\tX O\n     ---------\n\n";
        for(i=1;i<10;++i)//displaying
        {
            cout<<"     ";
            cout<<a[i];
            if(i%3==0)
            {
                cout<<"\n\n";
            }
        }

                       if((j+1)%2==0)//X or O
                       {
                            if(w==1)
                            {
                                cout<<"\n\tPLAYER 1 WON!!\n";
                                p1++;
                                break;
                            }

                    cout<<"\n  2nd player's turn : ";
                    cin>>ch;
                    if(ch>6)
                        n=ch-6;
                    else if(ch<4)
                        n=ch+6;
                    else
                        {n=ch;}
                    a[n]='O';
               }
               else
               {
                    if(w==1)
                    {
                        cout<<"\n\tPLAYER 2 WON!!\n";
                        p2++;
                        break;
                    }

                    cout<<"\n  1st player's turn : ";
                    cin>>ch;
                    if(ch>6)
                        n=ch-6;
                    else if(ch<4)
                        n=ch+6;
                    else
                        n=ch;
                    a[n]='X';
               }
          for(c=1;c<10;++c)//for checking whether you  won or not
          {
               if(a[c]==a[c+1]&&a[c]==a[c+2]&&(c+2)%3==0&&a[c]!='_')//horizontal relation
               {
                    w=1;
               }
               if(a[c]==a[c+3]&&a[c]==a[c+6]&&a[c]!='_')//vertical relation
               {
                    w=1;
               }
               if(a[1]==a[5]&&a[5]==a[9]&&a[5]!='_')//diagonal relation #1
               {
                w=1;
               }
                 if(a[3]==a[5]&&a[5]==a[7]&&a[5]!='_')//diagonal relation #2
               {
                w=1;
               }


          }

}
/*ifstream fobj("XOpoints");
cout<<"Player 1 points : "<<p1;
cout<<"Player 2 points : "<<p2;
while(fobj)
{
    seekp()
}

*/
}

int main()
{
    int mchoice;
    cout<<"\n\n  M E N U\n *********\n 1) B I N G O\n 2) Tic Tac Toe\n\n";
    cout<<" ENTER CHOICE : ";
    cin>>mchoice;
    system("cls");
    if(mchoice==1) bingo();
    if(mchoice==2) xo();
}



