// Unique Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;


string UniqueSubstring(string input)
{
    
    pair<int, int> maxWindowIdx = { 0,0 };
    unordered_map<char,int> occuredList;
    int winStartIdx = 0;
    int winEndIdx = 0;




    while (winEndIdx  < input.size())
    {
        char ch = (char)input[winEndIdx];
        if (occuredList.find(ch) == occuredList.end())  occuredList.insert({ ch,winEndIdx });           
        
        else
        {   
            if (winStartIdx <= occuredList[ch])
            {
                ((winEndIdx - winStartIdx) > (maxWindowIdx.second - maxWindowIdx.first))
                    ? maxWindowIdx = { winStartIdx, winEndIdx }
                    : maxWindowIdx = { maxWindowIdx.first, maxWindowIdx.second };

                winStartIdx = occuredList[ch] + 1;
            }
            occuredList[ch] = winEndIdx;
        }
        winEndIdx++;
    }
    ((winEndIdx - winStartIdx) > (maxWindowIdx.second - maxWindowIdx.first))
        ? maxWindowIdx = { winStartIdx, winEndIdx }
        : maxWindowIdx = { maxWindowIdx.first, maxWindowIdx.second };

    return input.substr(maxWindowIdx.first, maxWindowIdx.second - maxWindowIdx.first);
}



int main()
{
    //cout << UniqueSubstring("AABCB");
    cout << UniqueSubstring( "pqrabceba" ) << endl;
    cout << UniqueSubstring("abcbdfdfbcvsdc") << endl;
    


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
