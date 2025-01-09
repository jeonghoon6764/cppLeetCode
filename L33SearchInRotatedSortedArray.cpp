class Solution {
    /*
    LeetCode Problem 33
    Search in Rotated Sorted Array

    complexity analysis:
    Time Complexity: O(log n)
    Space Complexity: O(1)
    */
public:
    int search(vector<int>& nums, int target) {
        int start_index = FindStartIndex(nums, 0, nums.size() - 1);
        int ret = BinarySearch(nums, start_index, 0, nums.size() - 1, target);

        return nums[ret] == target ? ret : -1;
    }

    int BinarySearch(vector<int>& nums, int start_index, int start, int end, int target) {
        int mid = (start + end) / 2;
        int calculated_mid = IndexMatcher(start_index, mid, nums);

        if (start == end) {
            return calculated_mid;
        }

        int calculated_start = IndexMatcher(start_index, start, nums);
        int calculated_end = IndexMatcher(start_index, end, nums);
        

        if (nums[calculated_mid] == target) {
            return calculated_mid;
        } else if (nums[calculated_mid] > target) {
            return BinarySearch(nums, start_index, start, mid, target);
        } else {
            return BinarySearch(nums, start_index, (mid + 1) % nums.size(), end, target);
        }

    }

    int IndexMatcher(int start_index, int idx, vector<int>& nums) {
        return (start_index + idx) % nums.size();
    }

    int FindStartIndex(vector<int>& nums, int start, int end) {
        if (nums[start] < nums[end] || start == end) {
            return start;
        }
        int mid_index = (start + end) / 2;
        int mid_value = nums[mid_index];

        if (mid_value < nums[start]) {
            return FindStartIndex(nums, start, mid_index);
        } else {
            return FindStartIndex(nums, mid_index + 1, end);
        }
    }
};