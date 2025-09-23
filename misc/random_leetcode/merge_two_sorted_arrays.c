#include <stdio.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
	
}
int main(){	
	ListNode* node11 = new ListNode(1);
	ListNode* node12 = new ListNode(2);
	ListNode* node13 = new ListNode(4);
	node11->next = node12;
	node12->next = node 13;
	node13->next = nullptr;
	// in the above case we are directly writing node12-> next = node 13 casue we have intialized it like this -> ListNode* node12 = new ListNode(1); or = malloc(sizeof(ListNode); so it's already returning a memory address and hence

	ListNode* node21 = new ListNode(1);
	ListNode* node22 = new ListNode(3);
	ListNode* node23 = new ListNode(4);
	node21->next = node22;
	node22->next = node23;
	node23->next = nullptr;

	

}
