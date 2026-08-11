/*
Problem number: 16
Problem Link: https://leetcode.com/problems/3sum-closest/

Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).


Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4

Topics:
 - Array
 - Two Pointers
 - Sorting


*/

// Just solve the normal 3 sum problem and this is easy peasy for you then

#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sort(int left, int right, vector<int> &nums)
{
    if (left == right)
    {
        return {nums[left]};
    }

    int mid = left + (right - left) / 2;

    vector<int> left_half = merge_sort(left, mid, nums);
    vector<int> right_half = merge_sort(mid + 1, right, nums);

    vector<int> merged;
    int i = 0, j = 0;

    while (i < left_half.size() && j < right_half.size())
    {
        if (left_half[i] < right_half[j])
        {
            merged.push_back(left_half[i]);
            i++;
        }
        else
        {
            merged.push_back(right_half[j]);
            j++;
        }
    }

    while (i < left_half.size())
    {
        merged.push_back(left_half[i]);
        i++;
    }

    while (j < right_half.size())
    {
        merged.push_back(right_half[j]);
        j++;
    }

    return merged;
}


// Two pointer technique to find the closest 3-sum to the target
// One index is fixed, and the other two indices are moved based on the sum compared to the target

int closest_3sum(vector<int>& nums, int target, int& closest)
{
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int current_sum = nums[i] + nums[left] + nums[right];

            if (abs(current_sum - target) < abs(closest - target))
            {
                closest = current_sum;
            }

            if (current_sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return closest;
}

int main()
{
    vector<int> nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    int target = -2;
    vector<int> sorted_nums = merge_sort(0, nums.size() - 1, nums); 
    // if you use std::sort, you can replace this line with std::sort(nums.begin(), nums.end());
    // it works faster somehow, maybe the internal implementation of std::sort is better than my merge sort implementation, but I don't know why
    int closest = sorted_nums[0] + sorted_nums[1] + sorted_nums[2]; // Initialize closest with the sum of the first three elements

    closest_3sum(sorted_nums, target, closest);
    cout << closest << endl;
    return 0;
}