/*
***删除有序数组中的重复项 II***
双指针 slow 指向删除后有序数组的末尾,fast指向当前有序数组的待检查项
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }

        int fast = 2;
        int slow = 2;
        while (fast < n)
        {
            if (nums[slow - 2] != nums[fast])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
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
