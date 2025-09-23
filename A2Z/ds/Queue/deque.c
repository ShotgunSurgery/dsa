#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct deque
{
    int arr[MAX];
    int front;
    int rear;
} Deque;

void initDeque(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq)
{
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq)
{
    return (dq->front == -1);
}

void insertFront(Deque *dq, int key)
{
    if (isFull(dq))
    {
        printf("The Queue is full!\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = MAX - 1;
    }
    else
    {
        dq->front = dq->front - 1;
    }
    dq->arr[dq->front] = key;
}

void insertRear(Deque *dq, int key)
{
    // dq is already a pointer so we pass it directly instead of &dq
    if (isFull(dq))
    {
        printf("The Queue is full!\n");
        return;
    }

    if (dq->front == -1)
    { 
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    {
        dq->rear = 0; 
    }
    else
    {
        dq->rear = dq->rear + 1;
    }
    dq->arr[dq->rear] = key;
}

void printFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("The Dequeue is empty!\n");
        return;
    }
    printf("Front: %d\n", dq->arr[dq->front]);
}

void printRear(Deque *dq)
{
    if (isEmpty(dq) || dq->rear < 0)
    {
        printf("The Dequeue is empty!\n");
        return;
    }
    printf("Rear: %d\n", dq->arr[dq->rear]);
}

void deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        "The Deque is empty!\n";
        return;
    }
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->front = MAX - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->rear = dq->rear + 1;
    }
}

void deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear)
    { // only one element
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = MAX - 1;
    }
    else
    {
        dq->rear = dq->rear - 1;
    }
}

int main()
{
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);

    insertFront(&dq, 30);

    printFront(&dq);
    printRear(&dq);

    deleteFront(&dq);
    printFront(&dq);

    deleteRear(&dq);
    printRear(&dq);

    return 0;
}