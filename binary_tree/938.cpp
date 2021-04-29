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

// *** 广度遍历 ***
class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        std::queue<TreeNode *> mq;
        mq.push(root);
        int sum = 0;

        while (!mq.empty())
        {
            TreeNode *mt = mq.front();
            mq.pop();

            if (mt == nullptr)
            {
                continue;
            }
            else if (mt->val < low)
            {
                mq.push(mt->right);
            }
            else if (mt->val > high)
            {
                mq.push(mt->left);
            }
            else
            {
                mq.push(mt->left);
                mq.push(mt->right);
                sum += root->val;
            }
        }
        return sum;
    }
};

// *** 深度遍历 ***
// class Solution
// {
// public:
//     int dfs(TreeNode *root, int low, int high)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }

//         if (root->val < low)
//         {
//             return dfs(root->right, low, high);
//         }

//         if (root->val > high)
//         {
//             return dfs(root->left, low, high);
//         }

//         return root->val + dfs(root->left, low, high) + dfs(root->right, low, high);
//     }
//     int rangeSumBST(TreeNode *root, int low, int high)
//     {
//         return dfs(root, low, high);
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
    std::queue<TreeNode *> mt;
    cout << mt.size() << endl;
    mt.push(nullptr);
    mt.push(nullptr);
    cout << mt.size() << endl;
}
int main()
{
    Test1();
    return 0;
}
