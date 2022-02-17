// MinimunDifference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


pair<int, int> MinDifference(vector<int> a, vector<int> b) {
    pair<int, int> result;

    int minDiff = INT_MAX;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int leftIdx = 0;
    int rightIdx = 1;

    int i = 0;
    while (rightIdx < a.size() and i< b.size())
    {
        int current = b[i];
        if (a[leftIdx] <= current && current <= a[rightIdx])
        {

            int currMinDiff1 = abs(a[leftIdx] - current);
            int currMinDiff2 = abs(current - a[rightIdx]);
            int currMin = min(currMinDiff1, currMinDiff2);
            if (minDiff > currMin)
            {
                minDiff = currMin;
                currMinDiff1 < currMinDiff2 ? result = {a[leftIdx],current} : result = {a[rightIdx],current};
            }
            i++;
        }
        else
        {
            leftIdx += 1;
            rightIdx += 1;
        }
        
    }

    return result;
}




pair<int, int> minDifference(vector<int> a1, vector<int> a2) {
    //Complete this method
    // Write your code here.
    sort(a2.begin(), a2.end());
    vector<int> result;
    //iterate over 1 and do binary search
    int p1, p2;

    int diff = INT_MAX;

    for (int x : a1) {
        
        auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin();

        if (lb >= 1 and x - a2[lb - 1] < diff) {
            diff = x - a2[lb - 1];
            p2 = a2[lb - 1];
            p1 = x;
        }

        if (lb != a2.size() and a2[lb] - x < diff) {
            diff = a2[lb] - x;
            p1 = x;
            p2 = a2[lb];
        }
    }

    return { p1,p2 };
}

int main()
{
    vector<int> x = { 23,5,10,17,30 };
    vector<int> y = { 26,134,135,14,19 };
    pair<int,int> result = minDifference(x, y);
    cout << "(" << result.first << "," << result.second << ")";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
