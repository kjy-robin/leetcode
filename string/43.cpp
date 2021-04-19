//***字符串相乘***
// 与字符串相加有关

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        int m = num1.size(), n = num2.size();
        string ans;
        for (int i = n - 1; i >= 0; i--)
        {
            string cur;
            for (int j = i; j < n - 1; j++)
            {
                cur.push_back('0');
            }
            int x = num2[i] - '0';
            int add = 0;
            for (int j = m - 1; j >= 0; j--)
            {
                int y = num1[j] - '0';
                int sum = x * y + add;
                add = sum / 10;
                sum %= 10;
                cur.push_back(sum + '0');
            }
            if (add != 0)
            {
                cur.push_back(add % 10 + '0');
            }
            reverse(cur.begin(), cur.end());

            ans=Solution::add(ans,cur);
        }
        return ans;
    }
    static string add(string num1, string num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string cur;
        while (i >= 0 || j >= 0)
        {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int sum = x + y + add;
            add = sum / 10;
            sum %= 10;
            cur.push_back('0' + sum);
            i--;
            j--;
        }

        if (add != 0)
        {
            cur.push_back('0' + add % 10);
        }

        reverse(cur.begin(), cur.end());
        return cur;
    }
};

void Test1()
{
    string s1 = "0";
    string s2 = "6";
    cout << Solution::multiply(s1, s2) << endl;
}
int main()
{
    Test1();
    return 0;
}
