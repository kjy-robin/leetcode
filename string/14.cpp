// *** 最长公共前缀 ***
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


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }

        int length = strs[0].size();
        for (int i = 0; i < length; i++)
        {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if(i==strs[j].size()||strs[j][i]!=ch)
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
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
