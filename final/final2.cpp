#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

vector<pair<int, int>> phy, che, mat;

vector<pair<int, pair<int, pair<int, pair<int, pair<int, int>>>>>> myvec;
vector<string> student_name, colleges;
vector<pair<pair<int, int>, pair<int, int>>> bday;

#define E1(i) myvec[i].first
#define E2(i) myvec[i].second.first
#define E3(i) myvec[i].second.second.first
#define E4(i) myvec[i].second.second.second.first
#define E5(i) myvec[i].second.second.second.second.first
#define E6(i) myvec[i].second.second.second.second.second

int cnt = 0, belowequal, rnd = 1;
void collegewrite(int clg1, int rank, vector<int> &choices);
int countdays(int day, int month, int year);

class Database
{
    void writeraw()
    {
        int x = 0, day, month, year;

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
                       << "0" << day << "/";
            else
                write2 << "Birthdate: " << day << "/";

            if (month < 10)
                write2 << "0" << month << "/" << year << endl;
            else
                write2 << month << "/" << year << endl;

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

        int p, c, m, date, month, year, total, serialno;
        string temp, s;

        cout << BOLDWHITE << "Do you want to generate a set of random data?" << endl
             << "Enter Y for yes" << endl
             << endl;
        cin >> s;

        if (s == "Y" || s == "y" || s == "yes")
        {
            ifstream read1;
            ofstream writedata;
            string temp;

            read1.open("NameData.dat");
            writedata.open("Alldata.dat");
            srand(time(0));

            while (read1 >> temp)
            {
                p = ((rand() % 50) + 51);
                c = ((rand() % 50) + 51);
                m = ((rand() % 50) + 51);
                date = (rand() % 28) + 1;
                month = (rand() % 12) + 1;
                year = (rand() % 3) + 2001;

                writedata << cnt + 1 << " "
                          << temp << " "
                          << p << " "
                          << c << " "
                          << m << " "
                          << (rand() % 28) + 1 << " "
                          << (rand() % 12) + 1 << " "
                          << (rand() % 3) + 2001 << " "
                          << endl;

                cnt++;
            }
            read1.close();
            writedata.close();

            ifstream readall;
            readall.open("Alldata.dat");

            while (readall >> serialno >> temp >> p >> c >> m >> date >> month >> year)
            {
                student_name.push_back(temp);
                bday.push_back(make_pair(make_pair(serialno, date), make_pair(month, year)));
                myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(countdays(date, month, year), serialno))))));
            }

            belowequal = cnt;
        }

        else
        {
            ifstream readall;
            readall.open("Alldata.dat");

            while (readall >> serialno >> temp >> p >> c >> m >> date >> month >> year)
            {
                student_name.push_back(temp);
                bday.push_back(make_pair(make_pair(serialno, date), make_pair(month, year)));
                myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(countdays(date, month, year), serialno))))));
            }
            cnt = serialno;
        }
    }

    void callall()
    {
        this->writeraw();
        this->oursort();
    }
};

class college
{
public:
    vector<int> branch1, branch2, branch3;
    int b[3];

    void defineseats()
    {
        b[0] = rand() % 8 + 10;
        b[1] = rand() % 8 + 10;
        b[2] = rand() % 8 + 10;
    }
};

college clg[10];

class individual
{
    string name;
    int total, physics, maths, chemistry, rank;
    vector<int> choices;

public:
    float phyper, cheper, matper, totper, clg1 = -1, srno;
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
    void userchoices()
    {
        choices.clear();
        char c;
        int ch;

        cout << WHITE;
        cout << "Do you want to enter the seat allocation process." << endl;
        cout << "Enter" << GREEN << " 'Y' " << WHITE << "or" << GREEN << " 'y' " << WHITE << "for YES" << endl
             << endl;
        cout << "\t\t OR" << endl
             << endl;
        cout << "Enter" << RED << " 'N' " << WHITE << "or" << RED << " 'n' " << WHITE << "for NO" << endl;
        cout << "(We suggest to atleast try one round to check where you stand)" << endl;
        cin >> c;
        if (c == 'Y' || c == 'y')
        {
            system("CLS");
            cout << "Let's look at the choices of each college and their respective branches :  " << endl;

            cout << BOLDYELLOW << "Prefixes" << WHITE << " for colleges: " << endl
                 << endl;
            cout << BOLDMAGENTA << "(1) " << CYAN << "IIT-Bombay" << endl;
            cout << MAGENTA << "(2) " << CYAN << "IIT-Roorkee" << endl;
            cout << MAGENTA << "(3) " << CYAN << "DAIICT" << endl;
            cout << MAGENTA << "(4) " << CYAN << "IIIT-Vadodara" << endl;
            cout << MAGENTA << "(5) " << CYAN << "BITS-Pilani" << endl;
            cout << MAGENTA << "(6) " << CYAN << "IISc-Bangalore" << endl;
            cout << MAGENTA << "(7) " << CYAN << "NIT-Trichy" << endl;
            cout << MAGENTA << "(8) " << CYAN << "VIT" << endl;
            cout << MAGENTA << "(9) " << CYAN << "SRM" << endl;
            cout << MAGENTA << "(10) " << CYAN << "PDPU" << WHITE << endl
                 << endl;

            cout << WHITE;

            cout << BOLDYELLOW << "Suffixes" << WHITE << " for Branches: " << endl
                 << endl;
            cout << BOLDGREEN << "(1) " << CYAN << "Computer-Science" << endl;
            cout << GREEN << "(2) " << CYAN << "Mechanical" << endl;
            cout << GREEN << "(3) " << CYAN << "Electrical" << endl;
            cout << WHITE << endl;

            cout << "For ex :" << endl
                 << endl;
            cout << "For " << BOLDMAGENTA << "in IIT Bombay" << WHITE << "-" << GREEN << "Electrical " << MAGENTA << " 1" << GREEN << "3 " << WHITE << endl;
            cout << endl;
        }

        while (c == 'y' || c == 'Y')
        {
            cout << "Enter choice : ";
            cin >> ch;
            choices.push_back(ch);
            cout << endl;
            cout << "Do you want to enter another choice?" << endl;
            cout << "Enter" << GREEN << " 'Y' " << WHITE << "or" << GREEN << " 'y' " << WHITE << "for YES" << endl;
            cout << "Enter" << RED << " 'N' " << WHITE << "or" << RED << " 'n' " << WHITE << "for  NO" << endl;
            cout << "Enter here: " << endl;
            cin >> c;
        }
    }
    void assign(int i)
    {
        this->name = student_name[E6(i) - 1];
        this->total = E1(i);
        this->maths = E2(i);
        this->physics = E3(i);
        this->chemistry = E4(i);
        this->srno = E6(i);
        this->rank = i + 1;

        phy.push_back(make_pair(E3(i), rank));
        che.push_back(make_pair(E4(i), rank));
        mat.push_back(make_pair(E2(i), rank));
    }
    void sorteddata(ofstream &write1)
    {
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
                   << "0" << day << "/";
        else
            write1 << "Birthdate: " << day << "/";

        if (month < 10)
            write1 << "0" << month << "/" << year << endl;
        else
            write1 << month << "/" << year << endl;

        write1 << "Total: " << total << " ";
        write1 << "Physics: " << physics << " ";
        write1 << "Chemistry: " << chemistry << " ";
        write1 << "Maths: " << maths << endl;
        write1 << "Physics PR: " << std::fixed << std::setprecision(2) << phyper << " ";
        write1 << "Chemistry PR: " << std::fixed << std::setprecision(2) << cheper << " ";
        write1 << "Maths PR: " << std::fixed << std::setprecision(2) << matper << endl;
        write1 << "Total PR: " << std::fixed << std::setprecision(2) << totper << endl;
        write1 << "Choices entered: " << choices[0] << " " << choices[1] << " " << choices[2] << endl;

        write1 << "------------------------------------------------------------------------------------" << endl;
    }
    void check(int x)
    {
        if (clg1 == -2)
        {
            collegewrite(clg1, x + 1, choices);
            return;
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
                    break;
                }
                else
                    continue;
            }
        }
        collegewrite(clg1, x + 1, choices);
    }

    void display()
    {
        int newsr = srno;
        int day = bday[newsr - 1].first.second;
        int month = bday[newsr - 1].second.first;
        int year = bday[newsr - 1].second.second;

        cout << WHITE;
        cout << "         /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "        ///                                                                                                               ///" << endl;
        cout << "       ///" << YELLOW << "                                                 Rank - " << setw(3) << setfill(' ') << rank << " "
             << "                                                   " << WHITE << "///" << endl;
        cout << "      ///                                                                                                               ///" << endl;
        cout << "     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

        cout << endl
             << endl;

        cout << "     "
             << MAGENTA
             << "Sr. No: " << WHITE << srno << endl
             << endl;
        cout << "     "
             << MAGENTA
             << "Name: " << WHITE << name << endl;

        if (day < 10)
            cout << "     "
                 << MAGENTA
                 << "Birthdate: "
                 << WHITE
                 << "0" << day << "/";
        else
            cout << "     "
                 << MAGENTA
                 << "Birthdate: "
                 << WHITE << day << "/";

        if (month < 10)
            cout << "0" << month << "/" << year << endl
                 << endl;
        else
            cout << month << "/" << year << endl
                 << endl;

        cout << "     "
             << "<-----"
             << YELLOW
             << "  Marks  "
             << WHITE
             << "----->" << endl
             << endl;
        cout << "     "
             << BLUE << "Physics: " << WHITE << physics << CYAN << "\tPhysics PR: " << std::fixed << std::setprecision(2) << WHITE << phyper << endl;
        cout << "     "
             << BLUE << "Chemistry: " << WHITE << chemistry << CYAN << "\tChemistry PR: " << std::fixed << std::setprecision(2) << WHITE << cheper << endl;
        cout << "     "
             << BLUE << "Maths: " << WHITE << maths << CYAN << "\t\tMaths PR: " << std::fixed << std::setprecision(2) << WHITE << matper << endl
             << endl;
        cout << "     "
             << BLUE << "Total: " << WHITE << total << CYAN << "\t\tTotal PR: " << std::fixed << std::setprecision(2) << WHITE << totper << endl;
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
    }
};
individual *person;

void withdraw()
{
    for (int i = 0; i < 10; i++)
    {
        int a = rand() % (cnt / 100), b;
        for (int j = 0; j < a; j++)
        {
            if (clg[i].branch1.size() == 0)
            {
                break;
            }
            b = rand() % clg[i].branch1.size();
            if (person[clg[i].branch1[b] - 1].srno == cnt)
                continue;
            person[clg[i].branch1[b] - 1].clg1 = -2;
            clg[i].branch1.erase(clg[i].branch1.begin() + b);
        }
        a = rand() % (cnt / 100);
        for (int j = 0; j < a; j++)
        {
            if (clg[i].branch2.size() == 0)
            {
                break;
            }
            b = rand() % clg[i].branch2.size();
            if (person[clg[i].branch2[b] - 1].srno == cnt)
                continue;
            person[clg[i].branch2[b] - 1].clg1 = -2;
            clg[i].branch2.erase(clg[i].branch2.begin() + b);
        }
        a = rand() % (cnt / 100);
        for (int j = 0; j < a; j++)
        {
            if (clg[i].branch3.size() == 0)
            {
                break;
            }

            b = rand() % clg[i].branch3.size();
            if (person[clg[i].branch3[b] - 1].srno == cnt)
                continue;
            person[clg[i].branch3[b] - 1].clg1 = -2;
            clg[i].branch3.erase(clg[i].branch3.begin() + b);
        }
    }
}

void percentile()
{
    belowequal = cnt;
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
    int date = 1, month = 1, year = 2000;
    string name;
    int p = 10, c = 10, m = 10;

    cout << "Enter name: ";
    getchar();
    getline(cin, name);
    student_name.push_back(name);

    while (1)
    {
        cout << "Enter Physics Marks: ";
        cin >> p;
        if (p > 100 || p < 0)
            cout << RED << "Oops! You entered ambiguos marks!" << WHITE << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Chemistry Marks: ";
        cin >> c;
        if (c > 100 || c < 0)
            cout << RED << "Oops! You entered ambiguos marks!" << WHITE << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Maths Marks: ";
        cin >> m;
        if (m > 100 || m < 0)
            cout << RED << "Oops! You entered ambiguos marks!" << WHITE << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Your date of birth: ";
        cin >> date;
        if (date > 31 || date < 0)
            cout << RED << "Oops! You entered ambiguos date!" << WHITE << endl
                 << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Your month of birth: ";
        cin >> month;
        if (month > 12 || month < 0)
            cout << RED << "Oops! You entered ambiguos month!" << WHITE << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Your year of birth: ";
        cin >> year;
        if (year > 2003 || year < 2000)
            cout << RED << "Oops! You entered ambiguos year!" << WHITE << endl
                 << endl;
        else
            break;
    }

    bday.push_back(make_pair(make_pair(cnt + 1, date), make_pair(month, year)));

    myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(countdays(date, month, year), cnt + 1))))));

    sleep(1);
    system("CLS");
    for (int i = 0; i < 2; i++)
    {
        cout << YELLOW << "Uploading your data to the database ";
        sleep(1);
        system("CLS");
        cout << YELLOW << "Uploading your data to the database .";
        sleep(1);
        system("CLS");
        cout << YELLOW << "Uploading your data to the database ..";
        sleep(1);
        system("CLS");
        cout << YELLOW << "Uploading your data to the database ...";
        sleep(1);
        system("CLS");
    }
    cout << WHITE;

    cout << GREEN << "Succesfully Uploaded!!" << WHITE << endl;

    ofstream insideuserinput;
    insideuserinput.open("Alldata.dat", ios::app);
    insideuserinput << cnt + 1 << " "
                    << name << " "
                    << p << " "
                    << c << " "
                    << m << " "
                    << date << " "
                    << month << " "
                    << year << " "
                    << endl;
    insideuserinput.close();
    cnt++;
}

void sortsubjects()
{
    sort(phy.rbegin(), phy.rend());
    sort(che.rbegin(), che.rend());
    sort(mat.rbegin(), mat.rend());
}

void collegewrite(int clg1, int rank, vector<int> &choices)
{
    ofstream write;
    if (rnd == 1)
    {
        write.open("Round1.dat", ios::app);
    }
    else if (rnd == 2)
    {
        write.open("Round2.dat", ios::app);
    }
    else if (rnd == 3)
    {
        write.open("Round3.dat", ios::app);
    }

    if (clg1 == -2)
    {
        write << "Rank : " << rank << endl;
        write << "You have withdrawn your seat" << endl;
        write << endl;
    }
    else if (clg1 == -1)
    {
        write << "Rank : " << rank << endl;
        write << "You have not been assigned any seat in any college of your preferrence" << endl;
        write << endl;
    }
    else
    {
        write << "Rank : " << rank << endl;
        int one, two;
        one = clg1 / 10;
        two = clg1 % 10;

        switch (two)
        {
        case 1:
            write << "You have been alloted a seat in Computer Science";
            break;
        case 2:
            write << "You have been alloted a seat in Mechanical";
            break;
        case 3:
            write << "You have been alloted a seat in Electrical";
            break;
        default:
            break;
        }
        write << " in " << colleges[one - 1] << endl
              << endl;
    }
}

int countdays(int day, int month, int year)
{
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days;
    int a = 0;
    if (year == 2000)
    {
        arr[1]++;

        for (int i = 0; i < month - 1; i++)
            a += arr[i];
        a += day;
        return -1 * a;
    }
    a += 366;
    for (int i = 2001; i < year; i++)
    {
        a += 365;
    }
    for (int i = 0; i < month - 1; i++)
        a += arr[i];
    a += day;
    return -1 * a;
}

void collegedata()
{
    int i;
    ofstream write;
    write.open("CollegeData.dat", ios::app);
    write << "//////////////////////////////////////////////////////////////////" << endl;
    write << "////                                                           ///" << endl;
    write << "////                         ROUND                             ///" << endl;
    write << "////                                                           ///" << endl;
    write << "//////////////////////////////////////////////////////////////////" << endl;
    for (int x = 0; x < 10; x++)
    {

        write << colleges[x] << endl;
        write << "Computer Science : " << clg[x].b[0] << endl;
        for (i = 0; i < clg[x].branch1.size(); i++)
        {
            write << clg[x].branch1[i] << " ";
        }
        if (i != clg[x].b[0] - 1)
        {
            for (int j = i + 1; j < clg[x].b[0]; j++)
            {
                write << "__ ";
            }
        }
        write << endl;
        write << "Mechanical : " << clg[x].b[1] << endl;
        for (i = 0; i < clg[x].branch2.size(); i++)
        {
            write << clg[x].branch2[i] << " ";
        }
        if (i != clg[x].b[1] - 1)
        {
            for (int j = i + 1; j < clg[x].b[1]; j++)
            {
                write << "__ ";
            }
        }
        write << endl;
        write << "Electrical : " << clg[x].b[2] << endl;
        for (i = 0; i < clg[x].branch3.size(); i++)
        {
            write << clg[x].branch3[i] << " ";
        }
        if (i != clg[x].b[2] - 1)
        {
            for (int j = i; j < clg[x].b[2]; j++)
            {
                write << "__ ";
            }
        }
        write << endl
              << "------------------------------------------------------------------------------------" << endl;
    }
    write.close();
}

void branchclear()
{
    for (int i = 0; i < 10; i++)
    {
        clg[i].branch1.clear();
        clg[i].branch2.clear();
        clg[i].branch3.clear();
    }
}

int main()
{
    system("CLS");
    Database student;

    userinput();
    sleep(1);
    system("CLS");
    cout << YELLOW;
    for (int i = 0; i < 2; i++)
    {
        cout << "Now Sorting the data to assign ranks .";
        sleep(1);
        system("CLS");
        cout << "Now Sorting the data to assign ranks .";
        sleep(1);
        system("CLS");
        cout << "Now Sorting the data to assign ranks ..";
        sleep(1);
        system("CLS");
        cout << "Now Sorting the data to assign ranks ...";
        sleep(1);
        system("CLS");
    }
    cout << GREEN << "Process Complete!!" << endl;
    sleep(1);
    system("CLS");
    student.callall();

    person = new individual[cnt];

    for (int i = 0; i < cnt; i++)
    {
        person[i].assign(i);
    }

    sortsubjects();
    percentile();
    ofstream openclose;
    openclose.open("Ranks.dat");
    openclose.close();
    ofstream openclose1;
    openclose1.open("Round1.dat");
    openclose1.close();
    ofstream openclose2;
    openclose2.open("Round2.dat");
    openclose2.close();
    ofstream openclose3;
    openclose3.open("Round3.dat");
    openclose3.close();
    ofstream opencloseclg;
    opencloseclg.open("CollegeData.dat");
    opencloseclg.close();

    ofstream write1;
    write1.open("Ranks.dat", ios::app);
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        clg[i].defineseats();
    }
    int a;

    for (a = 0; a < cnt; a++)
    {
        if (person[a].srno == cnt)
            break;
    }
    person[a].display();
    person[a].userchoices();
    cout << endl;
    char c;
    for (int j = 0; j < 3; j++)
    {
        branchclear();
        system("CLS");
        for (int i = 0; i < 2; i++)
        {
            cout << "Round " << j + 1 << " in progress ";
            sleep(1);
            system("CLS");
            cout << "Round " << j + 1 << " in progress .";
            sleep(1);
            system("CLS");
            cout << "Round " << j + 1 << " in progress ..";
            sleep(1);
            system("CLS");
            cout << "Round " << j + 1 << " in progress ...";
            sleep(1);
            system("CLS");
        }

        for (int i = 0; i < cnt; i++)
        {
            person[i].check(i);
        }
        collegedata();
        cout << "Round " << j + 1 << " Ended !!!" << endl
             << endl;
        cout << "Please visit CollegeData file to view remaining seats." << endl
             << endl;

        if (person[a].clg1 != -2)
        {
            cout << "Do you want to " << RED << "withdraw" << WHITE << " you your seat?" << endl;
            cout << "Enter" << RED << " 'Y' " << WHITE << "or" << RED << " 'y' " << WHITE << "for YES" << endl;
            cout << "Enter" << GREEN << " 'N' " << WHITE << "or" << GREEN << " 'n' " << WHITE << "for  NO" << endl
                 << endl;
            cin >> c;
            if (c == 'y' || c == 'Y')
                person[a].clg1 = -2;
        }

        if (j != 2)
            withdraw();
        rnd++;
    }
    for (int i = 0; i < cnt; i++)
    {
        person[i].sorteddata(write1);
    }
    write1.close();
    cout << RESET;
    return 0;
}