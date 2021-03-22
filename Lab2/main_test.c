#include "main.h"

void test_cheakInput()
{
    assert(cheakInput(-1) == 0);
    assert(cheakInput(2) == 1);  
    assert(round(0.5) == 1.0);
    
}

#undef main

int main()
{
    test_cheakInput();
    printf("Test done true");
	return 0;
}
