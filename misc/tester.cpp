#include <iostream>
using namespace std;

class Deque {
    int *arr;
    int front, rear, size;

public:
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == size-1) || (front == rear+1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int x) {
        if (isFull()) return;
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = size-1;
        } else {
            front--;
        }
        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) return;
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size-1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) return;
        if (front == rear) {
            front = rear = -1;
        } else if (front == size-1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) return;
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size-1;
        } else {
            rear--;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);

    cout << dq.getFront() << " " << dq.getRear() << endl; // 2 20

    dq.deleteFront();
    dq.deleteRear();

    cout << dq.getFront() << " " << dq.getRear() << endl; // 5 10
}
