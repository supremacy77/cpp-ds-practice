#include<iostream>
using namespace std;


template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedQueue {
private:
    Node<T>* front;//队头指针
    Node<T>* rear;//队尾指针
    int count;//元素个数
public:
    LinkedQueue() : front(nullptr), rear(nullptr), count(0) {}
    ~LinkedQueue() {
        while (front) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (rear) {
            rear->next = newNode;
        }
        rear = newNode;
        if (!front) {               
            front = rear;
        }
        count++;
    }
    void dequeue() {
        if (front) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
            count--;
            if (!front) {
                rear = nullptr;
            }
        }
    }
    T getFront() {
        if (front) {
            return front->data;
        }
        throw runtime_error("Queue is empty");
    }
    bool isEmpty() {
        return count == 0;
    }
    int size() {
        return count; 
    }

    void display() {
        Node<T>* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};      

int main() {
    LinkedQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout << "队列元素 ";
    queue.display();
    cout << "队头元素: " << queue.getFront() << endl;
    queue.dequeue();
    cout << "出队后队列: ";
    queue.display();
    cout << "队列大小: " << queue.size() << endl;
    return 0;
}