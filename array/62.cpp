// *** 不同路径 ***

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 第一次做题,采用了动态规划的方法
// 第二次做的时候可以尝试数学的方法
class Solution
{
public:
    static int uniquePaths(int m, int n)
    {
        std::vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for (size_t i = 1; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (size_t j = 1; j < n; j++)
        {
            dp[0][j] = 1;
        }
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1];
    }
};

void Test1()
{
    cout<<Solution::uniquePaths(3,7)<<endl;
}
int main()
{
    Test1();
    return 0;
}
