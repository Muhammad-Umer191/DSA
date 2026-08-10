
// Test cases passed 311/316
// Not completed yet

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

vector<pair<int, int>> helper_3sum(vector<int>& nums, int target, int start_index = 0)
{
    unordered_map<int, vector<int>> map;
    vector<pair<int, int>> result;

    for (int i = start_index; i < nums.size(); i++)
    {
        map[nums[i]].push_back(i);

        if (map[target - nums[i]].size() &&
            map[target - nums[i]].front() != i)
        {
            int first = target - nums[i];
            int second = nums[i];

            if (first > second)
                swap(first, second);

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
                result.push_back(temp);
            }
        }
    }

    for (auto triplet : result)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    } 



    return 0;
}