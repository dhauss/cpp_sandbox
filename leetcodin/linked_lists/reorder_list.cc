#include <iostream>

#include "LLUtil.h"

/*
143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/

void reorder_list(LLUtil::ListNode* head);
int main()
{

    LLUtil::ListNode* test_1 = LLUtil::build_ll(1, 4);
    LLUtil::ListNode* test_2 = LLUtil::build_ll(1, 5);
    LLUtil::ListNode* test_3 = LLUtil::build_ll(1, 1);

    reorder_list(test_1);
    reorder_list(test_2);
    reorder_list(test_3);

    std::cout << "Test 1:\n";
    LLUtil::print_ll(test_1);

    std::cout << "\nTest 2:\n";
    LLUtil::print_ll(test_2);

    std::cout << "\nTest 3:\n";
    LLUtil::print_ll(test_3);

    test_1 = LLUtil::destroy_ll(test_1);
    test_2 = LLUtil::destroy_ll(test_2);
    test_3 = LLUtil::destroy_ll(test_3);

    return 0;
}

void reorder_list(LLUtil::ListNode* head)
{
    LLUtil::ListNode* slow = head;
    LLUtil::ListNode* fast = head->next;
    LLUtil::ListNode* prev = nullptr;
    LLUtil::ListNode* second_head = nullptr;

    // find middle of list
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half of list
    fast = nullptr;
    second_head = slow->next;
    slow->next = nullptr;
    slow = nullptr;
    while(second_head)
    {
        LLUtil::ListNode* tmp = second_head->next;
        second_head->next = prev;
        prev = second_head;
        second_head = tmp;
    }

    //reorder list by merging first half with reversed second half
    while(prev && head)
    {
        LLUtil::ListNode* head_nxt = head->next;
        LLUtil::ListNode* prev_nxt = prev->next;
        head->next = prev;
        prev->next = head_nxt;
        head = head_nxt;
        prev = prev_nxt;
    }
}