// PairSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<list>
#include <iostream>
#include<unordered_set>
using namespace std;


list<pair<int,int>> FindPairSum(vector<int> integers, int k) {
    list<pair<int, int>> pairSumList;
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


int main()
{
    vector <int> integers = {2,1,8,6,-2,5,3,0};  

    list<pair<int, int>> pairSumList = FindPairSum(integers, 8);
    for (pair<int,int> pairsum : pairSumList)
        cout <<"(" << pairsum.first << ", " << pairsum.second<<")" << "\n";    
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
