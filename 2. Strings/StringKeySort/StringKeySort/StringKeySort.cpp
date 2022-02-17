// StringKeySort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool compareStr(pair<string, string> a, pair<string, string> b)
{
    return a.first < b.first;
}
bool compareInt(pair<string, string> a, pair<string, string> b)
{
    return stoi(a.first) < stoi(b.first);
}



char* StringTokenizerDIY(char* str, char delim)
{
    static char* input = NULL;
    if (str != NULL) input = str;
    if (input == NULL) return NULL;

    char* token = new char[strlen(input) + 1];


    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != delim) token[i] = input[i];
        else
        {
            token[i] = '\0';
            input += i + 1;
            return token;
        }
    }

    //for last token
    token[i] = '\0';

    input = NULL;

    return token;

}


int main()
{
    bool isNumeric = false;
    bool isReverse = false;
    int keyIndex = 2;
    vector<string> input = { "92 022","82 12","77 13" };
    vector<pair<string, string>> keyString;

    for (string x : input)
    {
        
        char* token = StringTokenizerDIY((char*)x.c_str(), ' ');
        int i = 1;
        while (token != NULL and i++<keyIndex)     
            token = StringTokenizerDIY(NULL, ' ');              
        
        keyString.push_back({ token, (char*)x.c_str() });

    }

    if (isNumeric) sort(keyString.begin(), keyString.end(),compareInt);
    else sort(keyString.begin(), keyString.end(), compareStr);
    if (isReverse) reverse(keyString.begin(), keyString.end());
    for (pair<string,string> pair: keyString) cout << pair.second << endl;

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
