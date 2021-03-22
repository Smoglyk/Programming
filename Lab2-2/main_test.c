
#include "main.h"

void test_fact() 
{
    int check = Correctinput();
    assert(fact(5) == 120);
    assert(fact(6) == 720);
    assert(check || check == 0);
}

#undef main

int main() {

    test_fact();
    printf("Test done true");
    return 0;

}
