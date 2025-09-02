#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxl = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int h = min(height[left], height[right]);
            int area = h * (right - left);
            if (area > maxl) maxl = area;

            if (height[left] < height[right]) left++;
            else right--;
        }

        return maxl;
    }
};