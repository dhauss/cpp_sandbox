#include<cstdint>
#include <iostream>
#include <vector>

#include "LLUtil.h"

/*
1. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

LLUtil::ListNode* merge_two_lists(LLUtil::ListNode* list1, LLUtil::ListNode* list2);

int main()
{
    LLUtil::ListNode* test_1a = LLUtil::build_ll(std::vector<int32_t>{1, 2, 4});
    LLUtil::ListNode* test_1b = LLUtil::build_ll(std::vector<int32_t>{1, 3, 4});
    LLUtil::ListNode* test_1_res = merge_two_lists(test_1a, test_1b);
    std::cout << "Test 1\n";
    LLUtil::print_ll(test_1_res);

    test_1a = nullptr;
    test_1b = nullptr;

    LLUtil::ListNode* test_2a = nullptr;
    LLUtil::ListNode* test_2b = nullptr;
    LLUtil::ListNode* test_2_res = merge_two_lists(test_2a, test_2b);
    std::cout << "Test 2\n";
    LLUtil::print_ll(test_2_res);

    LLUtil::ListNode* test_3a = LLUtil::build_ll(1, 1);
    LLUtil::ListNode* test_3b = LLUtil::build_ll(0, 0);
    LLUtil::ListNode* test_3_res = merge_two_lists(test_3a, test_3b);
    std::cout << "Test 3\n";
    LLUtil::print_ll(test_3_res);

    test_3a = nullptr;
    test_3b = nullptr;

    LLUtil::ListNode* test_4a = nullptr;
    LLUtil::ListNode* test_4b = LLUtil::build_ll(0, 0);
    LLUtil::ListNode* test_4_res = merge_two_lists(test_4a, test_4b);
    std::cout << "Test 4\n";
    LLUtil::print_ll(test_4_res);
    test_4b = nullptr;

    test_1_res = LLUtil::destroy_ll(test_1_res);
    test_2_res = LLUtil::destroy_ll(test_2_res);
    test_3_res = LLUtil::destroy_ll(test_3_res);
    test_4_res = LLUtil::destroy_ll(test_4_res);
}

LLUtil::ListNode* merge_two_lists(LLUtil::ListNode* list1, LLUtil::ListNode* list2)
{
    LLUtil::ListNode head = LLUtil::ListNode();
    LLUtil::ListNode* cur = &head;

    while(list1 && list2)
    {
        if(list1->val < list2->val)
        {
            cur->next = list1;
            list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }

    while(list1)
    {
        cur->next = list1;
        cur = list1;
        list1 = list1->next; 
    }

    while(list2)
    {
        cur->next = list2;
        cur = list2;
        list2 = list2->next;
    }
   
    return head.next;
}