// *** 二叉树的锯齿形层序遍历 ***
#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res = {};
        if (root == nullptr)
        {
            return res;
        }
        bool odd = true;
        std::stack<TreeNode *> mstack;

        mstack.push(root);

        while (!mstack.empty())
        {
            vector<int> temp;
            std::stack<TreeNode *> mmstack;
            int n = mstack.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur_node = mstack.top();
                mstack.pop();
                temp.push_back(cur_node->val);
                if (odd)
                {
                    if (cur_node->left != nullptr)
                    {
                        mmstack.push(cur_node->left);
                    }
                    if (cur_node->right != nullptr)
                    {
                        mmstack.push(cur_node->right);
                    }
                }
                else
                {
                    if (cur_node->right != nullptr)
                    {
                        mmstack.push(cur_node->right);
                    }
                    if (cur_node->left != nullptr)
                    {
                        mmstack.push(cur_node->left);
                    }
                }
            }
            mstack = mmstack;
            res.push_back(temp);
            odd = !odd;
        }
        return res;
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
