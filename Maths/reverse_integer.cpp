/*
Problem number: 7
Problem link: https://leetcode.com/problems/reverse-integer/description/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


Constraints:

-231 <= x <= 231 - 1

Topics:
 - Math

*/

// Common mistakes and notes:
// Nothing to say on this. This was easy peasy. Just need to take care of overflow and underflow.

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;


int reverse(int x)
{
    int rev = 0;

    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;

        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            return 0;

        rev = rev * 10 + pop;
    }

    return rev;
}

int main()
{
    int x = -123;

    int reversed = reverse(x);
    cout << "Reversed integer: " << reversed << endl;

    return 0;
}