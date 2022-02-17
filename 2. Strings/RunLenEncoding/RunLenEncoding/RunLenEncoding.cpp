// RunLenEncoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
using namespace std;

//str is the input the string
string compressString(const string& str)
{
    string out = "";
    int counter = 1;
    int i = 1;
    char track = str[0];
    while (str[i] != '\0')
    {
        char current = str[i];
        if (current == track) counter++;
        else
        {
            out += track + to_string(counter);
            counter = 1;
            track = str[i];
        }
        i++;
    }
    out += track + to_string(counter);
    return out.length() < str.length() ? out : str;
}



int main()
{
    cout << compressString("bbbaaaadexxxxxx");
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
