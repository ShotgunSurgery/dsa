#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *Tortoise = head;
        ListNode *Hare = head;

        while (Hare && Hare->next)
        {
            Tortoise = Tortoise->next;
            Hare = Hare->next->next;
            // break is used for loops, switch whereas exit is used to terminate entire program
        }
        return Tortoise;
    }
};

int main()
{
}