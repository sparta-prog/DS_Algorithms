#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *findListNode(ListNode *head, int k)
{
    ListNode *temp = head;

    for (int i = 1; i < k; i++)
    {
        if (temp == nullptr)
            return nullptr;

        temp = temp->next;
    }
    return temp;
}

ListNode* reverseList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *prev = nullptr, *curr = head, *next=nullptr;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode *reverseInKGroup(ListNode *head, int k)
{
    if (head == nullptr || k <= 1)
        return head;

    ListNode *newHead = nullptr, *groupHead = head, *nextListNode, *grpPrev;

    while (groupHead != nullptr)
    {
        ListNode *kthListNode = findListNode(groupHead, k);

        if (kthListNode == nullptr)
        {   
            if(grpPrev)
            {
                grpPrev->next = groupHead;
            }
            break;
        }

        //save the prev
        nextListNode = kthListNode->next;
        kthListNode->next = nullptr;

        ListNode* reversedHead = reverseList(groupHead);

        // identify first group
        if (newHead == nullptr)
        {
            newHead = reversedHead;
        }

        if(grpPrev != nullptr)
        {
            grpPrev->next = reversedHead;
        }
        
        grpPrev = groupHead;

        groupHead = nextListNode;
    }
    return newHead?newHead:head;
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    ListNode *head, *temp = n1;

    head = reverseInKGroup(temp, 2);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}