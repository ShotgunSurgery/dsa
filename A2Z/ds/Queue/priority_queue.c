// elements with higher priority are removed first

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int items[MAX_SIZE];
    int size;
} PriorityQueue;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heap ds and heap memory are two different things
// heap ds -> specifically min-heap here i.e. smallest element at the top -> the core functionality of this priority_queue
// i.e. the whole queue can be in any order but the only thing that is garunteed is that the smallest element will be at the top
// IN THIS BY "MESSED BY IT MEANS THAT BECAUSE THE HEAP IN A ARRAY IS ESSENTIALLY A BINARY TREE SO FROM THE OUT IT MIGHT LOOKED MESSED UP LIKE  [2, 3, 15, 5, 4, 45] BUT IT IS A BINARY TREE IN DISGUISE SO IT'S SORTED ACTUALLY"

// heap stored in a array = binary tree where root element is at 0 always -> min heap -> smallest element at 0 and vise-versa
// example -> [2, 3, 15, 5, 4, 45] -> 3, 15 are children of 2 and 5, 4 are children of 3 and 45 is child of 15 and this representatin is possible because of these formulas -
// Parent of node at index i → (i-1)/2
// Left child of node at index i → 2*i + 1
// Right child of node at index i → 2*i + 2

// if the new element is smaller than it's parent then we keep swaping till this condition false
void heapifyUp(PriorityQueue *pq, int index)
{
    // index cause if index = 0 then it's already the top element so expression evaluates to false then
    // (index - 1) / 2-> we find the parent element and compare it to the current element
    if (index && pq->items[(index - 1) / 2] > pq->items[index])
    {
        // as mentioned above we swap here then
        swap(&pq->items[(index - 1) / 2], &pq->items[index]);
        heapifyUp(pq, (index - 1) / 2); // we repeate
    }
}

void enqueue(PriorityQueue *pq, int value)
{
    pq->items[pq->size++] = value;
    heapifyUp(pq, pq->size - 1);
}

int peek(PriorityQueue *pq)
{
    if (!pq->size)
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    return pq->items[0];
}

void heapifyDown(PriorityQueue *pq, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->items[left] < pq->items[smallest])
        smallest = left;

    if (right < pq->size && pq->items[right] < pq->items[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&pq->items[index], &pq->items[smallest]);
        heapifyDown(pq, smallest);
    }
}
// the smallest element if removed
int dequeue(PriorityQueue *pq)
{
    if (!pq->size)
    {
        printf("The Priority Queue is empty!");
        return -1;
    }

    int item = pq->items[0];
    pq->items[0] = pq->items[--pq->size];
    heapifyDown(pq, 0);
    return item;
}

int main()
{
    PriorityQueue pq = {{0}, 0};

    enqueue(&pq, 1);
    enqueue(&pq, 3);
    enqueue(&pq, 7);
    enqueue(&pq, 15);
    enqueue(&pq, 8);
    enqueue(&pq, 9);
    enqueue(&pq, 2);

    printf("The Top Element of the Priority Queue rn is: %d\n", peek(&pq));
    printf("The dequed element is: %d\n", dequeue(&pq));
    printf("The Top Element of the Priority Queue rn is: %d\n", peek(&pq));
    printf("The dequed element is: %d\n", dequeue(&pq));
    printf("The Top Element of the Priority Queue rn is: %d\n", peek(&pq));
    printf("The dequed element is: %d\n", dequeue(&pq));
    printf("The Top Element of the Priority Queue rn is: %d\n", peek(&pq));
    printf("The dequed element is: %d\n", dequeue(&pq));
    printf("The Top Element of the Priority Queue rn is: %d\n", peek(&pq));
    printf("The dequed element is: %d\n", dequeue(&pq));
    printf("The Top Element of the Priority Queue rn is: %d\n", peek(&pq));
    printf("The dequed element is: %d\n", dequeue(&pq));
    printf("The Top Element of the Priority Queue rn is: %d\n", peek(&pq));
    printf("The dequed element is: %d\n", dequeue(&pq));
    printf("The Top Element of the Priority Queue rn is: %d\n", peek(&pq));
}