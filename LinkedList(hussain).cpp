#include<iostream>
using namespace std;

template <class T>
class LinkedList{
    
    class Node{
        public:
        T data;
        Node *next;

        Node(T item){
            data = item;
            next = NULL;
        }
    };
    // Node *head, *tail;
    // int size;

    public:
        Node *head, *tail;
        int size;
        LinkedList();

        void addFirst(T);
        void addLast(T);
        void addPos(int, T);//pos, item
        void addAfter(T, T);//key, item
        void addBefore(T, T);//key, item

        T removeFirst();
        T removeLast();
        T removePos(int);
        void removeKey(T);
        void clear(); //removes all nodes

        void display();
        bool isEmpty();
    
};

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
void LinkedList<T>::addBefore(T key, T item){
    if(isEmpty()){
        cout << "List is empty\n";
        return;
    }
    Node *node = new Node(item);
    Node *p = head;
    if(p->data == key){
        addFirst(item);
        return;
    }
    while(p->next != NULL){
        if(p->next->data == key){
            node->next = p->next;
            p->next = node;
            size++;
            return;
        }
        p = p->next;
    }
    cout << "The given key does not exist\n";
}

template <class T>
void LinkedList<T>::addAfter(T key, T item){
    if(isEmpty()){
        cout << "List is empty\n";
        return;
    }
    Node *node = new Node(item);
    Node *p = head;
    while(p != NULL){
        if(p->data == key){
            node->next = p->next;
            p->next = node;
            if(node->next == NULL)
                tail = node;
            size++;
            return;
        }
        p = p->next;
    }
    cout << "The given key does not exist\n";
}

template <class T>
void LinkedList<T>::addPos(int pos, T item){
    if(isEmpty()){
        cout << "List is empty\n";
        return;
    }
    if(pos > size || pos < 0){
        cout << "Invalid position OR position does not exist\n";
        return;
    }
    if(pos == 0){
        addFirst(item);
        return;
    }
    if(pos == size){
        addLast(item);
        return;
    }
    Node *node = new Node(item);
    Node *p = head;
    for(int count = 1; true; count++){ //no condition needed
        if(count == pos){
            node->next = p->next;
            p->next = node;
            size++;
            return;
        }
        p = p->next;
    }
    /* (if you don't have size variable)
    //OR pos--;
    while(p != NULL && --pos){ //OR pos != 0
        p = p->next; //OR pos--
    }
    
    if(pos == 0){
        node->next = p->next;
        p->next = node;
    }else
        cout << "Pos does not exist"; */
}

template <class T>
void LinkedList<T>::addFirst(T item){
    Node *node = new Node(item);
    if(isEmpty()){
        head = node;
        tail = head;
    }
    else{
        node->next = head;
        head = node;
    }
    size++;
}

template <class T>
void LinkedList<T>::addLast(T item){
    Node *node = new Node(item);
    if(isEmpty()){
        head = node;
        tail = node;
    }
    else{
        tail->next = node;
        tail = tail->next; 
        /*(if tail not used)
        Node *i = head;
        while(i->next != NULL)
            i = i->next;
        
        i->next = node;*/
    }
    size++;
}

template <class T>
T LinkedList<T>::removePos(int pos){
    if(isEmpty()){
        cout << "Cannot remove! List is empty\n";
        return -1;
    }
    if(pos < 0 || pos >= size){
        cout << "Invalid position OR position does not exist\n";
        return -1;
    }
    if(pos == 0)
        return removeFirst();
    
    if(pos == size - 1)
        return removeLast();

    Node *p = head; Node *q;
    for(int count = 1; true; count++){ //no condition needed
        q = p;
        p = p->next;
        if(count == pos){
            q->next = p->next;
            T data = p->data;
            delete p;
            size--;
            return data;
        }
    }

    
}

template <class T>
void LinkedList<T>::removeKey(T key){
    if(isEmpty()){
        cout << "Cannot remove! List is empty\n";
        return;
    }
    Node *p = head;
    if(p->data == key){
        removeFirst();
        return;
    }
    while(p->next != NULL && p->next->data != key)
        p = p->next;
    
    if(p->next == NULL)
        cout << "The given data does not exist\n";
    else{ // p->next->data == key
        Node *toDel = p->next;
        if(p->next == tail){
            tail = p;
            p->next = NULL;
        }
        else
            p->next = p->next->next;

        delete toDel;
    }
    size--;
}

template <class T>
T LinkedList<T>::removeFirst(){ //void type might be better
    if(isEmpty()){
        cout << "Cannot remove! List is empty\n";
        return -1;
    }
    Node *p = head;
    T data = p->data;
    if(head == tail){ //OR if(head->next == NULL)
        head = NULL;
        tail = NULL;
    }
    else
        head = head->next;

    delete p;
    size--;
    return data;
}

template <class T>
T LinkedList<T>::removeLast(){
    if(isEmpty()){
        cout << "Cannot remove! List is empty\n";
        return 0; //error
    }
    Node *p = head;
    T data;
    if(head == tail){ //OR if(head->next == NULL)
        removeFirst();
        // data = p->data;
        // head = NULL;
        // tail = NULL;
        // delete p;
    }
    else{
        while(p->next->next != NULL) //OR != tail
            p = p->next;
            
        data = p->next->data;
        tail = p;
        delete(p->next);
    }
    size--;
    return data;
}

template <class T>
void LinkedList<T>::clear(){
    while(!isEmpty()){
        if(!isEmpty())
            cout << "rem : " << head->data << " ";
        removeFirst();
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::display(){
    if(isEmpty())
        cout << "List is empty\n";
    else{
        Node *i = head;
        cout << "\nList : [";
        while(i != NULL){
            cout << i->data << " -> ";
            i = i->next;
        }
        cout << "NULL] (Size : " << size << ")\n";
    }
}

template <class T>
bool LinkedList<T>::isEmpty(){
    if(head == NULL) //OR size == 0
        return true;
    return false;
}

int main(){

    LinkedList<int> list;

    list.removeLast();

    list.addFirst(5);
    list.addFirst(4);
    list.addLast(6);
    list.addLast(7);
    list.addLast(8);
    list.addFirst(3);
    list.addFirst(2);
    list.display();

    list.removePos(5);
    list.display();

    list.addPos(5, -1);
    list.display();

    list.removeKey(6);
    list.display();

    list.removeFirst();
    list.display();

    list.addAfter(8, 10);
    list.display();

    list.addLast(90);
    list.display();

    list.addPos(3, 99);
    list.display();

    list.addBefore(3, 0);
    list.display();

    list.removeKey(99);
    list.display();

    list.clear();
    list.display();
    //cout << list.tail->data << "<-T " << " || " << list.head->data << "<-H ";

    cout << endl;
}