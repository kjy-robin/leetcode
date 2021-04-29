// *** 平衡二叉树 ***
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
    int height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);

        if (abs(left_height - right_height) > 1 || left_height == -1 || right_height == -1)
        {
            return -1;
        }

        return std::max<int>(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return height(root) >= 0;
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
