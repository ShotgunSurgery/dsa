#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* create_node(int x) {
    Node* node = new Node;
    node->data = x;
    node->next = nullptr;
    return node;
}

void print_list(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null\n";
}


void insert_node(Node* &head, int pos, int val) {
    Node* new_node = create_node(val);

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != nullptr; ++i) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Position out of bounds.\n";
        return;
    }

    new_node->next = curr->next;
    curr->next = new_node;
}


int main() {
    Node* a = create_node(3);
    Node* b = create_node(4);
    Node* c = create_node(5);
    Node* d = create_node(1);
    Node* e = create_node(9);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Node* head = a;

    cout << "Initial list:\n";
    print_list(head);

    int p, n;
    cout<<"Enter a position to create node: \n";
    cin>>p;
    cout<<"Enter the data in the node: \n";
    cin>>n;

    insert_node(head, p, n);

    print_list(head);
    
    return 0;
}
