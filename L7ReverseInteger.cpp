class Solution {
    /*
    LeetCode Problem 7
    Reverse Integer

    complexity analysis:
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            if (ret > INT_MAX / 10) {
                return 0;
            } else if (ret == INT_MAX / 10) {
                if (INT_MAX % 10 < x) {
                    return 0;
                }
            } else if (ret < INT_MIN / 10) {
                return 0;
            } else if (ret == INT_MIN / 10) {
                if (INT_MIN % 10 > x) {
                    return 0;
                }
            }
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};