#include <iostream>
#include <vector>

#include "LLUtil.h"

// util functions for linked list problems

namespace LLUtil
{
    ListNode* build_ll(std::uint32_t start, std::uint32_t end)
    {
        // helper function to build linked lists with consecutive vals
        ListNode* head = new ListNode(start);

        ListNode* temp = head;
        for(std::uint32_t i = ++start; i <= end; i++)
        {
            temp->next = new ListNode(i);
            temp = temp->next;
        }
        temp = nullptr;

        return head;
    }

    ListNode* build_ll(std::vector<std::int32_t> vals)
    {
        // helper function to build linked lists with vector of vals
        ListNode* head = new ListNode(vals[0]);

        ListNode* temp = head;
        for(std::uint32_t i = 1; i < vals.size(); i++)
        {
            temp->next = new ListNode(vals[i]);
            temp = temp->next;
        }
        temp = nullptr;

        return head;
    }

    ListNode* destroy_ll(ListNode* head)
    {
        // vanilla destructor
        while(head)
        {
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }

        return nullptr;
    }

    void print_ll(ListNode* head)
    {
        // helper function to print linked lists
        while(head)
        {
            std::cout << head->val << '\n';
            head = head->next;
        }
    }
} // LLUtil