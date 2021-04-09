// 寻找旋转排序数组中的最小值

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 当 nums[mid]<nums[r]时,最小的数字肯定在区间[l,mid]以内,因此更新r=mid
// 当 nums[mid]>nums[r]时,最小的数字肯定在区间(mid,r]之间,因此更新l=mid+1
class Solution
{
public:
    static int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return nums[l];
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
    std::vector<int> mv={4,5,6,7,0,1,2};
    Solution::findMin(mv);

}
int main()
{
    Test1();
    return 0;
}
