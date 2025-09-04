// linked lists do not store nodes in contigeous memory locations like arrays
// |data|ptr| -> |data|ptr| -> |data|null|
#include <stdio.h>
#include <stdlib.h>

// address of the 'structure' and the first element of structure is the same, the structure is nothing but
// contigeous memory locations if second element is to be accessed offset by sizeof(int) to get next to get
// first element offset by sizeof 0
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

struct Node *createNode(int data)
{
    // identifiers -> user defined names etc given to variables
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (!newNode)
    {
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
void insertAtBegining(struct Node **headRef, int data)
{
    struct Node *newNode = createNode(data);
    // *headRef points to the memory address of the first node so
    // first set newNode->next as a pointer to the next node
    newNode->next = *headRef;
    // set the ptr headRef (which always points to the first node in the list) to the address of newNode we just created
    *headRef = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node **head, int data, int position)
{
    Node *newNode = createNode(data);

    if (position == 0)
    {
        insertAtBegining(head, data);
        return;
    }

    Node *temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromFirst(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteFromEnd(Node** head){
    // in case list is empty
    if(*head == NULL){
        printf("List is empty!");
        return;
    }

    // in case only one element in list 
    Node* temp = *head;
    if(temp->next == NULL){
        free(temp);
        *head = NULL;
        return;
    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteFromPosition(Node** head, int position){
    if(*head == NULL){
        printf("List is empty!\n");
        return;
    }

    Node* temp = *head;
    if(position = 0){
        deleteFromFirst(head);
        return;
    }

    for(int i = 0; temp != NULL && i < position - 1; i++){
        temp = temp->next;
    }

    if(temp == NULL  || temp->next == NULL){
        printf("Position out of range\n");
    }

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
};

int main()
{
    struct Node *head = NULL;

    insertAtBegining(&head, 10);
    print(head);

    insertAtEnd(&head, 20);
    print(head);

    insertAtBegining(&head, 30);
    print(head);

    insertAtPosition(&head, 50, 2);
    print(head);

    deleteFromFirst(&head);
    print(head);

    deleteFromEnd(&head);
    print(head);

    deleteFromPosition(&head, 1);
    print(head);

    return 0;
}