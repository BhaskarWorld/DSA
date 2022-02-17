// WarmUp_SearchAll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;



vector<int> stringSearch(string big, string small) {
    //store the occurrences in the result vector
    vector<int> result = {};

    int isPresent = big.find(small);

    while (isPresent != -1) {
        result.push_back(isPresent);
        isPresent = big.find(small, isPresent + 1);
    } 

    return result;
}




int main()
{
    string bigString = "I liked the movie, acting in movie was great";
    string smallString = "movie";
    for (int item : stringSearch(bigString, smallString)) cout << item << " ";
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
