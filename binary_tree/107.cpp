// *** 二叉树的层序遍历 ***
#include <iostream>
#include <vector>
#include <string>
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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }

        std::stack<int> mstack;
        std::queue<TreeNode*> mqueue;
        std::vector<int> mvector = {1};

        mqueue.push(root);
        while (!mqueue.empty())
        {
            int num = 0;
            for (int i = 0; i < mvector.back(); i++)
            {

                TreeNode *cur_node = mqueue.front();
                mqueue.pop();
                mstack.push(cur_node->val);

                if (cur_node->right != nullptr)
                {
                    mqueue.push(cur_node->right);
                    num++;
                }

                if (cur_node->left != nullptr)
                {
                    mqueue.push(cur_node->left);
                    num++;
                }
            }
            mvector.push_back(num);
        }

        vector<vector<int>> res;
        for (int i = mvector.size() - 1; i >= 0; i--)
        {   
            std::vector<int> temp;
            for (int j = mvector[i]; j > 0; j--)
            {
                temp.push_back(mstack.top());
                mstack.pop();
            }
            res.push_back(temp);
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
