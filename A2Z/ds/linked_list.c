// linked lists do not store nodes in contigeous memory locations like arrays 
// |data|ptr| -> |data|ptr| -> |data|null|
#include <stdio.h>

// address of the 'structure' and the first element of structure is the same, the structure is nothing but 
// contigeous memory locations if second element is to be accessed offset by sizeof(int) to get next to get
// first element offset by sizeof 0
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    // identifiers -> user defined names etc given to variables 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(!newNode){
        printf("Memory allocation failed!\n");
        // return only just ends the function but not allowed here 
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    // if a var is declared in this function then it's destroyed after fxn ends so &var cannot be returned cause it would 
    // be a dangling pointer we can in that case either return var a copy of it or allocate memory to it 
    return newNode; // here we return the address of the structure 

    // should I return &newNode or newNode ???
    // ans -> we return newNode cause newNode is already a pointer to the struct (see malloc) which is also 
    // the expected return type but returning &newNode we would be returning the 'address of newNode' itself
    // i.e. A POINTER TO A POINTER
}

// here **headRed is a pointer -> to a pointer head which points to -> the struct in the function we would directly change 
// the head pointer -------------------^ but if we only pass head then we would be making a copy of head and chaning 
// it which would make no diffrence 
void insertAtBegining(struct Node** headRef, int data){
    struct Node* newNode = createNode(data);
    // *headRef points to the memory address of the first node so 
    // first set newNode->next as a pointer to the next node 
    newNode->next = *headRef;
    // set the ptr headRef (which always points to the first node in the list) to the address of newNode we just created 
    *headRef = newNode;
}

int main(){


}