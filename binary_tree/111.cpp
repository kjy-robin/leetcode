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


// bfs 广度优先遍历
class Solution {
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        std::queue<TreeNode *> mt;
        std::queue<int> md;

        mt.push(root);
        md.push(1);

        while (!mt.empty())
        {
            TreeNode *cur_node=mt.front();
            int cur_deep=md.front();
            mt.pop();
            md.pop();

            if (cur_node->left == nullptr && cur_node->right == nullptr)
            {
                return cur_deep;
            }

            if (cur_node->left != nullptr)
            {
                mt.push(cur_node->left);
                md.push(cur_deep + 1);
            }

            if (cur_node->right != nullptr)
            {
                mt.push(cur_node->right);
                md.push(cur_deep + 1);
            }
        }
        return 0;
    }
};

// dfs 深度优先遍历
// --- right answer ---
// class Solution {
// public:
//     void dfs(TreeNode *root, int deep, int &min_length)
//     {
//         if (root->left == nullptr && root->right == nullptr)
//         {
//             min_length = std::min<int>(min_length, deep);
//             return;
//         }

//         if (deep >= min_length)
//         {
//             return;
//         }

//         if (root->left != nullptr)
//         {
//             dfs(root->left, deep + 1, min_length);
//         }

//         if (root->right != nullptr)
//         {
//             dfs(root->right, deep + 1, min_length);
//         }
//     }
//     int minDepth(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }
//         int min_length = INT32_MAX;

//         dfs(root, 1, min_length);
//         return min_length;
//     }
// };

// 注意叶节点是指既没有左节点也没有右节点的节点
// --- wrong answer
// class Solution
// {
// public:
//     void dfs(TreeNode *root, int deep, int &min_length)
//     {
//         if (root == nullptr)
//         {
//             min_length = std::min<int>(deep, min_length);
//             return;
//         }

//         if (deep >= min_length)
//         {
//             return;
//         }

//         dfs(root->left, deep + 1, min_length);
//         dfs(root->right, deep + 1, min_length);
//     }
//     int minDepth(TreeNode *root)
//     {
//         int min_length = INT32_MAX;
//         dfs(root, 0.0, min_length);
//         return min_length;
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
