#include<iostream>
using namespace std;

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

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    Node* temp = head;
    
    if(position==1)
    {
        insertAtHead(head,d);
        return;
    }
    
    int cnt = 1;
    while(cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }
    
    if(temp == NULL)
    {
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, int position)
{
    if(position==1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt=1;
        while(cnt<position)
        {
            prev = curr;
            curr= curr -> next;
            cnt++;
        }
    
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
    }
}


void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    //created new node
    Node* node1 = new Node(10);
    //cout << node1->data <<endl;
    //cout << node1->next <<endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtTail(tail,12);
    print(head);

    insertAtPosition(head,tail,2,33);
    print(head);


    deleteNode(head,2);
    print(head);
}
