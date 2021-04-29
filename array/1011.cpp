#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
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
    int shipWithinDays(vector<int> &weights, int D)
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0.0);

        while (left < right)
        {
            int cur = 0;
            int need = 1;
            int mid = (left + right) / 2;
            for (int &weight : weights)
            {
                if (cur + weight > mid)
                {
                    cur = 0;
                    need++;
                }
                cur += weight;
            }

            if (need <= D)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;

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
