#include <iostream>
using namespace std;
class stack_arr
{
public:
    int stackk[100];
    int top = -1;
    void push(int x)
    {
        if (top == 99)
        {
            cerr << "stack overflow";
        }
        else
        {
            top++;
            stackk[top] = x;
        }
    }
    void printit()
    {
        for (int i = 0; i < top + 1; i++)
        {
            std::cout << stackk[i] << ", ";
        }
    }
    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
        {
            std::cerr << "stack is empty";
        }
    }
    int Top()
    {
        if (top != -1)
        {
            return stackk[top];
        }
        else
        {
            std::cerr << "stack is empty";
        }
    }
    int size()
    {
        return top + 1;
    }
};
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

class stack_LL
{
public:
    node *top;
    int n = 0;
    stack_LL()
    {
        top = nullptr;
    }
    void push(int x)
    {
        if (top == nullptr)
        {
            top = new node(x);
            n++;
        }
        else
        {
            node *newnode = new node(x);
            newnode->next = top;
            top = newnode;
            n++;
        }
    }
    void printit()
    {
        node *current = top;
        while (current != nullptr)
        {
            cout << current->val << ", ";
            current = current->next;
        }
    }
    int pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        else if (n == 1)
        {
            node *temp = top;
            top = nullptr;
            int topdata=temp->val;
            delete temp;
            n=0;
            return topdata;
        }
        else
        {
            node *temp = top;
            int topdata=temp->val;
            top = top->next;
            delete temp;
            n--;
            return topdata;
        }
    }
    int peek()
    {
        return top->val;
    }
    int size()
    {
        return n;
    }
    bool isempty(){
        if(top==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
};

class queue{
    
};

int main()
{
    stack_LL a;
    a.push(0);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(3);
    a.printit();
    cout << "\n\n"
         << a.peek();
    ;

    return 0;
}