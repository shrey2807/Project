#include <bits/stdc++.h>
using namespace std;

// void Showall();

// vector<pair<int, int>> Marks_Vector;
int SR_NO = 0;
int cnt = 0;

class Database
{
    // vector<int> sr_no;
    // vector<int> physics;
    // vector<int> chemistry;
    // vector<int> maths;
    // vector<int> total;

public:
    // constructor
    vector<string> student_name;
    vector<pair<int, pair<int, pair<int, int>>>> myvec;
    Database()
    {
        // string temp;
        char s;

        cout << "Do you want to generate a set of random data?" << endl
             << "Enter Y for yes" << endl;
        cin >> s;

        if (s == 'Y')
        {
            ofstream write;
            ifstream read1;
            string temp;

            write.open("Onlyone.dat");
            read1.open("NameData.dat");
            srand(time(0));

            while (read1 >> temp)
            {
                cnt++;
                write << ((rand() % 50) + 51) << " ";
                write << ((rand() % 50) + 51) << " ";
                write << ((rand() % 50) + 51) << " ";
                write << temp << endl;
            }
            write.close();
            read1.close();
            string str;
        }
        ifstream read2;
        int p, c, m, i = 0;
        string name;
        read2.open("Onlyone.dat");

        while (read2 >> p >> c >> m >> name)
        {
            student_name.push_back(name);
            myvec.push_back(make_pair(p + c + m, make_pair(p, make_pair(c, m))));
            i++;
        }
        read2.close();
    }

    void Show();
    void result()
    {

        int s = myvec.size();
        sort(myvec.rbegin(), myvec.rend());

        cout << endl
             << "---------------------------------------" << endl
             << "              FINAL RESULT             " << endl
             << "---------------------------------------" << endl;

        for (int i = 0; i < s; i++)
        {
            cout << student_name[i] << "'s rank is " << i + 1 << endl
                 << "Total: " << myvec[i].first << endl
                 << "P: " << myvec[i].second.first << endl
                 << "C: " << myvec[i].second.second.first << endl
                 << "M: " << myvec[i].second.second.second << endl;
            cout << endl;
        }
        // for (int i = 0; i < cnt; i++)
        // {
        //     cout << student_name[Marks_Vector[i].second] << " got the rank " << (sr_no[i] + 1) << "with ID " << Marks_Vector[i].second << endl;
        // }
        cout << endl;
    }
};

// void Database::Show()
// {
//     for (int i = 0; i < cnt; i++)
//     {
//         cout << endl;
//         cout << "-------------------------------------------- " << endl
//              << "Application number : " << sr_no[i] << endl
//              << "Name : " << student_name[i] << endl
//              << "Marks : " << endl
//              << "P : " << physics[i] << endl
//              << "C : " << chemistry[i] << endl
//              << "M : " << maths[i] << endl
//              << "Total : " << total[i] << endl
//              << "-------------------------------------------- "
//              << endl;
//     }
//     return;
// }

int main()
{
    Database student;
    // student.Show();
    student.result();

    return 0;
}
