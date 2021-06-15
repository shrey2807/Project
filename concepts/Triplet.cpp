#include <bits/stdc++.h>
using namespace std;

struct Test
{
    int x, y, z;
};

int main()
{
    // Creating a vector of Test
    vector<Test> Marks_Vector;

    Marks_Vector.push_back({2, 31, 102});
    Marks_Vector.push_back({5, 23, 114});
    Marks_Vector.push_back({9, 10, 158});

    // sort(Marks_Vector.rbegin(), Marks_Vector.rend());

    for (int i = 0; i < 3; i++)
    {
        cout << Marks_Vector[i].x
             << " " << Marks_Vector[i].y
             << " " << Marks_Vector[i].z << endl;
    }

    return 0;
}
