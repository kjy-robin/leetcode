//*** 实现 strStr() ***
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

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty() || needle.empty())
        {
            return 0;
        }

        if(haystack.size()<needle.size())
        {
            return -1;
        }

        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < needle.size(); j++)
            {
                if (needle[j] != haystack[i + j])
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                return 2;
            }
        }
        return -1;
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
