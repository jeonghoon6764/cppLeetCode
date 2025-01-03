class Solution {
    /*
    LeetCode Problem 8
    String to Integer (atoi)

    complexity analysis:
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
public:
    int myAtoi(string s) {
        int start = 0;
        bool pos = isPostive(s, &start);
        bool overflowed = false;
        int ret = getNum(start, s, pos, &overflowed);
        
        if (overflowed) {
            return pos ? INT_MAX : INT_MIN;
        }
        return pos ? ret : ret * (-1);
    }

    bool isPostive(string s, int* point) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '+' || s[i] == '-') {
                *point = i + 1;
                return s[i] == '+';
            } else {
                *point = i;
                return true;
            }
        }
        return true;
    }

    int getNum(int start, string s, bool pos, bool* overflowed) {
        int num = 0;
        for (;start < s.length(); start++) {
            if (s[start] >= '0' && s[start] <= '9') {
                if (num > INT_MAX / 10) {
                    *overflowed = true;
                    return 0;
                } else if (pos && num == INT_MAX / 10 && s[start] - '0' > INT_MAX % 10) {
                    *overflowed = true;
                    return 0;
                } else if (!pos && num == INT_MAX / 10 && s[start] - '0' >= INT_MIN % 10 * (-1)) {
                    *overflowed = true;
                    return 0;
                }
                num *= 10;
                num += s[start] - '0';
            } else {
                return num;
            }
        }
        return num;
    }
};