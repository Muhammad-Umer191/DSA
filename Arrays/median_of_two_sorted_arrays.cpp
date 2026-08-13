#include <iostream>
#include <vector>


using namespace std;

int median_of_sorted_arrays(vector<int>& nums1, vector<int>nums2)
{

    int size1 = nums1.size();
    int size2 = nums2.size();

    if (size1 == 0)
    {
        if (size2%2 == 0)
        {
            return (nums2[size2/2] + nums2[size2/2 + 1] ) / 2;
        }
        else
        {
            return nums2[size2/2];
        }
    }
    else if (size2 == 0)
    {
        if (size1 % 2 == 0)
        {
            return (nums1[size1 / 2] + nums1[size1 / 2 + 1]) / 2;
        }
        else
        {
            return nums2[size1 / 2];
        }
    }
    else
    {
        // if (nums1[size1 - 1] < nums2[0])
        // {
        //     int total_size = size1 + size2;
        //     if (total_size % 2 == 0)
        //     {
        //         if (total_size / 2 > size1)
        //         {
        //             return (nums2[total_size - size1] + nums2[total_size - size1 + 1]) / 2;
        //         }
        //         else if (total_size / 2 == size1)
        //         {
        //             return (nums1[total_size/2] + nums2[0]) / 2;
        //         }
        //         else
        //         {

        //         }  
        //     }
        // }

        // TODO: Add binary search logic instead of this one



    }

}

int main()
{
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {4,5};
    int median = median_of_sorted_arrays(nums1, nums2);
    cout <<"Median of these two sorted arrays is as: " << median << "\n";

    return 0;
}

/*

[1,2,3,4,5,6,7,8,9,10,11,14]
           * *


[1,2,3,5,8,10] [4,6,7,9,11,14]
      *             * 
[]

*/