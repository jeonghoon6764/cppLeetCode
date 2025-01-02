class Solution {
        /*
        LeetCode Problem 6
        Zigzag Conversion

        complexity analysis:
        Time Complexity: O(n) (n == string length)
        Space Complexity: O(n)
        */
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        std::vector<std::string> arr(numRows);
        int curr = 0;
        bool dir = true;

        for (int i = 0; i < s.length(); i++) {
            arr[curr] += s[i];
            if (curr == 0 && !dir) {
                dir = !dir; //bounce
            } else if (curr == numRows - 1 && dir) {
                dir = !dir; //bounce
            }
            if (dir) {
                curr++;
            } else {
                curr--;
            }
        }

        std::string ret;
        for (int i = 0; i < numRows; i++) {
            ret += arr[i];
        }
        return ret;
    }
};