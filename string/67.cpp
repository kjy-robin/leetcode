// *** 二进制求和
#include <iostream>
#include <vector>
#include <string>
#include <stack>

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
    static string addBinary(string a, string b)
    {
        int na = a.size() - 1;
        int nb = b.size() - 1;
        std::stack<int> res;
        int add = 0;
        while (na >= 0 || nb >= 0)
        {
            int num_a = na >= 0 ? a[na--] - '0' : 0;
            int num_b = nb >= 0 ? b[nb--] - '0' : 0;
            int sum = num_a + num_b + add;
            add = sum / 2;
            sum %= 2;
            res.push(sum);
        }
        
        if(add)
        {
            res.push(1);
        }

        string ans;
        while (!res.empty())
        {
            int num = res.top();
            res.pop();
            ans.push_back(num + '0');
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
    cout<<Solution::addBinary("1001","101")<<endl;
}
int main()
{
    Test1();
    return 0;
}
