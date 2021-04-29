// *** 二叉树展开为链表 ***
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

class Solution {
public:
    void dfs(TreeNode *root, queue<TreeNode *> mq)
    {
        if (root == nullptr)
            return;
        mq.push(root);
        dfs(root->left, mq);
        dfs(root->right, mq);
    }
    void flatten(TreeNode *root)
    {
        queue<TreeNode *> mq;
        dfs(root, mq);
        
        TreeNode *pre=new TreeNode();

        while(!mq.empty())
        {
            TreeNode* cur = mq.front();
            mq.pop();
            
            cur->left=nullptr;
            cur->right=nullptr;
            
            pre->right=cur;
            pre=pre->right;
        }
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
