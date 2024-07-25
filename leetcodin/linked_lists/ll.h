#pragma once

#include <cstdint>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace LLUtil
{
    ListNode* reverse_list_iter(ListNode* head);
    ListNode* reverse_list_rec(ListNode* head);
    ListNode* build_ll(std::uint32_t start, std::uint32_t end);
    ListNode* destroy_ll(ListNode* head);
    void print_ll(ListNode* head);
}