// Subarray Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>

using namespace std;


bool outOfOrder(vector<int> arr, int i)
{
    //corner cases
    if (i == 0)
        return arr[i] > arr[i + 1];
    if (i == arr.size() - 1)
        return arr[i] < arr[i - 1];

    return arr[i - 1] > arr[i] or arr[i] > arr[i + 1];
}


pair<int, int> unSortedSubArray(vector<int > arr)
{
    pair<int, int> result(-1,-1);
    
    int n = arr.size();
    if (n < 2) return result;
    
    int smallest = INT_MAX;
    int largest = INT_MIN;
    

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];

        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    int j = 0;
    while (smallest >=arr[j] ) j++ ;
    result.first = j;

    j = n;
    while (largest <= arr[--j]) ;
    result.second = j;
    

    return result;
}




int main()
{
    vector<int> arr = { 0,1,2,3,4,5,8,6,7,9,10,11 };
    pair<int, int> result = unSortedSubArray(arr);
    cout << "(" << result.first << ", " << result.second << ")";
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
