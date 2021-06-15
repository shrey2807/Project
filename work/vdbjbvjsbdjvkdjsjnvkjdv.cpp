#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> tp;
    tp.push_back(5);
    tp.push_back(7);
    tp.push_back(10);
    vector<int>::iterator it;
    int one = 1;
    cout << tp.size();
    tp.erase(tp.begin() + one);
    cout << tp.size();
    // cout << tp[0] << " " << tp[1] << " " << tp[2];
    return 0;
}