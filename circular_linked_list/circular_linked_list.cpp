#include<iostream>
using namespace std;    
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }
};
class CircularLinkedList{
    public:
    Node* head;
    CircularLinkedList(){
        head=NULL;
    }
    void insertAtEnd(int value){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=newNode;
            newNode->next=head;
            newNode->prev=head;
        }
        else{
            Node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
            newNode->next=head;
            head->prev=newNode;
        }
    }
    void display(){
        if(head==NULL){
            cout<<"List is empty."<<endl;
            return;
        }
        Node* temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
    void deleteNode(int value){
        if(head==NULL){
            cout<<"List is empty."<<endl;
            return;
        }
        Node* temp=head;
        while(temp->data!=value){
            temp=temp->next;
            if(temp==head){
                cout<<"Value not found in the list."<<endl;
                return;
            }
        }
        if(temp->next==temp){
            head=NULL;
        }
        else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            if(temp==head){
                head=temp->next;
            }
        }
        delete temp;
    }
};