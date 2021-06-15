#include <bits/stdc++.h>
using namespace std;

// void Showall();

// vector<pair<int, int>> Marks_Vector;
int SR_NO = 0;
int cnt = 6;

class Database
{
    vector<string> student_name;
    vector<int> sr_no;
    vector<int> physics;
    vector<int> chemistry;
    vector<int> maths;
    vector<int> total;
    vector<int> days1;
    // vector<pair<int, int>> bd;
    vector<pair<int, pair<int, pair<int, pair<int, pair<int, int>>>>>> myvec;
    // vector<pair<int, pair<int, pair<int, int>>>>  myvec;

public:
    // constructor
    Database()
    {
        string temp;
        char s;

        cout << "Do you want to generate a set of random data?" << endl
             << "Enter Y for yes" << endl;
        cin >> s;

        // if (s == 'Y')
        // {

        //     ofstream write;
        ifstream read1;

        // ofstream bday;
        //     string temp;

        // bday.open("Birthdate.dat");
        read1.open("NameData.dat");
        //     write.open("Onlyone.dat");
        //     srand(time(0));

        //     while (read1 >> temp)
        //     {
        //         cnt++;
        //         write << ((rand() % 50) + 51) << " ";
        //         write << ((rand() % 50) + 51) << " ";
        //         write << ((rand() % 50) + 51) << " ";
        //         write << temp << endl;

        //         bday << (rand() % 28) + 1 << " ";
        //         bday << (rand() % 12) + 1 << " ";
        //         bday << (rand() % 3) + 2001 << endl;
        //     }

        // }
        // write.close();
        // read1.close();
        // bday.close();

        // while (read1 >> temp)
        // {
        //     bday << (rand() % 28) + 1 << " ";
        //     bday << (rand() % 12) + 1 << " ";
        //     bday << (rand() % 3) + 2001 << endl;
        // }
        ifstream read2, read3;
        int p, c, m, i = 0, j = 0;
        int date, month, year, days;
        string name;

        read3.open("Birthdate.dat", ios::app);
        read2.open("Onlyone.dat");

        while (j < cnt)
        {
            read3 >> date >> month >> year;
            int days2 = ((year - 2001) * 12 * 28) + ((month - 1) * 28) + date;
            days1.push_back(-1 * days2);
            // bd.push_back(make_pair(days, j));
            j++;
        }
        read3.close();

        // sort(bd.rbegin(), bd.rend());

        // for (int i = 0; i < cnt; i++)
        //     sr_no.push_back(i);
        // for (int x = 0; x < cnt; x++)
        // {
        //     sr_no[x] = bd[x].second;
        // }
        int k = 0;
        while (k < cnt)
        {
            read2 >> p >> c >> m >> name;
            student_name.push_back(name);
            myvec.push_back(make_pair(p + c + m, make_pair(p, make_pair(c, make_pair(m, make_pair(days1[k], k + 1))))));
            k++;
        }
        read2.close();

        sort(myvec.rbegin(), myvec.rend());

        // for (int i = 0; i < cnt; i++)
        // {
        //     total.push_back(i);
        //     physics.push_back(i);
        //     chemistry.push_back(i);
        //     maths.push_back(i);
        // }

        // for (int i = 0; i < cnt; i++)
        // {
        //     total[i] = myvec[i].first;
        //     physics[i] = myvec[i].second.first;
        //     maths[i] = myvec[i].second.second.first;
        //     chemistry[i] = myvec[i].second.second.second.first;
        // }
    }

    void Show();
    void result()
    {
        // ofstream write2;
        // write2.open("myvectorpair.dat");
        // int s = myvec.size();

        for (int i = 0; i < cnt; i++)
        {
            cout << student_name[myvec[i].second.second.second.second.second - 1] << " ";
            cout << myvec[i].second.second.second.second.second << " ";
            cout << myvec[i].first << " ";
            cout << myvec[i].second.first << " ";
            cout << myvec[i].second.second.first << " ";
            cout << myvec[i].second.second.second.first << endl;
            // cout << "Sr no: " << sr_no[i] << " Name: " << student_name[sr_no[i]] << endl;
            // cout << "Total: " << total[i] << " ";
            // cout << "P: " << physics[i] << " ";
            // cout << "C: " << chemistry[i] << " ";
            // cout << "M: " << maths[i] << " "
            //      << endl
            //      << endl;
        }
        // write2.close();
    }
};

// sort(myvec.rbegin(), myvec.rend());

// cout << endl
//      << "---------------------------------------" << endl
//      << "              FINAL RESULT             " << endl
//      << "---------------------------------------" << endl;

// writeme<<"Sr No.\t\tName\t\tPhy\t\tChe\t\tMat\t\tTotal"<<endl;

// for(int i = 0;i < cnt; i++)
// {
//     writeme<<myvec[i].second.second.second.second<<"\t\t"<<student_name[bd[i].second]<<"\t\t"<<myvec[i].second.first<<"\t\t"<<myvec[i].second.second.first<<"\t\t"<<myvec[i].second.second.second.first<<"\t\t"<<myvec[i].first<<endl;
// cout << student_name[i] << "'s rank is " << i + 1 << endl
//      << "Total: " << myvec[i].first << endl
//      << "P: " << myvec[i].second.first << endl
//      << "C: " << myvec[i].second.second.first << endl
//      << "M: " << myvec[i].second.second.second.first << endl
//      << "Sr No: " << myvec[i].second.second.second.second << endl;
// cout << endl;
// for (int i = 0; i < cnt; i++)
// {
//     cout << student_name[Marks_Vector[i].second] << " got the rank " << (sr_no[i] + 1) << "with ID " << Marks_Vector[i].second << endl;
// }
// cout << endl;

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
    system("CLS");
    Database student;
    // student.Show();
    student.result();

    return 0;
}