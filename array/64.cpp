// ***最小路径和***
/* 动态规划 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    static int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = std::min<int>(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
void Test1()
{
    vector<vector<int>> mv = {{1,2,3},{4,5,6}};
    cout << Solution::minPathSum(mv)<<endl;
}
int main()
{
    Test1();
    return 0;
}
