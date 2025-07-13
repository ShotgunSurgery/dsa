#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node
{
    //	 we only need a empty pointer to store the memory location but the datatype it points to should be Node hence below
    struct Node* prev;
    int data;
    struct Node* next;
};

Node* create_node(int x)
{
    // Node* node = (Node*) malloc(sizeof(Node));
    Node* node = new Node;
    
    if(!node){
        cout<<"Failed memory allocation";
        exit(1);
    }
    
    node->prev = nullptr;
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
    // c->next = a;
    
    // a->prev = c;
    b->prev = a;
    c->prev = b;

    // cout<<a->data<<'\n'<<b->data<<'\n'<<c->data<<'\n';

    // traversing a linked list
    
    Node* current_node = a;
    cout<<"hello, world!";

    while(current_node){
	cout<<current_node->data<<'\n';
	current_node = current_node->next;
    }

    // freeing up space 
    delete a;
    delete b;
    delete c;

    return 0;



}
