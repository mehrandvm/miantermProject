#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>
//#include <windows.h>
#include <string.h>

#define X 30
#define Y 14
#define MineNum 10

int arrX[10];
int arrY[10];
char Minefield[X][Y];

void printMap();
void clearscreen();
void createMap();
int getRandY();
int getRandX();
int CheckX(int xUser);
int CheckY(int yUser);

int main()
{
    createMap();
    char oneInput[3];
    int firstInput;
    int xUser, yUser;
    int arrX[MineNum], arrY[MineNum], n, i;

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
    printf("\n");
    printf("\n");

    while (1)
    {
        printMap();
        scanf("%d", &firstInput);
        scanf("%d", &xUser);
        scanf("%d", &yUser);

        if (firstInput == 1)
        {
            clearscreen();
            if (CheckX(xUser) == 1 && CheckY(yUser) == 1)
                printf("BOOM\n");
        }
        else if (firstInput = 2)
        {
            clearscreen();
            if (Minefield[yUser - 1][xUser - 1] == 'P')
                printf("Already Flagged!\n");
            Minefield[yUser - 1][xUser - 1] = 'P';
        }
        else if (firstInput == 3)
        {
            clearscreen();
            if (Minefield[yUser - 1][xUser - 1] == 'P')
                printf("Its not Flagged!\n");
            Minefield[yUser - 1][xUser - 1] = '#';
        }
    }
}

void clearscreen()
{
    system("clear");
}

void createMap()
{
    int i, j;
    for (i = 0; i < Y; i++)
    {
        for (j = 0; j < X; j++)
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
        printf("%d ", i);
    }

    printf("\n");

    for (i = 0; i < Y; i++)
    {
        printf("%d  ", i + 1);
        if ((i + 1) / 10 == 0)
            printf(" ");
        for (j = 0; j < X; j++)
        {

            putchar(Minefield[i][j]);
            printf("  ");
        }
        putchar('\n');
    }
}

int CheckX(int xUser)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (xUser == arrX[i])
        {
            printf("X yes\n");
            return 1;
        }
    }
    return 0;
}

int CheckY(int yUser)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (yUser == arrY[i])
        {
            printf("Y yes\n");
            return 1;
        }
    }
    return 0;
}
