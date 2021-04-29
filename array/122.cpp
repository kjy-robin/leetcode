// *** 买卖股票的最佳时机 II ***
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

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};

// 第一次做,感觉可以优化
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int profit = 0;
//         int cur_profit = 0;
//         int buy_price = prices[0];
//         for (int i = 1; i < prices.size(); i++)
//         {
//             if (prices[i] < prices[i - 1])
//             {   cur_profit=0;
//                 buy_price = prices[i];
//             }
//             else if (prices[i] - buy_price >= cur_profit)
//             {
//                 cur_profit += (prices[i] - prices[i - 1]);
//                 profit += (prices[i] - prices[i - 1]);
//             }
//             else if (prices[i] - buy_price < cur_profit)
//             {
//                 cur_profit=0;
//                 buy_price = prices[i];
//             }
//         }
//         return profit;
//     }
// };

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
