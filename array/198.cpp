// *** 打家劫舍 ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 动态规划

1. dp[i]=max(dp[i-1],dp[i-2]+nums[i])
2. dp数组是单调递增的,dp[i]表示当打劫到i位置房屋时,所能打劫到的最大金额.
3. 题目中规定不能打劫相邻的两间房屋,并不意味着只能打劫 RAR类型的,也可以是RAAR类型,中间可以相隔多间房屋

*/
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        if (nums.size() == 1)
        {
            return nums[0];
        }

        int first = nums[0];
        int second = std::max<int>(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            int temp = second;
            second = std::max<int>(first + nums[i], second);
            first = temp;
        }
        return second;
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
}
int main()
{
    Test1();
    return 0;
}
