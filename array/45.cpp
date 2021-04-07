/*
*** 跳跃游戏 II***
*/
#include <iostream>
#include <vector>
using namespace std;

// --- 自己做的 ---
// class Solution
// {
// public:
//     int jump(vector<int> &nums)
//     {
//         int step = 0;
//         int cur_index = 0;
//         while (cur_index < nums.size())
//         {
//             int max_step = 0;
//             int max_step_pos = 0;
//             for (int i = 1; i <= nums[cur_index]; i++)
//             {
//                 if (cur_index + i >= nums.size())
//                 {
//                     return step + 1;
//                 }
//                 if (i + nums[cur_index + i] > max_step)
//                 {
//                     max_step = i + nums[cur_index + i];
//                     max_step_pos = i;
//                 }
//             }
//             cur_index += max_step_pos;
//             step++;
//         }
//         return step;
//     }
// };

// --- 答案 ---
// 注意
// 1.无需遍历数组中最后一个位置,因为最后一个元素肯定能达到
// 2.在遍历的过程中不断更新可达到的最远位置 max_pos
// 3.只有当当前位置是上一步所能达到的最远位置的时候才对步数以及 end的位置进行更新


class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int step = 0;
        int end = 0;
        int max_pos = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            max_pos = std::max<int>(max_pos, i + nums[i]);
            if (i == end)
            {
                end = max_pos;
                step++;
            }
            cout<<"i : end : max_pos : step:\t"<<i<<" | "<<end<<" | "<<max_pos<<" | "<<step<<endl;
        }
        return step;
    }
};
void Test1()
{
    int ma[] = {2, 3, 1, 1, 4};
    vector<int> mv(ma, ma + sizeof(ma) / sizeof(int));
    Solution ss;
    cout<<ss.jump(mv)<<endl;
}
int main()
{
    Test1();
    return 0;
}
