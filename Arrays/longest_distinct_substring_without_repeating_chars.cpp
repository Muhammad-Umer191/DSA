/*
Problem number 3
Problem Link = https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string s, find the length of the longest substring without duplicate characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 105
s consists of English letters, digits, symbols and spaces.

Topics
 - Staff
 - Hash Table
 - String
 - Sliding Window

*/

// Common mistakes and points to note:

// The approach I have used is also O(n) but it is relatively very slow as compared to the sliding window technique. Will implement that in later sessions as I 
// have not mastered the sliding window concept yet.

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// The below is the best solution using sliding window technique

// int lengthOfLongestSubstring(string s)
// {
//     vector<int> last(256, -1);

//     int left = 0;
//     int ans = 0;

//     for (int right = 0; right < s.size(); right++)
//     {

//         left = max(left, last[s[right]] + 1);

//         last[s[right]] = right;

//         ans = max(ans, right - left + 1);
//     }

//     return ans;
// }

int longest_substring_helper(string str, unordered_map<char, bool> &all_letters)
{
    int len = str.size();
    int max_length = 0;
    vector<char> temp;

    for (int i = 0; i < len; i++)
    {
        int inner_loop_len = 0;
        for (int j = i; j < len && (j - i) < 95; j++)
        {
            char letter = str[j];

            if (all_letters[letter] == false)
            {
                all_letters[letter] = true;
                temp.push_back(letter);
                inner_loop_len++;
                max_length = max(max_length, inner_loop_len);
            }
            else
            {
                break;
            }
        }

        while (!temp.empty())
        {
            char charac = temp.front();
            all_letters[charac] = false;
            temp.erase(temp.begin());
        }
    }
    return max_length;
}

int main()
{
    unordered_map<char, bool> all_letters;

    string str = "OXVM.R#x~\"wj7x@`pxUNj!B/qg[]2$c0g6d>l%)l&pW9Tw(+t6@@?QU-wyQN!Sozb:d<G`E?Ozf'TCFl}-*i:|iM\\HT|`6-k4h: vru},9^no~N|p/>;7rgC7";

    int longest_substring = longest_substring_helper(str, all_letters);

    cout << "Longest substring length of distinct chars is: " << longest_substring << "\n";
    return 0;
}
