// ring buffer
#include <stdio.h>

#define MAX_SIZE 7

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    return ((rear + 1) % MAX_SIZE == front);
}

int isEmpty(){
    return front == -1;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % MAX_SIZE;
    }

    return data;
}
int enqueue(int data)
{
    if (isFull())
    {
        printf("The Queue overflowed!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Element %d inserted\n", data);
}

void display(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while(i != rear){
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Dequeued element: %d\n", dequeue());
    display();

    return 0;
}