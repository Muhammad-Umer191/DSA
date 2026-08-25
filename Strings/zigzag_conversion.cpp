/*
Problem number: 6
Problem Link: https://leetcode.com/problems/zigzag-conversion/description/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

Topics
 - String

*/

// Common mistakes and notes: 
// The approach from where I got the idea to solve this is from a Cipher making text named as Railfence Cipher

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


string zigzag_conversion(string str, int rows)
{
    if (rows <= 1 || str.length() <= rows)
    {
        return str;
    }

    string res = "";
    vector <vector<char>> temp (rows);
    int current_row = 0;
    bool dir_flag = false; // Flag changes to true when going down, false when going up

    for (int i = 0; i < str.size(); i++)
    {
        temp[current_row].push_back(str[i]);

        // flip the direction of flag when hitting the boundary limits
        if (current_row == 0 || current_row == rows - 1)
        {
            dir_flag = !dir_flag;
        }
        if (dir_flag)
        {
            current_row++;
        }
        else
        {
            current_row--;
        }
    }

    for (int i = 0 ; i < temp.size(); i++)
    {
        for (int j = 0 ; j < temp[i].size(); j++)
        {
            res+= temp[i][j];
        }
    }

    return res;
}

int main()
{
    int rows = 3;
    string str = "PAYPALISHIRING";
    cout << "The output string is: " << zigzag_conversion(str, rows) << "\n";
    return 0;
}