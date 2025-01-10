class Solution {
    /*
    LeetCode Problem 38
    Count and Say

    complexity analysis:
    Time Complexity: O(2^n)
    Space Complexity: O(2^n)
    */
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        return Calculate("1", n - 1);
    }

    string Calculate(string str, int n) {
        int count = 1;
        char character = str[0];
        string next_string;

        for (int i = 1; i < str.length(); i++) {
            if (str[i] == character) {
                count++;
            } else {
                next_string += (char)(count + '0');
                next_string += character;
                character = str[i];
                count = 1;
            }
        }
        next_string += (char)(count + '0');
        next_string += character;

        n--;
        if (n > 0) return Calculate(next_string, n);
        return next_string;
    }
};