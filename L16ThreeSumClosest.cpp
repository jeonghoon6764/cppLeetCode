class Solution {
    /*
    LeetCode Problem 16
    3 Sum Closest

    complexity analysis:
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int current_closest = 999999;
        std:sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            FindNextClosest(nums, i, &current_closest, target);
        }
        return current_closest;
    }

    void FindNextClosest(vector<int>& nums, int idx_start, int* current_closest, int target) {
        int left_pointer = idx_start + 1;
        int right_pointer = nums.size() - 1;

        while(left_pointer < right_pointer) {
            int sum = nums[idx_start] + nums[left_pointer] + nums[right_pointer];
            int diff = std::abs(target - sum);
            int original_diff = std::abs(target - *current_closest);
            if (diff < original_diff) {
                *current_closest = sum;
            }

            if (sum < target) {
                left_pointer++;
            } else if (sum > target) {
                right_pointer--;
            } else {
                left_pointer++;
                right_pointer--;
            }
        }
    }


};