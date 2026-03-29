#include<iostream>
using namespace std;


//手动实现栈

template <typename T>
class Stack {
    private:
    T* data; // 存储数据的数组
    int topIdx; //栈顶下标
    int capacity; //当前容量
    

    //扩容
    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0;i <= topIdx; ++i){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    public:
    //构造函数
    Stack(int initCap = 4) {
        capacity = initCap;
        data = new T[capacity];
        topIdx = -1;//空栈
    }

    //析构函数
    ~Stack() {
        delete[] data;
    }

    //入栈
    void push(const T& val) {
        if (topIdx == capacity - 1) {
            resize();//满了就扩容
        }
        data[++topIdx] = val;
    }

    //出栈
    void pop() {
        if (empty()){
            cout << "栈空，无法出栈"<<endl;
            return;
        }
        --topIdx;
    }

    //获取栈顶元素
    T top() const {
        if(empty()) {
            cout<<"栈空，无栈顶元素"<<endl;
            return T();
        }
        return data[topIdx];
    }
    //判断是否为空
    bool empty() const {
        return topIdx ==-1;
    }

    //获取元素个数
    int size() const {
        return topIdx + 1;
    }
};

//测试
int main(){
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);//触发扩容

    cout<<"栈顶："<<st.top()<<endl;
    cout<<"大小："<<st.size()<<endl;

    st.pop();
    cout<<"pop后栈顶："<<st.top()<<endl;


    while (!st.empty()) {
        cout << st.top()<<"  ";
        st.pop();
    }
    cout << endl;

    return 0;
}
