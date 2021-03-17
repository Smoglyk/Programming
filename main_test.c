#include "main.h"



void test_cheakInput()
{
    assert(cheakInput(-1) == 0);
    assert(cheakInput(2) == 1);   
}


#undef main

int main()
{
	test_cheakInput();
    printf("Test done true");
	return 0;
}