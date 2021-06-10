#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> marks;
int srno = 0;

class students
{
public:
    string name;
    int myownmarks;
};

int main()
{
    students arr[4];
    arr[0].name = "A";
    arr[1].name = "B";
    arr[2].name = "C";
    arr[3].name = "D";

    vector<pair<int, int>> marks;
    vector<string> name;
    name.push_back("Shrey");
    name.push_back("Vandan");
    name.push_back("Kashyap");
    name.push_back("Kavan");

    ifstream fin("marksfile.dat", ios::in);
    int marks_individual;

    for (int i = 0; i < 4; ++i)
    {
        // fin >> marks_individual;

        fin >> marks_individual;
        marks.push_back(make_pair(marks_individual, i));
    }

    fin.close();

    sort(marks.rbegin(), marks.rend());

    for (int i = 0; i < 4; i++)
    {
        cout << "rank "
             << i + 1 << " : " << arr[i].name << " with marks " << marks[i].first << endl;
    }

    return 0;
}