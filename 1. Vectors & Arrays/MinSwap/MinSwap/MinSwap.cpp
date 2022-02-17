// MinSwap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<vector>
#include <iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int MinSwaps(vector<int> arr)
{
    int n = arr.size();
    int minSwaps = 0;
    
    vector<pair<int, int>> valueIndex;
    for (int i = 0; i < n; i++)
        valueIndex.push_back({arr[i],i});

    sort(valueIndex.begin(), valueIndex.end());


    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        int old_idx = valueIndex[i].second;             
        int new_idx = i;

        if (old_idx == new_idx or visited[new_idx]) continue;

        int cycle = 0;
        while (!visited[new_idx]) {
            visited[new_idx] = true;
            new_idx = valueIndex[new_idx].second;
            cycle++;
        }
        minSwaps += (cycle - 1);
    }


    return minSwaps;
}



int main()
{
    vector<int> arr = {2,4,5,1,3};
    cout << MinSwaps(arr);
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
