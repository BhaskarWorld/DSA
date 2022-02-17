// HighestpeakMountain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


int HightestPeakMountain(vector<int> mountains)
{    
    int maxLen = 0;
    
    int len = 0;
    int currleftThrough = 0;
    int currPeakIdx = -1;


    for (int i = 1; i < mountains.size() - 1; i++)
    {
        if (mountains[i - 1] < mountains[i] && mountains[i]> mountains[i + 1])   currPeakIdx = i;
        
        if (mountains[i - 1] > mountains[i]&& mountains[i] < mountains[i + 1] && currleftThrough< currPeakIdx <i && currPeakIdx != -1)
        {
            len = i - currleftThrough + 1;
            maxLen = max(maxLen, len);
            currleftThrough = i;
            currPeakIdx = -1;
        }
    }
    return maxLen;

}



int main()
{

    vector<int> mountains = { 5,6,1,2,3,2,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,0,-1,4 };
    cout << HightestPeakMountain(mountains);
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
