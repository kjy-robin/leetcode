// *** 三角形最小路径和 ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 动态规划 */
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

// 注意 size_t 为无符号数,即 size_t 不会为负数,当size_t =0时进行减一操作,会得到一个非常大的数
class Solution
{
public:
    static int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        std::vector<int> res(n);
        res[0] = triangle[0][0];
        int ans=res[0];
        for (int i = 1; i < n; i++)
        {
            auto &vec = triangle[i];
            for (int j = i; j >=0; j--)
            {
                if (j == i)
                {
                    res[j] = res[j - 1] + vec[j];
                    ans = res[j];
                }
                else if (j == 0)
                {
                    res[j] = res[j] + vec[j];
                }
                else
                {
                    res[j] = std::min<int>(res[j - 1] + vec[j], res[j] + vec[j]);
                }

                if(res[j]<ans)
                {
                    ans=res[j];
                }
            }
        }
        return ans;
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
    vector<int> a={2};
    vector<int> b={3,4};
    vector<int> c={6,5,7};
    vector<int> d={4,1,8,3};
    vector<vector<int>> test;
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    test.push_back(d);
    cout<<Solution::minimumTotal(test)<<endl;
}
int main()
{
    Test1();
    return 0;
}
