// *** 全排列 ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
    采用回溯法,每次只确定一个位置上的数,然后再确认其他位置上的数字,当所有位置上的数字都确定以后,返回即可.
*/

class Solution
{
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, int first, int length)
    {
        if (first == length)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = first; i < length; i++)
        {
            swap(nums[i],nums[first]);

            backtrack(ans,nums,first+1,length);

            swap(nums[i], nums[first]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0, nums.size());
        return ans;
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
