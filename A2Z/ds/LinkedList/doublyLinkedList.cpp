#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int inp_data){
        data = inp_data;
        prev = nullptr;
        next = nullptr;
    }
}

int main(){

}