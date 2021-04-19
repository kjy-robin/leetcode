// *** 全排列II ***

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> perm;
    vector<int> vis;
    vector<vector<int>> ans;

public:
    void backtrack(vector<int> &nums, int first, int length)
    {
        if (first == length)
        {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < length; i++)
        {
            if(vis[i]|| (i>0 && nums[i]==nums[i-1]&& !vis[i-1]))
            {
                continue;
            }
            perm.push_back(nums[i]);
            vis[i]=1;
            backtrack(nums,first+1,length);
            perm.pop_back();
            vis[i]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, nums.size());
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
