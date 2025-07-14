#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;
};

Node* create_node(int x) {
    Node* node = new Node;
    node->prev = nullptr;
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

Node* delete_nth(Node* head, int n) {
    if (!head || n <= 0) return head;

    Node* current = head;
    int count = 1;

    // Traverse to n-th node
    while (current && count < n) {
        current = current->next;
        count++;
    }

    if (!current) return head; // n was out of bounds

    // Case: deleting head
    if (current == head) {
        head = current->next;
        if (head) head->prev = nullptr;
    } else {
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
    }

    delete current;
    return head;
}

int main() {
    Node* a = create_node(3);
    Node* b = create_node(4);
    Node* c = create_node(5);

    a->next = b; b->prev = a;
    b->next = c; c->prev = b;

    Node* head = a;

    cout << "Initial list:\n";
    print_list(head);

    int n;
    cout << "Enter the node number to delete (1-based): ";
    cin >> n;

    head = delete_nth(head, n);

    cout << "After deletion:\n";
    print_list(head);

    // Free remaining memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
