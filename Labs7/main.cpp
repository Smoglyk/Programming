#include "main.h"
#include <stdio.h>
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


int main()
{
    List list;

    cout << "Add(1), find(2), Remove(3), Get size(4), get all cost(5), clear(6), get last(7), exite(0)\n";
    while(1)
    {
        int i = Correctinput();
        switch(i)
        {
            case 1:
            {
                cout << "Add aouthor, name, cost\n";
                string author, name;
                cin >> author;
                cin >> name;
                int cost = Correctinput();
                list.push_back(author, name, cost);
                break;
            }
            case 2:
            {
                cout << "Input athor\n";
                string author;
                cin >> author;
                vector<Book> b = list.Search_author(author);
                for(int i = 0; i < list.GetSize(); i++)
                {
                    cout << b[i].author << b[i].name;
                }
                break;
            }
            case 3:
            {
                cout << "Input name and author\n";
                string name, author;
                cin >> name;
                cin >> author;
                list.Remove(name, author);
                cout << "Clear done\n";
                break;
            }
            case 4:
            {
                cout << "Couter:\n";
                cout << list.GetSize();
                break;
            }
            case 5:
            {
                cout << "All cost book: \n";
                cout << list.ReturnCost() << "\n";
                break;
            }
            case 6:
            {
                list.clear();
                break;
            }
            case 7:
            {
                list.pop_front();
                
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
}
