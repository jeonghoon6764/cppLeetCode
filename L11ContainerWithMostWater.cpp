class Solution {
    /*
    LeetCode Problem 11
    Container With Most Water

    complexity analysis:
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
public:
    int maxArea(vector<int>& height) {
        int left_pointer = 0;
        int right_pointer = height.size() - 1;
        int max_value = -1;

        while (left_pointer < right_pointer) {
            max_value = std::max(max_value, 
            std::min(height[left_pointer], height[right_pointer]) * (right_pointer - left_pointer));

            if (height[left_pointer] < height[right_pointer]) {
                left_pointer++;
            } else if (height[left_pointer] > height[right_pointer]) {
                right_pointer--;
            } else {
                left_pointer++;
                right_pointer--;
            }
        }
        return max_value;
    }
};