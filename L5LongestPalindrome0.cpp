class Solution {
        /*
        LeetCode Problem 5
        Longest Palindromic Substring

        complexity analysis:
        Time Complexity: O(n^2)
        Space Complexity: O(n^2)
        */
        
public:
    string longestPalindrome(string s) {
        //recurrrnce relation
        //arr[i][j] : string start from i end at j.
        //arr[i][j] == arr[i + 1][j - 1] && s[i] == s[j].
        
        int max = 1; // from constraints, 1 <= s.length <= 1000.
        int start = 0;
        
        //initializing 2d bool array
        bool** arr = new bool*[s.length()];
        for (int i = 0; i < s.length(); i++) {
            arr[i] = new bool[s.length()]();
        }
        //base case: arr[i][i] = true, arr[i][i + 1] = s[i] == s[i + 1].
        for (int i = 0; i < s.length(); i++) {
            arr[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            arr[i][i + 1] = s[i] == s[i + 1];
            if (arr[i][i + 1]) {
                max = 2;
                start = i;
            }
        }
        //fill up the array to calculate
        for (int i = s.length() - 1; i >= 0 ; i--) {
            for (int j = i + 2; j < s.length(); j++) {
                if (!arr[i + 1][j - 1]) {
                    continue;
                }
                arr[i][j] = s[i] == s[j];
                if (arr[i][j] && max < j - i + 1) {
                    max = j - i + 1;
                    start = i;
                }
            }
        }

        //delete (free) array 
        for (int i = 0; i < s.length(); i++) {
            delete[] arr[i];
        }
        delete[] arr;
        return s.substr(start, max);
    }
};