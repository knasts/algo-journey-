#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    vector<pair<int, string>> roman_list =
    {   {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"} };

    string intToRoman(int num)
    {
        string roman = "";

        for (int i = 0; i != roman_list.size(); i++)
        {
            while (num >= roman_list[i].first)
            {
                roman += roman_list[i].second;
                num -= roman_list[i].first;
            }
        }
        return roman;
    }
};


int main()
{
    Solution solution;

    string sol = solution.intToRoman(1994);
    string answer = "MCMXCIV";

    if(sol == answer) cout << "yeyy" << endl;
    else cout << "nahh" << endl;

}

