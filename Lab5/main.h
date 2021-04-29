#include <iostream>
#include <assert.h>
int Correctinput();
int Input(int *size);


using namespace std;
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
        if(tail != nullptr)
            tail->Npoint = nullptr;
        return last->data;
    };
    void clear()
    {
        while (head != nullptr)
        {
            List_queue* kill = head;
            head = head->Npoint;
            if(tail != nullptr)
                head->Ppoint = nullptr;
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