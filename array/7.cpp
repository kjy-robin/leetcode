// *** 整数反转 ***
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

/*
8bit 最大数为2^8-1;
INT_MAX = 2147483647
INT_MIN =-2147483648
-1%10=-1;
*/
class Solution
{
public:
    static int reverse(int x)
    {
        int res = 0;
        while (x != 0)
        {
            int temp = x % 10;
            if (res > INT32_MAX / 10 || (res == INT32_MAX && temp > 7))
            {
                return 0;
            }
            if (res < INT32_MIN / 10 || (res == INT32_MIN && temp < -8))
            {
                return 0;
            }
            res = res * 10 + temp;
            x /= 10;
        }
        return res;
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
    cout<<(-1%10)<<endl;
}
int main()
{
    Test1();
    return 0;
}
