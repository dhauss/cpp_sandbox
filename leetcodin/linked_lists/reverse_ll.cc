#include <cstdint>
#include <iostream>
#include "LLUtil.h"

/*
206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

LLUtil::ListNode* reverse_list_iter(LLUtil::ListNode* head);
LLUtil::ListNode* reverse_list_rec(LLUtil::ListNode* head);
void test_solutions(LLUtil::ListNode* test);

int main()
{
    LLUtil::ListNode* test_1 = LLUtil::build_ll(1, 5);
    LLUtil::ListNode* test_2 = LLUtil::build_ll(1, 2);
    LLUtil::ListNode* test_3 = LLUtil::build_ll(0, 0);
    LLUtil::ListNode* test_4 = nullptr;

    test_solutions(test_1);
    test_solutions(test_2);
    test_solutions(test_3);
    test_solutions(test_4);

    test_1 = LLUtil::destroy_ll(test_1);
    test_2 = LLUtil::destroy_ll(test_2);
    test_3 = LLUtil::destroy_ll(test_3);
    test_4 = LLUtil::destroy_ll(test_4);

    return 0;
}


LLUtil::ListNode* reverse_list_iter(LLUtil::ListNode* node)
{
    LLUtil::ListNode* cur_prev = nullptr;
    while(node)
    {
        LLUtil::ListNode* temp_node = node;
        node = node->next;
        temp_node->next = cur_prev;
        cur_prev = temp_node;
    }

    return cur_prev;
}

LLUtil::ListNode* reverse_list_rec(LLUtil::ListNode* node)
{
    if(!node || !node->next)
    {
        return node;
    }

    LLUtil::ListNode* head = reverse_list_rec(node->next);
    node->next->next = node;
    node->next = nullptr;

    return head;
}

void test_solutions(LLUtil::ListNode* head)
{
    // helper function to test iterative and recursive solutions
    std::cout << "Original Array\n";
    LLUtil::print_ll(head);

    std::cout << "Reversed Array (iterative)\n";
    head = reverse_list_iter(head);
    LLUtil::print_ll(head);

    std::cout << "Reversed Once More! (recursive)\n";
    head = reverse_list_rec(head);
    LLUtil::print_ll(head);
}