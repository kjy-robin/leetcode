#include <vector>
#include <iostream>
using namespace std;

void print(const vector<int> &mv)
{
    for (size_t i = 0; i != mv.size(); i++)
    {
        cout << mv[i] << " | ";
    }
    cout << endl;
}

int getIndex(vector<int> &mv, int low, int high)
{
    int tmp = mv[low];
    while (low < high)
    {
        while (low < high && mv[high] >= tmp)
        {
            high--;
        }
        cout << "***high:\t" << high << endl;
        mv[low] = mv[high];

        while (low < high && mv[low] <= tmp)
        {
            low++;
        }
        cout << "***low:\t" << low << endl;
        mv[high] = mv[low];
    }
    mv[low] = tmp;
    return low;
}

void quicksort(vector<int> &mv, int low, int high)
{
    if (low < high)
    {
        int x = getIndex(mv, low, high);
        quicksort(mv, low, x - 1);
        quicksort(mv, x + 1, high);
    }
}

void Test1()
{
    int ma[] = {9, 2, 4, 6, 3, 9, 6};
    vector<int> mv(ma, ma + sizeof(ma) / sizeof(int));
    print(mv);
    vector<int>::iterator it = mv.begin();
    // it++;
    mv.erase(it+7);
    cout << "cur iterator:\t" << *it << endl;

    // quicksort(mv, 0, mv.size() - 1);
    print(mv);
}

class Solution
{
public:
    int randompartition(vector<int> &nums, int low, int high)
    {
        int index = rand() % (high - low + 1) + low;
        swap(nums[index], nums[high]);
        partition(nums, low, high);
        return partition(nums, low, high);
    }

    int partition(vector<int> &nums, int low, int high)
    {
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (nums[j] <= nums[high])
            {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]); 
        return i + 1;
    }

    int findKthLargestNum(vector<int> &nums, int low, int high, int index)
    {
        int x = randompartition(nums, low, high);
        if (x == index)
        {
            return nums[x];
        }

        return x < index ? findKthLargestNum(nums, x + 1, high, index) : findKthLargestNum(nums, low, high - 1, index);
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(0));
        return findKthLargestNum(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

int main()
{
    Test1();
    return 0;
}
