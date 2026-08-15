/*

Problem number: 2
Problem Link: https://leetcode.com/problems/add-two-numbers/description/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

Topics:
 - Principal
 - Linked List
 - Math
 - Recursion

*/

// Common mistaked and notes:
// Just cater carry and add properly along with node handelling

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// The node class or struct is given already
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *add_two_number(ListNode *l1, ListNode *l2)
{
    ListNode *l3 = new ListNode();
    ListNode *ret = l3;
    int add = 0;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr)
    {
        add = carry;
        carry = 0;

        if (l1 != nullptr)
        {
            add = add + l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            add = add + l2->val;
            l2 = l2->next;
        }

        if (add > 9)
        {
            carry = add / 10;
            add = add % 10;
        }

        l3->val = add;

        if (l1 != nullptr || l2 != nullptr)
        {
            l3->next = new ListNode();
            l3 = l3->next;
        }
    }

    if (carry != 0)
    {
        l3->next = new ListNode(carry);
    }

    return ret;
}

int main()
{
    ListNode *l11 = new ListNode(2);
    ListNode *l12 = new ListNode(4, l11);
    ListNode *l13 = new ListNode(3, l12);

    ListNode *l21 = new ListNode(5);
    ListNode *l22 = new ListNode(6, l21);
    ListNode *l23 = new ListNode(4, l22);

    ListNode *result = add_two_number(l13, l23);

    while (result != nullptr)
    {
        cout << result->val;
        result = result->next;
    }
    return 0;
}