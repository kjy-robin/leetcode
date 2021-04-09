// *** 旋转链表 ***

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || head == nullptr)
        {
            return head;
        }

        int length = 0;
        ListNode *p = head;
        while (p != nullptr)
        {
            p = p->next;
            length++;
        }

        int rotate_num=k%length;

        ListNode *q = head;
        p = head;
        for (int i = 0; i < rotate_num; i++)
        {
            q = q->next;
        }
        while(q->next!=nullptr)
        {
            p=p->next;
            q=q->next;
        }
        q->next=head;
        q=p->next;
        p->next=nullptr;
        return q;
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
