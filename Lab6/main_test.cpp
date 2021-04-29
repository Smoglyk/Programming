#include "main.h"

void test_checkInput()
{
    int size = 2;
    assert(Check_input(size) == 1);
    size = -1;
    assert(Check_input(size) == 0);

}

void test_checkTree()
{
    Tree<int>* tree = new Tree<int>();
    if(tree == nullptr)
        exit(1);
    assert(tree->isEmpty() == 1);
    tree->add(5, "Pudg");
    tree->add(7, "Axe");
    assert(tree->isEmpty() == 0);
    
}

void test_checkFind()
{
    Tree<int>* tree = new Tree<int>();
    if(tree == nullptr)
        exit(1);
    tree->add(2, "Pudg");
    assert(tree->find(2));
}


#undef main

int main() {

    test_checkInput();
    test_checkTree();
    test_checkFind();
    printf("Test done true");
    return 0;

}