#include <bits/stdc++.h>
using namespace std;

#define E1(i) myvec[i].first
#define E2(i) myvec[i].second.first
#define E3(i) myvec[i].second.second.first
#define E4(i) myvec[i].second.second.second.first
#define E5(i) myvec[i].second.second.second.second.first
#define E6(i) myvec[i].second.second.second.second.second

int cnt = 0;

class Database
{
    vector<string> student_name;
    vector<pair<pair<int, int>, pair<int, int>>> bday;
    vector<pair<int, pair<int, pair<int, pair<int, pair<int, int>>>>>> myvec;

    void writeraw()
    {
        int x = 0;
        int day, month, year;

        ofstream write2("Rawdata.dat");
        while (x != cnt)
        {
            day = bday[x].first.second;
            month = bday[x].second.first;
            year = bday[x].second.second;

            write2 << "Sr No: " << E6(x) << "\t";
            write2 << "Name : " << student_name[x] << "\t";

            if (day < 10)
                write2 << "Birthdate: "
                       << "0" << day << "/" << month << "/" << year << endl;
            else
                write2 << "Birthdate: " << day << "/" << month << "/" << year << endl;

            write2 << "Physics: " << E3(x) << "\t";
            write2 << "Chemistry: " << E4(x) << "\t";
            write2 << "Maths: " << E2(x) << "\t";
            write2 << "Total: " << E1(x);
            write2 << endl
                   << endl;
            x++;
        }
        write2.close();
    }

    void sorteddata()
    {
        ofstream write1("Ranks.dat");
        int x = 0;
        while (x != cnt)
        {
            int newsr = E6(x);
            int day = bday[newsr - 1].first.second;
            int month = bday[newsr - 1].second.first;
            int year = bday[newsr - 1].second.second;

            write1 << "Rank " << x + 1 << endl;
            write1 << "Sr. No: " << E6(x) << "\t"
                   << "Name: " << student_name[newsr - 1] << " ";
            if (day < 10)
                write1 << "Birthdate: "
                       << "0" << day << "/" << month << "/" << year << endl;
            else
                write1 << "Birthdate: " << day << "/" << month << "/" << year << endl;
            write1 << "Total: " << E1(x) << " ";
            write1 << "Physics: " << E3(x) << " ";
            write1 << "Chemistry: " << E4(x) << endl;
            write1 << "Maths: " << E2(x) << " ";
            write1 << endl;
            x++;
        }
        write1.close();
    }

    void oursort()
    {
        sort(myvec.rbegin(), myvec.rend());
    }

public:
    Database()
    {
        string temp;
        char s;

        cout << "Do you want to generate a set of random data?" << endl
             << "Enter Y for yes" << endl;
        cin >> s;

        if (s == 'Y')
        {
            ifstream read1;
            string temp;

            read1.open("NameData.dat");
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

                bday.push_back(make_pair(make_pair(cnt + 1, date), make_pair(month, year)));

                myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(-1 * days, cnt + 1))))));
                cnt++;
            }
            read1.close();
        }
    }

    void callall()
    {
        this->writeraw();
        this->oursort();
        this->sorteddata();
    }
};

int main()
{
    system("CLS");
    Database student;
    student.callall();
    return 0;
}