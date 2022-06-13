// StringWindow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <unordered_map>
#include <string>

using namespace std;



string StringWindowWithHashmap(string inputString, string requiredPattern)
{
    unordered_map<char, int> frqPattern, frqWindow;

    int matchCount = 0;

    int startWindowIdx = 0;
    int endWindowIdx = 0;

    int bestWindowSize = INT16_MAX;
    int currentWindowSize = 0;
    int bestStartWindowIdx = -1;

    // Frequency Map of the Pattern String
    for(char ch : requiredPattern)
    {
        if (frqPattern.find(ch) == frqPattern.end())  frqPattern.insert({ ch, 1 });
        else frqPattern[ch] += 1;
    }
    


    for (char ch : inputString)
    {
        endWindowIdx += 1;
        if (frqWindow.find(ch) == frqWindow.end())  frqWindow.insert({ ch, 1 });
        else frqWindow[ch] += 1;


        if (frqPattern.find(ch) != frqPattern.end() && frqWindow.find(ch) != frqWindow.end()) //if the character exists in pattern
            matchCount = (frqPattern[ch] >= frqWindow[ch]) ? matchCount + 1 : matchCount; // increase matchCount if character frequency in window is less than equal to that in pattern.

        // Check If all the characters are matched
        if (matchCount == requiredPattern.length())
        {
            //contacts the window from the left until pattern match is not hampered
            while (frqPattern.find(inputString[startWindowIdx]) == frqPattern.end() || frqPattern[inputString[startWindowIdx]] < frqWindow[inputString[startWindowIdx]])
            {
                if (frqWindow[inputString[startWindowIdx]] == 1) frqWindow.erase(inputString[startWindowIdx]);
                else frqWindow[inputString[startWindowIdx]] -= 1;
                startWindowIdx += 1;

            }

            currentWindowSize = endWindowIdx - startWindowIdx ;
            if (currentWindowSize < bestWindowSize) 
            {
                bestWindowSize = currentWindowSize;
                bestStartWindowIdx = startWindowIdx;
            }

        }

    }



    return (bestStartWindowIdx == -1) ? "No Window found!" : inputString.substr(bestStartWindowIdx, bestWindowSize);


}




string StringWindowWithArray(string inputString, string requiredPattern)
{
    int FP[256] = { 0 };
    int FW[256] = {0};

    int matchCount = 0;

    int startWindowIdx = 0;
    int endWindowIdx = 0;

    int bestWindowSize = INT16_MAX;
    int currentWindowSize = 0;
    int bestStartWindowIdx = -1;

    // Frequency Map of the Pattern String
    for (char ch : requiredPattern) FP[ch] += 1;
    



    for (char ch : inputString)
    {
        endWindowIdx += 1;
        FW[ch] += 1;


        if (FP[ch] != 0) //if the character exists in pattern
            matchCount = (FP[ch] >= FW[ch]) ? matchCount + 1 : matchCount; // increase matchCount if character frequency in window is less than equal to that in pattern.

        // Check If all the characters are matched
        if (matchCount == requiredPattern.length())
        {
            //contacts the window from the left until pattern match is not hampered
            while (FP[inputString[startWindowIdx]] == 0 || FP[inputString[startWindowIdx]] < FW[inputString[startWindowIdx]]) //loops run if the character is not in pattern or the character appears more in the freqWindow than in freqPattern
            {
                FW[inputString[startWindowIdx]] -= 1;                
                startWindowIdx += 1;
            }

            //Keeps Track of the best window size 
            currentWindowSize = endWindowIdx - startWindowIdx;
            if (currentWindowSize < bestWindowSize)
            {
                bestWindowSize = currentWindowSize;
                bestStartWindowIdx = startWindowIdx;
            }

        }

    }



    return (bestStartWindowIdx == -1) ? "No Window found!" : inputString.substr(bestStartWindowIdx, bestWindowSize);


}






int main()
{
    
    cout << StringWindowWithHashmap("fizzbuzzfkjhjkh", "fuzz") << endl;
    cout << StringWindowWithArray("fizzbuzzfkjhjkh","fuzz") << endl;
    //cout << StringWindow("abcbdfdfbcvsdc") << endl;



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
