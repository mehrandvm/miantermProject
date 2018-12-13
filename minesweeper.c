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
    static int arrX[MineNum], arrY[MineNum];
    int i, n;

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
    printf(ANSI_COLOR_RED "This text is RED!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN "This text is GREEN!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_YELLOW "This text is YELLOW!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_BLUE "This text is BLUE!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_CYAN "This text is CYAN!" ANSI_COLOR_RESET "\n");
    printf("\n");

    while (1)
    {
        printMap();
        scanf("%d", &firstInput);
        scanf("%d", &xUser);
        scanf("%d", &yUser);
        if (firstInput == 1)
        {

            for (i = 0; i < MineNum; i++)
            {
                if (xUser == arrX[i] && yUser == arrY[i])
                {
                    printf("BOOM\n");
                    for (i = 0; i < MineNum; i++)
                    {
                        Minefield[arrX[i]][arrY[i]] = '*';
                    }
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
        printf(ANSI_COLOR_CYAN "%d "ANSI_COLOR_RESET, i);
    }

    printf("\n");

    for (i = 0; i < Y; i++)
    {
        printf(ANSI_COLOR_CYAN" %d "ANSI_COLOR_RESET, i + 1);
        if ((i + 1) / 10 == 0)
            printf(" ");
        for (j = 0; j < X; j++)
        {
            ANSI_COLOR_CYAN;
            
            if(Minefield[i][j]=='P'){
            printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET, Minefield[i][j]);
            }
            else if(Minefield[i][j]=='*'){
            printf(ANSI_COLOR_RED"%c"ANSI_COLOR_RESET, Minefield[i][j]);
            }
            else{
            printf(ANSI_COLOR_BLUE"%c"ANSI_COLOR_RESET, Minefield[i][j]);
            }
            printf("  ");
        }
        putchar('\n');
    }
}
