// ->top only returns the index of the top element and not 
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
}Stack;

// * -> dereference operator 
void initilize(Stack* stack){
    stack->top = -1;
}

bool ifFull(Stack* stack){
    return stack->top == MAX_SIZE - 1;
}

bool ifEmpty(Stack* stack){
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

// In Cpp it's top(), in Java/Python it's peek();
int peek(Stack* stack){
    if(ifEmpty(stack)){
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// In cpp pop() function only deletes the element from the memory unlike Java/Python where it also returns it 
int pop(Stack* stack){
    if(ifEmpty(stack)){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];  // Return the top element, then decrement top
}

char* infix_to_postfix(char* arr, Stack* stack){
    for(int i = 0; arr[i] != '\0'; i++){
        char ch = arr[i];
        if(isdigit(ch)){
            // ascii value of 0 is 48, 1 is 49 and so on hence the following 
            push(&stack, ch - '0');
        }
        else if(ch == ' '){
            continue;
        }


    }
}


int main(){
    Stack stack;
    // & -> is called address of operator used to pass the address of the memory location/ variable
    initilize(&stack);

    push(&stack, 1);
    // printf("Now the top element is: %d", peek(&stack));

    push(&stack, 2);
    // printf("Now the top element is: %d\n", peek(&stack));

    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 7);
    while(!ifEmpty(&stack)){
        printf("");
    }
    // printf("Now the top element is: %d\n", peek(&stack));

    printf("Enter a Infix string: ");
    char arr[10];
    scanf("%s", arr);
    char output[10] = infix_to_postfix(&arr, &stack);
    // for(int i = 0; i < 10; i++){
    //     scanf("%c", arr[i]);
    // }


    // while(!ifEmpty(&stack)){
    //     printf("Top element: %d\n", peek(&stack));
    //     printf("Popped element: %d\n", pop(&stack));
    // }

    // int choice = 1;
    // while(choice == 1){
    //     printf("Select an Operation: \n1. Push \n2. Pop \n3.Peek \n4.Exit");
    //     scanf("%d", &choice);
    //     switch(choice){
    //         case 1: 
    //         int x;
    //         printf("Enter the element to push: ");
    //         scanf("%d", &x);
    //     }

}