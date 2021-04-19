// *** 合并两个数组 ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p = m - 1;
        int q = n - 1;
        int tail = m + n - 1;
        while (p >= 0 || q >= 0)
        {
            if (p == -1)
            {
                nums1[tail--] =nums2[q--];
            }
            else if (q==-1)
            {
                nums1[tail--] = nums1[p--];
            }
            else if (nums1[p] > nums2[q])
            {
                nums1[tail--] = nums1[p];
            }
            else
            {
                nums1[tail--] = nums2[q];
            }
        }
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
