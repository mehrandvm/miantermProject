#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>
//#include <windows.h>
#include <string.h>

#define X 30
#define Y 14
#define MineNum 10
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int arrX[10];
int arrY[10];
char Minefield[X][Y];

void Reccursion(int xUser,int yUser);
void printMap();
void clearscreen();
void createMap();
int getRandY();
int getRandX();
int CheckX(int xUser);
int CheckY(int yUser);
char c;

int main()
{
    createMap();
    char oneInput[3];
    int firstInput;
    int xUser, yUser;
    static int arrX[MineNum], arrY[MineNum];
    int i, n, counter=0;

    for (i = 0; i < MineNum; i++)
    {
        n = rand() % 30 + 1;
        arrX[i] = n;
    }

    for (i = 0; i < MineNum; i++)
    {
        n = rand() % 14 + 1;
        arrY[i] = n;
    }

    printf("\n");

    for (i = 0; i < MineNum; i++)
    {
        printf("%d ", arrX[i]);
    }
    printf("\n");
    for (i = 0; i < MineNum; i++)
    {
        printf("%d ", arrY[i]);
    }
    printf("\n");

    while (1)
    {
        printMap();
        scanf("%d", &firstInput);
        scanf("%d", &xUser);
        scanf("%d", &yUser);

        if (firstInput == 1)
        {
            counter =0;
            for (i = 0; i < MineNum; i++)
            {
                if (xUser == arrX[i] && yUser == arrY[i])
                {
                    printf(ANSI_COLOR_RED "**********GAME OVER**********\n" ANSI_COLOR_RESET);
                    printf("\n");
                    for (i = 0; i < MineNum; i++)
                    {
                        Minefield[arrX[i]-1][arrY[i]-1] = '*';
                    }
                }
                else {
                    
                    if (xUser-1 == arrX[i] && yUser == arrY[i]) counter++;
                    if (xUser+1 == arrX[i] && yUser == arrY[i]) counter++;
                    if (xUser-1 == arrX[i] && yUser+1 == arrY[i]) counter++;
                    if (xUser+1 == arrX[i] && yUser+1 == arrY[i]) counter++;
                    if (xUser-1 == arrX[i] && yUser-1 == arrY[i]) counter++;
                    if (xUser+1 == arrX[i] && yUser-1 == arrY[i]) counter++;
                    if (xUser == arrX[i] && yUser+1 == arrY[i]) counter++;
                    if (xUser == arrX[i] && yUser-1 == arrY[i]) counter++;
                    //printf("counter is %d\n",counter);
                    if (counter==0) c = ' ';
                    if (counter==1) c = '1';
                    if (counter==2) c = '2';
                    if (counter==3) c = '3';
                    if (counter==4) c = '4';
                    if (counter==5) c = '5';
                    if (counter==6) c = '6';
                    if (counter==7) c = '7';
                    if (counter==8) c = '8';
                    if (counter==9) c = '9';
                    //printf("c is %c\n",c);
                    Minefield[xUser-1][yUser-1] = c;
                    if(c==' ') Reccursion(xUser-1,yUser-1);
                }
            }
        }
        if (firstInput == 2)
        {
            if (Minefield[yUser - 1][xUser - 1] == 'P')
                printf("Already Flagged!\n");
            Minefield[yUser - 1][xUser - 1] = 'P';
        }
        if (firstInput == 3)
        {
            if (Minefield[yUser - 1][xUser - 1] == '#')
                printf("Its not Flagged!\n");
            Minefield[yUser - 1][xUser - 1] = '#';
        }
    }
}

void Reccursion(int xUser,int yUser){
}


void clearscreen()
{
    system("clear");
}

void createMap()
{
    int i, j;
    for (j = 0; j < Y; j++)
    {
        for (i = 0; i < X; i++)
        {
            Minefield[i][j] = 35;
        }
    }
}

void printMap()
{

    int i, j;

    for (i = 0; i <= X; i++)
    {
        if (i / 10 == 0)
            printf(" ");
        printf(ANSI_COLOR_CYAN "%d " ANSI_COLOR_RESET, i);
    }

    printf("\n");

    for (j = 0; j < Y; j++)
    {
        printf(ANSI_COLOR_CYAN " %d " ANSI_COLOR_RESET, j + 1);
        if ((j + 1) / 10 == 0)
            printf(" ");
        for (i = 0; i < X; i++)
        {
            ANSI_COLOR_CYAN;

            if (Minefield[i][j] == 'P')
            {
                printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, Minefield[i][j]);
            }
            else if (Minefield[i][j] == '*')
            {
                printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, Minefield[i][j]);
            }
            else if (Minefield[i][j] == '1' || Minefield[i][j] == '2' || Minefield[i][j] == '3')
            {
                printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, Minefield[i][j]);
            }
            else if (Minefield[i][j] == '4' || Minefield[i][j] == '5' || Minefield[i][j] == '6')
            {
                printf(ANSI_COLOR_MAGENTA "%c" ANSI_COLOR_RESET, Minefield[i][j]);
            }
            else
            {
                printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, Minefield[i][j]);
            }
            printf("  ");
        }
        putchar('\n');
    }
}
