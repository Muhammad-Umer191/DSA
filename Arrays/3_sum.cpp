/*
Problem number: 15
Problem Link = https://leetcode.com/problems/3sum/description/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

Topics:
    - Array
    - Two Pointers
    - Sorting

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <set>
#include <map>

using namespace std;

/*
The below commented function is the standard solution you will find on the internet for this problem. It uses sorting and two pointers to find the triplets.

Common mistakes and points to note:

 Do not use quick sort to do this because it is not stable and in case it asks for indeces then it fails and you will have to implement your own stable sort.
 It uses a fixed pointer and two moving pointers to find the triplets. See the normal solution for more details. 

 Jugaru solution is below

*/

// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     vector<vector<int>> result;

//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < nums.size() - 2; i++)
//     {
//         if (i > 0 && nums[i] == nums[i - 1])
//             continue;

//         int left = i + 1;
//         int right = nums.size() - 1;

//         while (left < right)
//         {
//             int sum = nums[i] + nums[left] + nums[right];

//             if (sum == 0)
//             {
//                 result.push_back({nums[i],
//                                   nums[left],
//                                   nums[right]});

//                 while (left < right &&
//                        nums[left] == nums[left + 1])
//                 {
//                     left++;
//                 }

//                 while (left < right &&
//                        nums[right] == nums[right - 1])
//                 {
//                     right--;
//                 }

//                 left++;
//                 right--;
//             }
//             else if (sum < 0)
//             {
//                 left++;
//             }
//             else
//             {
//                 right--;
//             }
//         }
//     }

//     return result;
// }


/*

Jaguru solution is below:

It uses a hash map to find the pairs that sum up to the target value. It also uses a set to avoid duplicates. And before adding it to the
result vector, it checks if the pair already exists in the result vector. If it does not exist, then it adds it to the result vector.

If there are special cases like all zeros it will be treated specially. 

*/

// This is same as two sum with a differnce is that we are looking for pairs that sum up to a target value. The target value is the negative of the current number.
vector<pair<int, int>> helper_3sum(vector<int>& nums, int target, int start_index = 0)
{
    unordered_map<int, vector<int>> map;
    vector<pair<int, int>> result;

    for (int i = start_index; i < nums.size(); i++)
    {
        map[nums[i]].push_back(i);

        if (map[target - nums[i]].size() && map[target - nums[i]].front() != i)
        {
            int first = target - nums[i];
            int second = nums[i];

            bool exists = false;

            for (auto pair : result)
            {
                if (pair.first == first && pair.second == second)
                {
                    exists = true;
                    break;
                }
            }

            if (!exists)
                result.push_back({first, second});
        }
    }

    return result;
}


int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = {};
    map<set<int>, bool> check_dup;
    bool flag = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "[0, 0, 0]" << endl;
        return 0;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        vector<pair<int, int>> pair_2 = helper_3sum(nums, -(nums[i]), i + 1);

        if (pair_2.empty())
        {
            continue;
        }
        else
        {
            for (auto pair : pair_2)
            {
                vector<int> temp = {pair.first,pair.second,nums[i]};
                set<int> temp_s(temp.begin(), temp.end());
                if (!check_dup[temp_s])
                {
                    check_dup[temp_s] = true;
                    result.push_back(temp);
                }
            }
        }
    }

    for (auto triplet : result)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    } 



    return 0;
}