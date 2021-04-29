// *** 二叉树的右视图 ***
/*深度优先遍历*/
/*广度优先遍历*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
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

// 广度优先遍历
// 可以直接覆盖
class Solution {
public:
    vector<int> rightSideView(TreeNode *root)
    {
        std::queue<TreeNode *> mq;
        std::queue<int> deep;
        std::unordered_map<int, int> map;

        mq.push(root);
        deep.push(0);

        while (!mq.empty())
        {
            TreeNode *cur_node = mq.front();
            mq.pop();
            int cur_deep = deep.front();
            deep.pop();

            if (cur_node != nullptr)
            {
                map[cur_deep] = cur_node->val;

            mq.push(cur_node->left);
            deep.push(cur_deep + 1);

            mq.push(cur_node->right);
            deep.push(cur_deep + 1);
            }

        }

        vector<int> ans;
        for (int i = 0; i < map.size(); i++)
        {
            ans.push_back(map[i]);
        }

        return ans;
    }
};

// 深度遍历 
// 深度优先遍历是先进后出,要用到栈
// class Solution
// {
// public:
//     vector<int> rightSideView(TreeNode *root)
//     {
//         std::stack<TreeNode *> ms;
//         std::stack<int> deep;
//         std::unordered_map<int, int> map;

//         ms.push(root);
//         deep.push(0);
//         while (!ms.empty())
//         {
//             TreeNode *cur_node = ms.top();
//             ms.pop();
//             int cur_deep = deep.top();
//             deep.pop();

//             if (cur_node != nullptr)
//             {
//                 if (map.find(cur_deep) == map.end())
//                 {
//                     map.emplace(cur_deep, cur_node->val);
//                 }
//                 ms.push(cur_node->left);
//                 deep.push(cur_deep + 1);

//                 ms.push(cur_node->right);
//                 deep.push(cur_deep + 1);
//             }
//         }

//         vector<int> ans;
//         for (int i = 0; i < map.size(); i++)
//         {
//             ans.push_back(map[i]);
//         }

//         return ans;
//     }
// };

// 深度优先遍历
// --- right ans ---
// class Solution
// {
// public:
//     void dfs(TreeNode *root, std::unordered_map<int, int> &map, int deep)
//     {
//         if (root == nullptr)
//         {
//             return;
//         }

//         if (map.find(deep) == map.end())
//         {
//             map.emplace(deep, root->val);
//         }

//         dfs(root->right, map, deep + 1);
//         dfs(root->left, map, deep + 1);

//         return;
//     }
//     vector<int> rightSideView(TreeNode *root)
//     {
//         std::unordered_map<int, int> map;
//         dfs(root, map, 0);
//         std::vector<int> res;
//         for (int i = 0; i < map.size(); i++)
//         {
//             res.push_back(map[i]);
//         }
//         return res;
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
