// *** 二叉树的层序遍历 ***
#include <iostream>
#include <vector>
#include <string>
#include <deque>
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {{}};
        }

        vector<vector<int>> ans;
        std::deque<TreeNode *> my_deque;
        my_deque.push_back(root);
        int size = 1;
        int son_size = 0;
        while (size != 0)
        {
            vector<int> v;
            while (size != 0)
            {
                TreeNode *cur = my_deque.front();
                my_deque.pop_front();
                v.push_back(cur->val);
                if (cur->left!=nullptr)
                {
                    my_deque.push_back(cur->left);
                    son_size++;
                }

                if (cur->right!=nullptr)
                {
                    my_deque.push_back(cur->right);
                    son_size++;
                }
                size--;
            }
            ans.push_back(v);
            size = son_size;
            son_size = 0;
        }
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
