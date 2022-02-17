// Space20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;




string Space2(char *input)
{

    int nSpaces = 0;
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == ' ') nSpaces++; 
        i++;
    }
    

    
    

    int newLen = strlen(input) + (2 * nSpaces);
    input[newLen--] = '\0';

    for (int i = strlen(input) - 1; i >= 0;i--)
    {
        if (input[i] == ' ')
        {
            input[newLen--] = '0';
            input[newLen--] = '2';
            input[newLen--] = '%';
        }

        else  input[newLen--] = input[i];
        
    }

    
    

    return input;
}


int main()
{

    char input[1000];
    cin.getline(input, 1000);
    Space2(input);
    cout << input;
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
