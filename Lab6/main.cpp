#include <iostream>
#include "main.h"
using namespace std;

int Correctinput()
{
    int temp;
    char goodCheck;
    while(!scanf("%d", &temp) || !scanf("%c", &goodCheck) || goodCheck != '\n')
    {
        printf("Wrong input! Please, try again: ");
        fflush(stdin);
    }
    return temp;
}

int Check_input(int i)
{
    if(i == 1 || i == 2 || i == 3 || i == 4)
        return 1;
    else
        return 0;
}


int main()
{
    Tree<int>* tree = new Tree<int>();
    if(tree == nullptr)
        exit(1);
    cout << "What your want: add(1), remove(2), search(3), exit(0)\n";
    int i;
    
    while(true)
    {
    i = Correctinput();
    Check_input(i);
    switch(i)
    {
        case 1: 
        {
        cout << "Input number and name\n";
        int number;
        string name;
        cin >> number;
        cin >> name;
        tree->add(number, name);
        break;
        }
        case 2:
        {
        int i;
        cin >> i;
        tree->remove(i);
        break;
        }
        case 3:
        {
        int i;
        cin >> i;
        Node<int>* buffer = tree->find(i);
        if(buffer != nullptr)
            cout << "Number: " + to_string(buffer->data) + "; Name: " + buffer->str + "\n";
        else 
            cout << "Nothing\n";
        break;
        }
        case 0:
        {
        exit(1);
        break;
        }
        default:
        break;
    }
    }
    return 0;

}