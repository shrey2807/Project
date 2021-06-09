#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int num;
    cin >> num;
    srand(time(0));
    cout << endl;
    for (int i = 0; i < num; i++)
    {
        cout << ((rand() % 50) + 50) << endl;
        return 0;
    }
}
