/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    /*
    LeetCode Problem 24
    Swap Nodes in Pairs

    complexity analysis:
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
public:
    ListNode* swapPairs(ListNode* head) {
        return SwapNode(head);
    }

    ListNode* SwapNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        ListNode* node_next = node->next;
        ListNode* node_next_next = node->next->next;

        node_next->next = node;
        node->next = node_next_next;

        node = node_next;
        node->next->next = SwapNode(node->next->next);
        return node;
    }
};