// *** 验证二叉搜索树 ***
#include <iostream>
#include <vector>
#include <stack>
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

// 采用中序遍历的方式

class Solution {
public:
    static bool isValidBST(TreeNode *root)
    {
        std::stack<TreeNode *> my_stack;
        long inorder = INT64_MIN;
        while(!my_stack.empty()&& root!=nullptr)
        {
            while (root != nullptr)
            {
                my_stack.push(root);
                root = root->left;
            }

            root = my_stack.top();
            my_stack.pop();

            if (root->val >= inorder)
            {
                return false;
            }

            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};


// 需要注意数字的范围
// +++ 下面做对了 +++
// class Solution {
// public:
//    static bool isValid(TreeNode *root, long  min,  long max)
//     {
//         if (root == nullptr)
//         {
//             return true;
//         }

//         if (root->val <= min || root->val >= max)
//         {
//             return false;
//         }

//         return isValid(root->left,min,root->val)&&isValid(root->right,root->val,max);
//     }
//     static bool isValidBST(TreeNode *root)
//     {
//         return isValid(root,INT64_MIN, INT64_MAX);
//     }
// };

// --- 下面做错了 ---
/*
    原因分析,二叉树并不是只要求当前节点的值比左子节点大,正确的理解是当前节点的值比左子树的都要大.
*/
// class Solution
// {
// public:
//    static bool isValid(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return true;
//         }

//         if (root->left != nullptr && root->left->val >= root->val)
//         {
//             return false;
//         }

//         if (root->right != nullptr && root->right->val < root->val)
//         {
//             return false;
//         }

//         return isValid(root->left) && isValid(root->right);
//     }
//    static bool isValidBST(TreeNode *root)
//     {
//         return isValid(root);
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
    TreeNode *p1=new TreeNode(1);
    TreeNode *p2=new TreeNode(1);
    p1->left=p2;

    cout << Solution::isValidBST(p1) << endl;
    cout << INT64_MIN << endl;
    cout << INT64_MAX << endl;
}
int main()
{
    Test1();
    return 0;
}
