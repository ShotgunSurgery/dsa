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
    bool hasCycle(ListNode *head)
    {
        if(!head || !head->next) return false;  
        ListNode *Tortoise = head;
        ListNode *Hare = head;
        while (Hare && Hare->next)
        {
            Tortoise = Tortoise->next;
            Hare = Hare->next->next;
            if (Tortoise == Hare)
                return 1;
        }
        return 0;
    };
};

int
main()
{
}