#include "main.h"
#include <malloc.h>

void Matrix(int ***Cu, int x, int y, int z)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < x; i++)
        {
            for (j = 0; j < y; j++)
            {
                for (k = 0; k < z; k++)
                {
                    Cu[i][j][k] =  rand() % 2;
                    
                }
            }
        }
    
}
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
    int  i = 0, j = 0, k = 0, answer, sizeX = 8, sizeY = 8, sizeZ = 8, msizeX = 4, msizeY = 4, msizeZ = 4;

    int ***Cube = (int***)malloc(sizeX * sizeof(int**));
    for (i = 0; i < sizeX; i++)
	{
        Cube[i] = (int**)malloc(sizeY * sizeof(int*));
        for (j = 0; j < sizeY; i++)
	        Cube[i][j] = (int*)malloc(sizeZ * sizeof(int));
    }


    int ***miniCube = (int***)malloc(msizeX * sizeof(int**));
    for (i = 0; i < msizeX; i++)
	{
        miniCube[i] = (int**)malloc(msizeY * sizeof(int*));
        for (j = 0; j < msizeY; i++)
	        miniCube[i][j] = (int*)malloc(msizeZ * sizeof(int));
    }


    srand(time(NULL));
    printf("Are you want begin? Input 1(yes), 0(no).\n");
    answer =  Correctinput();
    Input01(answer);
    if(answer == 1)
    {
        Matrix(Cube, 8, 8, 8);
        
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

        Matrix(miniCube, 4, 4, 4);
    
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


    for (i = 0; i < sizeX; i++)
	{
        for (j = 0; j < sizeY; i++)
	         free(Cube[i][j]);
    }
    for (i = 0; i < sizeY; i++)
	         free(Cube[i]);
    
    free(Cube);


    for (i = 0; i < sizeX; i++)
	{
        for (j = 0; j < sizeY; i++)
	         free(miniCube[i][j]);
    }
    for (i = 0; i < sizeY; i++)
	         free(miniCube[i]);
    
    free(miniCube);
     
}
