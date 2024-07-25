#pragma once

#include <cstdint>

// linked list definition and util functions for ll problems

namespace LLUtil
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* build_ll(std::uint32_t start, std::uint32_t end);
    ListNode* build_ll(std::vector<std::int32_t> vals);
    ListNode* destroy_ll(ListNode* head);
    void print_ll(ListNode* head);
} // LLUtil