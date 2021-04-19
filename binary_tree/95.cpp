// *** 不同的二叉搜索树II ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*回溯*/
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<TreeNode*> generateTrees(int start,int end)
    {
        // 返回一个空指针
        if (start > end)
        {
            return {nullptr};
        }

        vector<TreeNode*> all_trees;
        vector<TreeNode*> left_trees;
        vector<TreeNode *> right_trees;
        for (int i = start; i <= end; i++)
        {
            left_trees = generateTrees(start, i - 1);

            right_trees = generateTrees(i + 1, end);

            for (auto &left : left_trees)
            {
                for (auto &right : right_trees)
                {
                    TreeNode *cur = new TreeNode(i);
                    cur->left = left;
                    cur->right = right;
                    all_trees.push_back(cur);
                }
            }
        }
        return all_trees;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        if (!n)
        {
            return {nullptr};
        }
        return generateTrees(1,n);
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
