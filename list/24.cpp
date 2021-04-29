// ***  两两交换链表中的节点 ***
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dumpy = new ListNode(0, head);
        ListNode *pre = dumpy;
        ListNode *cur = dumpy->next;
        ListNode *next;
        while (cur != nullptr)
        {
            next = cur->next;
            if (next == nullptr)
                break;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = pre->next;
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
