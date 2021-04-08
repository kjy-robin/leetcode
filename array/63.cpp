// *** 不同路径 II ***

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 当前状态只与上一个状态有关,即无后有效性
// std::vector<int> f(6);  //初始化vector f ,其大小为6.默认赋初值为0;
class Solution
{
public:
    static int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        std::vector<int> f(n);
        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j])
                {
                    f[j] = 0;
                }
                else if (i == 0 && j > 0)
                {
                    f[j] = f[j - 1];
                }
                else if (i > 0 && j > 0)
                {
                    f[j] += f[j - 1];
                }
            }
        }
        return f[n];
    }
};

void Test1()
{
}
int main()
{
    Test1();
    return 0;
}
