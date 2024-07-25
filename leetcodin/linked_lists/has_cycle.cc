#include <cstdint>
#include <iostream>
#include <vector>
#include <cassert>

#include "LLUtil.h"

/*
141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again
by continuously following the next pointer. Internally, pos is used to denote the index of the
node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/

bool has_cycle(LLUtil::ListNode* head);
void add_cycle(LLUtil::ListNode* head, std::uint32_t cycle_head, std::uint32_t cycle_tail);

int main()
{
    LLUtil::ListNode* test_1 = LLUtil::build_ll(std::vector<int32_t>{3,2,0,-4});
    add_cycle(test_1, 1, 3);

    LLUtil::ListNode* test_2 = LLUtil::build_ll(1, 2);
    add_cycle(test_2, 0, 1);

    LLUtil::ListNode* test_3 = LLUtil::build_ll(1, 1);

    LLUtil::ListNode* test_4 = nullptr;

    assert(has_cycle(test_1));
    assert(has_cycle(test_2));
    assert(!has_cycle(test_3));
    assert(!has_cycle(test_4));

    std::cout << std::boolalpha << has_cycle(test_1) << '\n';
    std::cout << std::boolalpha << has_cycle(test_2) << '\n';
    std::cout << std::boolalpha << has_cycle(test_3) << '\n';
    std::cout << std::boolalpha << has_cycle(test_4) << '\n';
}

bool has_cycle(LLUtil::ListNode* head)
{
    if(!head || !head->next)
    {
        return false;
    }

    LLUtil::ListNode* slow = head;
    LLUtil::ListNode* fast = head;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    
    return false;  
}

void add_cycle(LLUtil::ListNode* head, std::uint32_t cycle_head, std::uint32_t cycle_tail)
{
    // helper function to add cycle to valid linked list, points node in position
    // cycle_tail to node in position cycle_head (cycle_tail > cycle_head)

    LLUtil::ListNode* cycle_head_node = head;
    LLUtil::ListNode* cycle_tail_node = head;

    std::size_t i = 0;
    while(i < cycle_head)
    {
        cycle_head_node = cycle_head_node->next;
        cycle_tail_node = cycle_tail_node->next;
        i++;
    }

    while(i < cycle_tail)
    {
        cycle_tail_node = cycle_tail_node->next;
        i++;
    }
    
    cycle_tail_node->next = cycle_head_node;
}