// *** 回文数 ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0 && (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int reverse = 0;

        while (x > reverse)
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }

        return x == reverse || x == reverse / 10;

        // 需要额外的非常量空间
        // if (x < 0)
        // {
        //     return false;
        // }

        // if (x % 10 == 0)
        // {
        //     return false;
        // }
        // std::vector<int> temp;

        // while (x != 0)
        // {
        //     temp.push_back(x % 10);
        //     x /= 10;
        // }

        // int l = 0, r = temp.size() - 1;

        // while (l < r)
        // {
        //     if (temp[l++] != temp[r--])
        //     {
        //         return false;
        //     }
        // }
        // return true;
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
