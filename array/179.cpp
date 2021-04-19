/**** 最大数 ****/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            long sx = 10;
            long sy = 10;

            while (sx <= x)
            {
                sx *= 10;
            }

            while (sy <= y)
            {
                sy *= 10;
            }
            return x * sy + y > y * sx + x;
        });

        if(nums[0]==0)
        {
            return "0";
        }

        string ret;
        for(int &x:nums)
        {
            ret+=to_string(x);
        }
        
        return ret;

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
