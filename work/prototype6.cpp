#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> phy;
vector<pair<int, int>> che;
vector<pair<int, int>> mat;

vector<pair<int, pair<int, pair<int, pair<int, pair<int, int>>>>>> myvec;
vector<string> student_name;
vector<pair<pair<int, int>, pair<int, int>>> bday;

#define E1(i) myvec[i].first
#define E2(i) myvec[i].second.first
#define E3(i) myvec[i].second.second.first
#define E4(i) myvec[i].second.second.second.first
#define E5(i) myvec[i].second.second.second.second.first
#define E6(i) myvec[i].second.second.second.second.second

int cnt = 0;
int cnt2;
int belowequal;

class Database
{
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

    void printtoconsole()
    {
        int x = 0;
        while (x != cnt)
        {
            int newsr = E6(x);
            int day = bday[newsr - 1].first.second;
            int month = bday[newsr - 1].second.first;
            int year = bday[newsr - 1].second.second;

            cout << "Rank " << x + 1 << endl;
            cout << "Sr. No: " << E6(x) << "\t"
                 << "Name: " << student_name[newsr - 1] << " ";
            if (day < 10)
                cout << "Birthdate: "
                     << "0" << day << "/" << month << "/" << year << endl;
            else
                cout << "Birthdate: " << day << "/" << month << "/" << year << endl;
            cout << "Total: " << E1(x) << " ";
            cout << "Physics: " << E3(x) << " ";
            cout << "Chemistry: " << E4(x) << " ";
            cout << "Maths: " << E2(x) << endl;
            cout << endl;
            x++;
        }
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
            belowequal = cnt;
            read1.close();
        }
    }

    void callall()
    {
        this->writeraw();
        this->oursort();
        // this->sorteddata();
        // this->printtoconsole();
    }
};

class individual
{
    string name;
    int total;
    int physics;
    int maths;
    int chemistry;
    int rank;
    int srno;

public:
    float phyper;
    float cheper;
    float matper;
    float totper;
    void assign()
    {
        this->name = student_name[E6(cnt2) - 1];
        this->total = E1(cnt2);
        this->maths = E2(cnt2);
        this->physics = E3(cnt2);
        this->chemistry = E4(cnt2);
        this->srno = E6(cnt2);
        this->rank = cnt2 + 1;

        phy.push_back(make_pair(E3(cnt2), rank));
        che.push_back(make_pair(E4(cnt2), rank));
        mat.push_back(make_pair(E2(cnt2), rank));

        cnt2++;
    }

    void sorteddata()
    {
        ofstream write1;
        write1.open("Ranks.dat", ios::app);
        int x = 0;
        int newsr = srno;
        int day = bday[newsr - 1].first.second;
        int month = bday[newsr - 1].second.first;
        int year = bday[newsr - 1].second.second;

        write1 << "Rank " << rank << endl;
        write1 << "Sr. No: " << srno << "\t"
               << "Name: " << name << " ";
        if (day < 10)
            write1 << "Birthdate: "
                   << "0" << day << "/" << month << "/" << year << endl;
        else
            write1 << "Birthdate: " << day << "/" << month << "/" << year << endl;
        write1 << "Total: " << total << " ";
        write1 << "Physics: " << physics << " ";
        write1 << "Chemistry: " << chemistry << " ";
        write1 << "Maths: " << maths << endl;
        write1 << "Physics PR: " << std::fixed << std::setprecision(2) << phyper << " ";
        write1 << "Chemistry PR: " << std::fixed << std::setprecision(2) << cheper << " ";
        write1 << "Maths PR: " << std::fixed << std::setprecision(2) << matper << endl;
        // write1 << "Total PR: " << totper << endl;
        write1 << "Total PR: " << std::fixed << std::setprecision(2) << totper << endl;

        write1 << endl;
        write1.close();
    }
};

individual *person;

void percentile()
{
    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
        {
            if (phy[i].first != phy[i - 1].first)
                belowequal = cnt - i;

            person[phy[i].second - 1].phyper = ((float)(belowequal * 100) / (float)cnt);
        }
        else
        {
            person[phy[0].second - 1].phyper = 100;
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
        {
            if (che[i].first != che[i - 1].first)
                belowequal = cnt - i;

            person[che[i].second - 1].cheper = ((float)(belowequal * 100) / (float)cnt);
        }
        else
        {
            person[che[0].second - 1].cheper = 100;
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
        {
            if (mat[i].first != mat[i - 1].first)
                belowequal = cnt - i;

            person[mat[i].second - 1].matper = ((float)(belowequal * 100) / (float)cnt);
        }
        else
        {
            person[mat[0].second - 1].matper = 100;
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
        {
            if (E1(i) != E1(i - 1))
                belowequal = cnt - i;

            person[i].totper = ((float)(belowequal * 100) / (float)cnt);
        }
        else
        {
            person[0].totper = 100;
        }
    }
}

void sortall()
{
    sort(phy.rbegin(), phy.rend());
    sort(che.rbegin(), che.rend());
    sort(mat.rbegin(), mat.rend());
}

int main()
{
    system("CLS");

    Database student;
    student.callall();

    person = new individual[cnt];

    cnt2 = 0;

    for (int i = 0; i < cnt; i++)
    {
        person[i].assign();
    }

    sortall();

    percentile();

    ofstream openclose;
    openclose.open("Ranks.dat");
    openclose.close();

    for (int i = 0; i < cnt; i++)
    {
        person[i].sorteddata();
    }
    return 0;
}