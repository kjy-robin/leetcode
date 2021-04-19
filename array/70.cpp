// *** 爬楼梯 ***

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(const vector<int> &mv)
{
    for (size_t i = 0; i != mv.size(); i++)
    {
        cout << mv[i] << " | ";
    }
    cout << endl;
}

// f(x)=f(x-1)+f(x-2);
// f(0)=1,f(1)=1,f(2)=2;
// 写入边界条件 f(-2)=0 f(-1)=0,利用滚动数组优化
class Solution {
public:
    int climbStairs(int n) {
        int p=0,q=0,r=1;
        for(int i=1;i<=n;i++)
        {
            p=q;
            q=r;
            r=p+q;
        }
        return r;
    }
};

// --- wrong answer ---
// class Solution
// {
// public:
//     int nums = 0;
//     void climb(int n, int cur, int step)
//     {
//         if (cur + step > n)
//         {
//             return;
//         }

//         if(cur+step==n)
//         {
//             nums++;
//             return;
//         }

//         climb(n,cur+step,1);
//         climb(n,cur+step,2);
//     }
//     int climbStairs(int n)
//     {   
//         climb(n,0,0);
//         return nums;
//     }
// };
void Test1()
{
}
int main()
{
    Test1();
    return 0;
}
