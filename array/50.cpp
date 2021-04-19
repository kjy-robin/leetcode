#include <iostream>
// *** Pow(x,n) ***
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
// 也可以采用指数幂拆分的算法,降低空间复杂度

class Solution
{
public:
    double quickcalc(double x, long n)
    {
        double ans = 1.0;
        double x_contribute = x;
        while (n > 0)
        {
            if (n & 1 == 1)
            {
                ans *= x_contribute;
            }

            x_contribute *= x_contribute;
            n = n >> 1;
        }
        return ans;
    }
    double myPow(double x, int n)
    {
        long N = n;
        return N >= 0 ? quickcalc(x, N) : 1.0 / quickcalc(x, -N);
    }
};

// --- right ans ---
// 注意指数存在溢出的情况,可以将n用long来表示
// class Solution
// {
// public:
//     double quickcalc(double x, long n)
//     {
//         if (n == 0)
//         {
//             return 1;
//         }

//         double y = quickcalc(x, n / 2);
//         return n % 2 == 0 ? y * y : y * y * x;
//     }
//     double myPow(double x, int n)
//     {
//         long N = n;
//         return N >= 0 ? quickcalc(x, N) : 1.0 / quickcalc(x, -N);
//     }
// };

// --- wrong ans --
// 1. 未考虑指数为负数的情况
// 2. 如果采用逐个数字相乘的方法,那么时间复杂度为o(n),但是,可以采用分治的方法来减少时间复杂度
// class Solution
// {
// public:
//     double myPow(double x, int n)
//     {
//         if(n==0)
//         {
//             return 1;
//         }
//         double res = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             res*=x;
//         }
//         return res;
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
}
int main()
{
    Test1();
    return 0;
}
