#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char boarddisplay(char board[][3])
{
    int i,j,k;
    printf("0  1  2\n");
    for(i=0,k=0;i<3;i++,k++)
    {
        for(j=0;j<3;j++)
        {
            printf("%c  ",board[i][j]);
        }
        printf("%d\n",k);
    }
    return 0;
}
int turn1(char board[][3])
{
    int x_coordinate,y_coordinate,k;
    for(k=0;k<1;)
    {   printf("player 1,enter the x-coordinate\n");
        scanf("%d",&y_coordinate);
        printf("player 1,enter the y-coordinate\n");
        scanf("%d",&x_coordinate);
        if ((x_coordinate>2)||(y_coordinate>2)||(board[x_coordinate][y_coordinate]!='.'))
            {
                printf("enter a valid input\n");
            }
        else
        {
            k++;
        }
    }
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            char position=board[i][j];
            char space='.';
            {
                if ((position==space)&&(i==x_coordinate)&&(j==y_coordinate))
                {
                    board[i][j]='X';
                }
            }
        }
    }
    return board[3][3];
}
int turn2(char board[][3])
{
    int x_coordinate,y_coordinate,k;
    for(k=0;k<1;)
    {   printf("player 2,enter the x-coordinate\n");
        scanf("%d",&y_coordinate);
        printf("player 2,enter the y-coordinate\n");
        scanf("%d",&x_coordinate);
        if ((x_coordinate>2)||(y_coordinate>2)||(board[x_coordinate][y_coordinate]!='.'))
            {
                printf("enter a valid input\n");
            }
        else
        {
            k++;
        }
    }
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            char position=board[i][j];
            char space='.';
            {
                if ((position==space)&&(i==x_coordinate)&&(j==y_coordinate))
                {
                    board[i][j]='O';
                }
            }
        }
    }
    return board[3][3];
}
int check_board(char board[][3])
{
    int i,j,count,count_final;
    for(i=0,count=9;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if (board[i][j]!='.')
            {
                count--;
            }   
        }
    count_final=count;
    }
    if (((board[0][0]==board[0][1])&&(board[0][1]==board[0][2])&&(board[0][0]=='X'))||((board[1][0]==board[1][1])
    &&(board[1][1]==board[1][2])&&(board[1][0]=='X'))||((board[2][0]==board[2][1])&&(board[2][1]==board[2][2])&&(board[2][0]=='X'))
    ||((board[0][0]==board[1][0])&&(board[1][0]==board[2][0])&&(board[0][0]=='X'))||((board[0][1]==board[1][1])
    &&(board[1][1]==board[2][1])&&(board[0][1]=='X'))||((board[0][2]==board[1][2])&&(board[1][2]==board[2][2])&&(board[0][2]=='X'))
    ||((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])&&(board[0][0]=='X'))||((board[2][0]==board[1][1])&&
    (board[1][1]==board[0][2])&&(board[2][0]=='X')))
    {
        boarddisplay(board);
        printf("player 1 has won\n");
        exit(0);
    }
    else if (((board[0][0]==board[0][1])&&(board[0][1]==board[0][2])&&(board[0][0]=='O'))||((board[1][0]==board[1][1])
    &&(board[1][1]==board[1][2])&&(board[1][0]=='O'))||((board[2][0]==board[2][1])&&(board[2][1]==board[2][2])&&(board[2][0]=='O'))
    ||((board[0][0]==board[1][0])&&(board[1][0]==board[2][0])&&(board[0][0]=='O'))||((board[0][1]==board[1][1])
    &&(board[1][1]==board[2][1])&&(board[0][1]=='O'))||((board[0][2]==board[1][2])&&(board[1][2]==board[2][2])&&(board[0][2]=='O'))
    ||((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])&&(board[0][0]=='O'))||((board[2][0]==board[1][1])&&
    (board[1][1]==board[0][2])&&(board[2][0]=='O')))
    {
        boarddisplay(board);
        printf("player 2 has won\n");
        exit(0);
    }
    else if (count_final==0){boarddisplay(board);printf("It is a draw\n");exit(0);}
    return 0;
}
int main()
{
    char board[3][3];
    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j]='.';
        }
    }
    for (k=0;k<5;k++)
    {
        boarddisplay(board);
        turn1(board);
        check_board(board);
        boarddisplay(board);
        if(k==4)
        {
            break;
        }
        turn2(board);
        check_board(board);
    }
}