// StringTokenizerDIY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;





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
            input += i+1;
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
    char input[1000];
    cin.getline(input, 1000);

    char* token = StringTokenizerDIY(input, ' ');

    while (token != NULL)
    {
        cout << token << endl;
        token = StringTokenizerDIY(NULL, ' ');
    }
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
