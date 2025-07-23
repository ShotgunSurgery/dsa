#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
};

Node* create_node(int x)
{
    Node* node = (Node*) malloc(sizeof(Node));
    
    if(!node){
        cout<<"Failed memory allocation";
        exit(1);
    }

    node->data = x;
    node->next = nullptr;

    return node;
};

int main()
{
    int x = 3, y = 4, z =5;

    Node* a = create_node(x);
    Node* b = create_node(y);
    Node* c = create_node(z);

    a->next = b;
    b->next = c;
    c->next = nullptr;
    
    cout<<a<<'\n'<<b<<'\n'<<c;

    return 0;



}