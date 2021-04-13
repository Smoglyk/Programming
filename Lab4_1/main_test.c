#include "main.h"

void Check_Test()
{
    int i, j, sizeX = 2, sizeY = 8;
    char**Arr = (char**)malloc(sizeX * sizeof(char**));
   for(i = 0; i < sizeX; i++)
   {
       Arr[i] = (char*)malloc(sizeY * sizeof(char));
   }

   assert(Check_Empty(Arr, sizeX, sizeY) == 1);

   for(i = 0; i < sizeX; i++)
   {
       for(j = 0; j < sizeY; j++)
       {
           Arr[i][j] = 'a';
       }
   }
   
   assert(Check_Empty(Arr, sizeX, sizeY) == 0);
   assert(Check(Arr, sizeX, sizeY) == 1);
   
   for (i = 0; i < sizeX; i++)
	{
	    free(Arr[i]);
    }
    free(Arr);
}

#undef main
int main()
{
     Check_Test();
     printf("Test done true");
     return 0;
}