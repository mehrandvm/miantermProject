#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//defining constants

#define X 30
#define Y 14
#define MineNum 40

//global variables

static int arrX[40];
static int arrY[40];
char Minefield[X][Y];

//function prototypes
void printMap();
void clearscreen();
void createMap();
int checkNum(int xUser, int yUser, int i);
char printHowMany(int xUser, int yUser);
void MagicTop(int xUser, int yUser);
void MagicBottom(int xUser, int yUser);
void MagicRight(int xUser, int yUser);
void MagicLeft(int xUser, int yUser);
void MagicTopLeft(int xUser, int yUser);
void MagicTopRight(int xUser, int yUser);
void MagicBottomLeft(int xUser, int yUser);
void MagicBottomRight(int xUser, int yUser);
void Magic(int xUser, int yUser);
void numFix();
//main function

int main()
{
    srand(time(0));
    createMap();                                // make a 30 * 14 array with #s
    char commandInput[3];                       //for taking cho fla ufl
    int xUser, yUser;                           // coordiantes chosen by user
    int i, j, n, counter = 0, blankCounter = 0; // loop counter variables

    //Creating Random Ys

    for (i = 0; i < MineNum; i++)
    {
        n = rand() % 30 + 1;
        arrX[i] = n;
    }

    //Creating Random Ys

    for (i = 0; i < MineNum; i++)
    {
        n = rand() % 14 + 1;
        arrY[i] = n;
    }

    while (1)
    {
        //***This part will be deleted***///

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

        //***This part will be deleted***///
        char c;
        printMap();
        scanf("%s", &commandInput);
        scanf("%d", &xUser);
        scanf("%d", &yUser);

        if (commandInput[0] == 'c' && commandInput[1] == 'h' && commandInput[2] == 'o')
        {

            counter = 0;
            blankCounter = 0;
            for (i = 0; i < MineNum; i++)
            {
                if (xUser == arrX[i] && yUser == arrY[i])
                {
                    printf("*****GAME OVER*****\n\n");
                    for (i = 0; i < MineNum; i++)
                    {
                        Minefield[arrX[i] - 1][arrY[i] - 1] = '*';
                    }
                    //printMap();
                    //return 0;
                }
            }
            for (i = 0; i < MineNum; i++)
            {
                if (checkNum(xUser, yUser, i) == 1)
                {
                    c = printHowMany(xUser, yUser);
                    Minefield[xUser - 1][yUser - 1] = c;
                    break;
                }
                else if (checkNum(xUser, yUser, i) == 0)
                {
                    Magic(xUser, yUser);
                    numFix();
                    
                }
            }
        }
        if (commandInput[0] == 'f' && commandInput[1] == 'l' && commandInput[2] == 'a')
        {
            if (Minefield[yUser - 1][xUser - 1] == 'P')
                printf("Already Flagged!\n");
            Minefield[yUser - 1][xUser - 1] = 'P';
        }
        if (commandInput[0] == 'u' && commandInput[1] == 'f' && commandInput[2] == 'l')
        {
            if (Minefield[yUser - 1][xUser - 1] == '#')
                printf("Its not Flagged!\n");
            Minefield[yUser - 1][xUser - 1] = '#';
        }
    }

    return 0;
}

void clearscreen()
{
    system("cls");
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
        printf("%d ", i);
    }

    printf("\n");

    for (j = 0; j < Y; j++)
    {
        printf(" %d ", j + 1);
        if ((j + 1) / 10 == 0)
            printf(" ");
        for (i = 0; i < X; i++)
        {
            if (Minefield[i][j] == 'P')
            {
                printf("%c", Minefield[i][j]);
            }
            else if (Minefield[i][j] == '*')
            {
                printf("%c", Minefield[i][j]);
            }
            else if (Minefield[i][j] == '1' || Minefield[i][j] == '2' || Minefield[i][j] == '3')
            {
                printf("%c", Minefield[i][j]);
            }
            else if (Minefield[i][j] == '4' || Minefield[i][j] == '5' || Minefield[i][j] == '6')
            {
                printf("%c", Minefield[i][j]);
            }
            else
            {
                printf("%c", Minefield[i][j]);
            }
            printf("  ");
        }
        putchar('\n');
    }
}

int checkNum(int xUser, int yUser, int i)
{

    if (xUser - 1 == arrX[i] && yUser == arrY[i])
        return 1; //left
    if (xUser + 1 == arrX[i] && yUser == arrY[i])
        return 1; //right
    if (xUser - 1 == arrX[i] && yUser + 1 == arrY[i])
        return 1; //lower left
    if (xUser + 1 == arrX[i] && yUser + 1 == arrY[i])
        return 1; //lower right
    if (xUser - 1 == arrX[i] && yUser - 1 == arrY[i])
        return 1; //upper left
    if (xUser + 1 == arrX[i] && yUser - 1 == arrY[i])
        return 1; //upper right
    if (xUser == arrX[i] && yUser - 1 == arrY[i])
        return 1; //top
    if (xUser == arrX[i] && yUser + 1 == arrY[i])
        return 1; //bottom
    else
        return 0;
}

char printHowMany(int xUser, int yUser)
{
    int counter = 0;
    int i;
    char c;
    for (i = 0; i < MineNum; ++i)
    {
        if (xUser - 1 == arrX[i] && yUser == arrY[i])
            counter++;
        if (xUser + 1 == arrX[i] && yUser == arrY[i])
            counter++;
        if (xUser - 1 == arrX[i] && yUser + 1 == arrY[i])
            counter++;
        if (xUser + 1 == arrX[i] && yUser + 1 == arrY[i])
            counter++;
        if (xUser - 1 == arrX[i] && yUser - 1 == arrY[i])
            counter++;
        if (xUser + 1 == arrX[i] && yUser - 1 == arrY[i])
            counter++;
        if (xUser == arrX[i] && yUser + 1 == arrY[i])
            counter++;
        if (xUser == arrX[i] && yUser - 1 == arrY[i])
            counter++;
        if (xUser == arrX[i] && yUser == arrY[i])
            counter = -1;
    }
    if (counter == -1)
        c = '*';
    if (counter == 0)
        c = ' ';
    if (counter == 1)
        c = '1';
    if (counter == 2)
        c = '2';
    if (counter == 3)
        c = '3';
    if (counter == 4)
        c = '4';
    if (counter == 5)
        c = '5';
    if (counter == 6)
        c = '6';
    if (counter == 7)
        c = '7';
    if (counter == 8)
        c = '8';

    return c;
}

void MagicTop(int xUser, int yUser)
{
    if (printHowMany(xUser, yUser) == ' ' && yUser <= 14 && yUser >= 0 && xUser >= 0 && xUser <= 30)
    {
        Minefield[xUser - 1][yUser - 1] = ' ';
        MagicTop(xUser, yUser - 1);
    }
    else
    {
        Minefield[xUser - 1][yUser - 1] = printHowMany(xUser, yUser);
    }
}

void MagicBottom(int xUser, int yUser)
{
    if (printHowMany(xUser, yUser) == ' ' && yUser <= 14 && yUser >= 0 && xUser >= 0 && xUser <= 30)
    {
        Minefield[xUser - 1][yUser - 1] = ' ';
        MagicBottom(xUser, yUser + 1);
    }
    else
    {
        Minefield[xUser - 1][yUser - 1] = printHowMany(xUser, yUser);
    }
}

void MagicLeft(int xUser, int yUser)
{
    if (printHowMany(xUser, yUser) == ' ' && yUser <= 14 && yUser >= 0 && xUser >= 0 && xUser <= 30)
    {
        Minefield[xUser - 1][yUser - 1] = ' ';
        MagicLeft(xUser - 1, yUser);
    }
    else
    {
        Minefield[xUser - 1][yUser - 1] = printHowMany(xUser, yUser);
    }
}

void MagicRight(int xUser, int yUser)
{
    if (printHowMany(xUser, yUser) == ' ' && yUser <= 14 && yUser >= 0 && xUser >= 0 && xUser <= 30)
    {
        Minefield[xUser - 1][yUser - 1] = ' ';
        MagicRight(xUser + 1, yUser);
    }
    else
    {
        Minefield[xUser - 1][yUser - 1] = printHowMany(xUser, yUser);
    }
}

void MagicTopRight(int xUser, int yUser)
{
    if (printHowMany(xUser, yUser) == ' ' && yUser <= 14 && yUser >= 0 && xUser >= 0 && xUser <= 30)
    {
        Minefield[xUser - 1][yUser - 1] = ' ';
        MagicTopRight(xUser + 1, yUser - 1);
    }
    else
    {
        Minefield[xUser - 1][yUser - 1] = printHowMany(xUser, yUser);
    }
}

void MagicTopLeft(int xUser, int yUser)
{
    if (printHowMany(xUser, yUser) == ' ' && yUser <= 14 && yUser >= 0 && xUser >= 0 && xUser <= 30)
    {
        Minefield[xUser - 1][yUser - 1] = ' ';
        MagicTopLeft(xUser -1 , yUser - 1);
    }
    else
    {
        Minefield[xUser - 1][yUser - 1] = printHowMany(xUser, yUser);
    }
}

void MagicBottomLeft(int xUser, int yUser)
{
    if (printHowMany(xUser, yUser) == ' ' && yUser <= 14 && yUser >= 0 && xUser >= 0 && xUser <= 30)
    {
        Minefield[xUser - 1][yUser - 1] = ' ';
        MagicBottomLeft(xUser - 1, yUser +1);
    }
    else
    {
        Minefield[xUser - 1][yUser - 1] = printHowMany(xUser, yUser);
    }
}


void MagicBottomRight(int xUser, int yUser)
{
    if (printHowMany(xUser, yUser) == ' ' && yUser <= 14 && yUser >= 0 && xUser >= 0 && xUser <= 30)
    {
        Minefield[xUser - 1][yUser - 1] = ' ';
        MagicBottomRight(xUser + 1, yUser + 1);
    }
    else
    {
        Minefield[xUser - 1][yUser - 1] = printHowMany(xUser, yUser);
    }
}

void Magic(int xUser, int yUser)
{
    MagicTop(xUser, yUser);
    MagicBottom(xUser, yUser);
    MagicLeft(xUser, yUser);
    MagicRight(xUser, yUser);
    MagicBottomLeft(xUser, yUser);
    MagicTopLeft(xUser, yUser);
    MagicBottomRight(xUser, yUser);
    MagicTopRight(xUser, yUser);
}

void numFix()
{
    int i, j;
    for (j = 0; j < Y; ++j)
    {
        for (i = 0; i < X; ++i)
        {
            if(Minefield[i][j]==' ')
            Magic(i+1,j+1);
        }
    }
}