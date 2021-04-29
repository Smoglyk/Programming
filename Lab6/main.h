
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

int Check_input(int i);
int Correctinput();

template<typename T>
class Node
{
public:
    Node* left = nullptr;
    Node* right = nullptr;
    T data;
    string str;
    Node(T data, string str, Node* left = nullptr , Node* right = nullptr): str(str), data(data), left(left), right(right){}
};

template<typename T>
class Tree
{
public:
    Tree(){}
    ~Tree();
    Node<T>* roof = nullptr;
    int size = 0;
    std::vector<T> v;
    void add(T data, string str);
    void remove(T data);
    Node<T> *find(T data);
    void print(Node<T>* roof);
    void print();
    int GetSize();
    int isEmpty();
    void clear();
    void clear(Node<T>* roof);
    Node<T>* back();
};

template<typename T>
void Tree<T>::clear()
{
    clear(roof);
    roof = nullptr;
}

template<typename T>
void Tree<T>::clear(Node<T>* roof)
{
    if(roof != nullptr)
    {
        clear(roof->left);
        clear(roof->right);
        delete roof;
        cout << "All delete\n";
    }
}

template<typename T>
Node<T>* Tree<T>::back()
{
    return roof;
}

template<typename T>
void Tree<T>::print()
{
    v.clear();
    print(roof);
}

template<typename T>
void Tree<T>::print(Node<T>* roof)
{
    if(roof != nullptr)
    {
        v.push_back(roof->data);
        print(roof->left);
        print(roof->right);
    }
}

template<typename T>
void Tree<T>::add(T data, string str)
{
    if(roof == nullptr)
    {
        Node<T>* current = new Node<T>(data, str);
        roof = current;
        ++size;

    }
    else
    {
        Node<T>* current = roof;
        while(current  && current->data != data)
        {
            if(data < current->data && current->left == nullptr)
            {
                Node<T>* node = new Node<T>(data, str);
                current->left = node;
                current = node;
                ++size;
            }
            else if(data > current->data && current->right == nullptr)
            {
                Node<T>* node = new Node<T>(data, str);
                current->right = node;
                current = node;
                ++size;
                
            }
            if(data < current->data)
            {
                current = current->left;
            }
            else if(data > current->data)
            {
                current = current->right;
            }
        }
    }
}

template<typename T>
void Tree<T>::remove(T data)
{
    Node<T>* current = roof;
    Node<T>* parent = nullptr;
    while(current && current->data != data)
    {
       parent = current;
       if(data > current->data)
           current = current->right;
       else if(data < current->data)
           current = current->left;
    }
    if(!current)
        return;
    if(current->left == nullptr)
    {
        if(parent && parent->left == current)
        {
            parent->left = current->right;
        }
        if(parent && parent->right == current)
        {
            parent->right = current->right;
        }
        if(!isEmpty())
            --size;
        if(current == roof)
            roof = current->right;
        delete current;
        return;
    }
    if(current->right == nullptr)
    {
        if(parent && parent->left == current)
        {
            parent->left = current->left;
        }
        if(parent && parent->right == current)
        {
            parent->right = current->left;
        }
        if(!isEmpty())
            --size;
        if(current == roof)
            roof = current->left;
        delete current;
        return;
    }

    Node<T>* copy = current->right;
    while(copy->left)
    {
        copy = copy->left;
    }
    *current = *copy;
    T value = copy->data;
    remove(value);
}

template<typename T>
int Tree<T>::GetSize()
{
    return size;
}

template<typename T>
int Tree<T>::isEmpty()
{
    if(roof == nullptr)
        return 1;
    else
        return 0;
}

template<typename T>
Node<T>* Tree<T>::find(T data)
{
    Node<T>* current = roof;
    if(current != nullptr)
    {
        while(current)
        {
            if(data == current->data)
                return current;
            else
            {
                if(data > current->data)
                    current = current->right;
                else
                    current = current->left;
            }
        }
    }
    return nullptr;
}

template<typename T>
Tree<T>::~Tree()
{
    clear();
}

