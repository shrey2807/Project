#include <bits/stdc++.h>
using namespace std;

void Showall();

vector<pair<int, int>> Marks_Vector;
int SR_NO = 0;

class Database
{

public:
    string student_name;
    int sr_no;
    int physics;
    int chemistry;
    int maths;
    int total;

    // constructor
    Database()
    {
        // string str;
        ifstream Name;
        ifstream phy;
        ifstream che;
        ifstream mat;

        // assigning sr.no to students
        this->sr_no = SR_NO;

        // for reading student's name from NameData.dat file
        student_name.reserve(15);
        Name.open("NameData1.dat");
        for (int i = 0; i < sr_no; i++)
        {
            Name >> student_name;
            // getline(Name, str);
        }

        // getline(Name, student_name);
        Name >> student_name;

        // for reading data from PhysicsData.dat file
        phy.open("PhysicsData.dat", ios::in);
        phy.ignore(3 * sr_no) >> this->physics;
        phy.close();

        // for reading data from ChemistryData.dat file
        che.open("ChemistryData.dat", ios::in);
        che.ignore(3 * sr_no) >> this->chemistry;
        che.close();

        // for reading data from MathData.dat file
        mat.open("MathData.dat", ios::in);
        mat.ignore(3 * sr_no) >> this->maths;
        mat.close();

        // calculating the total marks
        this->total = this->chemistry + this->maths + this->physics;
        Marks_Vector.push_back(make_pair(this->total, sr_no));
        SR_NO++;
    }

    void Show();
};

Database student[10];

void Database::Show()
{
    cout << endl;
    cout << "-------------------------------------------- " << endl
         << "Application number : " << sr_no << endl
         << "Name : " << student_name << endl
         << "Marks : " << endl
         << "P : " << physics << endl
         << "C : " << chemistry << endl
         << "M : " << maths << endl
         << "Total : " << total << endl
         << "-------------------------------------------- "
         << endl;
    return;
};

void Showall()
{
    for (int i = 0; i < 10; i++)
    {
        student[i].Show();
    }
    return;
};

int main()
{
    Showall();

    sort(Marks_Vector.rbegin(), Marks_Vector.rend());

    cout << endl
         << "---------------------------------------" << endl
         << "              FINAL RESULT             " << endl
         << "---------------------------------------" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "rank " << i + 1 << " : " << student[Marks_Vector[i].second].student_name << " with marks " << Marks_Vector[i].first << endl;
    }
    cout << endl;

    return 0;
}