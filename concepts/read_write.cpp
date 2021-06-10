#include <bits/stdc++.h>
using namespace std;

// for exit function
// This program output values from an array to a file named example2.dat

int main()
{
    // int i;
    ofstream outdata;              // outdata is like cin
    int i;                         // loop index
    int num[5] = {4, 3, 6, 7, 12}; // list of output values

    outdata.open("example.dat"); // opens the file
    if (!outdata)
    { // file couldn't be opened
        cout << "Error: file could not be opened" << endl;
        exit(1);
    }

    for (i = 0; i < 5; ++i)
        outdata << num[i] << " ";
    outdata.close();

    // reading only
    ifstream fin("example.dat", ios::in);
    int marks;

    for (i = 0; i < 3; ++i)
    {
        fin >> marks;
        cout << marks << endl;
    }

    for (i = 0; i < 4; ++i)
    {
        fin >> marks;
        cout << marks << endl;
    }
    // fin >> marks;
    // cout<<marks<<endl;

    fin.close();
    return 0;
}