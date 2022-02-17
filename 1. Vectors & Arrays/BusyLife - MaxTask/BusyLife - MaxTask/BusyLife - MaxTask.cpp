// BusyLife - MaxTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;


bool compare(pair<int, int> v1, pair<int, int> v2) {
    return v1.second < v2.second;
}




int countActivites(vector<pair<int, int> > v) {
    //Complete this method

    sort(v.begin(), v.end(), compare);
    int count = 1;
    int finish = v[0].second;

    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= finish) {
            count++;
            finish = v[i].second;
        }
    }
    return count;
}

int MaxTask(vector<pair<int, int>> activities)
{
    int maxTask = 0;
    int n = activities.size();

    vector<pair< int,pair<int, int>>> activitiesMap;
    for (pair<int, int> activity : activities)
        activitiesMap.push_back({ activity.second - activity.first, activity });

    sort(activitiesMap.begin(), activitiesMap.end());
    


    unordered_set<int> occupied;

    for (int k = 0; k < n; k++)
    {
        bool isEligible = true;
        pair<int, int> item = activitiesMap[k].second;
        for (int i = item.first; i < item.second; i++)
            if (occupied.find(i) != occupied.end()) isEligible = false;

        if (isEligible)
        {
            for (int i = item.first; i < item.second; i++) occupied.insert(i);
            maxTask++;
        }
            

    }





    return maxTask;
}

int main()
{
    vector<pair<int, int>> activities = { {7,9},{0,10},{4,5}, {8,9}, {4,10}, {5,7} };
    auto start = clock();
    cout << MaxTask(activities)<<endl;
    cout << clock() - start<<endl;
    start = clock();
    cout << countActivites(activities)<<endl;
    cout << clock() - start;
    
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
