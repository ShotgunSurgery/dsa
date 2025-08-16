// ->top only returns the index of the top element and not 
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
}Stack;

//over here the order of the functions matter if one is used in another then it should be 
//defined above the other 

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

void push(Stack* stack, char n){
    if(ifFull(stack)){
        printf("Stack Overflow\n");
        // here even though the function has void return type still we return nothing below so that the function 
        // returns to where it was called and doesn't execute any furthure code below this 
        return;
    }
    stack->arr[++stack->top] = n;
    printf("Pushed %c onto the stack\n", n);
}

char peek(Stack* stack){
    if(ifEmpty(stack)){
        printf("Stack is Empty\n");
        return -1;
    }
    // whenever something like this -> stack->arr[stack->top] is directly used don't use &
    // why?
    // printf("%c", stack->arr[stack->top]);
    return stack->arr[stack->top];
}

int pop(Stack* stack){
    if(ifEmpty(stack)){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];  // Return the top element, then decrement top
}

// char* infix_to_postfix(char* arr, Stack* stack){
//     for(int i = 0; arr[i] != '\0'; i++){
//         char ch = arr[i];
//         if(isdigit(ch)){
//             // ascii value of 0 is 48, 1 is 49 and so on hence the following 
//             push(&stack, ch - '0');
//         }
//         else if(ch == ' '){
//             continue;
//         }


//     }
// }


int main(){
    Stack stack;
    // & -> is called address of operator used to pass the address of the memory location/ variable
    initilize(&stack);

    int choice = 1;
    while(1){
        printf("Enter the Operation you want to perform: \n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        scanf("%d", &choice);
        char x;
        switch(choice){
            case 1:
            printf("Enter char: ");
            scanf(" %c", &x);
            push(&stack, x);
            break;

            case 2:
            pop(&stack);
            break;

            case 3:
            x = peek(&stack);
            printf("%c\n", x);
            break;

            case 4:
            return 0;
        }
    }
}