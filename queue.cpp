#include<iostream>
#include<cmath>
using namespace std;
#define max 6

template<class T>
class Queue
{
private:
    int front,rear;
    T items[max];
public:
    Queue();
    void enQueue(T value);
    T deQueue();
    bool isEmpty();
    bool isFull();
    void display();

};

int main()
{
    Queue<int>q;
    //cout<<q.isEmpty()<<endl;
//    for(int i=0;i<max+1;i++)
//        q.enQueue(rand()%100);
//    cout<<endl;
//    for(int i=0;i<max+1;i++)
//        q.deQueue();

  q.deQueue();

  //enQueue 5 elements
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  // 6th element can't be added to because the queue is full
  q.enQueue(6);

  //q.display();

  //deQueue removes element entered first i.e. 1
  q.deQueue();
  q.enQueue(4);
  //Now we have just 4 elements
  //q.display();


}


template<class T>
Queue<T>::Queue()
{
    front=-1;
    rear=-1;
}
template<class T>
void Queue<T>::enQueue(T value)
{
    if(isFull())
        cout<<"Queue is full!"<<endl;
    else
    {
        if(front==-1)front=0;
        rear++;
        items[rear]=value;
        cout<<"Inserted "<<value<<endl;
    }
}
template<class T>
T Queue<T>::deQueue()
{
    T value;
    if(isEmpty())
    {
        cout<<"Queue is empty!\n";
        return -1;
    }
    else
    {
        value=items[front];
        if(front>=rear)
        {
            front=-1;
            rear=-1;
        }
        else
            front++;
        cout<<"Removed "<<value<<endl;
        return value;
    }
}
template<class T>
bool Queue<T>::isEmpty()
{
    if(front==-1)
        return true;
    else
        return false;
}
template<class T>
bool Queue<T>::isFull()
{
    if(front==0 && rear==max-1)
        return true;
    else
        return false;
}
template<class T>

void Queue<T>::display()
{
    int i;
    if(isEmpty())
        cout<<"\nEmpty Queue\n";
    else
    {
        cout <<endl<<"Front index-> "<<front
        <<"\nItems -> ";
        for (i = front; i <= rear; i++)
        cout<<items[i]<<"  "<<"\nRear index-> "<<rear<<endl;
    }
}
