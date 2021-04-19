
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// pre 永远指向被调换部分的前一个位置,
// cur 指向当前的节点
// next 永远指向 cur 的下一个位置

// next=cur->next;
// cur->next=next->next;
// next->next=pre->next;
// pre->next=next


class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dumpy = new ListNode(-1);
        dumpy->next = head;

        ListNode *pre = dumpy;
        ListNode *cur;
        ListNode *next;

        for (int i = 0; i < left - 1; i++)
        {
            pre=pre->next;
        }

        cur = pre->next;
        for (int i = 0; i < right - left; i++)
        {
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
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
