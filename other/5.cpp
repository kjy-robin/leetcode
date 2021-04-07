

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        string res;
        // l表示两个字符串中收尾两个字符之间的坐标差,最小为0,最大为n-1
        for (int l = 0; l < n; l++)
        {
            cout << "come here" << endl;
            // 每次开始都从字符串中第一个位置开始检索
            for (int i = 0; i + l < n; i++)
            {
                int j = i + l;
                cout << "come interal:\t" << i << " | " << j << endl;
                if (l == 0)
                {
                    dp[i][j] = true;
                }
                else if (l == 1)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                }
                if (dp[i][j] && (l + 1) > res.size())
                {
                    res = s.substr(i, l + 1);
                }
            }
        }
        return res;
    }
};

void Test1()
{
    string s("babab");
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
}
int main()
{
    Test1();
    return 0;
}
