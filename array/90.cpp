// *** 子集ii ***
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        for (int mask = 0; mask < (1 << nums.size()); mask++)
        {
            temp.clear();
            bool flag = true;
            for (int i = 0; i < nums.size(); i++)
            {
                if ((mask >> i) & 1)
                {
                    if (i > 0 && (nums[i] == nums[i - 1]) && (mask >> (i - 1) & 1) == 0)
                    {
                        flag = false;
                        break;
                    }
                    temp.push_back(nums[i]);
                }
            }
            if (flag)
            {
                res.push_back(temp);
            }
        }
        return res;
    }
};

// --- wrong answer ---
// class Solution {
// public:
//     vector<int> t;
//     vector<vector<int>> ans;

//     vector<vector<int>> subsetsWithDup(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         for (int mask = 0; mask < (1 << n); ++mask)
//         {
//             t.clear();
//             bool flag = true;
//             for (int i = 0; i < n; ++i)
//             {
//                 if (mask & (1 << i))
//                 {
//                     cout << std::bitset<8>(mask) << " | " << std::bitset<8>(mask >> (i - 1)) << endl;
//                     if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1])
//                     {
//                         flag = false;
//                         break;
//                     }
//                     t.push_back(nums[i]);
//                 }
//             }
//             if (flag)
//             {
//                 ans.push_back(t);
//             }
//         }
//         return ans;
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
    Solution ss;
    std::vector<int> mv={1,2,2,2,2};
    ss.subsetsWithDup(mv);

}
int main()
{
    Test1();
    return 0;
}
