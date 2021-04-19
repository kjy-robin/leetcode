// *** 加一 ***
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    static vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0)
            {
                return digits;
            }
        }
        cout << "size:\t" << digits.size();
        digits.resize(digits.size() + 1);
        cout << "size:\t" << digits.size();
        digits[0] = 1;
        return digits;
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
    std::vector<int> mv={9};
    print(Solution::plusOne(mv));
}
int main()
{
    Test1();
    return 0;
}
