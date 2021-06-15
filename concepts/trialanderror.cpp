#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, pair<int, pair<int, pair<int, pair<int, int>>>>>> myvec;
    for (int i = 0; i < 5; i++)
    {
        myvec.push_back(make_pair(3 * i, make_pair(i, make_pair(i, make_pair(i, make_pair(2 * i, 0))))));
    }

    for (int i = 0; i < 5; i++)
    {
        cout << myvec[i].first << " ";
        cout << myvec[i].second.first << " ";
        cout << myvec[i].second.second.first << " ";
        cout << myvec[i].second.second.second.first << " ";
        cout << myvec[i].second.second.second.second.first << " ";
        cout << myvec[i].second.second.second.second.second << endl;
    }

    return 0;
}