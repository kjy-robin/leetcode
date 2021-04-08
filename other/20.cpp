/* ***有效的括号*** */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s == "")
        {
            return true;
        }

        if(s.size()%2==1)
        {
            return false;
        }

        vector<char> vs;
        for (size_t i = 0; i < s.size(); i++)
        {
            if(vs.empty())
            {
                vs.push_back(s[i]);
            }
            else if (s[i])
        }

        return vs.empty();
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
