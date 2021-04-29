// *** 矩形区域不超过K的最大数值和 ***
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
/*困难*/
/*二分法*/

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
    static int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int ans = INT32_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) // 枚举上边界
        {
            vector<int> sum(n);
            for (int j = i; j < m; j++) //枚举下边界
            {
                for (int z = 0; z < n; z++)
                {
                    sum[z] += matrix[j][z]; //求取每列和
                }
            }

            set<int> sumset{0};
            int s = 0;

            for (int v : sum)
            {
                s += v;
                auto lb = sumset.lower_bound(s-k);
                if (lb != sumset.end())
                {   
                    cout<<"---------------"<<endl;
                    cout<<i<<" | "<<j<<endl;
                    cout<<s<<" * "<<*lb<<endl;
                    ans = std::max<int>(ans, s - *lb);
                }
                sumset.insert(s);
            }
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
    vector<int> v1 = {5, -4, -3, 4};
    vector<int> v2 = {-3, -4, 4, 5};
    vector<int> v3 = {5, 1, 5, -4};
    vector<vector<int>> matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    cout<<Solution::maxSumSubmatrix(matrix,-2)<<endl;
}
int main()
{
    Test1();
    return 0;
}
