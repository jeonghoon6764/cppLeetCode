/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    /*
    LeetCode Problem 116
    Populating Next Right Pointers in Each Node

    complexity analysis:
    Time Complexity: O(n)
    Space Complexity: O(logn)
    */
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<Node*> buff;
        AssignNext(root, buff, 0);
        return root;
    }

    void AssignNext(Node* node, vector<Node*>& buff, int floor) {
        /*
        Lesson learned:
        .size() returns size_t, unsigned interger that always postive integer.
        therefore, before compare the size, it should be casted to another integer
        type. i.e: (int)buff.size() - 1;
        */
        if ((int)buff.size() - 1 < floor) {
            buff.push_back(node);
        } else {
            node->next = buff[floor];
            buff[floor] = node;
        }
        if(node->right != nullptr) {
            AssignNext(node->right, buff, floor + 1);
        }
        if (node->left != nullptr) {
            AssignNext(node->left, buff, floor + 1);
        }
        return;
    }
};