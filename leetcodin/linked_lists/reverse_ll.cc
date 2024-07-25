#include <cstdint>
#include <iostream>
#include "ll.h"

ListNode* reverse_list_iter(ListNode* head);
ListNode* reverse_list_rec(ListNode* head);
void test_solutions(ListNode* test);

int main()
{
    ListNode* test_1 = LLUtil::build_ll(1, 5);
    ListNode* test_2 = LLUtil::build_ll(1, 2);
    ListNode* test_3 = LLUtil::build_ll(0, 0);
    ListNode* test_4 = nullptr;

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


ListNode* reverse_list_iter(ListNode* node)
{
    ListNode* cur_prev = nullptr;
    while(node)
    {
        ListNode* temp_node = node;
        node = node->next;
        temp_node->next = cur_prev;
        cur_prev = temp_node;
    }

    return cur_prev;
}

ListNode* reverse_list_rec(ListNode* node)
{
    if(!node || !node->next)
    {
        return node;
    }

    ListNode* head = reverse_list_rec(node->next);
    node->next->next = node;
    node->next = nullptr;

    return head;
}

void test_solutions(ListNode* head)
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