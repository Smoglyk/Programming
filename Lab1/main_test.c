#include "main.h"
#include <stdio.h>

void test_cheakDigital()
{
    assert(checkDigital(-1) == 0);
    assert(checkDigital(1) == 1);   
}


#undef main

int main()
{
	test_cheakDigital();
    printf("All ok");
	return 0;
}