// LongestBand.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


template<typename K, typename V>
void print_map(std::unordered_map<K, V> const& m)
{
    for (auto const& pair : m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}


int LongestBand(vector<int> vec)
{
    unordered_map<int, bool> bandItems;
    for (int i : vec)
        bandItems.insert({ i,false });
    
    int longestBand = 0;
    int band = 0;
    for (auto& it : bandItems)
    {
        
        int currentItem = it.first;
        int next = currentItem ;
        int prev = currentItem ;

        if (!bandItems[currentItem])
        {

            band = 1;
            bandItems[currentItem] = true;

            bool forward = true;
            bool backward = true;


            while (forward)
            {   
                next += 1;
                if (bandItems.find(next) == bandItems.end()) forward = false;
                else
                {
                    if (bandItems[next]) backward = false;
                    else
                    {
                        bandItems[next] = true;
                        band += 1;
                    }
                }
            }

            int j = 1;
            while (backward)
            {
                prev -= 1;
                if (bandItems.find(prev) == bandItems.end()) backward = false;
                else
                {  
                    if (bandItems[prev]) backward = false;
                    else
                    {
                        bandItems[prev] = true;
                        band += 1;
                    }
                }
            }
        }
        longestBand = max(longestBand, band);
    }
    



    return longestBand;
}








int main()
{
    vector<int> bandItems = {1,9,3,0,18,5,2,4,10,7,12,6};
    cout<< LongestBand(bandItems);
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
