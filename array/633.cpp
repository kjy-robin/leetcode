// *** 平方数之和 ***
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
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

class Solution {
public:
    bool judgeSquareSum(int c) {
        long l=0;
        long r=sqrt(c);
        while (l <= r)
        {
            int sum=l * l + r * r ;
            if (sum== c)
            {
                return true;
            }
            else if(sum>c)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return false;
    }
};

// 注意
// 1. 可能会发生溢出
// 2. 审题 是否存在两个整数,使得 a*a+b*b=c,所以a和b的取值范围是[0,sqrt(c)]
// --- right answer ----
// class Solution
// {
// public:
//     bool judgeSquareSum(int c)
//     {
//         for (long a = 0; a * a <= c; a++)
//         {
//             double b = sqrt(c - a * a);
//             if(b==(int)b)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

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
    double a = 3.0;
    int b = 3;
    cout << (a == b) << endl;
}
int main()
{
    Test1();
    return 0;
}
