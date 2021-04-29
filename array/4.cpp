// *** 寻找两个正序数组的中位数 ***
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

void print(const vector<int> &mv)
{
    for (size_t i = 0; i != mv.size(); i++)
    {
        cout << mv[i] << " | ";
    }
    cout << endl;
}

class Solution
{
public:
    static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        std::vector<int> merge;
        int i = 0;
        int j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (i == nums1.size())
            {
                merge.push_back(nums2[j++]);
            }
            else if (j == nums2.size())
            {
                merge.push_back(nums1[i++]);
            }
            else if (nums1[i] <= nums2[j])
            {
                merge.push_back(nums1[i++]);
            }
            else
            {
                merge.push_back(nums2[j++]);
            }
        }

        print(merge);

        int total_size = merge.size();
        if (total_size % 2 == 0)
        {
            return 1.0 * (merge[total_size / 2] + merge[total_size / 2 - 1]) / 2;
        }
        else
        {
            return 1.0 * merge[total_size / 2];
        }
    }
};

void Test1()
{
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    cout << Solution::findMedianSortedArrays(v1, v2) << endl;
}
int main()
{
    Test1();
    return 0;
}
