
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(int x) //my
{
    if (x < 0) return false;
    vector<int> arr;
    while (x != 0)
    {
        arr.push_back(x % 10);
        x /= 10;
    }
    // but inverted

    int cap = arr.size() - 1;

    for (int i = 0; cap >= 0; i++)
    {
        if (arr[i] != arr[cap]) return false;
        cap--;
    }
    return true;
}

int main()
{
    int x = -32323;
    cout << "x = " << x << endl;
    if (isPalindrome(x))
        cout << "true";
    else cout << "false";



}

