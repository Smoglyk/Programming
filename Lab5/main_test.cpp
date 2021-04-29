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

void test_cheakSteck()
{
    Steck steck;
    int size = 3;
    for (int i = 0; i < size; ++i)
    {
        steck.insert();
    }
    for (int i = 0; i < size; ++i)
    {
        steck[i]->add(i + 1);
        steck[i]->add(i + 2);
        steck[i]->add(i + 3);
    }
    for(int i = 0; i < size; ++i)
    {
        assert(steck[i]->list.MaxElement() == 3+i);
    }
    int j = 0;
    for(int i = 0; i < size; ++i)
    {
        assert(steck[i]->list.MaxSum() == 6 + j);
        j += 3;
    }

}


#undef main

int main() {

    test_cheakInput();
    test_cheakSteck();
    printf("Test done true");
    return 0;

}