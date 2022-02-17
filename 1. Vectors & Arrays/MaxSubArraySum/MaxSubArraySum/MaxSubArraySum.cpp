// MaxSubArraySum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int maxSubarraySum(vector<int> arr) {
    
    int maxSum = 0;
    int n = arr.size();


    int i = 0;
    for ( i = 0; i < n; i++)     
        if (arr[i] > 0 ) break;
        
    
    int sum = 0;
    for (int j = i; j < n; j++)
    {
        int current = arr[j];
        sum = max(0, sum+current);
        maxSum = max(maxSum, sum);
    }
   
    

    return maxSum;
}

int main()
{
    vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << maxSubarraySum(arr);
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
