// *** 路径总和 II ***
#include <iostream>
#include <vector>
#include <string>
#include <queue>
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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// *** 深度优先搜索 ***
class Solution
{
public:
    void dfs(TreeNode *root, int sum, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (root == nullptr)
        {
            return;
        }

        temp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == sum)
        {

            ans.push_back(temp);
        }
        dfs(root->left, sum - root->val, ans, temp);
        dfs(root->right, sum - root->val, ans, temp);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        std::vector<vector<int>> ans = {};
        std::vector<int> temp;
        dfs(root, targetSum, ans, temp);
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
