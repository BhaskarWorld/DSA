// BiggestNumberString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool lexicalCompare(int i1, int i2)
{
    string s1 = to_string(i1);
    string s2 = to_string(i2);
    return s1 + s2 > s2 + s1;
}


string BiggestNumberString(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), lexicalCompare);
    string out = "";
    for (int i : numbers)out += to_string(i);
    return out;
}



int main()
{
    cout<< BiggestNumberString({ 10,11,20,30,3 })<<endl;
    
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
