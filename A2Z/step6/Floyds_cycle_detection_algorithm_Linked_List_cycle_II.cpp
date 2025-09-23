#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* Tortoise = head;
        ListNode* Hare = head;

        while(Hare != nullptr && Hare->next != nullptr){
            Tortoise = Tortoise->next;
            Hare = Hare->next->next;
            if(Tortoise == Hare){
                Tortoise = head;
                while(Tortoise != Hare){
                    Tortoise = Tortoise->next;
                    Hare = Hare->next;
                }
                return Hare;
            }   
        }
        return NULL;
    }
};

int main()
{
}