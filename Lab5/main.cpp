#include <iostream>
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
class List_queue
{
public:
    int data;
    List_queue* Npoint;
    List_queue* Ppoint;
    List_queue(int data, List_queue* Npoint = nullptr) : data(data), Npoint(Npoint) {}
};

class Queue
{
public:
    Queue() {};
    List_queue* head = nullptr;
    List_queue* tail = nullptr;
    void insert(int data)
    {
        List_queue* current = new List_queue(data, head);
        if (current == 0)
            exit(1);
        if (head == nullptr)
        {
            head = tail = current;
        }
        else
        {
            List_queue* c = current->Npoint;
            c->Ppoint = current;
            head = current;
        }
    }
    void print()
    {
        List_queue* current = head;
        while (current != nullptr)
        {
            cout << current->data;
            current = current->Npoint;
        }
    }
    int get()
    {
        List_queue* last = tail;
        tail = tail->Ppoint;
        //tail->Npoint = nullptr;
        return last->data;
    };
    void clear()
    {
        while (head != nullptr)
        {
            List_queue* kill = head;
            head = head->Npoint;
            //head->Ppoint = nullptr;
            delete kill;
        }
    }
    int MaxSum()
    {
        List_queue* current = head;
        int max = 0;
        while (current != nullptr)
        {
            max += current->data;
            current = current->Npoint;
        }
        return max;
    }
    int MaxElement()
    {
        List_queue* current = head;
        int max = 0;
        while (current != nullptr)
        {
            if (max < current->data)
                max = current->data;
            current = current->Npoint;
        }
        return max;
    }
    ~Queue()
    {
        clear();
    }

};

class List_steck
{
public:
    Queue list;
    List_steck* Npoint;
    List_steck(List_steck* Npoint = nullptr) : Npoint(Npoint) {}
    void add(int data)
    {
        list.insert(data);
    }
};

class Steck
{
public:
    Steck() {};
    List_steck* head = nullptr;

    void insert()
    {
        List_steck* current = new List_steck(head);
        if (current == 0)
            exit(1);
        head = current;
    }
    List_steck* get()
    {
        List_steck* first = head;
        head = head->Npoint;
        return first;
    }
    List_steck* operator[](int i)
    {
        List_steck* current = head;
        int counter = 0;
        while (counter != i)
        {
            current = current->Npoint;
            ++counter;
        }
        return current;
    }
    void clear()
    {
        while (head != nullptr)
        {
            List_steck* kill = head;
            head = head->Npoint;
            delete kill;
        }

    }
    ~Steck()
    {
        clear();
    }

};

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