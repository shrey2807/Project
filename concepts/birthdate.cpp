#include <bits/stdc++.h>
using namespace std;

// void Showall();

// vector<pair<int, int>> Marks_Vector;
int SR_NO = 0;
int cnt = 0;

class Database
{
    vector<string> student_name;
    vector<int> sr_no;
    vector<int> physics;
    vector<int> chemistry;
    vector<int> maths;
    vector<int> total;
    vector<pair<int, int>> bd;
    vector<pair<int, pair<int, pair<int, pair<int, int>>>>> myvec;
    // vector<pair<int, pair<int, pair<int, int>>>>  myvec;

public:
    // constructor
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

            ofstream bday;
            string temp;

            bday.open("Birthdate.dat");
            read1.open("NameData.dat");
            write.open("Onlyone.dat");
            srand(time(0));

            while (read1 >> temp)
            {
                cnt++;
                write << ((rand() % 50) + 51) << " ";
                write << ((rand() % 50) + 51) << " ";
                write << ((rand() % 50) + 51) << " ";
                write << temp << endl;

                bday << (rand() % 28) + 1 << " ";
                bday << (rand() % 12) + 1 << " ";
                bday << (rand() % 3) + 2001 << endl;
            }
            write.close();
            read1.close();
            bday.close();
            string str;
        }
        ifstream read2, read3;
        int p, c, m, i = 0, j = 0;
        int date, month, year;
        string name;

        read3.open("Birthdate.dat");
        read2.open("Onlyone.dat");

        while (read3 >> date >> month >> year)
        {
            int days = ((year - 2001) * 12 * 28) + ((month - 1) * 28) + date;
            bd.push_back(make_pair(days, j));
            j++;
        }

        sort(bd.begin(), bd.end());
        for (int x = 0; x < cnt; x++)
        {
            sr_no[bd[x].second] = x;
        }

        while (read2 >> p >> c >> m >> name)
        {
            student_name.push_back(name);
            myvec.push_back(make_pair(p + c + m, make_pair(p, make_pair(c, make_pair(m, sr_no[i])))));
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
                 << "M: " << myvec[i].second.second.second.first << endl
                 << "Sr No: " << myvec[i].second.second.second.second << endl;
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
