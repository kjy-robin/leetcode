// *** 子集 ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// --- dfs ---
// 每个位置上的数字都有在和不在两种情况,可以用回溯的方法
class Solution {
public:
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;
    void dfs(int cur,std::vector<int> nums)
    {
        if(cur==nums.size())
        {  
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[cur]);
        dfs(cur + 1, nums);
        temp.pop_back();
        dfs(cur + 1, nums);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return ans;
    }
};

// --- 迭代法实现子集枚举 ---
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         std::vector<std::vector<int>> res;
//         std::vector<int> temp;
//         int n = nums.size();
//         for (int mask = 0; mask < (1 << n); mask++)
//         {
//             temp.clear();
//             for (int i = 0; i < n; i++)
//             {
//                 if (mask & (1 << i))
//                 {
//                     temp.push_back(nums[i]);
//                 }
//             }
//             res.push_back(temp);
//         }
//         return res;
//     }
// };

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

    std::vector<int> mv = {1, 2, 3, 4, 5, 6};
    std::vector<std::vector<int>> res=Solution::subsets(mv);
}
int main()
{
    Test1();
    return 0;
}
