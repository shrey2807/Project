#include <bits/stdc++.h>
using namespace std;

int SR_NO = 0;
int cnt = 0;

class Database
{
    vector<string> student_name;
    vector<int> sr_no;
    vector<pair<int, pair<int, pair<int, pair<int, pair<int, int>>>>>> myvec;

public:
    // constructor
    Database()
    {
        string temp;
        char s;

        cout << "Do you want to generate a set of random data?" << endl
             << "Enter Y for yes" << endl;
        cin >> s;

        if (s == 'Y')
        {

            // ofstream write;
            // ofstream bday;

            ifstream read1;

            int bd = 0;
            string temp;

            // bday.open("Birthdate.dat");
            read1.open("NameData.dat");
            // write.open("Onlyone.dat");
            srand(time(0));

            while (read1 >> temp)
            {
                int p = ((rand() % 50) + 51);
                int c = ((rand() % 50) + 51);
                int m = ((rand() % 50) + 51);

                int date = (rand() % 28) + 1;
                int month = (rand() % 12) + 1;
                int year = (rand() % 3) + 2001;
                int days = ((year - 2001) * 12 * 28) + ((month - 1) * 28) + date;

                student_name.push_back(temp);

                myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(days, cnt + 1))))));
                cnt++;
            }
            // write.close();
            read1.close();
            // bday.close();
        }

        sort(myvec.rbegin(), myvec.rend());
        // ifstream read2, read3;
        // int p, c, m, i = 0, j = 0;
        // int date, month, year, days;
        // string name;

        // read3.open("Birthdate.dat", ios::app);
        // read2.open("Onlyone.dat");

        // while (j < cnt)
        // {
        //     read3 >> date >> month >> year;
        //     int days2 = ((year - 2001) * 12 * 28) + ((month - 1) * 28) + date;
        //     days1.push_back(-1 * days2);
        //     j++;
        // }
        // read3.close();

        // int k = 0;
        // while (k < cnt)
        // {
        //     read2 >> p >> c >> m >> name;
        //     student_name.push_back(name);
        //     myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(days1[k], k + 1))))));
        //     k++;
        // }
        // read2.close();
    }
    void result()
    {

        // for (int i = 0; i < cnt; i++)
        // {
        //     cout << student_name[myvec[i].second.second.second.second.second - 1] << " ";
        //     cout << myvec[i].second.second.second.second.second << " ";
        //     cout << myvec[i].first << " ";
        //     cout << myvec[i].second.first << " ";
        //     cout << myvec[i].second.second.first << " ";
        //     cout << myvec[i].second.second.second.first << endl;
        // }
    }

    void writeinfile()
    {
        ofstream write1("Final1.dat");
        int p, c, m, x = 0, y = 0;
        int day, month, year;
        string name;
        while (x != cnt)
        {
            write1 << "Rank " << x + 1 << endl;
            write1 << "Sr. No: " << myvec[x].second.second.second.second.second << "\t"
                   << "Name: " << student_name[myvec[x].second.second.second.second.second - 1] << endl;
            write1 << "Total: " << myvec[x].first << " ";
            write1 << "Physics: " << myvec[x].second.second.first << " ";
            write1 << "Maths: " << myvec[x].second.first << " ";
            write1 << "Chemistry: " << myvec[x].second.second.second.first << endl;
            write1 << endl;
            x++;
        }

        ofstream write2("Final2.dat");
        ifstream readrandom;
        ifstream readrandombday;

        readrandom.open("Onlyone.dat");
        readrandombday.open("Birthdate.dat");

        while (y != cnt)
        {
            readrandom >> p >> c >> m >> name;
            readrandombday >> day >> month >> year;

            write2 << "Sr No: " << y + 1 << "\t";
            write2 << "Name : " << name << "\t";

            if (day < 10)
                write2 << "Birthdate: "
                       << "0" << day << "/" << month << "/" << year << endl;
            else
                write2 << "Birthdate: " << day << "/" << month << "/" << year << endl;
            write2 << "Physics: " << p << "\t";
            write2 << "Chemistry: " << c << "\t";
            write2 << "Maths: " << m << "\t";
            write2 << "Total: " << p + c + m;
            write2 << endl
                   << endl;
            y++;
        }

        readrandom.close();
        readrandombday.close();
    }
};

int main()
{
    system("CLS");
    Database student;
    student.result();
    student.writeinfile();

    return 0;
}