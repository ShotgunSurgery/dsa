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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *Tortoise = head;
        ListNode *Hare = head;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            Hare = Hare->next;
            count++;
        }

        if (Hare == nullptr)
        {
            return head->next;
        }

        while (Hare->next != NULL)
        {
            Tortoise = Tortoise->next;
            Hare = Hare->next;
            count++;
        }

        if (count == (n - 1))
        {
            head = head->next;
            return head;
        }

        ListNode *temp = Tortoise;
        Tortoise = Tortoise->next;
        ListNode *addr = Tortoise->next;
        temp->next = addr;

        return head;
    }
};

int main()
{
}