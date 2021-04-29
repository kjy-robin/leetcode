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

// DFS
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int row, int col, int m, int n)
    {
        grid[row][col] = '0';
        if (row - 1 >= 0 && grid[row - 1][col] == '1')
            dfs(grid, row - 1, col, m, n);
        if (row + 1 < m && grid[row + 1][col] == '1')
            dfs(grid, row + 1, col, m, n);
        if (col - 1 >= 0 && grid[row][col - 1] == '1')
            dfs(grid, row, col - 1, m, n);
        if (col + 1 < n && grid[row][col + 1] == '1')
            dfs(grid, row, col + 1, m, n);

        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int nums = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == '1')
                {
                    nums++;
                    dfs(grid, r, c, m, n);
                }
            }
        }
        return nums;
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
