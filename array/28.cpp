// ***  两数相除 ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static int divide(int dividend, int divisor)
    {
        if (dividend == 0)
        {
            return 0;
        }
        bool negative = false;
        if (dividend < 0)
        {
            negative = !negative;
            dividend *= (-1);
        }
        if(divisor<0)
        {
            negative = !negative;
            divisor *= (-1);
        }
        int l = 0, r = dividend;
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid * divisor <= dividend)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return negative ? ans * (-1) : ans;
    }
};

void print(const vector<int> &mv)
{
    for (size_t i = 0; i != mv.size(); i++)
    {
        cout << mv[i] << " | ";
    }
    cout << endl;
}
void Test1()
{
    cout<<Solution::divide(-5,2)<<endl;
}
int main()
{
    Test1();
    return 0;
}
