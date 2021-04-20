#include "main.h"

void test_cheakInput()
{
    int size = 2;
    std::cout << "1";
    assert(Input(&size) == 1);
    std::cout << "2";
     size = -1;
    assert(Input(&size) == 0);
    std::cout << "3";
}


#undef main

int main() {

    test_cheakInput();
    printf("Test done true");
    return 0;

}