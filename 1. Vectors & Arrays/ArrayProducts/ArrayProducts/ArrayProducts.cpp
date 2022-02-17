// ArrayProducts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
using namespace std;


vector<int> ProductArray(vector<int> arr)
{
    

    int n = arr.size();
    vector<int> productLeft(n, 1);
    vector<int> productRight(n,1);

    int leftProductTotal = 1;
    int rightProductTotal = 1;
    for (int i = 0; i < n; i++)
    {
        productLeft[i] = leftProductTotal;
        leftProductTotal *= arr[i];

        int j = n - i - 1;
        productRight[j] = rightProductTotal;
        rightProductTotal *= arr[j];
    }

    for (int i = 0; i < n; i++)    
        arr[i] = productLeft[i] * productRight[i];
    


    return arr;
}






int main()
{
    vector<int> arr = { 1,2,3,4,5 };
    cout << "{ ";
    for (int item : ProductArray(arr)) cout << item << " ";
    cout << "}";
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
