/*

Problem number: 4
Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

Video solution link for better understanding: https://youtu.be/F9c7LpRZWVQ?si=2H1hmkgAHV9S9vQw


Code
Testcase
Testcase
Test Result
4. Median of Two Sorted Arrays
Solved
Hard
Topics
premium lock icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

Topics
 - Mid Level
 - Array
 - Binary Search
 - Divide and Conquer

*/

// Common mistakes and points to note:
// Divide and conquer the solution by using binary search
// Try to understand the dry run first with an appraoch before coding so that you can validate that before coding part
// Handle the partition properly


// This method is the most optimal but there are other methods out there but they have more time complexity for the same solution

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

float median(vector<int> &nums1, vector<int> &nums2, int size1, int size2)
{
    int nums1l = INT_MIN, nums2l = INT_MIN;
    /*  These gives the largest values from the left half of the both array combined
     but the max element from both the arrays in the partition
     i.e. the max elements from the lower part of both nums arrays


    The one with r at the end are the vice versa of the above.

    */

    int nums1r = INT_MAX, nums2r = INT_MAX;

    int mid1, mid2, low = 0, high = size1;
    // Mids of the two arrays are caluculated on the basis of these variables
    // they tell in the symmetric partiotin how many would be from the nums1 and how many from the nums2

    int left = (size1 + size2 + 1) / 2;
    // How many elements should be on the left of the partition, is catered by this variable

    while (low <= high)
    {
        mid1 = (low + high) / 2;
        mid2 = left - mid1;

        nums1l = INT_MIN;
        nums1r = INT_MAX;
        nums2l = INT_MIN;
        nums2r = INT_MAX;

        if (mid1 > 0)
            nums1l = nums1[mid1 - 1];

        if (mid1 < size1)
            nums1r = nums1[mid1];

        if (mid2 > 0)
            nums2l = nums2[mid2 - 1];

        if (mid2 < size2)
            nums2r = nums2[mid2];

        if (nums1l <= nums2r && nums2l <= nums1r)
        {
            if ((size1 + size2) % 2 == 0)
            {
                return (min(nums2r, nums1r) + max(nums1l, nums2l)) / 2.0;
            }
            else
            {
                return max(nums1l, nums2l);
            }
        }
        else if (nums1l > nums2r)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }

    return 0;
}

float median_of_sorted_arrays(vector<int> &nums1, vector<int> &nums2)
{
    int size1 = nums1.size();
    int size2 = nums2.size();

    if (size1 > size2)
        return median(nums2, nums1, size2, size1);
    else
        return median(nums1, nums2, size1, size2);
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5};

    float median = median_of_sorted_arrays(nums1, nums2);

    cout << "Median of these two sorted arrays is as: " << median << "\n";

    return 0;
}