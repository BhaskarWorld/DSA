// Rains.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
using namespace std;

int Rains(vector<int> rains)
{
    int rain = 0;
    int currLeftPeak = -1;
    
    
    int n = rains.size();
    for (int i = 1; i < n - 1; i++)
    {
        if (rains[i - 1] < rains[i] && rains[i]> rains[i + 1])
        {
            if(currLeftPeak != -1)if (rains[i] < rains[currLeftPeak]) rain -= (rains[currLeftPeak] - rains[i])*(i-currLeftPeak-1);
            currLeftPeak = i;            
        }

        if (currLeftPeak != -1 && i!=currLeftPeak)
        {
            rain += rains[currLeftPeak] - rains[i];
        }
        
    }
    return rain;
}

int Rains2(vector<int> rains)
{
    int rain = 0;
    int n = rains.size();
    vector<int> left(n, 0), right(n, 0);
    left[0] = rains[0];
    right[n - 1] = rains[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], rains[i]);
        right[n - i - 1] = max(right[n - i], rains[n - i - 1]);
    }
    for (int i = 0; i < n - 1; i++) 
        rain += min(left[i], right[i]) - rains[i];
    
    return rain;
}




int main()
{
    vector<int> rains = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << Rains2(rains);
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
