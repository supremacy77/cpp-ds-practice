#include<iostream>
using namespace std;

//双向链表节点
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoubleLinkedList{
    public:
    Node* head;
    DoubleLinkedList(){
        head = NULL;
    }
    //在链表末尾插入节点
    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    //在链表头部插入节点
    void insertAtHead(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    //在指定位置插入节点
    void insertAtPosition(int value, int position){
        if(position <= 0){
            insertAtHead(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        int currentPos = 0;
        while(temp != NULL && currentPos < position){
            temp = temp->next;
            currentPos++;
        }
        if(temp == NULL){
            insertAtEnd(value);
            return;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        if(temp->prev != NULL){
            temp->prev->next = newNode;
        } else {
            head = newNode;
        }
        temp->prev = newNode;
    }
    //删除指定值的节点
    void deleteNode(int value){
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == value){
                if(temp->prev != NULL){
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if(temp->next != NULL){
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }
    //头删
    void deleteAtHead(){
        if(head == NULL) return;
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        delete temp;
    }
    //尾删
    void deleteAtEnd(){
        if(head == NULL) return;
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(temp->prev != NULL){
            temp->prev->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
    }
    //显示链表内容  
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    //反向显示链表内容
    void displayReverse(){
        if(head == NULL) return;
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    //析构函数，释放内存
    ~DoubleLinkedList(){
        Node* temp = head;
        while(temp != NULL){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};