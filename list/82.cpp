// *** 删除排序链表中的重复元素 II ***
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

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dumpy = new ListNode(-1, head);
        ListNode *cur = dumpy;
        int x;

        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next != nullptr && cur->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur=cur->next;
            }
        }
        return dumpy->next;
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
