#include "main.h"

int Check_Empty(char **arr,int sizeX)
{
   int i, y;
   if(!arr)
   {
       return 0;
   }
   for(i = 0; i < sizeX; i++)
   {
       if(!arr[i])
       {
           return 0;
       }
   }
   return 1;
}

int Check(char**arr, int sizeX, int sizeY)
{
    int i, y, memory, b = 0;
    for(i = 0; i < sizeX; i++)
    {
        memory = arr[i][0];
        for(y = 1; y < sizeY; y++)
        {
            if(memory  == arr[i][y])
            {
                b = 1;
                for(y = 0; y < sizeY; y++)
                {
                  arr[i][y] -= 32;
                }
                break;
            }
        }
    }
    return b;
}

void Input(char**arr, int sizeX, int sizeY)
{
    int i, y;
    for(i = 0; i < sizeX; i++)
    {
        for(y = 0; y < sizeY; y++)
        {
            printf("%c\t", arr[i][y]);
        }
        printf("\n");
    }
}

int main()
{
   int i, j, sizeX = 2, sizeY = 8;

   char**Arr = (char**)malloc(sizeX * sizeof(char**));
   for(i = 0; i < sizeX; i++)
   {
       Arr[i] = (char*)malloc(sizeY * sizeof(char*));
   }
   Check_Empty(Arr, sizeX);

   for(i = 0; i < sizeX; i++)
   {
       for(j = 0; j < sizeY; j++)
       {
           Arr[i][j] = 'a';
       }
   }

   Input(Arr, sizeX, sizeY);
   
   Check(Arr, sizeX, sizeY);

   Input(Arr, sizeX, sizeY);
  for (i = 0; i < sizeX; i++)
	{
	    free(Arr[i]);
    }
    free(Arr);
}
