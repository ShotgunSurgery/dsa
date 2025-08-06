// ->top only returns the index of the top element and not 
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
}Stack;

// * -> dereference operator 
void initilize(Stack* stack){
    stack->top = -1;
}

bool isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, int n){
    if(ifFull(stack)){
        printf("Stack Overflow\n");
        // here even though the function has void return type still we return nothing below so that the function 
        // returns to where it was called and doesn't execute any furthure code below this 
        return;
    }
    stack->arr[++stack->top] = n;
    printf("Pushed %d onto the stack\n", n);
}

bool ifFull(Stack* stack){
    return stack->top == MAX_SIZE - 1;
}

int peek(Stack* stack){
    if(ifEmpty(stack)){
        printf("Stack is Empty\n");
        return -1;
    }

    return stack->arr[stack->top];

}

int pop(Stack* stack){
    if(isEmpty(&stack)){
        printf("Stack Underflow\n");
        return -1;
    }
}


int main(){
    Stack stack;
    // & -> is called address of operator used to pass the address of the memory location/ variable
    initilize(&stack);

    push(&stack, 1);
    printf("Now the top element is: %d", peek(&stack));

    push(&stack, 2);
    printf("Now the top element is: %d", peek(&stack));

    push(&stack, 3);
    printf("Now the top element is: %d", peek(&stack));

    while(!isEmpty(&stack)){
        printf("Top element: %d", peek(&stack));
        printf("Popped element: %d", pop(&stack));
    }

}