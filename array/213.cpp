// *** 打家劫舍II ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int robson(vector<int> &nums, int start, int end)
    {
        int first = nums[start];
        int second = std::max<int>(first, nums[start + 1]);
        for (int i = start + 2; i <= end; i++)
        {
            int temp = second;
            second = std::max<int>(first + nums[i], second);
            first = temp;
        }
        return second;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return std::max<int>(nums[0], nums[1]);

        return std::max<int>(robson(nums, 0, nums.size() - 2), robson(nums, 1, nums.size() - 1));
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
