#include <cstdint>
#include <iostream>
#include <vector>
#include "LLUtil.h"
/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

LLUtil::ListNode* merge_k_lists(std::vector<LLUtil::ListNode*>& lists);
LLUtil::ListNode* merge_2_ll(LLUtil::ListNode* l1_head, LLUtil::ListNode* l2_head);
int main()
{
    auto l1 = LLUtil::build_ll(std::vector<std::int32_t>{1, 4, 5});
    auto l2 = LLUtil::build_ll(std::vector<std::int32_t>{1, 3, 4});
    auto l3 = LLUtil::build_ll(std::vector<std::int32_t>{2, 6});

    auto l4 = LLUtil::build_ll(std::vector<std::int32_t>{4, 7, 9, 10});
    auto l5 = LLUtil::build_ll(std::vector<std::int32_t>{3, 3, 6});

    auto test_1 = std::vector<LLUtil::ListNode*>{l1, l2, l3};
    auto test_2 = std::vector<LLUtil::ListNode*>{};
    auto test_3 = std::vector<LLUtil::ListNode*>{nullptr};
    auto test_4 = std::vector<LLUtil::ListNode*>{l4, l5};

    auto res_1 = merge_k_lists(test_1);
    auto res_2 = merge_k_lists(test_2);
    auto res_3 = merge_k_lists(test_3);
    auto res_4 = merge_k_lists(test_4);

    std::cout << "Test 1: \n";
    LLUtil::print_ll(res_1);
    std::cout << "\nTest 2: \n";
    LLUtil::print_ll(res_2);
    std::cout << "\nTest 3: \n";
    LLUtil::print_ll(res_3);
    std::cout << "\nTest 4: \n";
    LLUtil::print_ll(res_4);

    return 0;
}
LLUtil::ListNode* merge_k_lists(std::vector<LLUtil::ListNode*>& lists)
{
    if(lists.size() < 1)
    {
        return nullptr;
    }

    // continuously merge every pair of linked lists in lists until only 1 ll left
    while(lists.size() > 1)
    {
        auto merged_lists = std::vector<LLUtil::ListNode*>{};
        auto sz = lists.size();
        for(std::size_t i = 0; i < lists.size(); i += 2)
        {
            LLUtil::ListNode* l1 = lists[i];
            LLUtil::ListNode* l2 = ((i + 1) < lists.size())?  lists[i + 1] : nullptr;
            merged_lists.push_back(merge_2_ll(l1, l2));
        }
        lists = merged_lists;
    }

    return lists[0];
}

LLUtil::ListNode* merge_2_ll(LLUtil::ListNode* l1_head, LLUtil::ListNode* l2_head)
{
    if(!l2_head)
    {
        return l1_head;
    }

    auto dummy = LLUtil::ListNode();
    auto tail = &dummy;

    while(l1_head && l2_head)
    {
        if(l1_head->val < l2_head->val)
        {
            tail->next = l1_head;
            l1_head = l1_head->next;
        }
        else
        {
            tail->next = l2_head;
            l2_head = l2_head->next;
        }
        tail = tail->next;
    }

    if(l1_head) tail->next = l1_head;
    if(l2_head) tail->next = l2_head;

    tail = nullptr;
    return dummy.next;
}
    