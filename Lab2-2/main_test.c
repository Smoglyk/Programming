
#include "main.h"

void test_fact() 
{
    
    assert(fact(5) == 120);
    assert(fact(6) == 720);
    
}

#undef main

int main() {

    test_fact();
    printf("Test done true");
    return 0;

}
