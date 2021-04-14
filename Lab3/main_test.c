#include "main.h"

void test_cheakInput()
{
    int sizeX = 8, sizeY = 8, sizeZ = 8, i, j;
    int ***Cube = (int***)malloc(sizeX * sizeof(int**));
    for (i = 0; i < sizeX; i++)
	{
        Cube[i] = (int**)malloc(sizeY * sizeof(int*));
        for (j = 0; j < sizeY; i++)
	        Cube[i][j] = (int*)malloc(sizeZ * sizeof(int));
    }

    assert(Input01(1) == 1);
    assert(Input01(5) == 0);
    assert(Check_Empty(Cube, sizeX, sizeY, sizeZ) == 1);

    for (i = 0; i < sizeX; i++)
	{
        for (j = 0; j < sizeY; j++)
	         free(Cube[i][j]);
	free(Cube[i]);
    }
    
    free(Cube);
    
}


#undef main

int main() {

    test_cheakInput();
    printf("Test done true");
    return 0;

}
