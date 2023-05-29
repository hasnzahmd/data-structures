#include<iostream>
using namespace std;

template <class T>
class CQueue{
    T* arr;
    int front, rear, size;
    public:
        CQueue(int s);
        ~CQueue();

    bool isFull();
    bool isEmpty();
    void enQueue(T item);
    T deQueue();
    void display();
};

template <class T>
CQueue<T>::CQueue(int s){
    if(s <= 0)
        throw invalid_argument("Invalid input for size!");

    front = -1;
    rear = -1;
    size = s;
    arr = new T[s]();

}

template <class T>
CQueue<T>::~CQueue(){
    delete arr;
}

template <class T>
bool CQueue<T>::isFull(){
    if(front == 0 && rear == size - 1 || front == rear + 1)
        return true;
    return false;
}

template <class T>
bool CQueue<T>::isEmpty(){
    if(front == -1)
        return true;
    return false;
}

template <class T>
void CQueue<T>::enQueue(T item){
    if(isFull())
        cout << "Error! Queue is full\n";
    else{
        if(isEmpty())
            front = 0;
        rear = (rear + 1) % size;
        //******OR******
        // if(rear == size -1)
        //     rear = 0;
        // else
        //     rear++;
        //**************
        arr[rear] = item;
        cout << "Item inserted : " << item << "\n";
    }
}

template <class T>
T CQueue<T>::deQueue(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return -1;
    }
    else{
        T temp = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % size;
        
        cout << "Item removed : " << temp << "\n";
        return temp;
    }
}

template <class T>
void CQueue<T>::display(){
    if(isEmpty())
        cout << "Error! Queue is empty\n";
    else{
        cout << "\nFront -> " << front;
        cout << "\narr : ";
        
        //for(int i = 0; i != rear; i = (i + 1) % size)
        int i = front;
        while(i != rear){
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[i];

        cout << "\nRear -> " << rear << "\n\n";
    }
}

int main(){

    CQueue<int> q(5);

    q.deQueue();

    q.enQueue(100);
    q.enQueue(900);
    q.enQueue(500);
    q.enQueue(12);
    q.enQueue(70);

    q.display();

    q.deQueue();
    q.deQueue();
    q.deQueue();

    q.display();

    q.enQueue(23);
    q.enQueue(111);
    q.enQueue(33);
    q.enQueue(2);

    q.display();

    return 0;
}