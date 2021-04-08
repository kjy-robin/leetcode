// *** 下一个排列 ***

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 1. 从后往前寻找第一升序对[i,i+1](左小于右),遍历过的序列能够确保为降序[i+1,length-1].
// 2. 从后往前寻找第一个大于nums[i]的数,交换其值
// 3. 翻转交换后从位置i+1开始到length的所有元素

class Solution
{
public:
    static void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        // 第二个判断条件为>=号,即过滤两数相等的情况
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        // i之所以要大于等于0是为了保留 i=0的情况
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (nums[i] >= nums[j])
            {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());
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
    std::vector<int> mv={1,2};
    print(mv);
    Solution::nextPermutation(mv);
    print(mv);
}
int main()
{
    Test1();
    return 0;
}
