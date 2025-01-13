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
    LeetCode Problem 92
    Reverse Linked List 2

    complexity analysis:
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        std::queue<int> buff;
        ListNode* curr = head;
        for (int i = 0; i < left - 1; i++) {
            curr = curr->next;
        }
        reverse(curr, buff, right - left);
        return head;
    }

    void reverse(ListNode* curr, std::queue<int> &buffer, int remain) {
        buffer.push(curr->val);
        if (remain > 0) {
            reverse(curr->next, buffer, remain - 1);
        }
        curr->val = buffer.front();
        buffer.pop();
    }
};