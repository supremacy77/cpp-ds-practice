#include<iostream>
using namespace std;

template<typename T>
class Deque {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
public:
    Deque(int size) {
        arr = new T[size];
        capacity = size;
        front = -1;
        rear = 0;
    }       
    ~Deque() {
        delete[] arr;
    }
    void insertFront(T key) {
        if ((front == 0 && rear == capacity - 1) || (front == rear + 1)) {
            cout << "Overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front = front - 1;
        }
        arr[front] = key;   
    }
    void insertRear(T key) {
        if ((front == 0 && rear == capacity - 1) || (front == rear + 1)) {
            cout << "Overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        arr[rear] = key;
    }
    void deleteFront() {
        if (front == -1) {
            cout << "Underflow" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) { 
            front = 0;
        } else {
            front = front + 1;
        }
    }
    void deleteRear() {
        if (front == -1) {
            cout << "Underflow" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear = rear - 1;
        }
    }
    T getFront() {
        if (front == -1) {
            cout << "Underflow" << endl;
            return -1;
        }
        return arr[front];
    }
    T getRear() {
        if (front == -1) {
            cout << "Underflow" << endl;
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return ((front == 0 && rear == capacity - 1) || (front == rear + 1));
    }
};  