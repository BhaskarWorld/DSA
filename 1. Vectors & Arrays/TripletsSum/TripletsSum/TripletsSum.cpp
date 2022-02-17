// TripletsSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <time.h>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;


vector<pair<int, int>> FindPairSum(vector<int> integers, int k) {
    vector<pair<int, int>> pairSumList;
    unordered_set<int> s;
    for (int item : integers) {

        int first = item;
        int second = k - first;
        if (s.find(second) != s.end()) {
            pairSumList.push_back({ first,second });
            s.erase(second);
        }
        s.insert(first);
    }
    return pairSumList;
}



vector<vector<int>> TripletsSum(vector<int> input, int targetSum)
{
    //This method uses the two pointer approach to find the triplets.
    // The input array must be sorted.
    //Time Complexity: O(N^2)
    vector<vector<int>> tripletSum;
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        int lftPtr = i + 1;
        int rgtPtr = n - 1;

        while (lftPtr < rgtPtr)
        {
            int currentSum = input[i];
            currentSum += input[lftPtr];
            currentSum += input[rgtPtr];

            if (currentSum == targetSum)   tripletSum.push_back({ input[i], input[lftPtr++], input[rgtPtr--] });
            else if (currentSum < targetSum) lftPtr++;
            else rgtPtr--;
        }
    }

    return tripletSum;
}

vector<vector<int>> TripletsSumUsingPairSum(vector<int> input, int targetSum)
{
    //This method uses the PairSum approach to find the triplets.
    // The input array must be sorted.
    //Time Complexity: O(N^2)
    vector<vector<int>> tripletSum;
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        int lftPtr = i + 1;
        int rgtPtr = n - 1;

        auto first = input.begin() + lftPtr;
        auto last = input.begin() + rgtPtr + 1;

        // Copy the element
        vector<int> vector(first, last);            
        int currentInt = input[i];
        for (pair<int, int> p : FindPairSum(vector, targetSum - currentInt))
            tripletSum.push_back({ currentInt , p.second, p.first});
    }

    return tripletSum;
}




int main()
{

    vector<int> intVector = { 1,2,3,4,5,6,7,8,9,15 };
    int targetSum = 18;

    const clock_t begin_time = clock();
    vector<vector<int>> result = TripletsSumUsingPairSum(intVector, targetSum);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    cout << float(clock() - begin_time) ;
    cout << endl;
    
    
    cout << endl;



    const clock_t begin_time2 = clock();
    vector<vector<int>> result2 = TripletsSum(intVector, targetSum);

    for (int i = 0; i < result2.size(); i++) {
        for (int j = 0; j < result2[i].size(); j++)
            cout << result2[i][j] << " ";
        cout << endl;
    }
    cout << float(clock() - begin_time2) ;
    cout << endl;



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
