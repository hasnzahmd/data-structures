#include<iostream>
using namespace std;

class LinkedList
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
    
public:
    Node *head, *tail;
    int size;

    LinkedList();
    void insertAtHead(int d);
    void insertAtTail(int d);
    void insertAtPosition(int pos, int d);
    void deleteNode(int pos);
    void print();
    bool isEmpty();
};

int main()
{
    LinkedList list;
    list.print();

    cout<<"Creating list: \n";
    list.insertAtHead(5);
    list.insertAtTail(10);
    list.insertAtTail(15);
    list.insertAtHead(1);
    list.insertAtPosition(3,8);
    list.insertAtPosition(1,-2);
    list.insertAtPosition(6,18);
    list.print();

    cout<<"\nAfter deleting first node:\n";
    list.deleteNode(1);
    list.print();
    
    cout<<"\nAfter deleting last node:\n";
    list.deleteNode(6);
    list.print();

    cout<<"\nAfter deleting middle node:\n";
    list.deleteNode(3);
    list.print();

    cout<<endl;
}


LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedList::insertAtHead(int d)
{
    Node* temp = new Node(d);
    if(isEmpty())
    {
        head = temp;
        tail = head;
    }
    else
    {
        temp -> next = head;
        head = temp;
    }
    size++;
}

void LinkedList::insertAtTail(int d)
{
    Node* temp = new Node(d);
    if(isEmpty())
    {
        head = temp;
        tail = temp;
    }
    else
    {   
        tail -> next = temp;
        tail = tail -> next;
    }
    size++;
}

void LinkedList::insertAtPosition(int pos, int d)
{
    if(isEmpty())
    {
        cout << "List is empty\n";
        return;
    }

    if(pos > size || pos < 0)
    {
        cout << "Invalid position OR position does not exist\n";
        return;
    }  

    if(pos==1)
    {
        insertAtHead(d);
        return;
    }

    if(pos==size)
    {
        insertAtTail(d);
        return;
    }

    Node *temp = new Node(d);
    Node *p = head;
    for(int count = 1; true; count++)
        { //no condition needed
            if(count == pos-1){
                temp->next = p->next;
                p->next = temp;
                size++;
                return;
            }
            p = p->next;
        }
}

void LinkedList::deleteNode(int pos)
{
    if(isEmpty())
    {
        cout << "List is empty\n";
        return;
    }

    if(pos > size || pos < 0)
    {
        cout << "Invalid position OR position does not exist\n";
        return;
    }    

    if(pos==1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        size--;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt=1;
        while(cnt<pos)
        {
            prev = curr;
            curr= curr -> next;
            cnt++;
        }
    
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
    size--;
    }
}

void LinkedList::print()
{
    if(isEmpty())
        cout << "\nList is empty!  [Size: "<<size<<"]\n";
    else
    {
        Node* temp = head;
        cout<<endl;
        while(temp != NULL)
        {
            cout<<temp -> data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL  [Size: "<<size<<"]"<<endl;
    }
}

bool LinkedList::isEmpty()
{
    return head == NULL;
}


