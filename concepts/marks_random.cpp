#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, current_mark;
    cin >> num;

    ofstream outdata1;
    ofstream outdata2;
    ofstream outdata3;

    outdata1.open("physics.dat");
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
    outdata1.close();

    outdata2.open("chemistry.dat");
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
    outdata2.close();

    outdata3.open("maths.dat");
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
    outdata3.close();

    return 0;
}
