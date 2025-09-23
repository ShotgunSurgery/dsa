// when creating a copy of linked list the new pointers should not point to the previous lists memory locations or nodes
// shallow copy is copying a list such that the original and the newly created lists are entangled i.e. the pointers in the newly created list point to the original ones
// deep copy is copying a list such that the next pointers are pointing to the new nodes and not the original ones

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        ListNode *cursor = head;
        ListNode *prev = head;
        curr2 = head->next;
        org = head;

        // interstiching
        while (cursor != nullptr)
        {
            ListNode *newNode;              // create new node
            newNode->value = cursor->value; // cpy val
            newNode->next = prev->next;     // connect to next
            prev->next = newNode;           // connect with previous
        }

        // handling random ptrs
        while (org != nullptr)
        {
            if (org->random == nullptr)
            {
                curr2->random = nullptr;
            }
            else
                curr2->random = org->random->next;
            curr2 = curr->next->next;
            org = org->next->next;
        }

        curr2 = head->next;

        // destiching
        while (curr2->next != null)
        {
            curr2->next = curr2->next->next;
        }
    }
};