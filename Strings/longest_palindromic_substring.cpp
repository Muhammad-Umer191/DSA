/*

Problem number: 5
Problem Link: https://leetcode.com/problems/longest-palindromic-substring/description/

Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

Topics
- Two Pointers
- String
- Dynamic Programming
- Manacher

*/

// Common mistakes and notes:
// If you do by brute force it will take O(n^3) but by this method it will take O(n^2). It selects a char and started moving outward to check for palendrome and if
// it founds one and it is the longest till now then save it else continue. 

#include <iostream>
#include <string>

using namespace std;


// We start from center and go outward to check if the string is a palendrome and till when it hold the conditions we add the length in the variable
string longest_palindromic_substring(string str)
{
    int len = str.size();
    string max_string;
    int max_len = 0;
    int left, right;

    for (int i = 0; i < len; i++)
    {
        // This is for odd length palendrome
        left =i , right = i;

        while (left >= 0 && right < len && str[left] == str[right])
        {
            if ((right - left + 1) > max_len)
            {
                max_string = str.substr(left, right - left + 1);
                max_len = right - left + 1; 
            }
            left--;
            right++;
        }



        // for even length palendrome
        left = i, right = i + 1;

        while (left >= 0 && right < len && str[left] == str[right])
        {
            if ((right - left + 1) > max_len)
            {
                max_string = str.substr(left, right - left + 1);
                max_len = right - left + 1;
            }
            left--;
            right++;
        }
    }

    return max_string;

}

int main()
{
    string str = "bb";

    string max_substring = "";
    max_substring = longest_palindromic_substring(str);
    cout << "Longest Palindromic Substring is: " << max_substring << "\n";
    return 0;
}