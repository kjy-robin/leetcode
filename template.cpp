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
