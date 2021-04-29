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


int Input(int *size)
{
    if( *size >= 0)
        return 1;
    else
    {
        return 0;
    }
}

int main()
{
    Steck steck;
    int size = Correctinput();
    Input(&size);
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
    for (int i = 0; i < size; ++i)
    {
        int j = 0;
        while (j < 3)
        {

            cout << steck[i]->list.get();
            ++j;
        }
        cout << "\n";
    }
    int max = 0;
    int i, index;
    for (i = 0; i < size; i++)
    {
        if (max < steck[i]->list.MaxElement())
        {
            max = steck[i]->list.MaxElement();
            index = i;
        }
    }
    steck[index]->list.print();
    cout << "\n";
    int j;
    max = 0;
    for (j = 0; j < 3; j++)
    {
        if (max < steck[j]->list.MaxSum())
        {
            max = steck[j]->list.MaxSum();
            index = j;
        }
    }
    steck[index]->list.print();
    steck.clear();
    return 0;
}