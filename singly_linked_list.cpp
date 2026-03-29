#include<iostream>
using namespace std;

//1.定义链表节点结构体
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(nullptr) {}

};

//2.定义链表操作类
class LinkedList
{
private:
    ListNode* head;//头节点指针
public:
    LinkedList() : head(nullptr){};
    ~LinkedList();
    //功能1：尾插法插入节点
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        ListNode* cur = head;
        while( cur->next != nullptr) {
            //找到尾节点
            cur = cur->next;
        }
        cur->next = newNode;
    }
    /*头插法
    void addfront(int val){
        ListNode* newnode = new ListNode(val);
        newnode->next = head;
        head = newnode;
    } */
    

    //功能2：删除指定指的第一个节点
    bool deleteNode(int val) {
        if(head == nullptr) return false;
        //特殊情况：删除头节点
        if(head-> val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        ListNode* cur = head;
        while (cur->next != nullptr && cur->next->val != val) {
            cur = cur->next;
        }
        if (cur->next ==nullptr) return false;//未找到
        ListNode* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        return true;
    }


    //功能3：反转链表（双指针法）
     void reverse() {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur!= nullptr) {
            ListNode* next = cur->next;//保存下一个结点
            cur->next = pre;//反转指针
            pre = cur;// 移动pre
            cur = next;//移动cur
        }
        head = pre;//新的头节点是尾结点
     }

     //辅助功能：打印链表
     void printList(){
        ListNode* cur = head;
        while(cur!= nullptr){
            cout << cur->val<<" ";
            cur =cur->next;
        }
        cout<< endl;
     }
};
LinkedList::~LinkedList(){
    ListNode* cur = head;
    while(cur != nullptr){
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
    head = nullptr;
}
//3.测试代码
int main(){
    LinkedList list;
    //测试插入
    list.addAtTail(1);
    list.addAtTail(2);
    list.addAtTail(3);
    list.addAtTail(4);
    cout<<"原链表：";
    list.printList();
    //测试删除
    list.deleteNode(2);
    cout<<"删除2后:";
    list.printList();
    //测试反转
    list.reverse();
    cout << " 反转后:";
    list.printList();
    
    return 0;

}



