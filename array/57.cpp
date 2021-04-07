#include <vector>
#include <iostream>
using namespace std;

/*
***插入区间***

给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

2021/04/06
总结:
1.如果采用vector中的erase insert等方法对原数组进行处理,则会超出时间限制,比较好的方法是重新生成一个结果数组,然后将经过判断后的合法区间加入到该新数组中.
*/
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        bool placed = false;
        int left = newInterval[0];
        int right = newInterval[1];
        for (const auto &it : intervals)
        {
            if (it.at(0) > right)
            {
                if (!placed)
                {
                    res.push_back({left, right});
                    placed = true;
                }
                res.push_back(it);
            }
            else if (it.at(1) < left)
            {
                res.push_back(it);
            }
            else
            {
                left = std::min<int>(left, it.at(0));
                right = std::max<int>(right, it.at(1));
            }
        }
        if(!placed)
        {
            res.push_back({left,right});
        }
        return res;
    }
};

int main()
{
}