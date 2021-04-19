// 二叉搜索树节点最小距离
// 可以用中序遍历
// 性质:二叉搜索树中序遍历得到的值序列是递增有序的
#include <iostream>
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
    void dfs(TreeNode *root, int &pre, int &num)
    {
        if (root == nullptr)
            return;
        dfs(root->left, pre, num);
        if (pre == -1)
        {
            pre = root->val;
        }
        else
        {
            num = std::min<int>(num, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, num);
    }
    int minDiffInBST(TreeNode *root)
    {
        int num = INT32_MAX;
        int pre = -1;
        dfs(root, pre, num);
        return num;
    }
};

// --- 错误答案 ---
// class Solution
// {
// public:
//     int sub = INT32_MAX;
//     void calc(TreeNode *root, int num)
//     {
//         if (root == nullptr)
//             return;
//         sub = std::min<int>(abs(root->val - num), sub);

//         calc(root->left,root->val);
//         calc(root->right,root->val);
//         return;
//     }
//     int minDiffInBST(TreeNode *root)
//     {
//         calc(root,INT32_MAX);

//         return sub;
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
}
int main()
{
    Test1();
    return 0;
}
