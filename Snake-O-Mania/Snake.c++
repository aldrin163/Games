#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<process.h>
#include<conio.h>
using namespace std;
    //fstream fobj("scores.txt");


int i,j,a,b,d,score = 0;
const int r = 14, c =40;    //row and column sizes
char space[20][45], hero ='T', ans;

int snake_length = 2;
int x = (r+1)/2, y = (c+1)/2, cur_x = x-1, cur_y = y;   //to place the snake in the centre at the beginning
                                //previous element
int snake[r*(c-1)][2];   //array which stores info of all the coordinates in which the snake has travelled
int x1,y1;    // x1 and y1 are the coordinates of the food generated

//Note: X coordinate = y and Y coordinate = x (since rows and columns are stored in touples:-diff arrangement)

void create_space()
{
    for(i=0;i<r;i++)
            for (j=0; j < c; j++)
                {
                    space[i][j] = '_';
                    if(i==0||j==0||i==r-1||j==c-1)
                        space[i][j] = 'X';
                }
}

void disp_space()
{   
    for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                cout<<space[i][j]<<"_";
            cout<<endl;
        }
}

int game_over_check()
{
    if(snake_length>3) 
        for(a=0;a<snake_length;a++)     //if the snake comes and bites any of its own body
            if(x==snake[a][0]&&y==snake[a][1])
                return 1;

            //  Checking if the snake hits the boundary walls             

     for(a = 0;a<r;a++)     //for left and right(vertical) boundaries
        {
            if(x==a&&y==0)
                return 1;
            else if(x==a&&y==c-1)
                return 1;
        }

     for(b = 0;b<c;b++)     //for top and bottom(horizontal) boundaries
        {
            if(x==0&&y==b)
                return 1;
            else if(x==r-1&&y==b)
                return 1;
        }

    return 0;   //i.e. game is not over
}

void generate_food()
{
    start:
    x1 = rand()%12 + 1;     //not + 0 since the zeroth row is filled with the boundary xs
    y1 = rand()%38 + 1;     //similary not % 14 and 32 respectively
    for(i=0;i<snake_length;i++)
        if(snake[i][0] == x1 || snake[i][1] == y1)       //to ensure that the food does not appear on the 
            goto start;                         //snake itself

    space[x1][y1] = 'o';
}


void move()
{
    space[x][y] = hero;
    space[cur_x][cur_y] = 'x';
    cur_x = x; cur_y = y;

    if (x==x1&&y==y1)   //if the food is taken
        {
            snake_length++;
            score++;
            generate_food();            
        }    
}
        
int main()
{  
    cout<<"\n\n\t\t\tSNAKE-o-MANIA\n";
    cout<<"\t\t\t-------------\n";
    cout<<"INSTRUCTIONS:\n->Use the number pad as arrow keys.\n->Press enter after each Entry.\n";
    cout<<"->Enter '#' to exit any time\nHAVE FUN!!\n\n";

        snake[0][0] = cur_x;    //storing the current coordinates to the snake array
        snake[0][1] = cur_y;

    srand(time(NULL));  
    create_space();
    generate_food();

    while(ans!= '#')
    {  
        cout<<"SCORE: "<<score<<"\tSnake Length = "<<snake_length<<endl;

        if(game_over_check()==1)    //i.e if the game is over
            {
                cout<<"\t\tGAME OVER!!!!!!\n\n";
                exit(0);
            }
  
        snake[snake_length-1][0] = x;    //storing the current coordinates to the snake array
        snake[snake_length-1][1] = y;

        move();
        disp_space();
       
        space[snake[0][0]][snake[0][1]] = '_'; //the first element of the snake araray is showwn as the tail

        for(d = 0;d<snake_length-1;d++)   //circular queue
            {
                snake[d][0] = snake[d+1][0];
                snake[d][1] = snake[d+1][1];
            }
        
        cout<<"Coordinates: "<<x<<" "<<y<<"\n";
       ans = getch();
        //cin>>ans;
        cout<<string(10,'\n');

        if(ans=='6')
            y++; 
        else if(ans=='4')
            y--;
        else if(ans=='8')
            x--;
        else if(ans=='2')
            x++;
        else
            cout<<"Invalid Entry.\nTry Again\n\n";
    }
}