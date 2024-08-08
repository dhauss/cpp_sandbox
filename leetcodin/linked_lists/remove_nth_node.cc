#include <iostream>

#include "LLUtil.h"
/*
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

LLUtil::ListNode* remove_nth_from_end(LLUtil::ListNode* head, int n);
int main()
{
    auto test_1 = LLUtil::build_ll(1, 5);
    auto test_2 = LLUtil::build_ll(1, 1);
    auto test_3 = LLUtil::build_ll(1, 2);

    test_1 = remove_nth_from_end(test_1, 2);
    test_2 = remove_nth_from_end(test_2, 1);
    test_3 = remove_nth_from_end(test_3, 1);

    std::cout << "Test 1: \n";
    LLUtil::print_ll(test_1);
    std::cout << "\nTest 2: \n";
    LLUtil::print_ll(test_2);
    std::cout << "\nTest 3: \n";
    LLUtil::print_ll(test_3);
}

LLUtil::ListNode* remove_nth_from_end(LLUtil::ListNode* head, int n)
    {
        LLUtil::ListNode dummy = LLUtil::ListNode(0, head);
        LLUtil::ListNode* back = &dummy;
        LLUtil::ListNode* front = head;

        // set front node to be n spaces ahead of back node. back node is a dummy pointing at head
        while(front && n > 0)
        {
            front = front->next;
            --n;
        }

        // bring both nodes forward until front hits the tail and back->next is the node to be deleted from the list
        while(front)
        {
            front = front->next;
            back = back->next;
        }

        // remove nth node from back of list and delete removed node
        auto to_del = back->next;
        back->next = back->next->next;
        delete to_del;

        // return head
        return dummy.next;
    }