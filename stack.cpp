#include<iostream>
using namespace std;

template<class T>
class Stack
{
public:
    int nextIndex, capacity;
    T* arr;

    Stack();
    Stack(int siz);
    void push(T value);
    void pop();
    int top();
    int size(){return nextIndex;}
    bool isEmpty(){return (nextIndex == 0);}
   
};

void print(Stack<int> s)
{
    if(s.isEmpty())
        return;
    cout<<s.top()<<" ";
    s.pop();
    cout<<endl;
    print(s);
}


int main()
{
    Stack<int>s(4);

    cout<<"Size: "<<s.size()<<" Capacity: "<<s.capacity<<endl;

    cout<<"Stack push:\n";
    s.push(10);
    s.push(12);
    s.push(3);
    s.push(45);
    s.push(22);
    s.push(34);
    
    cout<<"Size: "<<s.size()<<" Capacity: "<<s.capacity<<endl;

    //print(s);

    cout<<"\nStack pop:\n";
    while(!s.isEmpty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
    cout<<"Size: "<<s.size()<<" Capacity: "<<s.capacity<<endl;

    cout<<s.top()<<endl;
    s.pop(); 

}

template<class T>
Stack<T>::Stack()
{
    nextIndex = 0;
    capacity = 10;
    arr = new T[10]();
}

template<class T>
Stack<T>::Stack(int siz)
{
    if(siz < 1)
    {
        cout<<"Invalid size"<<endl;
        Stack();
        return;
    }
        nextIndex = 0;
        capacity = siz;
        arr = new T[capacity]();
}

template<class T>
int Stack<T>::top()
{
    if(isEmpty())
    {
        cout<<"Stack is empty!"<<endl;
        return -1;
    }
    else
        return arr[nextIndex];
}

template<class T>
void Stack<T>::push(T value)
{
    if(nextIndex == capacity)
        {
            capacity *= 2;
            T* newArr = new T[capacity]();
            for(int i=0;i<=nextIndex;i++)
                newArr[i] = arr[i];
            delete arr;
            arr = newArr;
        }
    arr[++nextIndex]= value;
    cout<<value<<endl;
    
}

template<class T>
void Stack<T>::pop()
{
    if(nextIndex==0)
        cout<<"Stack is empty!\n";
    else
        nextIndex--;
}
