/*
Problem number: 1
Problem Link = https://leetcode.com/problems/two-sum/description/

You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/

// Common mistales and points to note:

// The same index is returned twice if the same number appears twice in the array and is used to add up to the target. 
// For example, if the array is [3,3] and the target is 6 then the output will be [0,1] because nums[0] + nums[1] = 6. 
// To solve this problem, 
// I have used a vector to store the indeces of the numbers in the array that appear more than once, 
// so that if a number appears twice, we can return the indeces of both numbers instead of sending the same index twice.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> two_sum(vector<int>& nums, int target)
{
    // The vector will store the indeces for the numbers in the array that appear more than once, 
    //so that if a number appears twice, we can return the indeces of both numbers instead of sending the same index twice.
    unordered_map<int, vector<int>> map;

    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]].push_back(i);
        if (map[target - nums[i]].size() && map[target - nums[i]].front() != i)
        {
            return {map[target - nums[i]].front(), i};
        }
    }
    
    // A solution will definitly exist as per the question but if it does not then this will prevent the program from crashing.
    return {};

}

int main()
{
    vector<int> nums = {3,3};
    int target = 6;

    vector<int> result = two_sum(nums, target);
    if (!result.empty())
    {
        cout << "The indeces for target " << target << " are: " << result[0] << " and " << result[1] << endl;
    }
    else
    {
        cout << "No two numbers found that add up to " << target << endl;
    }
    return 0;
}