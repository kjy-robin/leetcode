// *** 解码方法 ***
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
/*动态规划*/

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

/*  转移条件
1. s[i]不为0时,若只取当前一个字符做映射,则 f[i]=f[i-1];
2. 当i>0时,若s[i-1]不为0,且(s[i-1]-'0')*10+s[i]-'0'<=26时,则 f[i]=f[i-2];
3. 起始条件,f[0]=1,即当s为空字符时,可以解码出一种字符串
4. 注意下标问题,f[1]的含义为第一个字符对应的解码方法数即对应字符s[0]
*/
class Solution {
public:
    int numDecodings(string s)
    {
        int a = 0, b = 1, c = 0;
        int n = s.size();
        for (int i = 1; i <= n; i++)
        {
            c = 0;
            if (s[i - 1] != '0')
            {
                c += b;
            }

            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26))
            {
                c += a;
            }
            std::tie(a, b) = {b, c};
        }
        return c;
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
