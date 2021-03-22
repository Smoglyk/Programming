#include "main.h"

int Correctinput()
{
    int temp;
    char goodCheck;
    while(!scanf("%d", &temp) || !scanf("%c", &goodCheck) || goodCheck != '\n')
    {
        printf("Wrong input! Please, try again: ");
        fflush(stdin);
    }
    return temp;
}
int Input01(int answer)
{
     if(answer == 0 || answer == 1)
        return 1;
     else 
        return 0;
}
int main()
{
    int  Cube[8][8][8], i = 0, j = 0, k = 0, miniCube[4][4][4], answer;
    srand(time(NULL));
    printf("Are you want begin? Input 1(yes), 0(no).\n");
    answer =  Correctinput();
    Input01(answer);
    if(answer == 1)
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                for (k = 0; k < 8; k++)
                {
                    Cube[i][j][k] =  rand() % 2;
                    
                }
            }
        }
        
    
        for (k = 0; k < 8; k++)
        {
            for (i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    printf("%d\t", Cube[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
        }


        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    miniCube[i][j][k] = 1;
                }
            }
        }
        
        for (k = 0; k < 4; k++)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d\t", miniCube[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
        }
    } 
}