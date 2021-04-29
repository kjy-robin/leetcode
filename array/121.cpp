// *** 买入股票的最佳时机 ***
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


// 1.记录当前最低点为买入价格,因为买入价格越低,越有可能获利更多.
// 2.当当前价格大于买入价格时更新profit函数,不更新买入价格.
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int buy_price = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - buy_price > 0)
            {
                profit = std::max<int>(profit, prices[i] - buy_price);
            }
            else
            {
                buy_price = prices[i];
            }
        }
        return profit;
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
