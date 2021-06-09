#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, current_mark;
    cin >> num;

    ofstream outdata;

    outdata.open("physics.dat");
    if (!outdata)
    {
        cout << "Error: file could not be opened" << endl;
        exit(1);
    }

    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        current_mark = ((rand() % 50) + 51);
        outdata << current_mark << endl;
    }
    outdata.close();

    outdata.open("chemistry.dat");
    if (!outdata)
    {
        cout << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (int i = 0; i < num; i++)
    {
        current_mark = ((rand() % 50) + 51);
        outdata << current_mark << endl;
    }
    outdata.close();

    outdata.open("maths.dat");
    if (!outdata)
    {
        cout << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (int i = 0; i < num; i++)
    {
        current_mark = ((rand() % 50) + 51);
        outdata << current_mark << endl;
    }
    outdata.close();

    return 0;
}
