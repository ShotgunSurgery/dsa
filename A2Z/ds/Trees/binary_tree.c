#include <stdio.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int item){
    // when we do struct Node node_name; -> then compiler automatically allocates memory on "stack" this is done 
    // while the function is running but as soon as it ends the stack frame is destroyed so if we return that 
    // we would be returning a dangling pointer but we want something permanant (only be freed when we explicitly
    // free() it) so we must allocate the memory on heap and hence we do the following 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = item;
    temp->left = temp->right = NULL;

    return temp;
}

int main(){
    struct Node* firstNode = newNode(1);
    struct Node* secondNode = newNode(2);
    struct Node* thirdNode = newNode(3);

    // connecting the binary tree
    firstNode->left = secondNode;
    firstNode->right = thirdNode;

    return 0;
}