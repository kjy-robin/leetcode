#include <iostream>
// *** 乘积最大子数组 ***
#include <vector>
#include <string>
using namespace std;


//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int cur_max = nums[0], cur_min = nums[0], ans = nums[0];
        for (size_t i = 0; i < nums.size(); i++)
        {
            int temp_max = cur_max;
            int temp_min = cur_min;

            cur_max = std::max<int>(std::max<int>(temp_max * nums[i], temp_min * nums[i]), nums[i]);
            cur_min = std::min<int>(std::min<int>(temp_min * nums[i], temp_max * nums[i]), nums[i]);
            ans = std::max<int>(ans, cur_max);
        }
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
