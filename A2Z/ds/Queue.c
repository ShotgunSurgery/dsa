// FIFO

#include <stdio.h>

#define MAX_SIZE 7

typedef struct
{
    int items[MAX_SIZE];
    // where does front and end store ?
    int front;
    int back;
} Queue;

void initializeQueue(Queue *q)
{
    q->front = -1;
    q->back = 0;
}

int isEmpty(Queue *q)
{
    return q->front == q->back - 1;
}
int isFull(Queue *q)
{
    return q->back == MAX_SIZE;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("The Queue is Full\n");
        return;
    }

    q->items[q->back] = value;
    q->back++;
}

void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Current Queue: ");
    for (int i = q->front + 1; i < q->back; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void dequeue(Queue* q){
    if(isEmpty(q)){
        printf("The Queue is Empty!\n");
        return;
    }
    q->front++;
}

int peek(Queue* q){
    if(isEmpty(q)){
        printf("The queue is Empty!\n");
        return;
    }
    return q->items[q->front+1];
}

int main()
{
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    printQueue(&q);

    dequeue(&q);
    printQueue(&q);

    printf("The front element rn is: %d\n", peek(&q));

    return 0;

    
}