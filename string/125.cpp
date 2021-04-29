// *** 验证回文串 ***
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <ctype.h>
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
    bool isPalindrome(string s) {
        string sgood;
        for (char &ch : s)
        {
            if (isalnum(ch))
            {
                sgood += tolower(ch);
            }
        }

        int l = 0, r = s.size() - 1;

        while (l < r)
        {
            if (sgood[l] != sgood[r])
                return false;
            l++;
            r--;
        }
        return true;
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
    string s="abc";
    cout<<s.size()<<endl;
}
int main()
{
    Test1();
    return 0;
}
