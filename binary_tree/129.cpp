// ***  求根节点到叶节点数字之和 ***
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

class Solution
{
public:
    void dfs(TreeNode *root, int pre, int &sum)
    {
        if (root == nullptr)
            return;

        int cur_sum = pre * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            sum += cur_sum;
            return;
        }

        dfs(root->left, cur_sum, sum);
        dfs(root->right, cur_sum, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        dfs(root, 0.0, sum);
        return sum;
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
