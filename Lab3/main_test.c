#include "main.h"

void test_cheakInput()
{
    assert(Input01(1) == 1);
    assert(Input01(5) == 0);
    
}


#undef main

int main() {

    test_cheakInput();
    printf("Test done true");
    return 0;

}