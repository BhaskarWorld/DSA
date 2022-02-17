// SortSubSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void GetSubsequences(string input, string output, vector<string> &v)
{
    //base case(leaf node)
    if (input.size() == 0)
    {
        v.push_back(output);
        return;
    }

    //recursion case
    char ch = input[0];
    string reducedInput = input.substr(1);

    //include the letter
    GetSubsequences(reducedInput, output + ch, v);


    //exclude the letter
    GetSubsequences(reducedInput, output , v);
}

bool lenCompare(string s1, string s2)
{
    if (s1.length() == s2.length()) return s1 < s2;
    return s1.length() < s2.length();
}

int main()
{
    vector<string> Subsequence;
    string input = "abcd";
    string output = "";
    GetSubsequences(input, output, Subsequence);
    sort(Subsequence.begin(), Subsequence.end(), lenCompare);
    for (string item : Subsequence) cout << item << " ";
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
