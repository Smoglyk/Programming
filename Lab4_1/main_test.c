#include "main.h"

void Check_Test()
{
    int i, j, sizeX = 2, sizeY = 8;
    char**Arr = (char**)malloc(sizeX * sizeof(char**));
	if(Arr == 0)
		exit(1);
   for(i = 0; i < sizeX; i++)
   {
       Arr[i] = (char*)malloc(sizeY * sizeof(char));
	   if(Arr[i] == 0)
		exit(1);
   }

   assert(Check_Empty(Arr, sizeX) == 1);
   
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
