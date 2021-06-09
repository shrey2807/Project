#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> marks;
int srno = 0;

class students
{
public:
    string name;
    int myownmarks;
    int physics;
    int chemistry;
    int maths;
    int total;

    students()
    {
        ifstream fin("marksfile.dat", ios::in);

        fin.ignore(4 * srno) >> myownmarks;
        marks.push_back(make_pair(myownmarks, srno));

        fin.close();
        srno++;
    }
};

int main()
{
    students arr[4];
    arr[0].name = "A";
    arr[1].name = "B";
    arr[2].name = "C";
    arr[3].name = "D";

    sort(marks.rbegin(), marks.rend());

    for (int i = 0; i < 4; i++)
    {
        cout << "rank "
             << i + 1 << " : " << arr[marks[i].second].name << " with marks " << marks[i].first << endl;
    }

    // cout << arr[0].myownmarks << " " << arr[0].name << endl;
    // cout << arr[1].myownmarks << " " << arr[1].name << endl;
    // cout << arr[2].myownmarks << " " << arr[2].name << endl;
    // cout << arr[3].myownmarks << " " << arr[3].name << endl;

    return 0;
}