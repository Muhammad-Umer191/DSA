/*

Problem Link = https://leetcode.com/problems/intersection-of-two-arrays/description/

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/

// Common mistakes and points to note:

// An array is given not a set so an array can have the same value more than once


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Adding a struct to act as a default value for the unordered_map
// The unordered_map does not have a deafult value parameter and I have used structs because it is easy to implement where as the
// classes are used for complex tasks, a struct would be a simple and better approach
struct default_value
{
    int value = 0;
};


int main()
{
    vector<int> num1 = {409, 191, 845, 6};
    vector<int> num2 = {6,191,845};
    vector<int> intersection;

    unordered_map<int,default_value> present;
    for(int i = 0; i< num1.size(); i++)
    {
        if(present[num1[i]].value == 0)
        {
            present[num1[i]].value++;
        }
        else
        {
            continue;
        }
    }
    for(int i = 0; i < num2.size(); i++)
    {
        if(present[num2[i]].value == 1)
        {
            present[num2[i]].value++;
        }
        else
        {
            continue;
        }
    }

    // You cannot traverse an unordered_map with numeric indexing because the keys in it could be non contigious which are the case here also
    // for(int i = 0; i < present.size() ; i++)
    // {
    //     if(present[i].value > 1)
    //     {
    //         intersection.push_back(i);
    //     }
    // }


    for (auto [keys, values]: present)
    {
        if(present[keys].value == 2)
        {
            intersection.push_back(keys);
        }
    }

    for (int i = 0; i < intersection.size(); i++)
    {
        cout << intersection[i] << " ";
    }
    
    return 0;

}