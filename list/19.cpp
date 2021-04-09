// *** 删除链表的倒数第 N 个结点 ***

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

// --- 双指针法 ---
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *pre_head = new (ListNode);
        pre_head->next = head;
        ListNode *slow = pre_head;
        ListNode *fast = head;

        for (int i = 0; i < n; i++)
        {
            fast=fast->next;
        }

        while (fast!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
   
        slow->next=slow->next->next;
      

        return pre_head->next;
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
