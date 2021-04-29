// *** 组合 ***
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


void print(const vector<int> &mv)
{
    for (size_t i = 0; i != mv.size(); i++)
    {
        cout << mv[i] << " | ";
    }
    cout << endl;
}

class Solution {
public:
   static vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp_ans;
        backtrack(ans,temp_ans,1,n,k);
        return ans;
    }
    
   static  void backtrack(vector<vector<int>>& ans,vector<int>&temp_ans,int cur,int n,int k)
    {
        if (temp_ans.size() == k)
        {
            ans.push_back(temp_ans);
            print(temp_ans);
            return;
        }

        for (int i = cur; i <= n; i++)
        {
            temp_ans.push_back(i);
            backtrack(ans, temp_ans, i + 1, n, k);
            temp_ans.pop_back();
        }
        return;
    }
};

void Test1()
{
    Solution::combine(4,2);
}
int main()
{
    Test1();
    return 0;
}
