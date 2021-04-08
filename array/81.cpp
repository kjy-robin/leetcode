//***搜索旋转排序数组 II***
#include <iostream>
#include <vector>
using namespace std;

/*
错误1: 判断左边是否为升序的时候要用等于号
*/
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            return nums[0] == target;
        }

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[l] == nums[mid] && nums[mid] == nums[r])
            {
                l++;
                r--;
            }
            // 左边为升序
            else if (nums[l] <= nums[mid])
            {
                if (target < nums[mid] && target >= nums[l])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            // 右边为升序
            else
            {
                if (target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

void Test1()
{
}
int main()
{
    Test1();
    return 0;
}
