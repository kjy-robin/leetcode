// *** 将有序数组转化为二叉搜索树 ***
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
    TreeNode *buildtree(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildtree(nums, left, mid - 1);
        root->right = buildtree(nums, mid + 1, right);

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildtree(nums, 0, nums.size() - 1);
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
