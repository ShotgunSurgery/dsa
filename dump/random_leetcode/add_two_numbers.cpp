#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	// default constructor -> runs when we create a node without passing values, initilizes a linked list with val = 0 and next to nullptr
	ListNode* (): val(0), next(nullptr) {}
	// similalry below constructor runs when the node is initilized with a values
	ListNode* (int x): val(x), next(nullptr) {}
	// similarly below is when we initilize it with both value and pointer to the next variable 
	ListNode* (int x, ListNode* next): val(x), next(next) {} 
	
};

class Solution{
	public:
		ListNode* addTwoNumbers(ListNode* 11, ListNode* 12){

		}
}

int main(){
	

}
