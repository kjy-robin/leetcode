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
    void DFS(TreeNode *root, std::vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }

        DFS(root->left, res);
        res.push_back(root->val);
        DFS(root->right, res);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        std::vector<int> res;
        TreeNode *dumpy = new TreeNode();
        TreeNode *cur = dumpy;

        DFS(root, res);
        for (int i = 0; i != res.size(); i++)
        {
            TreeNode *new_node = new TreeNode(res[i]);
            cur->right = new_node;
            cur = cur->right;
        }
        return dumpy->right;
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
