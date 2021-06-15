#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> phy;
vector<pair<int, int>> che;
vector<pair<int, int>> mat;

vector<pair<int, pair<int, pair<int, pair<int, pair<int, int>>>>>> myvec;
vector<string> student_name;
vector<pair<pair<int, int>, pair<int, int>>> bday;
vector<string> colleges;

#define E1(i) myvec[i].first
#define E2(i) myvec[i].second.first
#define E3(i) myvec[i].second.second.first
#define E4(i) myvec[i].second.second.second.first
#define E5(i) myvec[i].second.second.second.second.first
#define E6(i) myvec[i].second.second.second.second.second

int cnt = 0;
int cnt2;
int belowequal;
void collegewrite(ofstream &write1, int clg1, int round, vector<int> &choices);

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
class college
{
public:
    vector<int> branch1, branch2, branch3;
    int b[3];

    college()
    {
        b[0] = rand() % 8 + 10;
        b[1] = rand() % 8 + 10;
        b[2] = rand() % 8 + 10;
    }
    void collegedata(int x)
    {
        int i;
        ofstream write;
        write.open("CollegeData.dat", ios::app);
        write << colleges[x] << endl;
        write << "Computer Science : " << b[0] << endl;
        for (i = 0; i < branch1.size(); i++)
        {
            write << branch1[i] << " ";
        }
        if (i != b[0] - 1)
        {
            for (int j = i + 1; j < b[0]; j++)
            {
                write << "__ ";
            }
        }
        write << endl;
        write << "Mechanical : " << b[1] << endl;
        for (i = 0; i < branch2.size(); i++)
        {
            write << branch2[i] << " ";
        }
        if (i != b[1] - 1)
        {
            for (int j = i + 1; j < b[1]; j++)
            {
                write << "__ ";
            }
        }
        write << endl;
        write << "Electrical : " << b[2] << endl;
        for (i = 0; i < branch3.size(); i++)
        {
            write << branch3[i] << " ";
        }
        if (i != b[2] - 1)
        {
            for (int j = i; j < b[2]; j++)
            {
                write << "__ ";
            }
        }
        write << endl
              << "------------------------------------------------------------------------------------" << endl;
    }
};

college clg[10];

class individual
{
    string name;
    int total, physics, maths, chemistry, rank, srno, round;
    vector<int> choices;

public:
    float phyper, cheper, matper, totper, clg1 = -1;
    individual()
    {
        int a, b;
        for (int i = 0; i < 3; i++)
        {
            a = rand() % 10 + 1;
            b = rand() % 3 + 1;
            choices.push_back(a * 10 + b);
        }
    }
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
        write1 << "Marks(Total,Phy,Che,Maths) as (Marks,PR) pair" << endl;
        write1 << "(" << total << "," << std::fixed << std::setprecision(2) << totper << ")"
               << " ";
        write1 << "(" << physics << "," << std::fixed << std::setprecision(2) << phyper << ")"
               << " ";
        write1 << "(" << chemistry << "," << std::fixed << std::setprecision(2) << cheper << ")"
               << " ";
        write1 << "(" << maths << "," << std::fixed << std::setprecision(2) << matper << ")"
               << " " << endl;
        // write1 << "Total: " << total << " ";
        // write1 << "Physics: " << physics << " ";
        // write1 << "Chemistry: " << chemistry << " ";
        // write1 << "Maths: " << maths << endl;
        // write1 << "Physics PR: " << std::fixed << std::setprecision(2) << phyper << " ";
        // write1 << "Chemistry PR: " << std::fixed << std::setprecision(2) << cheper << " ";
        // write1 << "Maths PR: " << std::fixed << std::setprecision(2) << matper << endl;
        // write1 << "Total PR: " << std::fixed << std::setprecision(2) << totper << endl;
        // write1 << "Choices entered: " << choices[0] << " " << choices[1] << " " << choices[2] << endl;

        collegewrite(write1, clg1, round, choices);

        write1 << "------------------------------------------------------------------------------------" << endl;
        write1.close();
    }
    void check(int x)
    {

        if (x != 0)
        {
            int a, b, j = 2 * x;
            for (int i = 0; i < 3; i++)
            {
                a = rand() % 10 + 1;
                b = rand() % 3 + 1;
                choices.push_back(a * 10 + b);
            }
        }
        int size = choices.size();
        int one, two;
        for (int i = 0; i < size; i++)
        {
            one = choices[i] / 10;
            two = choices[i] % 10;
            if (two == 1)
            {
                if (clg[one - 1].branch1.size() < clg[one - 1].b[0])
                {
                    clg1 = choices[i];
                    clg[one - 1].branch1.push_back(rank);
                    round = x + 1;
                    break;
                }
                else
                    continue;
            }
            else if (two == 2)
            {
                if (clg[one - 1].branch2.size() < clg[one - 1].b[1])
                {
                    clg1 = choices[i];
                    clg[one - 1].branch2.push_back(rank);
                    round = x + 1;
                    break;
                }
                else
                    continue;
            }
            else
            {
                if (clg[one - 1].branch3.size() < clg[one - 1].b[2])
                {
                    clg1 = choices[i];
                    clg[one - 1].branch3.push_back(rank);
                    round = x + 1;
                    break;
                }
                else
                    continue;
            }
        }
        round = x + 1;
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
    belowequal = cnt;
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
    belowequal = cnt;
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
    belowequal = cnt;
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
void userinput()
{
    int date, month, year;
    string name;
    int p, c, m;

    cout << "Enter name: " << endl;
    cin >> name;
    student_name.push_back(name);

    cout << "Enter Physics Marks: " << endl;
    cin >> p;
    cout << "Enter Chemistry Marks: " << endl;
    cin >> c;
    cout << "Enter Maths Marks: " << endl;
    cin >> m;
    cout << "Enter Your date of birth: " << endl;
    cin >> date;
    cout << "Enter Your month of birth: " << endl;
    cin >> month;
    cout << "Enter Your year of birth: " << endl;
    cin >> year;

    int days = ((year - 2001) * 12 * 28) + ((month - 1) * 28) + date;

    bday.push_back(make_pair(make_pair(cnt + 1, date), make_pair(month, year)));

    myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(-1 * days, cnt + 1))))));
    cnt++;
}
void sortall()
{
    sort(phy.rbegin(), phy.rend());
    sort(che.rbegin(), che.rend());
    sort(mat.rbegin(), mat.rend());
}
void collegewrite(ofstream &write1, int clg1, int round, vector<int> &choices)
{
    int i = 0;
    if (round == 2)
    {
        write1 << "Round 1 : " << choices[i] << " " << choices[i + 1] << " " << choices[i + 1] << endl;
        write1 << "You have not been assigned any seat in any college of your preferrence" << endl;
        i = 3;
    }
    if (round == 3)
    {
        write1 << "Round 1 : " << choices[i] << " " << choices[i + 1] << " " << choices[i + 1] << endl;
        write1 << "You have not been assigned any seat in any college of your preferrence" << endl;
        i = 3;
        write1 << "Round 2 : " << choices[i] << " " << choices[i + 1] << " " << choices[i + 1] << endl;
        write1 << "You have not been assigned any seat in any college of your preferrence" << endl;
        i = 6;
    }
    write1 << "Round " << round << " : " << choices[i] << " " << choices[i + 1] << " " << choices[i + 1] << endl;
    if (clg1 == -1)
    {
        write1 << "You have not been assigned any seat in any college of your preferrence" << endl;
        write1 << endl;
    }
    else
    {
        int one, two;
        one = clg1 / 10;
        two = clg1 % 10;

        switch (two)
        {
        case 1:
            write1 << "You have been alloted a seat in Computer Science";
            break;
        case 2:
            write1 << "You have been alloted a seat in Mechanical";
            break;
        case 3:
            write1 << "You have been alloted a seat in Electrical";
            break;

        default:
            break;
        }

        switch (one)
        {
        case 1:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 2:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 3:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 4:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 5:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 6:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 7:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 8:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 9:
            write1 << " in " << colleges[one - 1] << endl;
            break;
        case 10:
            write1 << " in " << colleges[one - 1] << endl;
            break;

        default:
            break;
        }
    }
}
int main()
{
    system("CLS");

    Database student;
    userinput();
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

    colleges.push_back("IIT-Bombay");
    colleges.push_back("IIT-Roorkee");
    colleges.push_back("DAIICT");
    colleges.push_back("NIT-Trichy");
    colleges.push_back("IIIT-Vadodara");
    colleges.push_back("BITS-Pilani");
    colleges.push_back("VIT");
    colleges.push_back("SRM");
    colleges.push_back("IISc-Bangalore");
    colleges.push_back("PDPU");

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < cnt; i++)
        {
            if (person[i].clg1 == -1)
                person[i].check(j);
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        person[i].sorteddata();
    }
    ofstream openclose1;
    openclose1.open("CollegeData.dat");
    openclose1.close();
    for (int i = 0; i < 10; i++)
    {
        clg[i].collegedata(i);
    }
    return 0;
}