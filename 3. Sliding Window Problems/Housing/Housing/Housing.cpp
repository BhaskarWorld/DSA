 // Housing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <vector>
#include <iostream>
using namespace std;

vector<pair<int, int>> GetConnectingPlots(vector<int> plots, int plotArea)
{
    vector<pair<int, int>> connectingPlots;
    
    int windowStartIdx = 0;
    int windowEndIdx = 0;
    int windowSum = 0;

    for (int plot : plots)
    {
        windowSum += plots[windowEndIdx++];
        if (windowSum > plotArea)
            while (windowSum > plotArea)
                windowSum -= plots[windowStartIdx++];
        if(windowSum == plotArea) connectingPlots.push_back({ windowStartIdx ,windowEndIdx - 1 });

    }

    return connectingPlots;
}


int main()
{
    vector<int> plots = { 1,3,2,1,4,1,3,2,1,1 };
    int plotArea = 8;
    for (pair<int, int> p : GetConnectingPlots(plots, plotArea)) cout << "(" << p.first << " " << p.second << ")";
    


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
