#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int getParent(int index)
    {
        return (index - 1) / 2;
    }
    int getLeftChild(int index)
    {
        return (2 * index) + 1;
    }
    int getRightChild(int index)
    {
        return (2 * index) + 2;
    }


    void shift_down(vector<int>& array, int arrSize, int index)
    {
        if (index < 0 || index >= arrSize) return;

        int left_ch_i = getLeftChild(index);
        int right_ch_i = getRightChild(index);
        int min_ch_i = index;


        if (left_ch_i < arrSize && array[left_ch_i] < array[min_ch_i])
        {
            min_ch_i = left_ch_i;
        }
        if (right_ch_i < arrSize && array[right_ch_i] < array[min_ch_i])
        {
            min_ch_i = right_ch_i;
        }

        if (min_ch_i != index)
        {
            swap(array[index], array[min_ch_i]);
            shift_down(array, arrSize, min_ch_i);
        }
    }

    void buildHeap(vector<int>& array, int arrSize)
    {
        for (int i = arrSize / 2 - 1; i >= 0; i--)
        {
            shift_down(array, arrSize, i);
        }
    }

    void heapSort(vector<int>& array, int k)
    {
        int arrSize = array.size();
        buildHeap(array, k);
        for (int i = k; i < arrSize; i++)
        {
            if (array[i] > array[0])
            {
                swap(array[0], array[i]);
                shift_down(array, k, 0);
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        heapSort(nums, k);
        return nums[0];
    }
};

int main()
{
    Solution solution;

    vector<int> nums = { 3, 2, 1, 5, 6, 4 };
    int k = 2;
    int n = 3;

    int result = solution.findKthLargest(nums, k);
    cout << "the " << k << "-th largest element is: " << result << endl;
    result = solution.findKthLargest(nums, n);
    cout << "the " << n << "-th largest element is: " << result << endl;

    return 0;
}
