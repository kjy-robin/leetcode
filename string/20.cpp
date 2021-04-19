// *** 有效的括号 ***
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    static bool isValid(string s)
    {
        if (s == "")
        {
            return true;
        }

        std::stack<int> ms;

        ms.push(s[0]);
        for (size_t i = 1; i < s.size(); i++)
        {
            if (ms.empty())
            {
                ms.push(s[i]);
            }
            else if (ms.top() == (s[i] - 1) || ms.top() == (s[i] - 2))
            {
                ms.pop();
            }
            else
            {
                ms.push(s[i]);
            }
        }
        return ms.empty();
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
    cout<<Solution::isValid("[][][][)]")<<endl;
}
int main()
{
    Test1();
    return 0;
}
