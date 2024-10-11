/************************************************************************************************
Author: Aarav Subberwal
Date: 10/10/24

While coding this I was actually unaware about that there already exists library for linked lists
in standard template library in C++. But anyway here's my own library for dealing with linked lists
in C++. I tried to replicate the methods usually used in std::vector and made them reusuable for
LL's. In fact to define one you can just pass a vector as a arguement. This was supposed to be a
few hours project which I'm decently proud of. I feel like writing this library is the best way for
a student to learn LL's and be proficient in them.

Stuff to add:
->binary search
->sort
->DLL's
->define the dataype of LL
**************************************************************************************************/
#include <iostream>
#include <vector>
// reverse, search, sort, [] for indexing
class node
{
public:
    node *next = nullptr;
    node *back = nullptr;
    int val;
    node(int data)
    {
        val = data;
    }
    node(int data, node *n)
    {
        val = data;
        next = n;
    }
    node(int data, node *n, node *m)
    {
        val = data;
        next = n;
        back = m;
    }
};

class SLL
{
public:
    node *p_head = nullptr;
    int n;
    SLL(std::vector<int> sll)
    {
        if (sll.empty())
        {
            n = 0;
        }
        else
        {
            n = sll.size();
            p_head = new node(sll[0]);
            node *current = p_head;
            for (int i = 1; i < sll.size(); i++)
            {
                current->next = new node(sll[i]);
                current = current->next;
            }
        }
    }

    ~SLL()
    {
        node *current = p_head;
        while (current != nullptr)
        {
            node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    int at(int index)
    {
        if ((index < n) && (index >= 0))
        {
            node *current = p_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->val;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }

    node atNode(int index)
    {
        if ((index < n) && (index >= 0))
        {
            node *current = p_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return *current;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }

    bool isempty()
    {
        if (n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int index, int data)
    {
        if (n == 0)
        {
            std::cerr << "SLL is empty";
        }
        else
        {
            if (index == 0) // insert at front
            {
                node *newfirstnode = new node(data);
                newfirstnode->next = p_head;
                p_head = newfirstnode;
            }
            else if (index == n) // insert at end
            {
                node *newtail = new node(data);
                node *current = p_head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = newtail;
            }
            else if (index < n) // insert anywhere
            {
                node *newnode = new node(data);
                node *current = p_head;
                node *temp;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                temp = current->next;
                current->next = newnode;
                newnode->next = temp;
            }
            else
            {
                std::cerr << "Index out of bounds";
                exit;
            }
            n++;
        }
    }
    void remove(int index) // remove(index)
    {
        if (index == 0)
        { // remove first element
            if (this->isempty())
            {
                std::cerr << "sll is empty";
            }
            else
            {
                node *temp = p_head;
                p_head = p_head->next;
                delete temp;
            }
        }
        else if (index < n)
        { // remove any element
            node *current = p_head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else
        {
            std::cerr << "index out of bonds";
        }
        n--;
    }
    void printlist()
    {
        node *current = p_head;
        while (current != nullptr)
        {
            std::cout << "-->" << current->val;
            current = current->next;
        }
    }

    int size()
    {
        return n;
    }

    void push_back(int data)
    {
        if (n == 0)
        {
            p_head = new node(data);
        }
        else
        {
            node *newtail = new node(data);
            node *current = p_head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newtail;
        }
        n++;
    }

    void pop_back()
    {
        if (n == 0)
        {
            std::cerr << "SLL is empty";
        }
        else
        {
            node *current = p_head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        n--;
    }

    void merge(SLL other)
    {
        node *temp = p_head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the end of the first list
        }
        temp->next = other.p_head;
        n+=other.size();
    }

    void reverse()
    { // gdbd
        node *current = p_head;
        node *prev = nullptr;
        node *after = nullptr;
        while (current->next != nullptr)
        {
            after = current->next;
            current->next = prev;
            prev = current;
            current = after;
        }
        p_head = prev;
    }

    bool linearsearch(int value)
    {
        node *current = p_head;
        while (current->next != nullptr)
        {
            if (value == current->val)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class DLL
{
public:
    node *p_head = nullptr;
    node *p_tail = nullptr;
    int n;
    DLL(std::vector<int> dll)
    {

        if (dll.empty())
        {
            n = 0;
        }
        else
        {
            p_head = new node(dll[0]);
            n = dll.size();
            node *current = p_head;
            node *temp;
            for (int i = 1; i < n; i++)
            {
                current->next = new node(dll[i]);
                temp = current;
                current = current->next;
                current->back = temp;
            }
            current->next=nullptr;
            p_tail=current;
        }
    }
    ~DLL()
    {
        node *temp = p_head;
        while (temp != nullptr)
        {
            node *nextnode = temp->next;
            delete temp;
            temp = nextnode;
        }
    }
    void printlist()
    {
        node *current = p_head;
        while (current != nullptr)
        {
            std::cout << "<->" << current->val;
            current = current->next;
        }
    }

    int at(int index)
    {
        if ((index < n) && (index >= 0))
        {
            node *current = p_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->val;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }

    node atNode(int index)
    {
        if ((index < n) && (index >= 0))
        {
            node *current = p_head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return *current;
        }
        else
        {
            std::cerr << "Index out of bonds";
        }
    }

    bool isempty()
    {
        if (n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int index, int data)
    {
        if (index == 0)
        {
            node *newnode = new node(data, p_head);
            p_head->back = newnode;
            p_head = newnode;
            p_head->back = nullptr;
        }
        else if (index == n)
        {
            node *newtail = new node(data);
            node *current = p_head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newtail;
        }
        else if (index < n)
        {
            node *newnode =new node(data);
            node *current = p_head;
            for(int i=0;i<index-1;i++){
                current=current->next;
            }
            newnode->next=current->next;
            newnode->back=current;
            current->next->back=newnode;
            current->next=newnode;
        }
        else
        {
            std::cerr << "Index out of bounds";
            exit;
        }
        n++;
    }
    void remove(int index){
        if(index==0){
            node *temp=p_head;
            p_head=p_head->next;
            p_head->back=nullptr;
            delete temp;
        }
        else if(index<n-1){
            node *current = p_head;
            for(int i=0;i<index-1;i++){
                current=current->next;
            }
            node*temp=current->next;
            current->next=current->next->next;
            temp->next->back=current;
            delete temp;
        }
        else if(index==n-1){
            node *temp=p_tail;
            p_tail=p_tail->back;
            p_tail->next=nullptr;
            delete temp;
        }
        else{
            std::cerr<<"Index out of bonds";
            exit;
        }
        n--;
    }
};

int main()
{
    std::vector<int> a = {1, 2, 3, 4};

    DLL b(a);
    b.remove(3);
    b.printlist();
}
