#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
    public:
        string name, author;
        Book(){}
};  

class Node
{
    public:
        Node *pNext;
        Book data;
        int counter = 0;
        Node(){};
        Node(string author, string name,int counter, Node *pNext = nullptr);
};

class List
{
public:
    List();
    int push_back( string author, string name,int counter);
    int GetSize();
    int ReturnCost();
    int pop_front();
    int clear();
    int Remove(string name, string author);
    ~List();


private:
    
    Node *head;
    int size;
    int cost = 0;
public:
    vector<Book> Search_author(string author);

};

List::~List()
{
}

int List::ReturnCost()
{
    Node* current = head;
    while(current!=nullptr)
    {
        cost += current->counter;
        current = current->pNext;
    }
    return cost;
}
List::List()
{
    size = 0;
    head = nullptr;
}

int List::push_back(string author, string name, int counter)
{
  if (head == nullptr)
  {
      head = new Node(author,name,counter);
      size++;
      return 1;
  }
  else
  {
      Node *current = head;
      while(current->pNext != nullptr)
      {
          current = current->pNext;
      }
      current->pNext = new Node(author,name, counter);
      size++;
      return 0;
  }
  
}

int List::GetSize()
{
    return size;
}

int List::pop_front()
{
    if(head != nullptr)
    {
        Node *kill = head;
        head = head->pNext;
        delete kill;
        size--;
        return 1;
    }
    else 
        return 0;

}

int List::clear()
{
    if(head != nullptr)
    {
         for(int i = 0; i < size; i++)
        {
            Node *kill = head;
            head = head->pNext;
            delete kill;
        }
        size = 0;
        return 1;
    }
    else 
        return 0;
   
}

int List::Remove(string name, string author)
{
   if(head != nullptr)
   {
        Node *current = head;
        int index = -1;
        for(int i = 0; i < size; i++)
        {
            if(current->data.name == name && current->data.author == author)
            {
                index = i;
                break;
            }
            current = current->pNext;
        }

        if(index == 0)
        {
            pop_front();
        }
        else if(index > 0)
        {
            Node *previous = head;

            for(int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }
       
            Node *ToDelete = previous->pNext;
            previous->pNext = ToDelete->pNext;
            delete ToDelete;
            size--;
        }
        return 1;
   }
   else
        return 0;

}


vector<Book> List::Search_author(string author)
{
    vector<Book> arr;
    
    Node *current = head;

    while(current != nullptr)
    {
        if(current->data.author == author)
        {
            arr.push_back(current->data);
        }
        current = current->pNext;
    }
    return arr;
}


Node::Node(string author, string name,int counter, Node *pNext)
{
    data.author = author;
    data.name = name;
    this->counter = counter;
    this->pNext = pNext;
}
