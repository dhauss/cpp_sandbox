#include <cstdint>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse_list_iter(ListNode* head);
ListNode* reverse_list_rec(ListNode* head);
ListNode* build_ll(std::uint32_t start, std::uint32_t end);
ListNode* destroy_ll(ListNode* head);
void print_ll(ListNode* head);
void test_solutions(ListNode* test);

int main()
{
    ListNode* test_1 = build_ll(1, 5);
    ListNode* test_2 = build_ll(1, 2);
    ListNode* test_3 = build_ll(0, 0);
    ListNode* test_4 = nullptr;

    test_solutions(test_1);
    test_solutions(test_2);
    test_solutions(test_3);
    test_solutions(test_4);

    test_1 = destroy_ll(test_1);
    test_2 = destroy_ll(test_2);
    test_3 = destroy_ll(test_3);
    test_4 = destroy_ll(test_4);

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

ListNode* reverse_list_rec(ListNode* node) {
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
    print_ll(head);
    std::cout << "Reversed Array (iterative)\n";
    head = reverse_list_iter(head);
    print_ll(head);
    std::cout << "Reversed Once More! (recursive)\n";
    head = reverse_list_rec(head);
    print_ll(head);
}

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