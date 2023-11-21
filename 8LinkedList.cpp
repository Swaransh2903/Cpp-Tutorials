// Linked List : type of linear data structure which is a collection of nodes and which can be changed at runtime.

//  Node: collection of data and pointer to the next node.

// LL advanatages: dynamic structure,no memory wastage, deletion is easy

// Types of LL : singly,doubly,circular, circular doubly

// 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};
void InsertAtHead(Node* &head,int d)
{
    Node* temp=new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node* &tail,int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail=tail->next;
}
void InsertAtPosition(Node* &tail,Node* &head,int position,int d)
{
    // insert at start
    if(position==1)
    {
        InsertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    // inserting at last position
    if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}
void deleteNode(int position,Node* &head)
{
    // deleting first node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    InsertAtHead(head,12);
    InsertAtHead(head,15);
        InsertAtTail(tail,16)
    return 0;

}