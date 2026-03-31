#include<iostream>
using namespace std;


//队列的实现
//队列数据结构
template <class T>
class quene{
    private:
    T* data;//队列的基地址
    int head;//队列的头下标
    int tail;//队列的尾下标
    int capacity;//队列的容量
    public:
    //构造函数
    quene(int capacity){
        data = new T[capacity];
        if(data == nullptr) {
            cout<<"资源申请失败";
            return;
        }
        head = 0;
        tail = 0;
        this->capacity = capacity;
    }

    //析构函数
    ~quene(){
        delete[] data;
    }

    //元素入队
    void push(T t){
        if((tail + 1) % capacity == head){
            cout<<"队列已满";
            return;
        }
        data[tail] = t;
        tail = (tail + 1) % capacity;

    }

    //元素出队
    void pop () {
       if(head == tail){
        cout<<"队列为空";
        return;
       } 
        head = (head + 1) % capacity;
    }

    //获取头元素
    T get (){
        if(head == tail){
        cout<<"队列为空";
        return T(); //返回默认值，表示队列为空
       } 
      T d = data[head];
      pop(); //出队操作
        
        return  d;
        
    }

    //辅助功能 打印队列元素
    void print(){
        if(head == tail){
            cout<<"队列为空";
            return;
        }
        int i = head;
        while(i != tail){
            cout<<data[i]<<" ";
            i = (i + 1) % capacity;
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