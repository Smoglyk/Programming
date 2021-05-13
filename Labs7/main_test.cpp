#include "main.h"
#include <assert.h>
using namespace std;

void Test()
{
    List list;
    assert(list.push_back("G", "P", 7) == 1);
    assert(list.push_back("L", "M", 7) == 0);
    assert(list.push_back("J", "O", 7) == 0);
    vector<Book> b = list.Search_author("G");
    assert(b[0].name == "P");
    assert(list.GetSize() == 3);
    assert(list.ReturnCost() == 21);
    assert(list.pop_front() == 1);
    assert(list.pop_front() == 1);
    assert(list.clear() == 1);
    assert(list.pop_front() == 0);
    assert(list.clear() == 0);
    list.push_back("Pudge", "Mid", 2);
    list.push_back("Lion", "Hard", 4);
    assert(list.Remove("Hard", "Lion") == 1);
    assert(list.Remove("Mid", "Pudge") == 1);
    assert(list.Remove("Mid", "Pudge") == 0);
}



#undef main

int main()
{
    Test();
    cout << "Test done true\n";
    return 0;
}