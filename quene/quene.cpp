#include<iostream>
using namespace std;


//队列的实现
//队列数据结构
template <class T>
class quene{
    private:
    T* base;//队列的基地址
    T* head;//队列的头指针
    T* tail;//队列的尾指针
    int size;
    public:
    //构造函数
    quene(int size){
        base = new T[size];
        if(base == nullptr) {
            cout<<"资源申请失败";
            return;
        }
        head = base;
        tail = base;
    }

    //析构函数
    ~quene(){
        delete[] base;
    }

    //元素入队
    void push(T t){
        if(tail == base + size){
            cout<<"队列已满";
            return;
        }
        *tail = t;
        tail++;

    }

    //元素出队
    void pop () {
       if(head == tail){
        cout<<"队列为空";
        return;
       } 
        head++;
    }

    //获取头元素
    T get (){
        if(head == tail){
        cout<<"队列为空";
        return T(); //返回默认值，表示队列为空
       } 
        T val = *head;
        head++;
        return val;
        
    }

    //辅助功能 打印队列元素
    void print(){
        for(T* p = head; p != tail; p++){
            cout<<*p<<" ";
        }
        cout<<endl;
    }   




};

int main(){
    quene<int> q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"队列元素：";
    q.print();
    cout<<"出队元素："<<q.get()<<endl;
    cout<<"队列元素：";
    q.print();
     return 0;




}