class Solution {
    /*
    LeetCode Problem 15
    3 Sum

    complexity analysis:
    Time Complexity: O(n^2)
    Space Complexity: O(1) //except output array.
    */
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            Calculate(nums, i, &ret);
        }
        return ret;
    }

    void Calculate(vector<int>& arr, int target_idx, vector<vector<int>>* ret) {
        int left_pointer = target_idx + 1;
        int right_pointer = arr.size() - 1;

        while(left_pointer < right_pointer && right_pointer > target_idx && left_pointer < arr.size()) {
            if (arr[target_idx] + arr[left_pointer] + arr[right_pointer] == 0) {
                vector<int> sub_vector;
                sub_vector.push_back(arr[target_idx]);
                sub_vector.push_back(arr[left_pointer]);
                sub_vector.push_back(arr[right_pointer]);
                ret->push_back(sub_vector);

                if (!MoveIdx(&left_pointer, true, arr) || !MoveIdx(&right_pointer, false, arr)) {
                    return;
                }
            } else if (arr[target_idx] + arr[left_pointer] + arr[right_pointer] > 0) {
                if (!MoveIdx(&right_pointer, false, arr)) {
                    return;
                }
            } else {
                if (!MoveIdx(&left_pointer, true, arr)) {
                    return;
                }
            }
        }
    }

    bool MoveIdx(int* idx, bool isLeft, vector<int>& arr) {
        int current_value = arr[*idx];
        int direction = isLeft ? 1 : -1;
        *idx += direction;
        if (*idx < 0 || *idx > arr.size() - 1) {
            return false;
        }
        return arr[*idx] == current_value ? MoveIdx(idx, isLeft, arr) : true;
    }
};