#include<iostream>
using namespace std;

class Stack
{
    class Node
    {
    public:
        int data;
        Node* next;

        Node(int d)
        {
            data = d;
            next = NULL;
        }
    };

    int size;
    Node* head;
public:
    Stack();
    void push(int d);
    void pop();
    int top();
    int getSize();
    bool isEmpty();
}; 

int main()
{
    Stack s;
    cout<<"Size of stack: "<<s.getSize()<<endl;

    cout<<"\nStack push:\n";
    s.push(10);
    s.push(12);
    s.push(3);
    s.push(8);
    s.push(22);
    s.push(34);
    
    cout<<"\nSize of stack: "<<s.getSize()<<endl;

    cout<<"\nStack pop:\n";
    while(!s.isEmpty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    cout<<"\nSize of stack: "<<s.getSize()<<endl;

}

Stack::Stack()
{
    head = NULL;
    size = 0;
}
void Stack::push(int d)
{
    Node* temp = new Node(d);
    if(isEmpty())
        head = temp;
    else
    {
        temp -> next = head;
        head = temp;
        cout<<d<<endl;
    }
    size++;
}
void Stack::pop()
{
    if(isEmpty()){
        cout<<"Stack is empty!\n";
        return;
    }
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
    size--;
}
int Stack::top()
{
    if(isEmpty())
    {
        cout<<"Stack is empty!";
        return -1;
    }
    return head -> data;
}
int Stack::getSize()
{
    return size;
}
bool Stack::isEmpty()
{
    return size == 0;
}