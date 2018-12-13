// this game is free for anyone. if you find this helpful, please, in gratitude help me when   //  i put my posts on go4expert thanks :) enjoy........
// for more info read the manual of minesweeper in windows, its quite similar.
// the mines placed in this game are randomly generated.
// please modify the code anyway you wish and let me know of any bugs.. :)
// printmatrix() is a function borrowed from elsewhere but it just prints the array. 

#include<stdio.h>  // interger to pointer without cast PROBLEM....
#include<stdlib.h> // SOLUTION :  whenever using string the data type  
                  // of the array must be char

void welcome();
void rand_mines(char msweep[12][12]);
void printmatrix(char msweep[12][12],int r,char user_chart[12][12]);
int process(char msweep[12][12],int r,int c,char user_chart[12][12]);

int main()

{                    // size of array is 10,array starts from 1 to 11

char msweep[12][12] = {{'0'}};      
int i,r,c;   
char user_chart[12][12] = {{'0'}};

// welcome();   
    
 rand_mines(msweep);  

// printmatrix(msweep,12,user_chart);  // note grid from 1 to 11  
  
  printf("Enter your location(ONLY 1 - 11) on the minefield x,y\n");
  scanf("%d%d",&r,&c);
 
              printmatrix(msweep,12,user_chart);  
 
 i = process(msweep,r,c,user_chart); //returns 1 or 0,1 is notmine 0 = mine
  
     
  while(i == 1)     
   {
     printf("Lucky BRAT, live on for another step\n");      
     printf(" %c Surrounding MINEs\n\n",msweep[r][c]);
     
     printmatrix(msweep,12,user_chart); 
     
     printf("enter next move...(ONLY 1 - 11) ");
     scanf("%d%d",&r,&c);
     i=0; 
     
     i = process(msweep,r,c,user_chart);    
   
   
   }  

  if(i==0)
   printf("Game OVER, ta ta. you stepped on a MINE !!\n");

return 0;    
    
}

void welcome()
{

char op; // opereation

 printf("Welcome to MINESWEEPER in C >>.....\n");

 printf("Enter <<\n");
 printf("         i for instructions\n");
 printf("         any other key to enter game\n");
 scanf("%c",&op);

 if(op == 'i')
  {
   printf("OH DEAR, what a shock you are unfortunatly in the midst of a "); printf("mine field.\n");    
  printf("Enter the coordinates of the x and y plane between 1 to 11\n");   
   printf("Are you destined to DIE or live ?\n");
   printf("HA ha ha hah, GOOD LUCK\n\n");
  
  }
else
 return;    
}

void rand_mines(char msweep[12][12])

{
    
int r,c,m;

 //srand(12);   
 
 for(m=0;m<20;m++) // plant 20 rand mines(m
     
  {
   r = rand() % 13; // this is mine planting     
                    // so can be at the edges aswell
   c = rand() % 13; // so 0 to 13 is APPROPRIATE.
    
   
   msweep[r][c] = '9'; 
  printf("%d %d \n",r,c);
  
  }  
    
return;

}

void printmatrix(char msweep[][12],int r,char user_chart[12][12])
{
    
int i,j;    
 
printf("   .-.-.-.-.-.-.-.-.-.-.-.\n");

 for(i=1;i<r;i++)
  {
   printf("./.");

   for(j=1;j<12;j++) //printing 1 to 11    
    {
     printf("%c ",user_chart[i][j]);//to refer to mines use msweep[i][j]    
    } 
   
   printf(".\\.");
   
   printf("\n");   
  
  }

printf(".-.-.-.-.-.-.-.-.-.-.-.-.\n\n");

return;    
}

int process(char msweep[12][12],int r,int c,char user_chart[12][12])
{
    
 int i=r,j=c,b=0,k;    
 char C;

 if(msweep[r][c] == '9')   
 {  k=0;
   return k;
 }
 else
  {
   if(msweep[i-1][j-1] == '9')    
    b++;  
   if(msweep[i-1][j] == '9')    
    b++;  
   if(msweep[i-1][j+1] == '9')    
    b++;  
   if(msweep[i][j-1] == '9')    
    b++;  
   if(msweep[i][j+1] == '9')    
    b++;  
   if(msweep[i+1][j-1] == '9')    
    b++;  
   if(msweep[i+1][j] == '9')    
    b++;  
   if(msweep[i+1][j+1] == '9')    
    b++;  
  
  C = (char)(((int)'0')+b); // to covert int to char;

   msweep[r][c] = C;
   user_chart[r][c] = C;
  
  }
    
 return 1;  
    
}